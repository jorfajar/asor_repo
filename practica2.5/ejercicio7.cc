#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char**argv){
  if(argc < 2){
    printf("Introduce los parámetros.\n");
    return -1;
  }
  
  struct addrinfo hints;
  struct addrinfo *result;
  
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;
  
  if(getaddrinfo(argv[1], argv[2], &hints, &result) != 0){
    printf("ERROR: No se ha podido ejecutar el getaddrinfo.\n");
    exit(EXIT_FAILURE);
  }
  
  int socketTCP = socket(result->ai_family, result->ai_socktype, 0);
  connect(socketTCP, (struct sockaddr *)result->ai_addr, result->ai_addrlen);
  freeaddrinfo(result);
  
  char host[NI_MAXHOST];
  char serv[NI_MAXSERV];
  
  char bufin[256];
  char bufout[256];
  ssize_t c;
  
  while(1){
    c = read(0, bufout, 255);
    bufout[c] = '\0';
    send(socketTCP, bufout, c, 0);
    
    if((bufout[1] == 'q') && (c == 2)){
      printf("Conextión terminada.\n");
      break;
    }
    
    c = recv(socketTCP, bufin, 255, 0);
    bufin[c] = '\0';
    printf("[OUT]: %s\n", bufin);
  }
  close(socketTCP);
  return 0;
}
