#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv){
  if(argc < 2){
    printf("ERROR: se debe especificar la ruta por parámetro.\n");
    return -1;
  }
  
  struct stat buff;
  int statint = stat(argv[1], &buff);
  
  if(statint == -1){
    printf("ERROR: no existe el directorio.\n");
    return -1;
  }
  
  char *hard = malloc(sizeof(char)*(5 + strlen(argv[1])));
  char *sym = malloc(sizeof(char)*(5 + strlen(argv[1])));
  
  strcpy(hard, argv[1]);
  strcpy(sym, argv[1]);
  
  hard = strcat(hard, ".hard");
  sym = strcat(sym, ".sym");
  
  printf("HARD: %s\n", hard);
  printf("SYM: %s\n", sym);
  
  mode_t mode = buff.st_mode;
  
  if(S_ISREG(mode)){
    printf("%s es un archivo ordinario.\n", argv[1]);
    
    if(link(argv[1], hard) == -1){
      printf("ERROR: no se ha podido crear un enlace rígido.\n");
    }else{
      printf("Se ha creado un enlace rígido.\n");
    }
    
    if(symlink(argv[1], sym) == -1){
      printf("ERROR: no se ha podido crear un enlace simbólico.\n");
    }else{
      printf("Se ha creado un enlace simbólico.\n");
    }
  }else{
    printf("ERROR: la ruta introducida no es un archivo ordinario.\n");
  }
  
  return 0;
}
