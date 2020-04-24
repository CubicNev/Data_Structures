/*
Cola: fifo
TDA cola
*/
typedef struct Nodo{
	Elem dato;
	Elem prio;
	struct Nodo *sig;
}*ApNodo;

typedef struct CNodo{
	ApNodo prim;
	ApNodo ult;
}*ColaP;

ColaP nueva(){
	ColaP t =(ColaP) malloc(sizeof(struct CNodo));
	t->prim=t->ult=NULL;//El nodo que se crea apunta a null, baia
	return t;
}

int esnueva(ColaP q){
	return (q->prim==NULL)&&(q->ult==NULL);
}

ColaP formar(ColaP q, Elem e, Elem e1){
	ColaP NC = nueva();
	NC->prim = q->prim;
	NC->ult = q->ult;
	ApNodo t = (ApNodo) malloc(sizeof(struct Nodo));
	t->dato = e;
	t->sig = NULL;
	t->prio = e1;
	if(esnueva(q)){
		NC->prim=NC->ult=t;
	}else{
		NC->ult->sig=t;
		NC->ult=t;
	}	
	return NC;	
}

Elem primero(ColaP q){
	return q->prim->dato;
}

Elem prioridad(ColaP q){
	return q->prim->prio;
}

ColaP desformar(ColaP q){
	ColaP t = nueva();
	t->prim = q->prim;
	t->ult = q->ult;
	if(t->prim==t->ult)
		t->prim=t->ult=NULL;
	else
		t->prim=t->prim->sig;
	return t;
}

void ImpColaP(ColaP q){
	ColaP copia = nueva();
	copia->prim=q->prim;
	copia->ult=q->ult;
	if(!esnueva(copia)){
		printf("Elemento: ");
		ImpElem(primero(copia));
		printf(" Prioridad: ");
		ImpElem(prioridad(copia));
		printf("\n");
		ImpColaP(desformar(copia));
	}
}
