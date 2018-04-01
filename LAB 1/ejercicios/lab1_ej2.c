#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int progresion(int,int);

int main (int argc,char *argv[])

{
	int numuno;
	int numdos;

	printf("\n Este programa recibe dos numeros y calcule la suma de la progresión geométrica ");
	printf("1 + x + x^2 + x^3 + x^4 + ? + x^n  .  \n ");
	
	printf("Digite primer numero :");
	scanf("%d",&numuno);
	
	printf("Digite segundo numero :");
	scanf("%d",&numdos);
	
	int resultado;
	resultado=progresion(numuno,numdos);
	printf("%d",resultado);
	
	return 0;
}

int progresion(int numuno , int numdos){
	int i;
	int suma;
	suma=0;
	for(i=0;i<=numdos;i++){
		suma=suma+pow(numuno,i);
		
	}
	return suma;
	
	
}
