#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sumaDigitos(int);

int main (int argc,char *argv[])

{
	int numuno;
	

	printf("\n Este programa recibe un numero y retorna suma de sus digitos ");
	printf("si el numero es positivo.\n ");
	
	printf("Digite primer numero :");
	scanf("%d",&numuno);
	

	
	int resultado;
	resultado=sumaDigitos(numuno);
	printf("LA SUMA ES IGUAL A  :");
	printf("%d",resultado);
	
	return 0;
}

int sumaDigitos(int numuno ){
	 int suma=0;
	 
	if(numuno>0){
	while (numuno!=0) {
         suma+=numuno%10; 
         numuno=numuno/10;
     }	
	}else{
		return -1;
	}	
	return suma;
		 

	
}
