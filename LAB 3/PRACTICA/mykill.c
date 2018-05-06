

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "colores.h"

int main(int argc,char *argv[])
{
	// Se crean dos variables para la invocacion del comando kill
	int signal, pid;

	// Si el numero de argumentos que llegaron fue 2 entonces
	if (argc == 2)
	{
		// Se captura el pid del proceso y se asume que la señal a enviar es 9 (señal 9 = matar proceso)
		signal = 9;
		pid = atoi((argv[1]));
	}
	else if (argc == 3) // O si el numero de argumentos que llegaron fue 3 entonces
	{
		// Se captura tanto la señal a enviar como el identificador proceso de destino
		signal = atoi((argv[1]));
		pid = atoi((argv[2]));
	}
	else // Si llegaron menos o mas parametros entonces
	{
		// Se imprime un mensaje de error y se termina el programa
		printf(RED "No se proporcionaron los parametros correctamente\n"RESET);
		return 0;
	}

	// Ahora, si el retorno de kill es 0, se envio correctamente la señal al proceso de destino
	if(kill(pid,signal)==0)
	{
		printf(YEL "Se envio correctamente la señal al proceso #%d.\n"RESET,pid);
	}
	else // Sino se imprime un mensaje de error
	{
		printf(RED "Error al enviar la señal al proceso #%d, puede ser que tal proceso no exista\n"RESET,pid);
	}

	return 0;
}
