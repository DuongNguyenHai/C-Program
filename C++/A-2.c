// file viet theo chuan cua c khong phai c++
#include <stdio.h>

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
	
	selectsort(a,n);
	
	printf("Day duoc sap xep theo thu tu tang dan \n");
	for(i=0;i<n;i++){
		printf("%f  ",a[i]);
	}
}
