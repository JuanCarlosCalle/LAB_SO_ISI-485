#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

long acumulador = 0; // Variable global


struct parametros_hilo
{
    FILE *archivo;
    int posicionInicio;
    int limite;
};

int contarElementos(char *nombreArchivo);

void* sumarElementos(void* parametros)
{
    struct parametros_hilo *p = (struct parametros_hilo*) parametros;
    
    FILE *archivo = p->archivo;
    int i = 0;
    int j = p->posicionInicio;
    int k = p->limite;
    
    char *linea = NULL;
    size_t longitud = 0;
    
    for (i = 0; i < j; i++)
    {
        getline(&linea, &longitud, archivo);
    }
    
    for (i = j; i < k; i++)
    {
        getline(&linea, &longitud, archivo);
        acumulador = acumulador + atoi(linea);
    }
    
    fclose(archivo);
    
    if (linea)
    {
        free(linea);
    }

    return NULL;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Se necesita un nombre de archivo como unico parametro!\n");
        return -1;
	 }

	 struct timeval stop, start;
	 gettimeofday(&start, NULL);
	 
    char* nombreArchivo = argv[1];
    
    int numElementos = contarElementos(nombreArchivo);
    
    if (numElementos == 0)
    {
        printf("El archivo esta vacio!\n");
        return -1;
    }
    
    pthread_t hilo1;
    pthread_t hilo2;
    struct parametros_hilo hiloParam1;
    struct parametros_hilo hiloParam2;
    
    hiloParam1.archivo = fopen(nombreArchivo, "r");
    hiloParam1.posicionInicio = 0;
    hiloParam1.limite = numElementos/2;
	 
    hiloParam2.archivo = fopen(nombreArchivo, "r");
    hiloParam2.posicionInicio = numElementos/2;
    hiloParam2.limite = numElementos;
    
    pthread_create(&hilo1, NULL, &sumarElementos, &hiloParam1);
    pthread_create(&hilo2, NULL, &sumarElementos, &hiloParam2);
    
    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);
    
    printf("La suma de los elementos del vector es: %ld\n", acumulador);
    
	 gettimeofday(&stop, NULL);
    printf("Tiempo de computo: %lu\n", stop.tv_usec - start.tv_usec);
	 
    return 0;
}

int contarElementos(char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "r");
    int caracter=0;
    int numLineas=0;
    
    if (archivo == NULL)
    {
        return 0;
    }
    
    while(!feof(archivo))
    {
        caracter = fgetc(archivo);
        if(caracter == '\n')
        {
            numLineas++;
        }
    }
    
    fclose(archivo);
    return numLineas;
}
