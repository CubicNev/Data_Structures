/*
 Carlos Nevarez
 13-03-19
 Ejecutable que hace pruebas a una cola con prioridades usando un elemento 
 simple tipo entero.
*/

#include <stdio.h>
#include <stdlib.h>
# include "ColaP.h"

int main(){
	 
	 ColaP p = nueva();
	 printf("\n Se ha creado una cola nueva\n");
	 p = formar(formar(formar(formar(formar(p,4),6),8),8),9);
	 printf("\n Se ha llenado la cola:\n ");
	 ImpCola(p);
	 /*printf("\n Agregando el numero 1 a la cola\n ");
	 ImpCola(formarP(p,1));*/
	 ColaP q = formar(formar(formar(formar(formar(formar(nueva(),9),10),10),11),11),12);
	 printf("\n Segunda cola:\n ");
	 ImpCola(q);
	 printf("\n Probando que pegue bien dos colas:\n ");
	 ImpCola(PegaColas(p,q));
	 printf("\n Probando que forme por prioridades (Con 1):\n ");
	 ImpCola(formarP(p,1));
	 printf("\n Probando que forme por prioridades (Con 8):\n ");
	 ImpCola(formarP(p,8));
	 printf("\n Probando que forme por prioridades (Con 6):\n ");
	 ImpCola(formarP(p,6));
	 printf("\n Probando que forme por prioridades (Con 9):\n ");
	 ImpCola(formarP(p,9));
	 printf("\n Probando que forme por prioridades (Con 14):\n ");
	 ImpCola(formarP(p,14));
	return 0;
}
