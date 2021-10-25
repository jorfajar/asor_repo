#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

const int MAX_ERROR = 255;

int main(){
  char *s;
  int i;
  
  for(int i = 0; i < MAX_ERROR; ++i){
    printf("ERROR(%d): %s\n", i, sterror(i));
  }
  return 1;
}

/*
  Devuelve ERROR(0): Success y del ERROR(1) al ERROR(133) diversos errores
*/
