#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <syscall.h>

int main()
{
    int i = 1;
    int pid;
    
    // El proceso 1 imprime su PID y el de su padre
    printf("Proceso %d - El ID de mi padre es: %d\n", i, (int)getppid());
    printf("Proceso %d - Mi ID es: %d\n\n", i, (int)getpid());
    fflush(stdout);
    
    pid = fork(); // Creacion del proceso 2
    if (pid == -1)
    {
        printf("No se pudo crear el proceso %d - Abortando!!\n", i+1);
        return -1;
    }
    else if (pid == 0)
    {
        // El proceso 2 imprime su PID y el de su padre
        i = i + 1;
        printf("Proceso %d - El ID de mi padre es: %d\n", i, (int)getppid());
        printf("Proceso %d - Mi ID es: %d\n\n", i, (int)getpid());
        fflush(stdout);
        
        sleep(20);
    }
    else
    {
        pid = fork(); // Creacion del proceso 3
        if (pid == -1)
        {
            printf("No se pudo crear el proceso %d - Abortando!!\n", i+2);
            return -1;
        }
        else if (pid == 0)
        {
            // El proceso 3 imprime su PID y el de su padre
            i = i + 2;
            printf("Proceso %d - El ID de mi padre es: %d\n", i, (int)getppid());
            printf("Proceso %d - Mi ID es: %d\n\n", i, (int)getpid());
            fflush(stdout);
            
            pid = fork(); // Creacion del proceso 4
            if (pid == -1)
            {
                printf("No se pudo crear el proceso %d - Abortando!!\n", i+1);
                return -1;
            }
            else if (pid == 0)
            {
                // El proceso 4 imprime su PID y el de su padre
                i = i + 1;
                printf("Proceso %d - El ID de mi padre es: %d\n", i, (int)getppid());
                printf("Proceso %d - Mi ID es: %d\n\n", i, (int)getpid());
                fflush(stdout);
                
                sleep(20);
            }
            else
            {
                pid = fork(); // Creacion del proceso 5
                if (pid == -1)
                {
                    printf("No se pudo crear el proceso %d - Abortando!!\n", i+2);
                    return -1;
                }
                else if (pid == 0)
                {
                    // El proceso 5 imprime su PID y el de su padre
                    i = i + 2;
                    printf("Proceso %d - El ID de mi padre es: %d\n", i, (int)getppid());
                    printf("Proceso %d - Mi ID es: %d\n\n", i, (int)getpid());
                    fflush(stdout);
                    
                    sleep(20);
                }
                else
                {
                    sleep(10);
                }
            }
        }
        else
        {
            pid = fork();
            if (pid == -1)
            {
                printf("Fallo la creacion del arbol de procesos\n");
                return -1;
            }
            else if(pid == 0)
            {
                execl("/bin/pstree", "pstree", (int)getppid(), NULL);
            }
            else
            {
                sleep(10);
            }
        }
    }
    
    return 0;
}
