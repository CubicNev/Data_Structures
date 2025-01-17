/*
	Carlos Nevarez
	Cola con prioridades y elem tipo struct
	21-03-19
	Hago uso del TDA de Cola para aplicarlos a una cola con prioridades.
	 *Una cola con prioridades deja formado el primer elemento, pero cuando 
	 se forma un nuevo elemento lo posiciona seg�n su prioridad, en este caso 
	 el menor numero tiene una mayor prioridad, y ademas si hay un elemento con
	 la misma prioridad se forma al elemento de entrada atras del elemento ya 
	 existente.
*/

#include "Elem.h"
#include "Cola.h"

Elem ultimo(ColaP q){
	return q->ult->dato;
}

ColaP formarP(ColaP c, Elem entrada){
	ColaP s = nueva();//Uso una sentinela para trabajar con el resto de la cola
	ColaP r = nueva();//La cola que retornare
	int agregado = 0;
	int PrdEnt = prioridad(entrada);
	
	if(esnueva(c)) //Condicion de bolsillo por si la cola no tiene elementos.
		return formar(c,entrada);
	else if(esnueva(desformar(c))) //Condicion para ver si solo tiene un elemento
		return formar(c,entrada);	
	else{
		s = desformar(c);//Trabajamos con el puro resto
		r = formar(nueva(),primero(c)); //Ya de entrada el primer elemento va ser el primero de c
		Elem cabeza = primero(s);//Primero del resto de c
		
		if(MayorPrioridad(PrdEnt, prioridad(cabeza))){//Si la prioridad de entrada es mayor a la del resto, entonces sera el segundo elemento
			r = formar(r,entrada);//Lo formo como segundo elemento
			//Debo pegar r con el resto, osea r+s
			while(!esnueva(s)){
				r = formar(r,primero(s));
				s = desformar(s);
			}
			
			return r;
		} else {
			//printf("lol\n");
			do{
				if(MenorPrioridad(PrdEnt,prioridad(cabeza)) || IgualPrioridad(PrdEnt,prioridad(cabeza)) || agregado==1){
					//printf("\n PrdEnt (%d) es de igual o menor prioridad (%d)", PrdEnt, cabeza);
					r = formar(r,cabeza);
					//printf("\n Se formo la cabeza del resto de la sentinela r:\n ");
					//ImpCola(r);
					//printf("\n Se desformo la sentinela:\n ");
					s = desformar(s);//Trabajo con el resto
					//esnueva(s)?puts("s se quedo vacia\n"):puts("s sigue llena: ");
					if(!esnueva(s)){
						cabeza = primero(s);
						//ImpCola(s);
					} else if(agregado!=1){
						//printf("\n PrdEnt (%d) es de menor prioridad a todo\n\n", PrdEnt, cabeza);
						r = formar(r,entrada);//Finalmente se forma el dato de entrada
					}
				} else if(MayorPrioridad(PrdEnt,prioridad(cabeza)) && agregado!=1){
					//printf("\n PrdEnt (%d) es de mayor prioridad (%d)", PrdEnt, cabeza);
					r = formar(r,entrada);//Finalmente se forma el dato de entrada
					//printf("\n Se ha formado (%d)\n ", PrdEnt);
					//ImpCola(r);
					agregado = 1;
					//printf("\n Lo que queda es:\n ");
					//ImpCola(s);
					//printf("\n Se agrega el siguiente elemento: \n ");
					r = formar(r,cabeza);
					//ImpCola(r);
					//printf("\n Desformandolo: ");
					s = desformar(s);
					//esnueva(s)?puts("s se quedo vacia\n"):puts("s sigue llena: ");
				}
			}while(!esnueva(s));
			
			return r;
		}
	}
		
}
