#include <stdio.h>

int main(int argc, char const *argv[])
{
	
	int num = 10;
	int *pi = &num;
	void *vp = pi;	// its equal void *vp = &num
	printf("Value of num : %d, Address of num : %p\n", num, &num);
	printf("Value of *pi : %d, Address of pi point to : %p, Address of pi : %p\n", *pi, pi, &pi);
	printf("Value of void *vp : %d, Address of void vp point to : %p, Address of void vp : %p\n", *(int *)vp, vp, &vp);


	// Change value through void *
	// If u wanna cast other type :
	// float : *(float *)vp
	// ...

	*(int *)vp = 20;
	printf("Value of num was changed by void *: %d\n", num);

	printf("size of int : %zu, size of void * point to int: %zu\n", sizeof(num), sizeof(*(int *)vp));

	return 0;
}