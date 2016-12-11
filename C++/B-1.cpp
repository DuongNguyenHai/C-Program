#include <stdio.h>
#include <stdlib.h> // exit()

int demtu(char s[]){
	int i=0,n=0;
	int kytu_flag=0;
	int space_flag=0;
	// mot tu duoc dem dua vao viec phat hien ra ky tu va khoang tro dang sau no.
	// dua vao flag de phat hien.
	while(s[i]!='\0'){
		// kiem tra xem s[i] co phai lo ky tu hay so hay khong. dua tren bang ascii.
		if( 'a'<=s[i] && s[i]<='z' || 'A'<=s[i] && s[i]<='Z' || '0'<=s[i] && s[i]<='9' ){
			kytu_flag=1;
			space_flag=0;
		}
		else {	// truong hop s[i] la cac ky tu space, tab, newline ...
			space_flag=1;
		}
		if( kytu_flag && space_flag ){
			n++;
			kytu_flag=0;
		}
		i++;
	}	
	return n;
} 

void doctep(char s[]){
	FILE *pfile;
	int i=0;
	pfile = fopen("file/B-1-read.txt","r");
	// kiem tra xem co mo duoc file khong, neu khong thi se bao loi va ket thuc chuong trinh,
	// gia tri tra ve qua ham exit() la -1
	if(pfile==NULL){
		perror("error opening file");
		exit(-1);
	}
	// copy toan bo cac ky tu trong file ra s[], bao gom ca ky tu space, tab, newline ...
	while( !feof(pfile) ){
		s[i]=fgetc(pfile);
		i++;
	}
	s[i]='\0';
}

int main(){
	char s[128]; // chuoi trong file chi chua toi da 128 ky tu
	doctep(s);
	printf("chuoi : \"%s\".\nso tu : %d",s,demtu(s));
	
	return 1;
}
