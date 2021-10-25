#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

int main(){
  time_t t = time(NULL);
  struct tm *info = localtime(&t);
  
  int year = info->tm_year;
  
  printf("%i\n", 1900 + year);
  
  char buf[100];
  strftime(buf, 100, "%A, %d of %B of , %H:%M", info);
  printf(%s\n, buf);
  
  return 0;
}

/*
La salida ha sido la siguiente:

Monday, 25 of October of , 16:26
*/
