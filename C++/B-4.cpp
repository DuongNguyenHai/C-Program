#include <stdio.h>
#include <stdlib.h> //exit()

int ktxau(char s1[], char s2[]){
	int i=0,j=0;
	bool flag_trung=false;
	while(s1[i]!='\0'){

		if(s1[i]==s2[0]){
			j=1;
			flag_trung=true;
			while(s2[j]!='\0'){
				if( s1[i+j]!=s2[j] ){
					flag_trung=false;
					break;
				}
				j++;
			}
			if(flag_trung)
				return 1;
		}
		
		i++;
	}
	return 0;
}
void doctep(char s1[], char s2[]){

	FILE *pfile;
	int i=0;
	pfile = fopen("file/B-4-read.txt","r");
	// kiem tra xem co mo duoc file khong, neu khong thi se bao loi va ket thuc chuong trinh,
	// gia tri tra ve qua ham exit() la -1
	if(pfile==NULL){
		perror("error opening file");
		exit(-1);
	}

//	if( fgets (s1, 128, pfile)==NULL ){
//		printf("s1 NULL!\n");
//	}
//	if( fgets (s2, 128, pfile)==NULL ){
//		printf("s2 NULL!\n");
//	}
	char c;
	while( (c = fgetc(pfile)) != '\n' && c != EOF) {
		if(c!='\n')
			s1[i] = c;
		i++;
	}
	s1[i]='\0';
	
	i=0;
	
	while( (c = fgetc(pfile)) != EOF) {
		if(c!='\n')
			s2[i] = c;
		i++;
	}
	s2[i]='\0';

}


int main(){

	char s1[128]; // so luong bien toi da la 128., muon lam mang dong co the dung malloc nhung phuc tap hon nhieu
	char s2[128]; // so luong bien toi da la 128., muon lam mang dong co the dung malloc nhung phuc tap hon nhieu
	
	printf("2 xau duoc phan biet voi nhau bang newline\n");
	doctep(s1,s2);
	printf("chuoi s1 : %s\n",s1);
	printf("chuoi s2 : %s\n",s2);
	
	if(ktxau(s1,s2))
		printf("chuoi s1 chua s2");
	else
		printf("chuoi s1 khong chua s2");
		
	return 1;
}

