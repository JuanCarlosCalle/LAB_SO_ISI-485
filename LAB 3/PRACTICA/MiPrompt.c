// Importes necesarios para este programa
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "parser.h"

// Importe para poder colorear la salida de la consola
#include "colores.h"

// Variable que me define el tamaño de las palabras (o Strings) a leer desde la consola
#define TAM 300

struct sigaction my_action;

void my_handler (int sig);

int main ()
{
  char ** items; // Arreglo de Strings en donde se depositaran los elementos escritos por consola (Cada token tendra su posicion)
  int num, background; // Variables con las cuales conocere cuantos tokens fueron ingresados por linea de comandos y si el ultimo de ellos es amperson
  char expresion[TAM]; // Variable para obtener la expresion completa de la linea de comandos
  int b = 0; // Variable centinela que se usa para mantener ejecutando este CLI
  int pid; // Variable para analizar el retorno de una bifurcacion

  // Variables auxiliares para el llamado de los comandos
  // Nota: Como tal estas variables son necesarias porque si CAMBIO DE DIRECTORIO DE TRABAJO entonces ya
  //       un simple llamado al comando ./my*** FALLARA! porque no estoy en la misma carpeta del comando.
  //       Entonces, la idea es almacenar siempre cual es la ruta que contiene los comandos y por tanto
  //       asi cambie el CLI de ruta de trabajo yo siempre podre saber donde estan los comandos.
  char rutaOrigen[1024];
  char aux[1024];
 
  // De la logica anterior, inicializo la ruta de los comandos como la ruta desde la cual ejecuto la consola
  getcwd(rutaOrigen, sizeof(rutaOrigen));
  //printf(MAG "La ruta con los ejecutables de los comandos es: %s\n" RESET, rutaOrigen);

   my_action.sa_handler = my_handler;
   my_action.sa_flags = SA_RESTART;
   sigaction (SIGTSTP, &my_action, NULL);

  while (b == 0) // Entonces mientras la consola este activa HAGA:
  {
	printf(MAG ": %s" RESET, rutaOrigen);
	printf("%c", '$');
  	//printf ("Teclea una orden~> "); // En primer lugar se imprime el mensaje estandar de este CLI
	fflush(stdout); // Esto es para vaciar el buffer de escritura
	fgets (expresion, TAM, stdin); // Luego y una vez el usuario escribe su comando y presiona enter, entonces se recupera lo que se escribio

	num = separaItems(expresion, &items, &background); // Se realiza un analisis de lo que digito

	if (num > 0) // Si el usuario escribio por lo menos un elemento entonces
	{
		// Si el comando que digito el usuario es 'myexit' entonces
		if (strcmp(items[0],"myexit")==0)
		{
			b = 1; // Se cambia la variable centinela que mantiene a este CLI funcionando y en la proxima iteracion se termina el programa
			printf(WHT "Saliendo de mi prompt!\n" RESET); // Antes de terminar se imprime un mensaje para indicarle al usuario que ha terminado este CLI
		}

		// Si el comando que digito el usuario es 'mypwd' entonces
		if (strcmp(items[0],"mypwd")==0)
		{
			pid = fork(); // Creo una bifuracion (hijo) de este programa
			
			if (pid == 0) // De este modo, si este es el programa hijo entonces
			{
				// Armo la ruta de donde esta el comando mypwd
				strcpy(aux,rutaOrigen);
				strcat(aux, "/mypwd");

				execl(aux, aux, NULL); // E invoco el programa 'mypwd'. Como tal no es necesario pasarle parametros adicionales

				// En caso que suceda un error con la llamada al comando se imprime un mensaje y se termina el hijo
				printf(RED "Error ~ mypwd!\n" RESET);
				exit(1);
			}
			else if (pid == -1) // En caso de error en la llamada al fork entonces
			{
				printf(RED "No se pudo invocar a mypwd!\n" RESET); // Se imprime un mensaje de error
			}
			else // Y si es el padre (o sea, la consola) entonces
			{
				wait(&pid); // Se espera a que termine el comando antes de seguir ejecutando instrucciones
			}
		}
//psinfo

// Si el comando que digito el usuario es 'psinfo' entonces
		if (strcmp(items[0],"psinfo")==0)
		{
			pid = fork(); // Creo una bifuracion (hijo) de este programa
			
			if (pid == 0) // De este modo, si este es el programa hijo entonces
			{
				// Armo la ruta de donde esta el comando psinfo
				strcpy(aux,rutaOrigen);
				strcat(aux, "/psinfo");

				if (num == 2) // Ahora, si el comando 'psinfo' solo tiene un parametro adicional entonces
				{
					execl(aux, aux, items[1], NULL); // Invoco psinfo y le paso ese unico parametro asumiendo que este es el pid del proceso a terminar
				}
				else // En cualquier otro caso
				{
					// Se escribe un mensaje de que los parametros no estan bien y se termina el hijo
					printf(RED "Verifique los parametros!\n"RESET);
					exit(0);
				}				

				// En caso que suceda un error con la llamada al comando se imprime un mensaje y se termina el hijo
				printf(RED "Error ~ psinfo!\n" RESET);
				exit(1);
			}
			else if (pid == -1) // En caso de error en la llamada al fork entonces
			{
				printf(RED "No se pudo invocar a mypwd!\n" RESET); // Se imprime un mensaje de error
			}
			else // Y si es el padre (o sea, la consola) entonces
			{
				wait(&pid); // Se espera a que termine el comando antes de seguir ejecutando instrucciones
			}
		}



//fin psinfo		
		
		
//mytime
// Si el comando que digito el usuario es 'mytime entonces
		if (strcmp(items[0],"mytime")==0)
		{
			pid = fork(); // Creo una bifuracion (hijo) de este programa
			
			if (pid == 0) // De este modo, si este es el programa hijo entonces
			{
				// Armo la ruta de donde esta el comando mytime
				strcpy(aux,rutaOrigen);
				strcat(aux, "/mytime");

				execl(aux, aux, NULL); // E invoco el programa 'mytime'. Como tal no es necesario pasarle parametros adicionales

				// En caso que suceda un error con la llamada al comando se imprime un mensaje y se termina el hijo
				printf(RED "Error ~ mytime!\n" RESET);
				exit(1);
			}
			else if (pid == -1) // En caso de error en la llamada al fork entonces
			{
				printf(RED "No se pudo invocar a mytime!\n" RESET); // Se imprime un mensaje de error
			}
			else // Y si es el padre (o sea, la consola) entonces
			{
				wait(&pid); // Se espera a que termine el comando antes de seguir ejecutando instrucciones
			}
		}


//fin mytime	
		
//myps
if (strcmp(items[0],"myps")==0)
		{
			pid = fork(); // Creo una bifuracion (hijo) de este programa
			
			if (pid == 0) // De este modo, si este es el programa hijo entonces
			{
				// Armo la ruta de donde esta el comando myps
				strcpy(aux,rutaOrigen);
				strcat(aux, "/myps");

				execl(aux, aux, NULL); // E invoco el programa 'myps'. Como tal no es necesario pasarle parametros adicionales

				// En caso que suceda un error con la llamada al comando se imprime un mensaje y se termina el hijo
				printf(RED "Error ~ myps!\n" RESET);
				exit(1);
			}
			else if (pid == -1) // En caso de error en la llamada al fork entonces
			{
				printf(RED "No se pudo invocar a myps!\n" RESET); // Se imprime un mensaje de error
			}
			else // Y si es el padre (o sea, la consola) entonces
			{
				wait(&pid); // Se espera a que termine el comando antes de seguir ejecutando instrucciones
			}
		}


//fin myps		

//mygrep
if (strcmp(items[0],"mygrep")==0)
		{
			pid = fork(); // Creo una bifuracion (hijo) de este programa
			
			if (pid == 0) // De este modo, si este es el programa hijo entonces
			{
				// Armo la ruta de donde esta el comando myls
				strcpy(aux,rutaOrigen);
				strcat(aux, "/mygrep");

				if (num == 1) // Si el comando 'myLs' ingresado por el usuario no tiene parametros entonces
				{
					execl(aux, aux, NULL); // Se invoca el programa mygrep sin parametros
				}
				else if (num == 2) // Por otro lado, si el usuario especifico una ruta entonces
				{
					execl(aux, aux, items[1], NULL); // Se invoca el programa mygrep con un parametro (que debe ser la ruta a explorar)
				}

				// En caso que suceda un error con la llamada al comando se imprime un mensaje y se termina el hijo
				printf(RED "Error ~ mygrep!\n" RESET);
				exit(1);
			}
			else if (pid == -1) // En caso de error en la llamada al fork entonces
			{
				printf("No se pudo invocar a mygrep!\n"); // Se imprime un mensaje de error
			}
			else // Y si es el padre (o sea, la consola) entonces
			{
				wait(&pid); // Se espera a que termine el comando antes de seguir ejecutando instrucciones
			}
		}


//fin mygrep

		
		
		// Si el comando que digito el usuario es 'myLS' entonces
		if (strcmp(items[0],"myls")==0)
		{
			pid = fork(); // Creo una bifuracion (hijo) de este programa
			
			if (pid == 0) // De este modo, si este es el programa hijo entonces
			{
				// Armo la ruta de donde esta el comando myls
				strcpy(aux,rutaOrigen);
				strcat(aux, "/myls");

				if (num == 1) // Si el comando 'myLs' ingresado por el usuario no tiene parametros entonces
				{
					execl(aux, aux, NULL); // Se invoca el programa myls sin parametros
				}
				else if (num == 2) // Por otro lado, si el usuario especifico una ruta entonces
				{
					execl(aux, aux, items[1], NULL); // Se invoca el programa myls con un parametro (que debe ser la ruta a explorar)
				}

				// En caso que suceda un error con la llamada al comando se imprime un mensaje y se termina el hijo
				printf(RED "Error ~ myls!\n" RESET);
				exit(1);
			}
			else if (pid == -1) // En caso de error en la llamada al fork entonces
			{
				printf("No se pudo invocar a myls!\n"); // Se imprime un mensaje de error
			}
			else // Y si es el padre (o sea, la consola) entonces
			{
				wait(&pid); // Se espera a que termine el comando antes de seguir ejecutando instrucciones
			}
		}

		// Si el comando que digito el usuario es 'myKill' entonces
		if (strcmp(items[0],"mykill")==0)
		{
			pid = fork(); // Creo una bifuracion (hijo) de este programa
			
			if (pid == 0) // De este modo, si este es el programa hijo entonces
			{
				// Armo la ruta de donde esta el comando mykill
				strcpy(aux,rutaOrigen);
				strcat(aux, "/mykill");

				if (num == 2) // Ahora, si el comando 'mykill' solo tiene un parametro adicional entonces
				{
					execl(aux, aux, items[1], NULL); // Invoco mykill y le paso ese unico parametro asumiendo que este es el pid del proceso a terminar
				}
				else if (num == 3) // Por otro lado, si el usuario especifico dos parametros entonces
				{
					execl(aux, aux, items[1], items[2], NULL); // Invoco mykill y le paso tanto el 1er parametro que debe ser la SEÑAL a enviar y como 2do parametro se entrega el pid de destino
				}
				else // En cualquier otro caso
				{
					// Se escribe un mensaje de que los parametros no estan bien y se termina el hijo
					printf(RED "Verifique los parametros!\n"RESET);
					exit(0);
				}

				// En caso que suceda un error con la llamada al comando se imprime un mensaje y se termina el hijo
				printf(RED "Error ~ mykill!\n" RESET);
				exit(1);
			}
			else if (pid == -1) // En caso de error en la llamada al fork entonces
			{
				printf("No se pudo invocar a mykill!\n"); // Se imprime un mensaje de error
			}
			else // Y si es el padre (o sea, la consola) entonces
			{
				wait(&pid); // Se espera a que termine el comando antes de seguir ejecutando instrucciones
			}
		}

		// Si el comando que digito el usuario es 'myCd' entonces
		if (strcmp(items[0],"mycd")==0)
		{
			if (num == 2) // Si el numero de tokens ingresados por el usuario son 2 (o sea, el comando y la ruta a cambiarse) entonces
			{
				int resultado; // Creo una variable con la que sabre si el cambio de directorio fue exitoso o no
				resultado = chdir(items[1]); // Luego, se efectua el cambio de directorio
				
				// Ahora, si resultado es cero es porque fue exitoso el proceso y por tanto
				if (resultado == 0)
				{
					// Se imprime un mensaje de exito en la operacion
					printf(CYN "Se cambio el directorio de trabajo!\n" RESET);
				}
				else // Sino
				{
					// Se imprime un mensaje de error en la operacion
					printf(RED "Fallo el cambio de directorio!\n" RESET);
				}
			}
			else // Sino
			{
				// Se imprime un mensaje al respecto
				printf(RED "El comando myCd necesita un unico parametro y es el de ruta.\n" RESET);
			}
		}

		// Si el comando que digito el usuario es 'myCp' entonces
		if (strcmp(items[0],"mycp")==0)
		{
			// Reviso que el usuario si haya escrito el numero de argumentos correcto y sino es asi entonces
			if (num != 3)
			{
				// Se escribe un mensaje de que los parametros no estan bien y se pasa al siguiente ciclo
				printf(RED "Verifique los parametros!\n"RESET);
				continue;
			}

			pid = fork(); // Si pasa la comprobacion anterior entonces creo una bifuracion (hijo) de este programa
			
			if (pid == 0) // De este modo, si este es el programa hijo entonces
			{
				// Armo la ruta de donde esta el comando myCp
				strcpy(aux,rutaOrigen);
				strcat(aux, "/mycp");

				// Y lo invoco pasandole los parametros correspondientes
				execl(aux, aux, items[1], items[2], NULL);

				// En caso que suceda un error con la llamada al comando se imprime un mensaje y se termina el hijo
				printf(RED "Error ~ mycp!\n" RESET);
				exit(1);	
			}
			else if (pid == -1) // En caso de error en la llamada al fork entonces
			{
				printf("No se pudo invocar a mycp!\n"); // Se imprime un mensaje de error
			}
			else // Y si es el padre (o sea, la consola) entonces
			{
				wait(&pid); // Se espera a que termine el comando antes de seguir ejecutando instrucciones
			}
		}

		// Si el comando que digito el usuario es 'myEcho' entonces
		if (strcmp(items[0],"myecho")==0)
		{
			pid = fork(); // Creo una bifuracion (hijo) de este programa
			
			if (pid == 0) // De este modo, si este es el programa hijo entonces
			{
				// Armo la ruta de donde esta el comando myEcho
				strcpy(aux,rutaOrigen);
				strcat(aux, "/myecho");

				// Luego, construyo un arreglo en donde depositare el mensaje a enviar y una variable auxiliar para recorrer los argumentos
				char msg[TAM] = "";
				int i;

				// A continuacion creo el mensaje
				for (i = 1; i < num; i++)
				{
					strcat(msg, items[i]);
					strcat(msg, " ");
				}
				
				// Y llamo al comando myecho entregandole el mensaje respectivo
				execl(aux, aux, msg, NULL);

				// En caso que suceda un error con la llamada al comando se imprime un mensaje y se termina el hijo
				printf(RED "Error ~ myecho!\n" RESET);
				exit(1);
			}
			else if (pid == -1) // En caso de error en la llamada al fork entonces
			{
				printf("No se pudo invocar a myecho!\n"); // Se imprime un mensaje de error
			}
			else // Y si es el padre (o sea, la consola) entonces
			{
				wait(&pid); // Se espera a que termine el comando antes de seguir ejecutando instrucciones
			}
		}

		// Si el comando que digito el usuario es 'myClr' entonces
		if (strcmp(items[0],"myclr")==0)
		{
			// Imprimo en consola el siguiente codigo, lo cual es equivalente a limpiar la consola
			printf("\e[1;1H\e[2J");
		}

		// Si el comando que digito el usuario es 'myPause' entonces
		if (strcmp(items[0],"mypause")==0)
		{
			pid = fork(); // Creo una bifuracion (hijo) de este programa
			
			if (pid == 0) // De este modo, si este es el programa hijo entonces
			{
				// Armo la ruta de donde esta el comando myPause e invoco el mismo
				strcpy(aux,rutaOrigen);
				strcat(aux, "/mypause");
				execl(aux, aux, NULL);

				// En caso que suceda un error con la llamada al comando se imprime un mensaje y se termina el hijo
				printf(RED "Error ~ mypause!\n" RESET);
				exit(1);
			}
			else if (pid == -1) // En caso de error en la llamada al fork entonces
			{
				printf("No se pudo invocar a myecho!\n"); // Se imprime un mensaje de error
			}
			else // Y si es el padre (o sea, la consola) entonces
			{
				wait(&pid); // Se espera a que termine el comando antes de seguir ejecutando instrucciones
				printf(WHT "Recibido!\n" RESET); // Y se imprime que la consola ya puede volver a continuar
			}
		}
	}

	liberaItems(items); // Al final, se libera la expresion ingresada por el usuario de la memoria
  }

  return 0;
}


void my_handler (int sig)
{
   printf (RED "\nIgnorando señal %d\n" RESET, sig);
   printf ("\nTeclea una orden~> ");
   fflush(stdout); 
}
