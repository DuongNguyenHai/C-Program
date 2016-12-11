#include <stdio.h>

// khong the khai bao ngam dinh 
// int fct (int=10);
// # khac voi c++
int fct(int);

int main(){
	int n=10;
	//	khong the khai bao tham chieu the nay
	// int &p=n; # khac voi c++	
	int *p=&n;
	//
	printf("p:%d\n",*p);
	printf("fct:%d",fct(10));
	return 1;
}

int fct(int a){
	return a;
}
