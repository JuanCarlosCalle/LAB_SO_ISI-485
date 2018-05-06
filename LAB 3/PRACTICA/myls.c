#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>
#include <dirent.h>

#include "colores.h"

int main(int argc,char *argv[])
{
	DIR *dir; // Puntero de ruta con el cual se revisara que archivos y directorios estan en el directorio especificado
	struct dirent *ent; // Variable para recorrer el contenido de dir

	// De este modo, si este programa fue invocado con una ruta (2do argumento) entonces
	if (argc == 2)
	{
		dir = opendir(argv[1]); // Se abre un puntero a la ruta especificada en los argumentos
	}
	else // Sino
	{
		dir = opendir("."); // La ruta por defecto es el directorio de trabajo
	}

	// Si el puntero de la direccion a explorar es diferente de nulo entonces
	if (dir != NULL)
	{
		// Se procede a recorrer cada uno de los elementos de la ruta
		while ((ent = readdir(dir)) != NULL)
		{
			// Si el elmento que estoy leyendo es '.' o '..' entonces
			if (strcmp(ent->d_name,".")==0 || strcmp(ent->d_name,"..")==0)
			{
			  continue; // Lo ignoro y paso al siguiente elemento
			}

			printf("%s\t", ent->d_name); // Imprimo la carpeta o archivo
		}

		printf("\n");
		closedir (dir); // Y por ultimo cierro el apuntador
	}
	else // sino
	{
		printf(RED "No se pudo abrir el directorio\n" RESET); // Se imprime un mensaje de error
		return -1;
	}

	return 0;
}
