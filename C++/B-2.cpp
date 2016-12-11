#include <stdio.h>
#include <stdlib.h> //exit()

void demkytu1(char s[], char kt[],int sl[], int &tskt){
	int i=0,j=0;
	int solan=1;
	tskt=0;
	while(s[i]!='\0'){
		// chi xet ky tu la chu cai va so
		if( 'a'<=s[i] && s[i]<='z' || 'A'<=s[i] && s[i]<='Z' || '0'<=s[i] && s[i]<='9' ){
			j=0;
			while(s[j]!='\0'){
				if(i!=j) // bo qua truong hop so sanh voi chinh minh
					if( s[i]==s[j])	// giong nhau, tang so lan
						solan++;
				j++;
			}
			// printf("solan: %d\n",solan);
			// kiem tra xem ky tu da co trong kt[] chua
			for(j=0;j<tskt;j++){
				if( s[i]==kt[j] )
					break;
			}
			// neu j==tskt tuc la chua co trong mang;
			if(j==tskt){
				kt[tskt]=s[i];	// luu ky tu
				sl[tskt]=solan; // luu so lan xuat hien cua ky tu
				tskt++;
			}
			solan=1; 		// reset so lan
		}
		
		i++;
	}
}

void doctep(char s[]){
	FILE *pfile;
	int i=0;
	pfile = fopen("file/B-2-read.txt","r");
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

void ghitep(char kt[],int sl[], int tskt){
	FILE *pfile;
	pfile = fopen("file/B-2-write.txt","w");
	if(pfile==NULL){
		perror ("Error opening file");
		exit(-1);
	}
	fprintf(pfile,"ky tu	:	so luong\n");
	for(int i=0;i<tskt;i++){
		fprintf(pfile,"%c	:	%d\n",kt[i],sl[i]);
	}
	fclose(pfile);
}

int main(){
	int tskt=0;
	char s[128]; // so luong bien toi da la 128., muon lam mang dong co the dung malloc nhung phuc tap hon nhieu
	char kt[128];
	int sl[128];
	
	doctep(s);
	printf("chuoi : \"%s\"\n",s);
	
	demkytu1(s,kt,sl,tskt);
	printf("Co phan biet chua hoa chu thuong\n");
	printf("kt : sl\n");
	for(int i=0;i<tskt;i++){
		printf("%c  :  %d\n",kt[i],sl[i]);
	}
	
	ghitep(kt,sl,tskt);
	return 1;
}

