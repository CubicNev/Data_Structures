/*
 Carlos Nevarez
 07-03-2019
 Ejecutable de la cola circular.
 - Menu que pida los datos
 - Falta imprimir
 - Carrusel agregue elementos hasta que me de un cero.
*/

# include <stdio.h>
# include <stdlib.h>
# include "Elem.h"
# include "ColaC.h"

int main(){
	 ColaC c = nuevaC();
	 int elem, i=1;
	 //c = formarC(formarC(formarC(formarC(formarC(c,1),2),3),4),5);
	 printf("\n ---- COLA CIRCULAR ---- \n\n");
	 
	 do{
	 	printf(" Ingresa elemento numero %d: ", i);
	 	scanf("%d",&elem);
	 	c = formarC(c,elem);
	 	i++;
	 } while(elem!=0);
	 	
 	 printf("\n El primer elemento es: "); ImpElem(primero(c));
 	 printf("\n La cola es: ");
 	 ImpColaC(c);
 	 printf("\n Primera rotacion: ");
 	 c = rotar(c);
	 ImpColaC(c);
 	 printf("\n\n ---- FIN ----");
	return 0;
}
