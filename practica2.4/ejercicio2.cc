#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#define PIPE_W 1
#define PIPE_R 0

int main(){
  int p_h[2];
  int h_p[2];
  
  pipe(p_h);
  pipe(h_p);
  
  switch(fork()){
    case -1:
      perror("ERROR: al hacer el fork");
      return 1;
      break;
    case 0:
      close(p_h[1]);
      close(h_p[1]);
      
      for (size_t i = 0; i < 10; ++i){
        ssize_t bytes = read(p_h[0], mensajePadre, 255);
        mensajePadre[bytes] = '\0';
        printf("[HIJO] Recibido %s\n", mensajePadre);
        sleep(1);
        if(i == 9) flag = 'q';
        write(h_p[1], &flag, 1);
      }
      break;
    default:
      close(
