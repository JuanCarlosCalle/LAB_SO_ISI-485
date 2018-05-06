#include <unistd.h>
#include <stdio.h>

#include "colores.h"

int main()
{
	char dirActual[1024];
	
	getcwd(dirActual, sizeof(dirActual));//char *getcwd(char *buffer, size_t size);

	if (dirActual != NULL)
	{
		printf(YEL "El directorio de trabajo actual es: %s\n" RESET, dirActual);
	}
	else
	{
		printf(RED "Error obteniendo directorio de trabajo\n" RESET);
	}
	
	return 0;
}
