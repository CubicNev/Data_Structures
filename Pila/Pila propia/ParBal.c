/*
 Carlos Nevarez
 14-02-19
 Balanceo de parentesis
 Hacer una parbal con pilas: Recibe una expresion "()(())(())()()\0" que me diga que esta balanceado
*/
#include <stdio.h>
#include <stdlib.h>
#include "ElemC.h"
#include "Pila.h"

int EsParI(char x);
int EsParD(char x);

int main(int argc, char *argv[]){
	 
	 Pila p = empty();
	 char *in = *(argv+1);
	 int i = 0;
	 
	 printf("\n----------------------\n ");
	 while(in[i]!='\0'){
	 	if(isempty(p))
			p = push(in[i], p);
		else if(EsParI(in[i])){
		    p = push(in[i],p);
		    ImpElem(top(p));
        } 
		else if(EsParD(in[i])){
		    putchar(in[i]);
		    p = pop(p);
        }
		    
	 	i++;
	 }
	 
	 if(isempty(p))
	   printf("Esta balanceada\n");
	 else
	   printf("No esta balanceada\n");
	 
	 printf("----------------------\n ");
	return 0;
}

int EsParI(char x){
	return x=='(';
}

int EsParD(char x){
	return x==')';
}
