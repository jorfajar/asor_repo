#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/type.h>

int main(){
  struct utsname info;
  if(uname(&info) == -1){
    printf("ERROR(%d); %s\n", errno, strerror(errno));
    return -1;
  }else{
    printf("Nombre del sistema: %s\n", info.sysname);
    printf("Nodename: %s\n", info.nodename);
    printf("Release: %s\n", info.release);
    printf("Version: %s\n", info.version);
    printf("Machine: %s\n", info.machine);
  }
  return 1;
}

/*
La salida ha sido la siguiente:

Nombre del sistema: Linux
Nodename: localhost.localdomain
Release: 3.10.0-862.11.6.el7.x86_64
Version: #1 SMP Tue Aug 14 21:48:04 UTC 2018
Machine: x86_64
*/
