#include <unistd.h>
#include <stdio.h>

int main(){
  printf("Numero maximo de enlaces: %li\n", pathconf("/", _PC_LINK_MAX));
  printf("Tamaño maximo de una ruta: %li\n", pathconf("/", _PC_PATH_MAX));
  printf("Tamaño maximo de un nombre de fichero: %li\n", pathconf("/", _PC_NAME_MAX));
  
  return 0;
}

/*
La salida es la siguiente:

Numero maximo de enlaces: 2147483647
Tamaño maximo de una ruta: 4096
Tamaño maximo de un nombre de fichero: 255
*/
