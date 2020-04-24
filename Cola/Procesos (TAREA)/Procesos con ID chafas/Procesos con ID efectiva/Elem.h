/*
 Carlos Nevarez
 28-02-09
*/

typedef struct Node{
	int id;
	int tiempo;	
} *Elem;

void ImpElem(Elem e){
	printf("[%d|%d] ", e->id, e->tiempo);
}


