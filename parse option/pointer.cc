#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PointerLevel2(int *x);
void PointerVoid(void *x);
void PointerVoidCstring(void *x);


int main(int argc, char const *argv[]) {
	int b;
	int a = 10;

	// PointerLevel2(&a);
	// printf("PointerLevel2, a : %d\n",a);

	// PointerVoid(&a);
	// printf("PointerVoid, a : %d\n",a);

	// int *c = &a;
	int *c = (int *)malloc(sizeof(int));
	c = &a;
	// int *d = c;
	// *d = 10;
	printf("c:%d\n", *c);

	char *str;
	void *vvv = str;
	vvv = (char *)"hehe";
	printf("leng:%ld\n", strlen((char *)vvv));
	printf("str: %s\n", str);

	// (char *)t = "duong";
	// PointerVoidCstring(c);

	free(c);
	return 0;
}

void PointerLevel2(int *x){
	*x = 10;
}

void PointerVoidInt(void *x) {
	*(int *)x =20;
}

void PointerVoidCstring(void *x) {

	// (char *)x = (char *)"Hey man";
	// char *c;
	// c = (char*)x;
	// printf("c:%s\n", c);

}