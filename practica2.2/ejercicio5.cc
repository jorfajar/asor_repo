#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fctnl.h>
#include <unistd.h>

int main(){
  int fd;
  
  fd = open("ej5.txt", O_WRLONLY | O_CREAT | O_TRUNC, 0645);
  
  if(fd == -1){
    perror("Error en open");
    return fd;
  }
  
  close(fd);
  
  return 0;
}
