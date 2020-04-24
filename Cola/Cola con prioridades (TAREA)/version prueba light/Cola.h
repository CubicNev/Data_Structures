/*
	Carlos Nevarez
	28-02-09
	TDA/Especificacion de cola (FIFO)
	13-03-19
	Cambio para que sea una cola con prioridades:
	 *Cambie Cola por ColaP
*/

#include "Elem.h"

typedef struct Nodo {
	Elem dato;
	struct Nodo *sig;
}*ApNodo;//(Apunta Nodo). Es un apodo de lista :v.

typedef struct CNodo{ 
	ApNodo prim;
	ApNodo ult;
}*ColaP;

ColaP nueva(){
	ColaP q = (ColaP) malloc(sizeof(struct CNodo));
	q->prim = NULL;
	q->ult = NULL;
	return q;
}

int esnueva(ColaP q){
	return (q->prim==NULL) && (q->ult==NULL);
}

ColaP formar(ColaP q, Elem e){
	ColaP copia = nueva();
	copia->prim = q->prim;
	copia->ult = q->ult;
	
	ApNodo t = (ApNodo) malloc(sizeof(struct Nodo));
	t->dato = e;
	t->sig = NULL;
	if(esnueva(q))
		copia->prim = copia->ult = t;
	else {
		copia->ult->sig=t;
		copia->ult=t;
	}
	
	return copia;
}

Elem primero(ColaP q){
	return q->prim->dato;
}

ColaP desformar(ColaP q){
	ColaP copia = nueva();
	copia->prim = q->prim;
	copia->ult = q->ult;
	
	if(copia->prim==copia->ult)
		copia->prim = copia->ult = NULL;
		//q = nueva(); Efecto colateral que destruye la cola ya que va cambiando el apuntador.
	else
		copia->prim = copia->prim->sig;
	
	return copia;
}

void ImpCola(ColaP q){
	ColaP copia = nueva();
	copia->prim = q->prim;
	copia->ult = q->ult;
	
	if(!esnueva(copia)){
		ImpElem(primero(copia));
		ImpCola(desformar(copia));
	}
}
