#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int a = 1;
  char *p = (char *) &a;
  if(*p & 1) {
    printf("Little-endian\n");
  } else {
    printf("Big-endian\n");
  }
  
  return EXIT_SUCCESS;
}

