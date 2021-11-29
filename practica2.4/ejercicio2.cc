#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv){
  int p_h[2];
  int h_p[2];
  int fin = 0, m = 0;
  
  if(pipe(p_h) == -1){
    perror("pipe");
    return -1;
  }
  
  if(pipe(h_p) == -1){
    perror("pipe");
    return -1;
  }
  
  switch(fork()){
    case -1:
      perror("ERROR: al hacer el fork");
      return 1;
      break;
    case 0:
      close(p_h[1]);
      close(h_p[0]);
      
      while(!fin){
        int rc = read(p_h[0], buffer, 256);
        buffer[rc] = '\0';
        printf("Mensaje recibido: %s\n", buffer);
        sleep(1);
        if(++m == 10){
          write(h_p[1], "q", 1);
          fin = 1;
        }else{
          write(h_p1[1], "l", 1);
        }
      }
      close(p_h[0]);
      close(h_p[1]);
      return 0;
      break;
    default:
      close(p_h[0]);
      close(h_p[1]);
      
      while(!fin){
        printf("? ");
        scanf("%s", buffer);
        write(p_h[1], buffer, strlen(buffer)+1);
        read(h_p[0], buffer, 1);
        if(buffer[0] == 'q'){
          fin = 1;
        }
      }
      close(p_h[1]);
      close(h_p[0]);
      return 0;
      break;
  }
  return 0;
}
        
