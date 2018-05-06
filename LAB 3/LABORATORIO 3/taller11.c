#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int factorial(int);

int main(int argc,char *argv[])
{
    //int numero = 5;
    //printf("El factorial de %d es: %d\n", numero, factorial(numero));
    
    int i, estado;
    int numHijos = 3;
    pid_t pid;
    
    for (i = 0; i < numHijos; i++)
    {
        pid = fork();
        if (pid == -1)
        {
            printf("No fue posible crear el hijo %d\n", i);
            return -1;
        }
        else if (pid == 0)
        {
            printf("Hijo %d:\n\n", i);
            
            for (i = 1; i < 11; i++)
            {
                printf("Fact(%d) = %d\n", i, factorial(i));
            }
            
            printf("--------\n");
            
            break;
        }
        else
        {
            wait(&estado);
        }
    }
    
    return 0;
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n*factorial(n-1);
    }
}
