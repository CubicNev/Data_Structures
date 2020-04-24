/*
 Carlos Nevarez
 28-02-09
*/
# include <stdio.h>
# include <stdlib.h>
# include "Elem.h"
# include "Cola.h"

void carrusel(Cola q);
Cola LlenarCola(Cola q, int n, int contador);
void ImpProcesos(Cola q, int n, int contador);
void AdminTiemp(Cola q, int contador);

int main(){
	 srand (getpid());//Funcion para que el rendom funcione correctamenteque funcione corrrectamente
	 int NumProc, i=1;
	 Cola q = nueva();
	 
	 //Genero el numero de procesos entre el 5 y el 10
	 NumProc = rand() % 6 + 5;
	 printf("\n El numero de procesos es %d.\n",NumProc);
	 
	 //Lleno la cola con el tiempo de cada proceso
	 q = LlenarCola(q,NumProc,i);	 
	 printf("Cabeza: ");
	 ImpElem(primero(q));
	 printf("\n Se han asignado los tiempos a los procesos. Tal que: \n");
	 ImpProcesos(q,NumProc,i);
	 
	 printf("\n Se ha inciciado la administracion de los procesos. \n");
	 AdminTiemp(q,i);
	 
	 if(esnueva(q))
	 	printf("\nSe han administrado todos los procesos.");
	 	
	return 0;
}

Cola LlenarCola(Cola q, int n, int contador){
	int TiempoProc = rand() % (32-8+1) + 8;
	if(n>0){
		printf("El tiemp de proc de %d es igual a %d\n",contador,TiempoProc);
		return LlenarCola(formar(q,TiempoProc),n-1,contador+1);
	} else{
		return q;
	}
}

void ImpProcesos(Cola q, int n, int contador){
	if(n>0){
		printf("El proceso %d tiene: ",contador);
		ImpElem(primero(q));
		q = formar(desformar(q), primero(q));
		return ImpProcesos(q, n-1,contador+1);	
	}
}

void AdminTiemp(Cola q, int contador){
	if(!esnueva(q)){
		printf("Corrida %d: ", contador);
		ImpElem(primero(q));
		
		if(primero(q)<=5){
			printf("Se saco un proceso de la cola.\n");
			return AdminTiemp(desformar(q),contador+1);
		}else{
			return AdminTiemp(formar(desformar(q),primero(q)-5),contador+1);
		}
	}
}

void carrusel(Cola q){
	if(!esnueva(q)){
		if((getchar())!='#'){
			ImpElem(primero(q));
			q = formar(desformar(q), primero(q));
			return carrusel(q);
		}
	}
}


//Multilevel feedback quote

