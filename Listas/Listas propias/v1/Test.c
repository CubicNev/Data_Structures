/*
 Carlos Nevarez
 08-02-2019
*/
# include <stdio.h>
# include <stdlib.h>
# include "Elem.h"
# include "Lista.h"

int main(){
	Lista l = vacia();
	
	printf("\n La lista esta vacia? \n R: ");
	esvacia(l)?puts("Simon"):puts("Nel"); //if taquigrafico que indica si la alista es vacia
	
	l = cons(5,cons(4,cons(3,cons(2,cons(1,vacia())))));
	printf("\n ...  \n");
	
	printf("\n Y ahora? \n R: ");
	esvacia(l)?puts("Si"):puts("No");
	
	printf("\n La cabeza es "); 
	ImpElem(cabeza(l));//Imprimir elemento, en este caso la cabeza es 5
	
	printf("\n El tercer elemento es ");
	ImpElem(cabeza(resto(resto(l))));
	
	printf("\n La lista tiene %d elementos\n", NumElem(l));
	
	/*11-02-2019*/
	Lista r = cons(10, cons(9, cons(8, cons(7, cons(6, vacia())))));
	printf(" Se ha creado una lista r\n");
	
	printf("\n La lista r+l es:\n");
	ImpLista(PegaListas(r,l));
	
	printf("\n El numero de elementos de las dos listas es: %d\n" , NumElem(PegaListas(r,l)));
	
	printf("\n La lista r+l invertida es:\n");
	ImpLista(InvLista(PegaListas(r,l)));
	
	Lista i = cons(10, cons(20, cons(30, cons(40, cons(50, vacia())))));
	printf("\n Se ha creado la lista i:\n");
	ImpLista(i);
	
	printf("\n Agregando el elemento 5:\n");
	ImpLista(InsOrd(5,i));
	
	printf("\n Agregando el elemento 25:\n");
	ImpLista(InsOrd(25,i));
	
	printf("\n Agregando el elemento 55:\n");
	ImpLista(InsOrd(55,i));
	
	return 0;
}
