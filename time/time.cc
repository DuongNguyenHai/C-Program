/* localtime example */
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <unistd.h>

int main ()
{
	std::vector<struct tm> sch;

  time_t rawtime;
  struct tm * tnow;
  // time ( &rawtime );
  // tnow = localtime ( &rawtime );
  // printf ( "Current local time and date: %s", asctime (tnow) );
  // printf("[Now] hour: %d, minute: %d, second: %d\n", tnow->tm_hour, tnow->tm_min, tnow->tm_sec);

  sch.resize(3);
  sch[0].tm_hour = 14;
  sch[0].tm_min = 13;
  sch[0].tm_sec = 0;

  sch[1].tm_hour = 14;
  sch[1].tm_min = 11;
  sch[1].tm_sec = 0;

  sch[2].tm_hour = 14;
  sch[2].tm_min = 14;
  sch[2].tm_sec = 0;

  int timer;

  for (int i = 0; i < 3; ++i)
  {
  	time ( &rawtime );
  	tnow = localtime ( &rawtime );
  	printf ( "Current local time and date: %s", asctime (tnow) );
  	// printf("[Now] hour: %d, minute: %d, second: %d\n", tnow->tm_hour, tnow->tm_min, tnow->tm_sec);
  	if ( tnow->tm_hour <= sch[i].tm_hour )
  	{
  		timer = (sch[i].tm_hour - tnow->tm_hour)*3600 + (sch[i].tm_min - tnow->tm_min)*60 + (sch[i].tm_sec - tnow->tm_sec);
  		if(timer >0) {
  			printf("[Schedule %d] hour: %d, minute: %d, second: %d\n", i, sch[i].tm_hour, sch[i].tm_min, sch[i].tm_sec);
  			printf("timer: %d\n", timer);
  			sleep(timer);
  		}
  	}
  }

  return 0;
}
