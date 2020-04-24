/*
	Carlos Nevarez
	Cola con prioridades
	13-03-19
	Hago uso del TDA de Cola para aplicarlos a una cola con prioridades.
	 *Una cola con prioridades deja formado el primer elemento, pero cuando 
	 se forma un nuevo elemento lo posiciona según su prioridad, en este caso 
	 el menor numero tiene una mayor prioridad, y ademas si hay un elemento con
	 la misma prioridad se forma al elemento de entrada atras del elemento ya 
	 existente.
*/

#include "Cola.h"

Elem ultimo(ColaP q){
	return q->ult->dato;
}

ColaP PegaColas(ColaP p1, ColaP p2){
	if(esnueva(p1) && esnueva(p2))
		return nueva();
	else if(esnueva(p1))
		return p2;
	else if(esnueva(p2))
		return p1;
	else
		return formar(PegaColas(p1,desformar(p2)),primero(p2));
	/*if(esnueva(p2))
		return p1;
	else//formar(PegaColas(desformar(p1),p2),primero(p2))
		return formar(PegaColas(p1,desformar(p2)),primero(p2));
		//formar(formar(desformar(p1),primero(p2)),primero(p2)) No imprime el primero de p1 y el ultimo de p2
		//formar(formar(desformar(p1),primero(p1)),primero(p2)) Imprime todas de p1 pero solo el primero de p2*/
}

ColaP formarP(ColaP c, Elem PrdEnt){
	ColaP s = nueva();//Uso una sentinela para trabajar con el resto de la cola
	ColaP r = nueva();//La cola que retornare
	int agregado = 0;
	
	if(esnueva(c)) //Condicion de bolsillo por si la cola no tiene elementos.
		return formar(c,PrdEnt);
	else if(esnueva(desformar(c))) //Condicion para ver si solo tiene un elemento
		return formar(c,PrdEnt);	
	else{
		s = desformar(c);//Trabajamos con el puro resto
		r = formar(nueva(),primero(c)); //Ya de entrada el primer elemento va ser el primero de c
		Elem cabeza = primero(s);//Primero del resto de c
		
		if(MayorPrioridad(PrdEnt, cabeza)){//Si la prioridad de entrada es mayor a la del resto, entonces sera el segundo elemento
			r = formar(r,PrdEnt);//Lo formo como segundo elemento
			//Debo pegar r con el resto, osea r+s
			while(!esnueva(s)){
				r = formar(r,primero(s));
				s = desformar(s);
			}
			
			return r;
		} else {
			//printf("lol\n");
			do{
				if(MenorPrioridad(PrdEnt,cabeza) || IgualPrioridad(PrdEnt,cabeza) || agregado==1){
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
						r = formar(r,PrdEnt);//Finalmente se forma el dato de entrada
					}
				} else if(MayorPrioridad(PrdEnt,cabeza) && agregado!=1){
					//printf("\n PrdEnt (%d) es de mayor prioridad (%d)", PrdEnt, cabeza);
					r = formar(r,PrdEnt);//Finalmente se forma el dato de entrada
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
