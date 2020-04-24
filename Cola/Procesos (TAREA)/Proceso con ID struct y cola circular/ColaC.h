/*
 Carlos Nevarez
 07-03-2019
 Especificacion para una cola circular.
 EL ULTIMO APUNTA AL PRIMERO.
*/

typedef struct Nodo{
	Elem dato;/*Elemento*/ 
	struct Nodo *sig;/*Apuntador a otro nodo*/
} *ColaC;

ColaC nuevaC(){
	return NULL;
}

int esnuevaC(ColaC c){
	return c==NULL;
}

ColaC formarC(ColaC c, Elem e){ //c siempre es el ultimo
	ColaC t = (ColaC) malloc(sizeof(struct Nodo));//crea nodo
	t->dato = e;//Le mete e
	//Tenemos dos casos
	if(esnuevaC(c)){
		t->sig = t;//t apunta sí mismo
	} else{
		t->sig = c->sig;//Como t ahora es el ultimo hacemos que apunte a donde apunta c
		c->sig = t;//c ahora esta atras de t
	}
	
	return t;
}

Elem primero(ColaC c){
	if(!esnuevaC(c))
		return c->sig->dato;
}

ColaC desformar(ColaC c){
	ColaC t;
	if(!esnuevaC(c)){
		if(c==c->sig)//Si solo hay un elemento
			return nuevaC();
		else{
			t = c->sig;
			c->sig = c->sig->sig;
			free(t); //Borro la basura
			return c;
		}
	} else
		return nuevaC();
}

ColaC rotar(ColaC c){
	return c->sig;
}

void ImpColaC(ColaC c){
	if(!esnuevaC(c)){
		ColaC o = c;//Sentinela 
		ImpElem(primero(c));
		
		while(o!=rotar(c)){
			c = rotar(c);
			ImpElem(primero(c));
		}
		printf("\n");
	}
}

