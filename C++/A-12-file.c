// file viet theo chuan cua c khong phai c++
#include <stdio.h>
#include <stdlib.h>

int tongchuthuong(char s[]){
	int i=0;
	int n=0;
	
	while(s[i]!='\0'){
		if( 96<s[i] && s[i]<123 )
			n++;
		i++;
	}
	
	return n;
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
	printf("Tong so chu thuong trong chuoi \"%s\" la: %d",s,tongchuthuong(s));
}

