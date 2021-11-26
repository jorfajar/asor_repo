#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/time.h>

void printAtrib(char *type){
  printf("[%s]PID: %i\n", type, getpid());
  printf("[%s]PPID: %i\n", type, getppid());
  printf("[%s]SID: %i\n", type, getsid(getpid()));
  
  struct rlimit limit;
  
  if(getrlimit(RLIMIT_NOFILE, &limit) == -1){
    perror("Unable to get the resource limits");
  }
  
  printf("[%s]LIMIT: %li\n", type, limit.rlim_max);
  
  char *path = malloc(sizeof(char)*(4096 + 1));
  char *rpath = getcwd(path, 4096 + 1);
  
  printf("[%s]CWD: %s\n", type, path);
  free(path);
}

int main(){
  pid_t pid = fork();
  
  switch(pid){
    case -1:
      perror("fork");
      exit(-1);
      break;
    case 0:
      pid_t mi_sid = setsid();
      char *ncwd = chdir("/tmp");
      
      printf("[Hijo] Proceso %i (Padre: %i)\n", getpid(), getppid());
      printAtrib("Hijo");
      sleep(3);
      break;
    default:
      printf("[Padre] Proceso %i (Padre: %i)\n", getpid(), getppid());
      printfAtrib("Padre");
      sleep(3);
      break;
  }
  
  return 0;
}
