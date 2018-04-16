#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc,char *argv[])
{
    if (argc != 2)
    {
        printf("Numero inesperado de argumentos\n");
        return -1;
    }
    
    int pid;
    pid = fork();
    
    if (pid == 0)
    {
        execl(argv[1], argv[1], NULL);
    }
    else
    {
        wait(&pid);
        printf("Programa principal terminado!\n");
    }
    
    return 0;
}
