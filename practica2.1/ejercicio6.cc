#include <unistd.h>
#include <stdio.h>

int main(){
  printf("Longitud maxima de los argumentos: %li\n", sysconf(_SC_ARG_MAX));
  printf("Numero maximo de hijos: %li\n", sysconf(_SC_CHILD_MAX));
  printf("Numero maximo de ficheros: %li\n", sysconf(_SC_OPEN_MAX));
  
  return 0;
}

/*
La salida es la siguiente:

Longitud maxima de los argumentos: 2097152
Numero maximo de hijos: 3836
Numero maximo de ficheros: 1024
*/
