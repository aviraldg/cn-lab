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
  
  server_sock = socket(server_sockaddr.sin_family, SOCK_STREAM, 0);
  if(server_sock == -1) {
    perror("socket()");
    return EXIT_FAILURE;
  }
  
  if(-1 == connect(sock, (struct sockaddr *) &server_sockaddr, sizeof(server_sockaddr))) {
    perror("connect()");
    return EXIT_FAILURE;
  }
  
  char buf[512];
  printf("=> ");
  scanf("%s", buf);
  send(sock, buf, sizeof(buf), 0);
  
  return EXIT_SUCCESS;
}

