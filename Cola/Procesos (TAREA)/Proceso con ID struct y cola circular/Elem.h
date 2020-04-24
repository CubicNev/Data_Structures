/*
 Carlos Nevarez
 21-03-2019
*/

typedef struct{
	int id;
	int tiempo;
} Elem;

void ImpElem(Elem e){
	printf("[%d|%d] ",e.id,e.tiempo);
}

int tiempo(Elem e){
	return e.tiempo;
}

int id(Elem e){
	return e.id;
}

void setTiempo(Elem e, int t){
	e.tiempo = t;
}
