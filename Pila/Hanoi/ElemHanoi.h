/*
	Carlos Nevarez
	Elemento para una pila
*/

typedef int Elem;

void ImpElem(Elem e){
	printf("[%d]\n", e);
}

int EsMenor(Elem e1, Elem e2){
	return e1<e2;
}
int EsMayor(Elem e1, Elem e2){
	return e1>e2;
}
int EsIgual(Elem e1, Elem e2){
	return e1==e2;
}
