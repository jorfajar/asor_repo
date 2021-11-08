#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int fd;
  mode_t prev = umask(027);
  
  fd = open("ej5.txt", O_RDONLY | O_CREAT | O_TRUNC, 0777);
  
  mode_t last = umask(prev);
  
  printf("Last: %i\n", last);
  
  close(fd);
  
  return 0;
}
