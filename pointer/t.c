#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	// printf("The case : void to int *\n");
	// printf("The case : void to char *\n");
	// char *p = (char *)malloc(10);
	// // p = (char *)"Hallo";
	// void *v = p;
	// printf("Value of pi : %s, Address of void p point to : %p, Address of p : %p\n", p, (void *)p, &p);
	// p = (char *)"Hallo";
	// printf("Value of void *v : %s, Address of void v point to : %p, Address of void v : %p\n", (char *)v, (void *)(char *)v, &v);
	// printf("Value of pi : %s, Address of void p point to : %p, Address of p : %p\n", p, (void *)p, &p);

	printf("The case : void** to char *\n");
	// char *pi = (char *)"Hallo";
	char *pi;
	// pi = (char *)"Hallo";
	void *vp = pi;
	printf("Value of pi : %s, Address of void pi point to : %p, Address of pi : %p\n", pi, (void *)pi, &pi);
	// pi = (char *)"Hallo";
	printf("Value of void *vp : %s, Address of void vp point to : %p, Address of void vp : %p\n", (char *)vp, (void *)(char *)vp, &vp);
	// vp = (char *)"Hallo";
	// printf("Value of pi : %s, Address of void pi point to : %p, Address of pi : %p\n", pi, (void *)pi, &pi);
	// printf("Value of void *vp : %s, Address of void vp point to : %p, Address of void vp : %p\n", (char *)vp, (void *)(char *)vp, &vp);

	char *p = (char *)vp;
	p = (char *)"Hallo everyone";
	// // (char *)vp = (char *)"Hallo";
	printf("Value of p : %s, Address of void p point to : %p, Address of p : %p\n", p, (void *)p, &p);
	printf("Value of pi : %s, Address of void vp point to : %p, Address of pi : %p\n", pi, (void *)pi, &pi);
	printf("Value of void *vp : %s, Address of void vp point to : %p, Address of void vp : %p\n", (char *)vp, (void *)(char *)vp, &vp);

	return 0;
}