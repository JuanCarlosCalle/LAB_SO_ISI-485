#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "colores.h"

//https://www.linuxjournal.com/files/linuxjournal.com/linuxjournal/articles/064/6483/6483l2.html
struct sigaction my_action;

void my_handler (int sig);
int flag = 0;

int main(int argc,char *argv[])
{

	// Se imprime un mensaje indicando que la consola va entrar en modo de espera y se ejecuta el comando de espera
	printf(WHT "Esperando por una señal...\n" RESET);
	//pause();
	
	my_action.sa_handler = my_handler;
    my_action.sa_flags = SA_RESTART; ///* Restart functions if interrupted by handler */
    sigaction (SIGINT, &my_action, NULL);

    while (flag == 0)
    {
    	if (flag == 1)
    	{
    		break;
    	}
    }

	return 0;
}

void my_handler (int sig)
{
	flag = 1;
    printf (RED "Recibida %d!\n" RESET, sig);
    fflush(stdout); 
}
