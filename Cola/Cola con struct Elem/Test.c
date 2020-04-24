/*
 Carlos Nevarez
 28-02-09
*/
# include <stdio.h>
# include <stdlib.h>
# include "Elem.h"
# include "Cola.h"

void carrusel(Cola q);

int main(){
	 Elem e1,e2,e3;
	 Cola q = nueva();
	 
	 printf("\n-------Se creo una nueva cola.-------\n");
	 esnueva(q)?puts(" La cola es nueva."):puts(" La cola no es nueva.");
	 
	 e1.id = 1;
	 e1.dato = 10;
	 q = formar(nueva(),e1);
	 printf("\n-------Se han agregado elemento-------\n");
	 esnueva(q)?puts(" Sigue nueva"):puts(" Ya no es nueva");
	 
	 printf(" El primer elemento es: ");
	 ImpElem(primero(q));
	 printf("\n La cola es: ");
	 ImpCola(q);
	 
	 e2.id = 2;
	 e2.dato = 11;
	 e3.id = 3;
	 e3.dato = 12;
	 q = formar(formar(q,e2),e3);
	 printf("\n-------Se han agregado mas elementos-------\n");
	 printf(" El primer elemento es: ");
	 ImpElem(primero(q));
	 printf("\n La cola es: ");
	 ImpCola(q);
	 printf("\n Probando el carrusel: ");
	 carrusel(q);
	 printf("\n Despues del carrusel: ");
	 ImpCola(q);
	return 0;
}

void carrusel(Cola q){
	if(!esnueva(q)){
		if(getchar()!='#'){
			ImpElem(primero(q));
			q = formar(desformar(q), primero(q));
			return carrusel(q);
		}
	}
}

