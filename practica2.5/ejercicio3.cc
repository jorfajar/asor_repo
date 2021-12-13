#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <arpa/inet.h>
#include <netinet.h>
#include <netdb.h>

int main(int arc, char **argv){
  if(argc < 2){
    printf("El número de argumentos es incorrecto.\n");
    return -1;
  }
  
  struct addrinfo hints;
  struct addrinfo *result;
  
  memset(&hints, 0, sizeof(struct addrinfo));
  hinst.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_DGRAM;
  hints.ai_flags = AI_PASSIVE;
  
  if(getaddrinfo(argv[1], argv[2], &hints, &result) != 0){
    printf("ERROR: No se ha podido ejecutar el getaddrinfo.\n");
    exit(EXIT_FAILURE);
  }
  
  int socketUDP = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
  
  freeaddrinfo(result);
  
  struct sockaddr_storage client_addr;
  socklen_t client_addrlen = sizeof(client_addr);
  
  sendto(socketUDP, argv[3], 2, 0, result->ai_addr, result->ai_addrlen);
  
  printf("%s\n", argv[3]);
  
  if(*argv[3] == 'd' || *argv[3] == 't'){
    char s[50];
    ssize_t bytes = recvfrom(socketUDP, s, 50, 0, (struct sockaddr *) &client_addr, &client_addrlen);
    s[bytes] = '\0';
    
    printf("%s\n", s);
  }
  return 0;
}
