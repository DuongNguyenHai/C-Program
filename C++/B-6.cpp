#include <stdio.h>
#include <stdlib.h> // exit()

// n la so ky tu phair cat, m la tong so ky tu
char *trichphai(char s[], int n, int m){
	int i=0;
	char *str = (char *)malloc(128);
	while( s[i]!='\0' ){
		str[i] = s[m-n+i];
		i++;
		if(i>n) break;
	}
	str[i]='\0';
	
	return str;
}


void doctep(char s[],int &m){
	FILE *pfile;
	pfile = fopen("file/B-6-read.txt","r");
	// kiem tra xem co mo duoc file khong, neu khong thi se bao loi va ket thuc chuong trinh,
	// gia tri tra ve qua ham exit() la -1
	if(pfile==NULL){
		perror("error opening file");
		exit(-1);
	}
	// copy toan bo cac ky tu trong file ra s[], bao gom ca ky tu space, tab, newline ...
	while( !feof(pfile) ){
		s[m]=fgetc(pfile);
		m++;
	}
	m--;
	s[m]='\0';
}

int main(){
	char s[128]; // chuoi trong file chi chua toi da 128 ky tu
	int n=0;
	int m=0; // bien cho tong so ky tu, tong ky tu bao gom ca space, tab, newline
	doctep(s,m);
	printf("chuoi : \"%s\"\nso luong ky tu la:%d\n",s,m);
	printf("Trich phai n ky tu, ban hay nhap n:\n");
	printf("n = ");scanf("%d",&n);
	
	if( n>=m){
		printf("n phai no hon so luong ky tu");
		return 0;
	}
		
	printf("chuoi cat duoc : \"%s\"",trichphai(s,n,m));
	return 1;
}
