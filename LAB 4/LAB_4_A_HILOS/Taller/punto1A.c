#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Se necesita un nombre de archivo como unico parametro!\n");
		  return -1;
	 }

	 struct timeval stop, start;
	 gettimeofday(&start, NULL);

    char const* const nombreArchivo = argv[1];
    FILE *archivo;
    
    archivo = fopen(nombreArchivo, "r");
    
    if (archivo == NULL)
    {
        return -1;
    }
    
    char *linea = NULL;
    size_t longitud = 0;
    ssize_t auxLectura;
    long acumulador = 0;
    
    while ((auxLectura = getline(&linea, &longitud, archivo)) != -1)
    {
	     acumulador = acumulador + atoi(linea);
    }
    
    printf("La suma de los elementos del vector es: %ld\n", acumulador);
    
    fclose(archivo);
    
    if (linea)
    {
        free(linea);
    }

	 gettimeofday(&stop, NULL);
    printf("Tiempo de computo: %lu\n", stop.tv_usec - start.tv_usec);
    
    return 0;
}
