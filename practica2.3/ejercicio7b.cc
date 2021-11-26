#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv){
  if(argc < 2){
    printf("ERROR: introduce el comando.\n");
    return -1;
  }
  
  if(execvp(argv[1], argv + 1) == -1){
    printf("ERROR: no se ha ejecutado correctamente.\n");
  }
  
  printf("El comando terminó de ejecutarse.\n");
  
  return 0;
}
