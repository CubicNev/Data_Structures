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
	 Cola q = nueva();
	 printf("\n-------Se creo una nueva cola.-------\n");
	 esnueva(q)?puts("La cola es nueva."):puts("La cola no es nueva.");
	 
	 q = formar(formar(formar(formar(formar(nueva(),'a'),'b'),'c'),'d'),'e');
	 printf("\n-------Se han agregado elementos-------\n");
	 esnueva(q)?puts("Sigue nueva"):puts("Ya no es nueva");
	 
	 printf("\nEl primer elemento es: ");
	 ImpElem(primero(q));
	 q = nueva();
	 printf("\nLa cola es:\n");
	 carrusel(q);
	 
	 printf("Despues del carrusel la cola es: ");
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

//Multilevel feedback quote

