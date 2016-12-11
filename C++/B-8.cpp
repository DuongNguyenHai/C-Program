#include <stdio.h>
#include <stdlib.h> //exit()

void chenx(float a[], int &n, float x){
	int i = 0;
	float tmp,tmp_next;
	while( i<n ){
		if(x<a[i])
			break;
		i++;
	}
//	printf("n:%d, x:%f, i:%d\n",n,x,i);
	int j = 0;
	// viet tu cuoi, chuyen n->n+1
	while( j<n-i ){
		a[n-j] = a[n-j-1];
		j++;
//		printf("a[%d]:%f\n",n-j,a[n+1-j]);
	}
	a[i]=x;
	n++;
}
// du lieu trong tep : 2,3,4,6,9,x  CHU Y : o cuoi la gia tri chen x.
void doctep(float a[], int &n,float &x){
	FILE *pfile;
	pfile = fopen("file/B-8-read.txt","r");
	if(pfile!=NULL){
		while( !feof(pfile) ){
			fscanf(pfile,"%f,", &a[n]);
			n++;
		}
	}else{
		perror ("Error opening file");
		exit(-1);
	}
	x=a[n-1]; //gia tri cuoi la x
	a[n-1]=NULL;
	n--;
	fclose(pfile);
}
// du lieu ghi ra dang: 2,3,4,6,9
void ghitep(float a[], int n){
	FILE *pfile;
	pfile = fopen("file/B-8-write.txt","w");
	if(pfile==NULL){
		perror ("Error opening file");
		exit(-1);
	}
	for(int i=0;i<n-1;i++){
		fprintf(pfile,"%f,",a[i]);
	}
	fprintf(pfile,"%f",a[n-1]);
	fclose(pfile);
}

int main(){
	int n = 0;
	float x;
	float a[128]; // so luong bien toi da la 128., muon lam mang dong co the dung malloc nhung phuc tap hon nhieu
	doctep(a,n,x);
	
//	printf("so luong so thuc :%d\n",n);
	for(int i=0;i<n;i++){
		printf("%f  ",a[i]);
	}
	
	printf("\nchen x=%f vao chuoi\n",x);
	chenx(a,n,2.3);
	
	for(int i=0;i<n;i++){
		printf("%f  ",a[i]);
	}
	
	ghitep(a,n);
	return 0;
}

