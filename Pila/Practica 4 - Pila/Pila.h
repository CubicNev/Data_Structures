typedef struct Nodo{
		Elem dato;
		struct Nodo *sig;
	} *Pila;
Pila empty(){
		return NULL;
	}

Lista cons(Elem e, Pila p){
		Pila x = (Lista) malloc(sizeof(struct Nodo));
		x -> dato = e;
		x -> sig = p;
		return x;
	}

int isempty(Pila p){
		return p==NULL;
	}	

Elem top(Pila p){
		return p -> dato;
	}

Lista pop(Pila p){
		return p -> sig;
	}


