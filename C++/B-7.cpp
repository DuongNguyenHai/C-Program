#include <stdio.h>
#include <math.h>	// ham pow(), ham tri tuyet doi cho float: fabs()

// ham de quy. no se nhan lien tuc tinh n*(n-1) toi khi nao n <=1
long giaithua(int n){
	if(n<=1)
		return 1;
	else
		return n*giaithua(n-1);
}

float ex(float x, float c){
	int n = 0;
	float exp_x=0, tmp;
	while(1){
		tmp = pow(x,n)/giaithua(n);	
		if( fabs(tmp) > c )
			exp_x += tmp;
		else
			break;
		n++;
	}
	return exp_x;
}

int main(){
	float x=0,c=0;
	
	printf("nhap x,c :\n");
	printf("x =");scanf("%f",&x);
	printf("c =");scanf("%f",&c);

	printf("Tinh exp(x), voi dieu kien abs(x^n/n!) < c :\nexp(x) = %f\n",ex(x,c));
	
	return 1;
}


