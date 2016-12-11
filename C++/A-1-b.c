// file viet theo chuan cua c not c++
#include <stdio.h>

void doicoso2(int n, int b[0], int *k){
	int i = 0, j = 0;
	int c;
	*k = 0;
	if(n==0) return "0";
	// chia n den khi nao = 0 thi thoi
	while(n){
		b[*k] = n%2;
		n = n/2;
		(*k)++;
	}
	
	j=*k-1;
	// dao nguoc gia tri cua chuoi b.
	while(i<j){
		c = b[i];
		b[i] = b[j];
		b[j] = c;
		i++; j--;
	}
}

void main(){
	int i=0, n = 0, b[16] , k;
	// mang b chua 16 bien, nen so nguyen toi da n = 2^16
	printf("Nhap vao so nguyen duong n : ");
	scanf("%d", &n);
	
	doicoso2(n,b,&k);
	
	printf("chuyen n sang co so 2 :");
	for(i=0; i<k;i++){
		printf("%d",b[i]);
	}
}
