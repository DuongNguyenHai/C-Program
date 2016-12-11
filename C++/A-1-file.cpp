// file viet theo chuan cua c not c++
#include <stdio.h>
#include <stdlib.h> // exit();

// viet ham duoi dang con tro ham de co the tra ve gia tri la con tro mang char
char *doinhiphan(int n){
	int k = 0, i = 0;
	char *b = new char[16];
	char c;

	if(n==0) return "0";
	// chia n den khi nao = 0 thi thoi
	while(n){
		b[k] = '0' + n%2;
		n = n/2;
		k++;
	}
	// gan gia tri '\0' de bien thanh chuoi ky tu
	b[k]='\0';
	k=k-1;
	// dao nguoc gia tri cua chuoi b.
	while(i<k){
		c = b[i];
		b[i] = b[k];
		b[k] = c;
		i++; k--;
	}
	
	return b;
}

void doctep(int &n){
	FILE *pfile;
	pfile = fopen("file/A-1-file.txt","r");
	if(pfile==NULL){
		perror ("Error opening file");
		exit(-1);
	}
		
	while( ! feof(pfile)){
		fscanf(pfile, "%d", &n);
	}
	fclose(pfile);	
}

int main(){
	int n = 0;

//	printf("Nhap vao so nguyen duong n : ");
//	scanf("%d", &n);
	doctep(n);
	printf("chuyen n sang co so 2 : %s",doinhiphan(n));
	return 0;
}
