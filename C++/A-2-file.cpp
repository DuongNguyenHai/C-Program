#include <stdio.h>
#include <stdlib.h> //exit()

void selectsort(float a[], int n){
	int i=0, j=0,min;
	float tmp;
	while(i<n){
		// gan min voi vi tri dau cua chuoi
		min = i;
		// j duoc dung de lam gia tri so sanh voi min
		j = i+1;
		while(j<n){
			if( a[min]>a[j] )
				min = j;
			j++;
		}
		// hoan doi vi tri dau cho vi tri co gia tri nho nhat
		tmp = a[i];
		a[i] = a[min];
		a[min] = tmp;
		// tang vi tri dau cua chuoi len 1
		i++;
	}
}

void doctep(float a[], int n){
	int i = 0;
	FILE *pfile;
	pfile = fopen("file/A-2-file.txt","r");
	if(pfile!=NULL){
		while( !feof(pfile) ){
			fscanf(pfile,"%f;", &a[i]);
			i++;
			if(i>=n) break;
		}
	}else{
		perror ("Error opening file");
		exit(-1);
	}
	fclose(pfile);
}

void ghitep(float a[], int n){
	FILE *pfile;
	pfile = fopen("file/A-2-file-write.txt","w");
	if(pfile==NULL){
		perror ("Error opening file");
		exit(-1);
	}
	for(int i=0;i<n;i++){
		fprintf(pfile,"%f; ",a[i]);
	}
	fclose(pfile);
}

int main(){
	int n = 10;
	float a[15];
	doctep(a,n);
	selectsort(a,n);
	int i = 0;
	printf("Day duoc sap xep theo thu tu tang dan \n");
	for(i=0;i<n;i++){
		printf("%f  ",a[i]);
	}
	ghitep(a,n);
	return 0;
}

