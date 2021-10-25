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
  
  return 0;
}

/*
La salida ha sido la siguiente:

2021
*/
