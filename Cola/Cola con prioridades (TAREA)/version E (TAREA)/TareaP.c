#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "ColaP.h"

int elegir(){
	int opcion;
	printf("Elija una opcion\n");
	printf("1.- Crear cola\n");
	printf("2.- Meter dato con su respectiva prioridad\n");
	printf("3.- Borrar dato con su respectiva prioridad\n");
	printf("4.- Imprimir cola\n");
	printf("5.- Salir\n");
	scanf("%i",&opcion);
	return opcion;
}

ColaP ObsPrioridad(ColaP q, int prio, int dato){
	if(prio==5){
		q = formar(q,dato,prio);
		return q;
	}else{
		Elem obs = primero(q);
		Elem pi = prioridad(q);
		q = formar(q, primero(q), prioridad(q));
		q = desformar(q);
		while(prio!=prioridad(q)&&obs!=primero(q)){
			q = formar(q, primero(q), prioridad(q));
			q = desformar(q);
		}
		while(prio==prioridad(q)&&obs!=primero(q)){
			q = formar(q, primero(q), prioridad(q));
			q = desformar(q);
		}
		if(pi==prioridad(q)){
			q = formar(q, primero(q), prioridad(q));
			q = desformar(q);
			while(prio>prioridad(q)&&obs!=primero(q)){
			q = formar(q, primero(q), prioridad(q));
			q = desformar(q);
			}
			while(prio>prioridad(q)&&obs!=primero(q)){
			q = formar(q, primero(q), prioridad(q));
			q = desformar(q);
			}
			q = formar(q,dato,prio);
		}else
			q = formar(q,dato,prio);		
		while(obs!=primero(q)){
			q = formar(q, primero(q), prioridad(q));
			q = desformar(q);
		}
		return q;
	}
}

ColaP MeterCola(ColaP q, int dato, int prioidad){
	ColaP t = desformar(q);
	if(esnueva(q))
		q = formar(q,dato,prioidad);
	else if(esnueva(t))
		q = formar(q,dato,prioidad);
	else
		q = ObsPrioridad(q,prioidad,dato);
	return q;
}

ColaP BorrarDato(ColaP q){
	return desformar(q);
}

int main(){
	ColaP q = nueva();
	int dato, prioridad;
	while(1){
		int xd = elegir();
		switch(xd){
			case 1:
				fflush( stdin );
				if(esnueva(q)){
					printf("\nIngrese un dato: ");
					scanf("%i",&dato);
					printf("Ingrese su prioidad: ");
					scanf("%i",&prioridad);
					q = MeterCola(q,dato,prioridad);
					printf("\nSu cola ha sido creada con un dato inicial");
					puts("\n--------------\n");
				}else{
					printf("\nYa tiene una cola creada, si desea borrarla presione 1, si no presione 0: ");
					if(getchar()=='1'){
						q = nueva();
						printf("\n Se borro todo el contenido de la cola");
					}
					puts("\n--------------\n");
				}
				break;
			case 2:
				fflush( stdin );
				printf("\nIngrese un dato: ");
				scanf("%i",&dato);
				printf("Ingrese su prioidad: ");
				scanf("%i",&prioridad);
				q = MeterCola(q,dato,prioridad);
				printf("Dato agregado a la cola");
				puts("\n--------------\n");
				break;
			case 3:
				fflush( stdin );
				q = BorrarDato(q);
				printf("Dato eliminado de la cola");
				if(esnueva(q))
					printf("\nSu cola quedo vacia, favor de crear una nueva");
				puts("\n--------------\n");
				break;
			case 4:
				fflush( stdin );
				if(!esnueva(q)){
					printf("\nSu cola es la siguiente:\n");
					ImpColaP(q);
					puts("\n--------------\n");
				}else{
					printf("\nSu cola esta vacia");
					puts("\n--------------\n");
				}	
				break;
			case 5:
				fflush( stdin );
				printf("\nSalio del programa");
				exit(0);
				break;
			default:
				printf("No elegio una opcion valida, favor de volver a seleccionar una\n");
		}
	}
	return 0;
}

