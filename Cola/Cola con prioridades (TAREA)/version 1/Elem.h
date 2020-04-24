/*
	Carlos Nevarez
	10-03-2019
	Elemento de una cola con prioridades. Es un struct que contiene al elemento y su prioridad.
*/

typedef int ElemI;
typedef char ElemC;

void ImpElemI(ElemI e){
	printf("[%d|",e);
}

int MayorPrioridad(ElemI e1, ElemI e2){
	return e1<e2;
}

int MenorPrioridad(ElemI e1, ElemI e2){
	return e1>e2;
}

int IgualPrioridad(ElemI e1, ElemI e2){
	return e1==e2;
}

int EsIgualP(ElemI e1, ElemI e2){
	return e1==e2;
}

void ImpElemC(ElemC e){
	printf("%c] ",e);
}

int EsMenorD(ElemC e1, ElemC e2){
	return e1<e2;
}

int EsIgualD(ElemC e1, ElemC e2){
	return e1==e2;
}

