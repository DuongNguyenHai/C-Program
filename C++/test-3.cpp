#include <iostream>

// co the khai bao ngam dinh (int=10) # voi c
int fct(int=10);

int main(){
	int n = 10;
	int &p=n;
	std::cout<<"p:"<<(p)<<std::endl;
	std::cout<<"fct:"<<fct();
	return 1;
}

int fct(int a){
	return a;
}
