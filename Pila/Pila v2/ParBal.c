/*
	Carlos Nevarez
	Balaceo de parentesis, entra una expresion y el programa me dice si
	esta balanceada, esto es que cada parentesis tenda su par.
	Ej. ()(())(())()() = balanceado
*/

#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "Pila.h"

int main(int argc, char *argv[]){
	 char *ent = *(argv+1);
	 int i=0, fpi=1;
	 Pila p = empty();
	 
	 //Procedimiento
	 while(ent[i]!='\0'){
	 	if(esParI(ent[i]))
	 		p = push(ent[i],p);
	 	else
	 		if(isempty(p))
	 			fpi = 0;
	 		else
	 			p = pop(p);
	 	
	 	i++;
	 }
	 
	 //Verificacion
	 printf("\n---------------------- ");
	 if(fpi && isempty(p))
	 	printf("\n Esta balanceado.");
	 else{
	 	printf("\n No esta balanceado.");
	 	if(!fpi)
	 		printf(" Puede que falten parentesis izquierdos.");
	 	else if(!isempty(p))
	 		printf(" Puede que falten parentesis izquierdos.");
	 }
	 printf("\n----------------------\n ");
	 
	return 0;
}
