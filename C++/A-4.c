// file viet theo chuan cua c khong phai c++
#include <stdio.h>

void bubblesort(float a[], int n){
	int i=0, j;
	float tmp;
	while(i<n){
		// gan j voi vi tri cuoi hang
		j=n-1;
		while(j>i){ // so sanh toi tan dau hang
			// neu vi tri sau < vi tri truoc thi hoan doi cho nhau
			if( a[j]<a[j-1] ){
				tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
			}
			j--;
		}
		// tang vi tri dau hang len 1
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
	
	bubblesort(a,n);
	
	printf("Day duoc sap xep theo thu tu tang dan \n");
	for(i=0;i<n;i++){
		printf("%f  ",a[i]);
	}
}

