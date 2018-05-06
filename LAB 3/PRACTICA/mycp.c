#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colores.h"

// ** importante que ningun nombre de carpetas de la ruta tenga espacios , por que lo toma como otros argumentos

int main(int argc,char *argv[])
{
	// En primer lugar se revisa que el numero de argumentos sea igual a 3, sino es asi entonces
	if(argc!=3)
	{
		// Se imprime un mensaje de error y se termina el programa
		printf(RED "No se proporcionaron los parametros correctamente\n"RESET);
		return 0;
	}
	
	// A continuacion creo las variables necesarias para el proceso de copiado
	char *rutaOrigen=argv[1]; 
	char *rutaDestino=argv[2];
	char *nombreArchivoOrigen=NULL;
	char character; // Variable auxiliar para copiar todos los caracteres del archivo origen al de destino
	FILE	*origen;
	FILE 	*destino;
	
	// Ahora intento abrir la ruta de origen
	origen = fopen(rutaOrigen,"r");
	if(origen==0) // Si se presento un problema entonces
	{
		// Imprimo un mensaje al respecto y termino
		printf(RED "Archivo origen no existe (%s)\n"RESET,rutaOrigen);
		return 0;
	}
	
	// Luego, se busca el final del nombre de la ruta origen para determinar el nombre del archivo
	nombreArchivoOrigen = strrchr(rutaOrigen,'/');//Localiza la última aparición de c (convertido a unsigned char) en la cadena apuntada por s (incluyendo el carácter nulo).
	//La función retorna un puntero a partir del carácter encontrado. Si no se ha encontrado el carácter, c, entonces retorna un puntero nulo.
	
	// En caso de que no tenga el caracter "/" significa que el nombre del archivo sera rutaOrigen
	if(nombreArchivoOrigen==NULL)
	{
		rutaDestino = strcat(rutaDestino,"/");
		rutaDestino = strcat(rutaDestino,rutaOrigen);
	}
	else
	{
		rutaDestino=strcat(rutaDestino,nombreArchivoOrigen);
	}

	// Despues, se crea un canal de escritura
	destino=fopen(rutaDestino,"w");
	if(destino==0)// Si se presento un problema entonces
	{
		// Imprimo un mensaje al respecto y termino
		printf(RED "Ruta destino no existe (%s)\n"RESET,rutaDestino);
		return 0;
	}
	
	
	// Por ultimo, se copia caracter por caracter al otro archivo	
	while((character=fgetc(origen))!=EOF)
		fputc(character,destino);
	
	// Se imprime un mensaje de exito en la operacion
	printf(GRN"Copia realizada correctamente!\n"RESET);	
	printf(BLU"Origen: %s\t Destino: %s\n"RESET,rutaOrigen,rutaDestino);

	// Y se cierran los canales que usamos para el copiado del archivo
	fclose(origen);
	fclose(destino);
	return 0;
}
