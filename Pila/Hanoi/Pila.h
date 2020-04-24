/*
	Carlos Nevarez
	Una pila es una estrucutra donde el ultimo dato en entrar es el primero en salir
*/

typedef struct Nodo{
	Elem dato;
	struct Nodo *sig;
} *Pila;

Pila empty(){
	return NULL;
}

Pila push(Elem e, Pila p){ //inserta
	Pila x = (Pila) malloc(sizeof(struct Nodo));
	x->dato = e;
	x->sig = p;
	
	return x;
}

int isempty(Pila p){
	return p == NULL;
}

Elem top(Pila p){ //Da el elemento en la cima de la pila
	return p->dato;
}

Pila pop(Pila p){ //Saca el ultimo que entro
	return p->sig;
}

Pila vaciar(Pila p){
	while(!isempty(p))
		p = pop(p);
	
	return p;
}

void ImpPila(Pila p){
	if(!isempty(p)){
		ImpElem(top(p));
		ImpPila(pop(p));
	} else
		printf("[]\n\n");
}

