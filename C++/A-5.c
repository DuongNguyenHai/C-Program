// file viet theo chuan cua c khong phai c++
#include <stdio.h>

// ham de quy. no se nhan lien tuc n*(n-1) toi khi nao n <=1
long giaithua(int n){
	if(n<=1)
		return 1;
	else
		return n*giaithua(n-1);
}

void main(){
	int n = 0;
	printf("nhap so nguyen duong : ");
	scanf("%d",&n);

	long u = giaithua(n);
	
	printf("Gai thua cua so n la : %ld\n",u);

}

