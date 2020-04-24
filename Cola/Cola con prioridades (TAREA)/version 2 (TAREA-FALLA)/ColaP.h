/*
	Carlos Nevarez
	10-03-2019
	TDA de cola con prioridades
*/
# include "Elem.h"

typedef struct Nodo {
	ElemC dato;
	ElemI prioridad;
	struct Nodo *sig;
} *ApNodo;

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

ColaP formar(ColaP q, ElemI e){
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

ElemC primero(ColaP q){
	return q->prim->dato;
}

ElemI primerP(ColaP q){
	return q->prim->prioridad;
}

ColaP desformar(ColaP q){
	ColaP copia = nueva();
	copia->prim = q->prim;
	copia->ult = q->ult;
	
	if(copia->prim == copia->ult)
		copia->prim = copia->ult = NULL;
	else
		copia->prim = copia->prim->sig;
		
	return copia;
}

ColaP formarP(ColaP q, ElemC dato, ElemI prioridadEnt){
	ColaP copia = nueva();
	copia->prim = q->prim;
	copia->ult = q->ult;
	
	ApNodo t = (ApNodo) malloc(sizeof(struct Nodo));
	t->dato = dato;
	t->prioridad = prioridadEnt;
	t->sig = NULL;
	
	struct Nodo *Anterior = copia->prim->sig;
	struct Nodo *Posterior = Anterior->sig;
	
	ElemI prioridadSigPrim = Anterior->prioridad;
	ElemI prioridadUlt = copia->ult->prioridad;
	
	printf("Se empezo a formar\n");
	if(esnueva(q)){
		copia->prim = copia->ult = t;
	} else if(MenorPrioridad(prioridadEnt, prioridadUlt) ||
			  IgualPrioridad(prioridadEnt, prioridadUlt)) {
		copia->ult->sig = t;
		copia->ult = t;
		return copia;
		
	} else if(MayorPrioridad(prioridadEnt, prioridadUlt)){
		
		if(MayorPrioridad(prioridadEnt, prioridadSigPrim)) {
			t->sig = copia->prim->sig;
			copia->prim->sig = t;
			return copia;
			
		} else {
		    while(MenorPrioridad(prioridadEnt, prioridadSigPrim)
		          || IgualPrioridad(prioridadEnt, prioridadSigPrim)){
		      prioridadSigPrim = Posterior->prioridad;
		      Anterior = Posterior;
		      Posterior = Posterior->sig;
		    }
		    Anterior->sig = t;
		    t->sig = Posterior;
		    return copia;
        }
		
	}
}

void ImpCola(ColaP q){
	ColaP copia = nueva();
	copia->prim = q->prim;
	copia->ult = q->ult;
	
	if(!esnueva(copia)){
	    printf("No es vacia");
		ImpElemC(primero(copia));
		ImpElemI(primerP(copia));
		ImpCola(desformar(copia));
	}else{
	    printf("es vacia");
    }
}

int valida(ColaP q){
	return 0;
}
