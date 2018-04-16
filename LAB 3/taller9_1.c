#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
main()
{
  int pid;
  if ((pid = fork()) == 0) {
  		execl("/bin/ls", "ls", "/", 0);
  }
  else {
    wait(&pid);
    printf("exec finalizado\n");
  }
}
