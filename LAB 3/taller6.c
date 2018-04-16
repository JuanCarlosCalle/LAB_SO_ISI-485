#include<stdio.h>
#include<unistd.h>
main() {
   printf("Hola ");
   fflush(stdout);
   fork();
   printf("Mundo");
   fflush(stdout);
   fork();
   printf("!");
   fflush(stdout);
}
