/*
	Carlos Nevarez
	Infijo a Posfijo. Pasa una expresion de la forma 5+3 a la forma 53+
	Ejemplo: (b+(b^2-4*a*c)^1/2)/(2*a) pasa a bb24a*c*-12/+2a
*/


#include <stdio.h>
#include <stdlib.h>
#include "Elem.h"
#include "Pila.h"

int main(int argc, char *argv[]){
	 Pila p = empty();
	 int i = 0;
	 char *in = *(argv+1);
	 
	 printf(" \n Es: ");
	 while(in[i]!='\0') {//Vamos a reccorrer toda la palabra
	 	if(esOperando(in[i]))
	 		ImpElem(in[i]);
	 	else if(esParI(in[i])) //Mete los parentesis izquierdos
	 		p = push(in[i],p);
	 	else if(esParD(in[i])){//Con los parentesis derechos vacia la pila
	 		while(!esParI(top(p))){
	 			ImpElem(top(p));
	 			p = pop(p);
			}
			p = pop(p); //Saca el parentesis izquierdo pero no lo imprime
		} else if(isempty(p))
			p = push(in[i], p);
		else if(esParI(top(p)))
			p = push(in[i],p);
		else{
			while(precedencia(in[i]) <= precedencia(top(p))){
				ImpElem(top(p));
				p = pop(p);
			}
			p = push(in[i],p);
		}
		i++;
	 }
	 
	 while(!isempty(p)){
	 	ImpElem(top(p));
	 	p = pop(p);
	 }
	 
	 printf("\n");
	return 0;
}
