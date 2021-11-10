#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv){
  if(argc < 2){
    printf("ERROR: se debe especificar la ruta por parámetro.\n");
    return -1;
  }
  
  int fd = open(argv[1], O_CREAT | O_RDWR, 0777);
  
  if(fd == -1){
    printf("ERROR: no se ha podido abrir o crear el fichero.\n");
    return -1;
  }
  
  int fd2 = dup2(fd, 1);
  
  printf("Se ha redirigido %d\n", argv[1]);
  
  dup2(fd2, fd);
  
  return 1;
}
