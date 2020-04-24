/*
 Carlos Nevarez
 18-02-19
 Conversion Infic a Postfix
*/

#include <stdio.h>
#include <stdlib.h>
#include "ElemC.h"
#include "Pila.h"

//(b+(b^2-4*a*c)^1/2)/(2*a)
int EsParI(char x);
int EsParD(char x);
int EsDigito(char x);
int EsLetra(char x);
int EsOperando(char x);
int EsOperador(char x);
int Prec(char x);

int main(int argc, char *argv[]){
	 Pila op = empty();
	 int i = 0;
	 char *in = *(argv+1);
	 
	 printf("\n----------------------\n ");
	 while(in[i]!='\0'){
	 	if(EsOperando(in[i]))
	 		ImpElem(in[i]);
	 		
	 	else if(EsParI(in[i]))
	 		op = push(in[i],op);
	 		
	 	else if(EsParD(in[i])){
	 		while(!EsParI(top(op))){
	 			ImpElem(top(op));
	 			op = pop(op);
			}
			op = pop(op);
			
		} else if(isempty(op))
			op = push(in[i], op);
			
		else if(EsParI(top(op)))
			op = push(in[i], op);
			
		else {
			while( Prec(in[i]) <= Prec(top(op)) ){
				ImpElem(top(op));
				op = pop(op);
			}
			op = push(in[i],op);
			
		}
		i++;
	 }
	 
	 //Vaciar la pila
	 while(!isempty(op)){
	 	ImpElem(top(op));
	 	op = pop(op);
	 }
	 
	 printf("\n----------------------\n");
	 
	return 0;
}

int EsParI(char x){
	return x=='(';
}

int EsParD(char x){
	return x==')';
}

int EsDigito(char x){
	return ((x>='0') && (x<='9'));
}

int EsLetra(char x){
	return (((x>='a')&&(x<='z')) || ((x>='A')&&(x<='Z')));
}

int EsOperando(char x){
	return EsDigito(x) || EsLetra(x);
}

//int EsOperando(char x){return (!EsOperador(x)&&!EsParI(x)&&!EsParD(x));}

int EsOperador(char x){
	if((x=='+')||(x=='-')||(x=='*')||(x=='/')||(x=='^'))
		return 1;
	else
		return 0;
}

int Prec(char x){
	switch(x){
		case '-': case '+': return 1;
		case '*': case '/': return 2;
		case '^': return 3;	
	}
}


/*
	Hacar una parbal con pilas: Recibe una epresion "()(())(())()()\0" que me diga que esta balanceado
	pila vacia = valorada
	pila 
*/
