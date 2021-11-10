#include <stdio.h>
#include <fnctl.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char **argv){
  if(argc < 2){
    printf("ERROR: se debe especificar la ruta por parámetro.\n");
    return -1;
  }
  
  int fd = open(argv[1], O_CREAT | ORDWR, 00777);
  
  if(fd == -1){
    printf("No se ha podido abrir o crear el fichero.\n");
    return -1;
  }
  
  struct flock lock;
  
  lock.l_type = F_UNLCK;
  lock.l_whence = SEEK_SET;
  lock.l_start = 0;
  lock.l_len = 0;
  lock.l_pid = getpid();
  
  int stauts = fcntl(fd, F_GETLK, &lock);
  
  if(lock.l_type == F_UNLCK){
    printf("STATUS: cerrojo desbloqueado.\n");
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    
    if(fcntl(fd, F_GETLK, &lock) == -1){
      printf("ERROR: no se ha podido crear el cerrojo.\n");
      close(fd);
      return 1;
    }else{
      printf("STATUS: creado cerrojo de escritura.\n");
    }
    
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    
    char buffer[1024];
    
    sprintf(buffer, "Hora: %d:%d\n", tm->tm_hour, tm->tm_min);
    
    write(fd, &buffer, strlen(buffer);
          
    sleep(30);
          
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
      
    if(fcntl(fd, F_GETLK, &lock) == -1){
      printf("ERROR: no se ha podido crear el cerrojo.\n");
      close(fd);
      return 1;
    }else{
      close(fd);
    }
  }else{
    printf("STATUS: cerrojo bloqueado.\n");
    close(fd);
    return 1;
  }
  close(fd);
          
  return 0;
}
