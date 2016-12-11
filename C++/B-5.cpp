#include <stdio.h>
#include <stdlib.h> // exit()

char *trichtrai(char s[], int n, int m){
	int i=0;
	char *str = (char *)malloc(128);
	// cat n ky tu bat dau tu vi tri m
	while( s[i]!='\0' ){
		str[i] = s[m+i];
		i++;
		if(i>n) break;
	}
	str[i]='\0';
	
	return str;
}


void doctep(char s[],int &m){
	FILE *pfile;
	pfile = fopen("file/B-5-read.txt","r");
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
	int n=0,m=0;
	int total=0;
	doctep(s,total);
	printf("chuoi : \"%s\"\nso luong ky tu la:%d\n",s,total);
	printf("Trich trai n ky tu tinh tu vi tri m, ban hay nhap m va n:\n");
	printf("m = ");scanf("%d",&m);
	printf("n = ");scanf("%d",&n);
	
	if( m>total){
		printf("m phai no hon so luong ky tu");
		return 0;
	}
		
	printf("chuoi cat duoc : \"%s\"",trichtrai(s,n,m));
	return 1;
}
