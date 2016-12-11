#include <stdio.h>
#include <stdlib.h> //exit()

void solan2(float a[], int n, float a2[], int &m){
	int i=0,j=0;
	m=0;
	int solan=1;
	while(i<n){
		// neu quet het chuoi ma khong bat gap phan tu nao giong minh thi j se bang n
		// cung nghia la phan tu a[i] do la duy nhat		
		for(j=0;j<n;j++){
			if(i!=j) // bo qua truong hop so sanh voi chinh minh
				if( a[i]==a[j])
					solan++;
		}
		// luu phan tu do vao mang a1 neu solan=2
		if(solan==2){
			// so sanh xem a[i] do da co trogn mang a2[] chua, neu chua se luu vao
			for(j=0;j<m;j++){
				if(a[i]==a2[j])
					break;	
			}
			// chua co phan tu nao trong mang
			if(j==m){
				a2[m]=a[i];
				m++;
			}
		}
		solan=1; //reset so lan
		i++;
	}
}

// du lieu trong tep : 2,3,4,6,9
void doctep(float a[], int &n){
	FILE *pfile;
	pfile = fopen("file/B-12-read.txt","r");
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
// du lieu ghi ra dang: 2,3,4,6,9
void ghitep(float a2[], int m){
	FILE *pfile;
	pfile = fopen("file/B-12-write.txt","w");
	if(pfile==NULL){
		perror ("Error opening file");
		exit(-1);
	}
	for(int i=0;i<m-1;i++){
		fprintf(pfile,"%f,",a2[i]);
	}
	fprintf(pfile,"%f",a2[m-1]);
	fclose(pfile);
}

int main(){
	int n = 0, m=0;
	
	float a[128]; // so luong bien toi da la 128., muon lam mang dong co the dung malloc nhung phuc tap hon nhieu
	float a2[128];
	doctep(a,n);
	
//	printf("so luong so thuc :%d\n",n);
	for(int i=0;i<n;i++){
		printf("%f  ",a[i]);
	}
	printf("\n");
	solan2(a,n,a2,m);
	
	printf("cac phan tu xuat hien 2 lan :\n");
	for(int i=0;i<m;i++){
		printf("%f  ",a2[i]);
	}
	
	ghitep(a2,m);
	return 1;
}

