#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int sock = -1;

int main(int argc, char *argv[]) {
  struct sockaddr_in server_sockaddr;
  memset(&server_sockaddr, 0, sizeof(server_sockaddr));
  
  server_sockaddr.sin_family = AF_INET;
  server_sockaddr.sin_port = htons(8000);
  server_sockaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  
  sock = socket(server_sockaddr.sin_family, SOCK_DGRAM, 0);
  if(sock == -1) {
    perror("socket()");
    return EXIT_FAILURE;
  }
  
  char buf[512];
  printf("=> ");
  scanf("%511[^\n]", buf);
  sendto(sock, buf, sizeof(buf), 0, (struct sockaddr *) &server_sockaddr, sizeof(server_sockaddr));
  
  return EXIT_SUCCESS;
}

