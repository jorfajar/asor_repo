#include <stdio.h>
#include <errno.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char **argv){
  if(argc < 2){
    printf("Introduce la dirección.\n");
    return -1;
  }
  
  printf("Protocolos: [2] AF_INET [10] AF_INET6\n");
  printf("Tipos: [1] SOCK_STREAM [2] SOCK_DGRAM [3] SOCK_RAW\n");
  
  struct addrinfo hints;
  struct addrinfo *result, *iterator;
  
  memset(&hints, 0, sizeof(struct addrinfo));
  
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = 0;
  hints.ai_flags = AI_PASSIVE;
  hints.ai_protocol = 0;
  hints.ai_canonname = NULL;
  hints.ai_addr = NULL;
  hints.ai_next = NULL;
  
  if(getaddrinfo(argv[1], NULL, &hints, &result) != 0){
    printf("ERROR: No se ha podido ejercutar el getaddrinfo.\n");
    exit(EXIT_FAILURE);
  }
  
  for(iterator = result; iterator != NULL; iterator = iterator->ai_next){
    switch(iterator->ai_family){
      case AF_INET:
        struct sockaddr_in *info = iterator->ai_addr;
        char ip[INET_ADDRSTRLEN + 1] = "";
        inet_ntop(AF_INET, &(info->sin6_addr), ip, INET_ADDRSTRLEN + 1);
        printf("%s\t", ip);
        break;
        
      case AF_INET6:
        struct sockaddr_in6 *info6 = iterator->ai_addr;
        char ipv6[INER6_ADDRSTRLEN + 1] = "";
        inet_ntop(AF_INET6, &(info6->sin6_addr), ipv6, INET6_ADDRSTRLEN + 1);
        printf("%s\t", ipv6);
        break;
        
      default:
        printf("ERROR: ai_family no está definida.\n");
        break;
    }
    printf("%i\t%i\t\n", iterator->ai_family, iterator->ai_socktype);
  }
  freeaddrinfo(result);
  return 0;
}
