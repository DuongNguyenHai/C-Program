#include <iostream>
#include <stdlib.h>
using namespace std;

class complex{
	private:
		float real;	// so thuc
		float img;	// so ao
		static int count;
	public:

		complex(float r, float i);
		~complex(){};
		void EnterValue();
		void Display();
		friend complex operator+(complex a, complex b);
};

int complex::count = 0;


complex::complex(float r=0, float i=0){
	count++;
	real = r;
	img = i;
}

void complex::EnterValue(){
	cout << "Nhap vao so phuc "<< count <<" : a +bi \n";
	
	cout << "a = "; 	cin >> real;
	while (!cin) {
        cout << "a phai la so ! hay nhap lai a \n" ;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "a = "; cin >> real;
    }
    
	cout << "b = "; cin >> img;
	while (!cin) {
        cout << "b phai la so ! hay nhap lai b \n" ;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "b = "; cin >> img;
    }
}

void complex::Display(){
	cout << real << " + " << img << "i\n";
}
complex operator+(complex a, complex b){
	complex c;
	c.real = a.real + b.real;
	c.img = a.img + b.img;
	return c;
}

int main(){
	complex a;
//	a.EnterValue();
	a.Display();
	complex b(1,5);
//	b.EnterValue();
	b.Display();
	complex c;
	c= a+b;
	cout << "Tong cua 2 so phuc : ";
	c.Display();
	return 1;
}
