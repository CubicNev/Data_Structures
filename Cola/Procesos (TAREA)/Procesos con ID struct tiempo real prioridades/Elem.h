/*
 Carlos Nevarez
 21-03-19
*/

typedef struct{
	int id;
	int prioridad;
	int tiempo;
} Elem;

void ImpElem(Elem e){
	printf("[%d|%d] ",e.dato,e.prioridad);
}

int prioridad(Elem e){
	return e.prioridad;
}

int tiempo(Elem e){
	return e.tiempo;
}

int MayorPrioridad(int prim, int seg){
	return prim<seg;//Si prim tiena mayor prioridad que seg
}

int MenorPrioridad(int prim, int seg){
	return prim>seg;//Si e1 tiena menor prioridad que e2
}

int IgualPrioridad(int prim, int seg){
	return prim==seg;
}
