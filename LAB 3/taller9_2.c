#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
  printf("Corriendo ps con execlp\n");
  execlp("ps", "ps", "-ax", 0);
  printf("Echo.\n");
  exit(0);
}
