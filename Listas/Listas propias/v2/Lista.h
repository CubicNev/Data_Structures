/*
 Las listas son apuntadores a nodos(estructuras autoreferenciadas)
 Carlos Nevarez
 08-02-2019
*/

typedef struct Nodo{
	Elem dato;/*Elemento*/ 
	struct Nodo *sig;/*Apuntador a otro nodo*/
} *Lista;

Lista vacia(){
	return NULL;
}

Lista cons(Elem e, Lista l){
	Lista t = (Lista) malloc(sizeof(struct Nodo));
	t->dato = e;
	t->sig = l;
	return t;
}

int esvacia(Lista l){
	return l==NULL;
}

Elem cabeza(Lista l){
	return l->dato;
}

Lista resto(Lista l){
	return l->sig;
}

int NumElem(Lista l){ //Tarea
	if(esvacia(l))
		return 0;
	else
		return 1+NumElem(resto(l));
}

Lista PegaListas(Lista l1, Lista l2){
	if(esvacia(l1))
		return l2;
	else
		return cons(cabeza(l1), PegaListas(resto(l1),l2));
}

void ImpLista(Lista l){
	if(!esvacia(l)){
		ImpElem(cabeza(l));
		ImpLista(resto(l));
	}
}

Lista InvLista(Lista l){
	if(esvacia(l))
		return l;
	else
		return PegaListas(InvLista(resto(l)), cons(cabeza(l),vacia()));
}

Lista InsOrd(Elem e, Lista l){
	if(esvacia(l))
		return cons(e, vacia());
	else if(EsMenor(e,cabeza(l)))
		return cons(e, l);
	else
		return cons(cabeza(l), InsOrd(e, resto(l)));
}

//14-02-19
//Definir una funcion que reciba como argumento una lista y devuelva otra lsita con los elementos ordenados ascendentemente
Lista OrdenaA(Lista l){//Tarea
	if(esvacia(l))
		return l;
	else
		return InsOrd(cabeza(l),OrdenaA(resto(l)));
}

//Para lista ordenada Descendentemente
Lista OrdenaD(Lista l){
	return InvLista(OrdenaA(l));
}

//Funcion que diga si el elemento esta en la lista
int VerElem(Elem e, Lista l){
	if(esvacia(l))
		return 0;
	else if(EsIgual(e,cabeza(l)))
		return 1;
	else
		return VerElem(e,resto(l));	
}

//18-02-19
void ImpListaA(Lista l, FILE *a){
	if(!esvacia(l)){
		ImpElemA(cabeza(l),a);
		ImpListaA(resto(l),a);
	}
}




