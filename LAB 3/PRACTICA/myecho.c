#include <unistd.h>
#include "colores.h"

int main(int argc, char *argv[])
{
	// Mientras hayan argumentos que imprimir haga
	while (*++argv)
	{
		printf(CYN "%s" RESET, *argv);
		if (argv[1]) printf(" ");
	}

	printf("\n"); // Una vez termine la impresion imprima un salto de linea
	return 0;
}
