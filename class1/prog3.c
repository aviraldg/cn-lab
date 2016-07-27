#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int a = 258;
  size_t n = sizeof(int)/sizeof(char);
  char b[n];
  char *p = (char *)&a;
  char *e = p + n;
  for(; p != e; p++) {
    printf("%d\n", *p);
  }
  
  return EXIT_SUCCESS;
}

