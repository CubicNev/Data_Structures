/*
 Carlos Nevarez
 21-03-19
 Ejecutable que hace pruebas a una cola con prioridades usando un elemento 
 tipo struct.
*/

#include <stdio.h>
#include <stdlib.h>
#include "ColaP.h"

int main(){
	 Elem e1, e2, e3, e4, e5, e;
	 ColaP p = nueva();
	 printf("\n Creo una cola nueva:");
	 ImpCola(p);
	 
	 e1.dato = 1;
	 e1.prioridad = 4;
	 e2.dato = 2;
	 e2.prioridad = 6;
	 e3.dato = 3;
	 e3.prioridad = 8;
	 e4.dato = 4;
	 e4.prioridad = 8;
	 e5.dato = 5;
	 e5.prioridad = 9;
	 
	 p = formar(formar(formar(formar(formar(p,e1),e2),e3),e4),e5);
	 printf("\n La cola ha sido llenada: ");
	 ImpCola(p);
	 
	 printf("\n --- INICIAN PRUEBAS DE COLA CON PRIORIDADES ---\n");
	 e.dato = 6;
	 
	 printf("\n Con un dato con prioridad 1:\n ");
	 e.prioridad = 1;
	 ImpCola(formarP(p,e));
	 
	 printf("\n Con un dato con prioridad 8:\n ");
	 e.prioridad = 8;
	 ImpCola(formarP(p,e));
	 
	 printf("\n Con un dato con prioridad 6:\n ");
	 e.prioridad = 6;
	 ImpCola(formarP(p,e));
	 
	 printf("\n Con un dato con prioridad 9:\n ");
	 e.prioridad = 9;
	 ImpCola(formarP(p,e));
	 
	 printf("\n Con un dato con prioridad 14:\n ");
	 e.prioridad = 14;
	 ImpCola(formarP(p,e));
	 
	 printf("\n --- FIN DE PRUEBAS DE COLA CON PRIORIDADES ---\n");
	 
	return 0;
}
