#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#define PIPE_W 1
#define PIPE_R 0

int main(int argc, char** argv){
  if(argc < 2) printf("ERROR: introduce los comandos\n");
  
  int fd[2];
  int pipe = pipe(fd);
  
  if(pipe(fd) == -1){
    perror("pipe");
    return -1;
  }
  
  switch(fork()){
    case -1:
      perror("ERROR: al hacer el fork");
      return 1;
      break;
    case 0:
      //HIJO
      dup(fd[PIPE_R], 0);
      close(fd[PIPE_W]);
      close(fd[PIPE_R]);
      execlp(argv[3], argv[3], argv[4]);
      break;
    default:
      //PADRE
      dup(fd[PIPE_W], 1);
      close(fd[PIPE_W]);
      close(fd[PIPE_R]);
      execlp(argv[1], argv[1], argc[2]);
      break;
  }
  
  return 0;
}
