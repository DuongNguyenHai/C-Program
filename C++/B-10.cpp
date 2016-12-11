#include <stdio.h>
#include <stdlib.h> //exit()

float nhonhat(float a[], int n, int vitri[], int &tongvitri){
	float min=a[0];
	int i=0,j=0;
	// tim min
	while(i<n){
		if(	min>a[i] )
			min=a[i];
		i++;
	}
	i=0;
	// tim cac vi tri cua max
	while(i<n){
		if(a[i]==min){
			vitri[j]=i;
			j++;
		}	
		i++;	
	}
	tongvitri=j;
	return min;
}
// du lieu trong tep : 2,3,4,6,9
void doctep(float a[], int &n){
	FILE *pfile;
	pfile = fopen("file/B-10-read.txt","r");
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
void ghitep(int vitri[], int tongvitri, float min){
	FILE *pfile;
	pfile = fopen("file/B-10-write.txt","w");
	if(pfile==NULL){
		perror ("Error opening file");
		exit(-1);
	}
	fprintf(pfile,"vi tri : ");
	for(int i=0;i<tongvitri;i++){
		fprintf(pfile,"%d ",vitri[i]);
	}
	fprintf(pfile,"\ntong vi tri : %d",tongvitri);
	fprintf(pfile,"\ngia tri min : %f",min);
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
	float min = nhonhat(a,n,vitri,tongvitri);
	printf("min:%f\n",min);
	printf("cac vi tri min : \n");
	for(int i=0;i<tongvitri;i++){
		printf("%d  ",vitri[i]);
	}
	ghitep(vitri,tongvitri, min);
	return 0;
}

