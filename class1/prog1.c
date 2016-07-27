#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int main(int argc, char *argv[]) {
  int a = 10, b = 15;
  printf("a = %d, b = %d\n", a, b);
  swap(&a, &b);
  printf("a = %d, b = %d\n", a, b);
  return EXIT_SUCCESS;
}

