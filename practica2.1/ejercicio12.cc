#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  time_t t = time(NULL);
  
  printf("%li\n", t);
  
  return 0;
}

/*
La salida ha sido la siguiente:

1635158906
*/
