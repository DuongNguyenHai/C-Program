#include <stdio.h>
#include <stdlib.h> //exit()

float lonnhat(float a[], int n, int vitri[], int &tongvitri){
	float max=a[0];
	int i=0,j=0;
	// tim max
	while(i<n){
		
		if(	max<a[i] )
			max=a[i];
		i++;
	}
	i=0;
	// tim cac vi tri cua max
	while(i<n){
		if(a[i]==max){
			vitri[j]=i;
			j++;
		}	
		i++;	
	}
	tongvitri=j;
	return max;
}
// du lieu trong tep : 2,3,4,6,9
void doctep(float a[], int &n){
	FILE *pfile;
	pfile = fopen("file/B-9-read.txt","r");
	if(pfile!=NULL){
		while( !feof(pfile) ){
			fscanf(pfile,"%f,", &a[n]);
			n++;
		}
	}else{
		perror ("Error opening file");
		exit(-1);
	}
	fclose(pfile);
}
// du lieu ghi ra file co dang: 2,3,4,6,9
void ghitep(int vitri[], int tongvitri, float max){
	FILE *pfile;
	pfile = fopen("file/B-9-write.txt","w");
	if(pfile==NULL){
		perror ("Error opening file");
		exit(-1);
	}
	fprintf(pfile,"vi tri : ");
	for(int i=0;i<tongvitri;i++){
		fprintf(pfile,"%d ",vitri[i]);
	}
	fprintf(pfile,"\ntong vi tri : %d",tongvitri);
	fprintf(pfile,"\ngia tri max : %f",max);
	fclose(pfile);
}

int main(){
	int n = 0, tongvitri=0;
	int vitri[128];
	float a[128]; // so luong bien toi da la 128., muon lam mang dong co the dung malloc nhung phuc tap hon nhieu
	doctep(a,n);
	
//	printf("so luong so thuc :%d\n",n);
	for(int i=0;i<n;i++){
		printf("%f  ",a[i]);
	}
	printf("\n");
	float max = lonnhat(a,n,vitri,tongvitri);
	printf("max:%f\n",max);
	printf("cac vi tri max : \n");
	for(int i=0;i<tongvitri;i++){
		printf("%d  ",vitri[i]);
	}
	ghitep(vitri,tongvitri, max);
	return 0;
}

