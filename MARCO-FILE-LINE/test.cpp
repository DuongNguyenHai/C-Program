#include <stdio.h>
#define merge(a, b) a##b

int main()
{
	printf("%d \n", merge(12, 34));
	printf("Current File :%s\n", __FILE__ );
	printf("Current Date :%s\n", __DATE__ );
	printf("Current Time :%s\n", __TIME__ );
	printf("Line Number :%d\n", __LINE__ );
   
   return 0;
}

