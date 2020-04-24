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
	ApNodo t = (ApNodo) malloc(sizeof(struct Nodo));
	t->dato = e;
	t->sig = NULL;
	if(esnueva(q))
		q->prim = q->ult = t;
	else {
		q->ult->sig=t;
		q->ult=t;
	}
	
	return q;
}

Elem primero(Cola q){
	return q->prim->dato;
}

Cola desformar(Cola q){
	if(q->prim==q->ult)
		q->prim = q->ult = NULL;
		//q = nueva(); Efecto colateral que destruye la cola ya que va cambiando el apuntador.
	else
		q->prim = q->prim->sig;
	
	return q;
}

void ImpCola(Cola q){
	if(!esnueva(q)){
		ImpElem(primero(q));
		ImpCola(desformar(q));
	}
}



