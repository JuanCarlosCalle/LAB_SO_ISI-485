// ¡¡¡OJO!!!
// El problema de esta implementacion es que no cambia el directorio de trabajo del padre,
// Sino el de si mismo por lo cual no considero esta como una solucion valida!
#include <unistd.h>

#include "colores.h"

int main(int argc,char *argv[])
{
	int resultado; // Variable con la que sabre si el cambio de directorio fue exitoso o no

	// Si este programa fue invocado con una ruta (2do argumento) entonces
	if (argc == 2)
	{
		resultado = chdir(argv[1]); // Se realiza el cambio de directorio
		
		// Ahora, si resultado es cero es porque fue exitoso el proceso y por tanto
		if (resultado == 0)
		{
			// Se imprime un mensaje de exito en la operacion
			printf(CYN "Se cambio el directorio de trabajo!\n" RESET);
		}
		else // Sino
		{
			// Se imprime un mensaje y se retorna
			printf(RED "Fallo el cambio de directorio!\n" RESET);
			return -1;
		}
	}
	else // Sino
	{
		return -1; // Se retorna de inmediato
	}
	
	return 0;
}
