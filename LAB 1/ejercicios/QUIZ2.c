//#include <iostream.h>
#include <conio.h> 
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int sumaDigitos(int);

int main (int argc,char *argv[])

{
	int numuno;
	char opcion; 
	bool continuar; 
	continuar=false; 
	
	while(continuar==false){

	printf("\n Este programa recibe un numero y retorna suma de sus digitos ");
	printf("si el numero es positivo.\n ");
	
	printf("Digite numero :");
	scanf("%d",&numuno);
		
	int resultado;
	resultado=sumaDigitos(numuno);
	printf("LA SUMA ES IGUAL A  :");
	printf("%d",resultado);
	
	printf("\n"); 
    system("pause"); 
    system("cls");
    
    printf("Desea continuar? presione la tecla S para proseguir o N para terminar: "); 
	opcion=getch(); 
	opcion=toupper(opcion); 
	if(opcion=='S'){ 
	continuar=false; 
	system("cls");}else
	{
		system("cls");
		continuar=true;
		printf("GRACIAS¡¡¡¡¡¡¡¡¡");
	}
	
}
	
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
