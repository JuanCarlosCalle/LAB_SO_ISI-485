#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define tamano 10


float calculate_standard_deviation(float *arregloNotas, int numNotas);

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Se necesita el nombre del archivo CSV y el numero de hilos!\n");
	     return -1;
	 }
	
	 FILE *archivo = fopen(argv[1], "r");
	
	 if (archivo == NULL)
    {
        printf("El archivo no existe o esta vacio!\n");
        return -1;
    }
    
    char *linea = NULL;
    size_t longitud = 0;
    ssize_t auxLectura;
    const char* token;

	 int conta = 0;
	 int tamanoBloque = tamano;
	 float *arregloNotas = malloc(tamano*sizeof(float));
    float auxNumero;
    
    while ((auxLectura = getline(&linea, &longitud, archivo)) != -1)
    {
        token = strtok(linea, ";");
        while(token != NULL)
        {
            auxNumero = atof(token);
            printf("%.4f\n", auxNumero);
            
            if (conta >= tamanoBloque-1)
            {
                tamanoBloque = tamanoBloque + tamano;
                arregloNotas = realloc(arregloNotas, tamanoBloque*sizeof(float));
            }
            
            arregloNotas[conta] = auxNumero;
            conta = conta + 1;
            
            token = strtok(NULL, ";\n");
        }
    }
	 
	 printf("El total de notas leidas fue: %d\n", conta);    

    /*int i;
    for (i=0;i<tamanoBloque;i++)
    {
        auxNumero = arregloNotas[i];
		  printf("%.4f\n", auxNumero);
    }*/
    
    fclose(archivo);
    
    if (linea)
    {
        free(linea);
    }
	 
	 printf("La desviacion estandar de las notas es = %.4f\n", calculate_standard_deviation(arregloNotas, conta));

    return 0;
}

float calculate_standard_deviation(float *arregloNotas, int numNotas)
{
    int i;
    float sum = 0.0, mean, standardDeviation = 0.0;
    
    for(i=0; i<numNotas; ++i)
    {
        sum += arregloNotas[i];
    }

    mean = sum/numNotas;

    for(i=0; i<numNotas; ++i)
    {
        standardDeviation += pow(arregloNotas[i] - mean, 2);
    }
    
    return sqrt(standardDeviation/numNotas);
}
