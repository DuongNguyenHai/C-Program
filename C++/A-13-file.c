// file viet theo chuan cua c khong phai c++
#include <stdio.h>
#include <stdlib.h>

char *doithuhoa(char s[]){
	int i = 0;
	while(s[i]!='\0'){
		if( 96<s[i] && s[i]<123 )
			s[i] = s[i]-32;
		i++;
	}
	return s;
}

void doctep(char s[]){
	FILE *pfile;
	pfile = fopen("file/A-13-file.txt","r");
	if(pfile==NULL){
		perror("error opening file");
		exit(-1);
	}

	fgets(s,128,pfile);
	fclose(pfile);
}

void main(){
	char s[128];
	doctep(s);
	printf("Doi chuoi vua nhap thanh chu in hoa: %s",doithuhoa(s));
}

