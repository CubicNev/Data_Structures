/*
 Carlos Nevarez
 18-02-19
 Implementar el tipo de dato pila y el TDA (solo constructoras)
*/

typedef struct Nodo{
		Elem dato;
		struct Nodo *sig;
	} *Pila;
	
Pila empty(){
		return NULL;
	}

Pila push(Elem e, Pila p){
		Pila x = (Pila) malloc(sizeof(struct Nodo));
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

Pila pop(Pila p){
		return p -> sig;
	}

