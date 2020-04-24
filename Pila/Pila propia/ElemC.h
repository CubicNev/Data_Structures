/*
 Carlos Nevarez
 Elem de tipo char
*/

typedef char Elem;

void ImpElem(Elem e){
	printf("%c", e);
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

