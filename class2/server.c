#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

int server_sock = -1;

int main(int argc, char *argv[]) {
  struct sockaddr_in server_sockaddr;
  memset(&server_sockaddr, 0, sizeof(server_sockaddr));
  server_sockaddr.sin_family = AF_INET;
  server_sockaddr.sin_port = htons(8000);
  server_sockaddr.sin_addr.s_addr = INADDR_ANY;
  
  server_sock = socket(server_sockaddr.sin_family, SOCK_STREAM, 0);
  if(server_sock == -1) {
    perror("socket()");
    return EXIT_FAILURE;
  }
  
  int yes = 1;
  setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
  
  if(-1 == bind(server_sock, (struct sockaddr *)&server_sockaddr, sizeof(server_sockaddr))) {
    perror("bind()");
    return EXIT_FAILURE;
  }
  
  if(-1 == listen(server_sock, 20)) {
    perror("listen()");
    return EXIT_FAILURE;
  }
  
  while(1) {
      struct sockaddr_in client_addr;
      size_t size;
      int client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &size);
      if(client_sock == -1) {
        perror("accept()");
        return EXIT_FAILURE;
      }
      char buf[512];
      recv(client_sock, buf, sizeof(buf), 0);
      printf("%s\n", buf);
      close(client_sock);
  }
  
  return EXIT_SUCCESS;
}

