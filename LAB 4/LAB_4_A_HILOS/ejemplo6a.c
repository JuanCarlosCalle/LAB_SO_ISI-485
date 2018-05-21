#include <pthread.h>
#include <stdio.h>
#include <sys/time.h> // Libreria necesaria para obtener el tiempo del sistema


void* calcular_primo(void* arg);

int main()
{
    pthread_t hilo_id;
    int cual_primo = 5000;
    int primo;

	 struct timeval stop, start; // Variables para alamcenar el tiempo de inicio y fin de una tarea
	 gettimeofday(&start, NULL); // Se inicia el cronometro
    
    /* Inicia el hilo, se requiere el 5000-esimo numero primo */
    pthread_create(&hilo_id, NULL, &calcular_primo, &cual_primo);
    /* Puedo hacer algo mientras... si quiero */
    /* Espero que el numero sea calculado y me sea entregado */
    pthread_join(hilo_id, (void*) &primo);

	 // Se para el croinometro y se imprime el tiempo que tomo completar la tarea
    gettimeofday(&stop, NULL);
    printf("Tiempo de computo: %lu\n", stop.tv_usec - start.tv_usec);
    
    /* Imprimo el numero entregado */
    printf("El numero primo es %d. \n", primo);
	return 0;
}

/* Calcula los numeros primos sucesivamente 
   Retorna el N-esimo numero primo
   donde N es el valor apuntado por *ARG. */
void* calcular_primo(void* arg)
{
    int candidato = 2;
    int n = *((int*) arg);
    while (1)
    {
        int factor;
        int es_primo  = 1;
        for (factor = 2; factor < candidato; factor++)
        {
            if (candidato % factor == 0)
            {
                es_primo = 0;
                break;
            }
        }

		  if (es_primo)
        {
            if (--n == 0)
                return (void*) candidato;
        }
        ++candidato;
    }
    return NULL;
}
