#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char **argv){
  if(argc < 2){
    printf("ERROR: se debe especificar la ruta del archivo como parámetro.\n");
    return -1;
  }
  
  struct stat buff;
  int statint = stat(argv[1], &buff);
  
  if(statint == -1){
    printf("ERROR: no existe el directorio.\n");
    return -1;
  }
  
  printf("MAJOR: %li\n", (long)major(buff.st_dev));
  printf("MINOR: %li\n", (long)minor(buff.st_dev));
  
  printf("inode: %li\n", buff.st_ino);
  
  printf("MODE: %i\n", buff.st_mode);
  
  mode_t mode = buff.st_mode;
  
  if(S_ISLNK(mode)){
    printf("%s es un enlace simbólico.\n", argv[1]);
  }else if(S_ISREG(mode)){
    printf("%s es un archivo normal.\n", argv[1]);
  }else if(S_ISDIR(mode)){
    printf("%s es un directorio.\n", argv[1]);
  }
  
  time_t t = buff.st_mtime;
  struct tm *tm = localtime(&t);
  
  printf("Último acceso (M): %d:%d\n", tm->tm_hour, tm->tm_min);
  
  time_t t2 = buff.st_ctime;
  struct tm *tm2 = localtime(&t2);
  
  printf("Último acceso (C): %d:%d\n", tm2->tm_hour, tm2->tm_min);
  
  return 0;
}
