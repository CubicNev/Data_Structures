/*
	Carlos Nevarez
	TDA/Especificacion de cola (FIFO)
	28-02-09
*/

typedef struct Nodo {
	Elem dato;
	struct Nodo *sig;
}*ApNodo;//(Apunta Nodo). Es un apodo de lista :v.

typedef struct CNodo{ 
	ApNodo prim;
	ApNodo ult;
}*Cola;

Cola nueva(){
	Cola q = (Cola) malloc(sizeof(struct CNodo));
	q->prim = NULL;
	q->ult = NULL;
	return q;
}

int esnueva(Cola q){
	return (q->prim==NULL) && (q->ult==NULL);
}

Cola formar(Cola q, Elem e){
	Cola copia = nueva();
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

Elem primero(Cola q){
	return q->prim->dato;
}

Cola desformar(Cola q){
	Cola copia = nueva();
	copia->prim = q->prim;
	copia->ult = q->ult;
	
	if(copia->prim==copia->ult)
		copia->prim = copia->ult = NULL;
		//q = nueva(); Efecto colateral que destruye la cola ya que va cambiando el apuntador.
	else
		copia->prim = copia->prim->sig;
	
	return copia;
}

void ImpCola(Cola q){
	Cola copia = nueva();
	copia->prim = q->prim;
	copia->ult = q->ult;
	
	if(!esnueva(copia)){
		ImpElem(primero(copia));
		ImpCola(desformar(copia));
	}
}
