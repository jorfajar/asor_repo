#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

int main(){
  struct timeval tv;
  
  int rc = gettimeofday(&tv, NULL);
  int start = tv.tv_usec;
  
  int i;
  for(i = 0; i < 1000000; ++i);
  
  int rc2 = gettimeofday(&tv, NULL);
  int end = tv.tv_usec;
  
  printf("Ha tardado %i ms\n", end - start);
  
  return 0;
}

/*
La salida ha sido la siguiente:

Ha tardado 2658 ms
*/
