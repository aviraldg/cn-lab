#include <stdlib.h>
#include <stdio.h>

struct pkt {
  char ch1;
  char ch2[2];
  char ch3;
};

int main(int argc, char *argv[]) {
  struct pkt data;
  printf("Enter a number: ");
  scanf("%c%c%c%c", &data.ch1, data.ch2, data.ch2+1, &data.ch3);
  int v;
  v = atoi((char *) &data);
  printf("%d\n", v);
  return EXIT_SUCCESS;
}

