#include <stdio.h>
#include <time.h>

int main ()
{
   time_t rawtime;
   struct tm *info;
   char buffer[50];

   time( &rawtime );

   info = localtime( &rawtime );

   strftime(buffer, sizeof(buffer),"%X - %x", info);
   printf("Formatted date & time : |%s|\n", buffer );
   char *str = &buffer[0];
   printf("Formatted date & time : |%s|\n", str );
   return(0);
}
