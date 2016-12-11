#include <stdio.h>
#include <time.h>
#include <stdint.h>

int main(int argc, char const *argv[]) {
  time_t t = time(NULL);
  printf("Now: %s", ctime(&t));
	t += 86400;
	printf("time_t %ld - %s\n", t, ctime(&t));
  return 0;
}
