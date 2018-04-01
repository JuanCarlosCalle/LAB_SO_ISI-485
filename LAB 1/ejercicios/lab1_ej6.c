#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int moneda();

int main (int argc,char *argv[])

{
	int valor;
	int contadorC=0;
	int contadorS=0;

	printf("\n Este programa Simula lanzamiento ");
	printf("de una moneda.\n ");
	int n;
	
	for(n=1;n<=100;n++){
		valor=moneda();
		if(0==valor){
			printf("C");
			contadorC++;
			
		}else{
			printf("S");
			contadorS++;
		}
	}
	
	printf("%d Numero caras : ",contadorC);
	printf("%d Numero sello : ",contadorS);
	
	
	return 0;
}

int moneda(void){
	int aleatorio;
	/*int C=1;
	int S=2;
	

	
	srand(time(NULL)) ;//otorga el poder al programa para generar numero aleatorio
	aleatorio = C + rand() % ((S+1)-C);
	*/
	return aleatorio=rand() % 2;
	
}
