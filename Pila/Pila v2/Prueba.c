/*
	Carlos Nevarez
	Pruebas para una pila
*/

#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "Pila.h"

int main(){
	 Pila p = empty();
	 
	 p = push('a',push('b',push('c',p)));
	 
	 while(!isempty(p)){
	 	ImpElem(top(p));
	 	printf(".");
	 	p = pop(p);
	 }
	return 0;
}
