#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  uid_t uid = getuid();
  
  printf("UID Real: %d\n", getuid());
  printf("UID Efectivo: %d\n", geteuid());
  
  return 0;
}

/*
La salida ha sido la siguiente:

UID Real: 1000
UID Efectivo: 1000
*/
