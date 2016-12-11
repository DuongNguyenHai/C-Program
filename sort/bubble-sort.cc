#include <stdio.h>


void BubbleSort(int bubble[], int size) {
	int tmp;
	for (int i = 0; i < size; ++i)
	{
		for (int j = i+1; j < size; ++j)
		{
			if(bubble[j]<bubble[i]) {
				tmp = bubble[j];
				bubble[j] = bubble[i];
				bubble[i] = tmp;
			}
		}
		for (int k = 0; k < size; ++k)
		{
			printf("%d ", bubble[k]);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	int bub[5] = {8,5,7,3,12};
	printf("bubble size: %ld\n", sizeof(bub)/sizeof(bub[0]));
	BubbleSort(bub, sizeof(bub)/sizeof(bub[0]));
	return 0;
}