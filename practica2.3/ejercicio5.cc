#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/resources.h>
#include <sys/time.h>

int main(){
  printf("PID: %i\n", getpid());
  printf("PPID: %i\n", getppid());
  printf("SID: %i\n", getsid(getpid()));
  
  struct rlimit limit;
  
  if(getrlimit(RLIMIT_NOFILE, &limit) == -1){
    perror("Unavle to get the resource limits");
    return -1;
  }
  
  printf("LIMIT: %li\n", limit.rlim_max);
  
  char *path = malloc(sizeof(char)*(4096 + 1));
  char *rpath = getcwd(path, 4096 + 1);
  
  printf("CWD: %s\n", path);
  free(path);
  
  return 0;
}
