// file viet theo chuan cua c khong phai c++
#include <stdio.h>

void insertionsort(float a[], int n){
	int i=1, j;
	float tmp;
	while(i<n){
		j = i;
		tmp = a[j];
		// hoan doi vi tri cua j voi j-1 neu tmp < a[j-1]
		while( j>0 && tmp<a[j-1] ){
			a[j] = a[j-1];
			j--;
		}
		// vi tri thich hop cua tmp
		a[j] = tmp;
		// tang vi tri dau cua chuoi len 1
		i++;
	}
}

void main(){
	int n, i=0;
	printf("nhap so luong day so muon sap xep: ");
	scanf("%d",&n);
	// tao mang float[n] va nhap du lieu
	float a[n];
	for(i=0;i<n;i++){
		printf("a[%d] : ",i);
		scanf("%f",&a[i]);
	}
	
	insertionsort(a,n);
	
	printf("Day duoc sap xep theo thu tu tang dan \n");
	for(i=0;i<n;i++){
		printf("%f  ",a[i]);
	}
}
