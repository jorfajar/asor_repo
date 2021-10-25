#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>

int main(){
  uid_t uid = getuid();
  
  printf("UID Real: %d\n", getuid());
  printf("UID Efectivo: %d\n", geteuid());
  
  struct passwd *pass = getwpuid(uid);
  
  char *name = pass->pw_name;
  char *dir = pass->pw_dir;
  char *info = pass->pw_gecos;
  
  printf("Username: %s\n", name);
  printf("Home: %s\n", dir);
  printf("Info: %s\n", info);
  
  return 0;
}

/*
La salida es la siguiente:

UID Real: 1000
UID Efectivo: 1000
Username: cursoredes
Home: /home/cursoredes
Info: cursoredes
*/
