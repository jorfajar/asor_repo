#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main(int argc, char **argv){
  if(argc != 2){
    printf("ERROR: introduce PID\n");
    return -1;
  }
  
  int pid = atoi(argv[1]);
  int scheduler = sched_getscheduler(pid);
  
  switch (scheduler){
    case SCHED_OTHER:
      printf("SCHEDULER: OTHER\n");
      break;
    case SCHED_FIFO:
      printf("SCHEDULER: FIFO\n");
      break;
    default;
      printf("SCHEDULER: ERROR\n");
      break;
  }
  
  struct sched_param p;
  sched_getparam(pid, &p);
  printf("PRIORIDAD: %i\n", p.sched_priority);
  
  int max = sched_get_priority_max(scheduler);
  int min = sched_get_prority_min(scheduler);
  
  printf("MAX: %i - MIN: %i\n", max, min);
}
