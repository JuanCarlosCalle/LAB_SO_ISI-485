#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int aleatorio(int,int);

int main (int argc,char *argv[])

{
	int numuno;
	int numdos;

	printf("\n Este programa genere un número  ");
	printf("aleatorio entre a y b.\n ");
	
	printf("Digite primer numero :");
	scanf("%d",&numuno);
	
	printf("Digite segundo numero :");
	scanf("%d",&numdos);
	
	int resultado;
	resultado=aleatorio(numuno,numdos);
	printf("%d",resultado);
	
	return 0;
}

int aleatorio(int numuno , int numdos){
	 int i, alea;

        srand(time(NULL));      
               
        
        alea = rand()%(numuno-numdos+1)+numdos;    
        
        return alea;
	
	
}
