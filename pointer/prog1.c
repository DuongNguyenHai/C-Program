#include <stdio.h>

int main(int argc, char const *argv[])
{
	// Initialization pointer

	int num = 10;
	int *p;
	p = &num;
	printf("Value of num : %d, Address of num : %p\n", num, &num);
	printf("Value of *pointer : %d, Address of pointer point to : %p, Address of pointer : %p\n", *p, p, &p); //can cast (void *)p

	// anotherway of initialize
	// int *t = &num;

	// int *e = (int *)num;	
	// printf("%d\n", *e);	// segmentation fault

	// Change value through pointer
	*p = 20;
	printf("Value of num was changed by *pointer : %d\n", num);



	return 0;
}