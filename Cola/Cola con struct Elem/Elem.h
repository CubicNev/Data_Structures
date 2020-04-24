/*
 Carlos Nevarez
 28-02-09
*/

typedef struct{
	int id;
	int dato;
} Elem;

void ImpElem(Elem e){
	printf("[%d|%d] ",e.id,e.dato);
}
