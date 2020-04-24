/*
  Carlos Nevarez
  13-03-2019
  Este elemento es de tipo int, servira para probar las prioridades.
  El numero más bajo es la prioridad más baja
*/

typedef int Elem;

Elem ImpElem(Elem e){
	printf("%d.",e);
}

int MayorPrioridad(Elem e1, Elem e2){
	return e1<e2;//Si e1 tiena mayor prioridad que e2
}

int MenorPrioridad(Elem e1, Elem e2){
	return e1>e2;//Si e1 tiena menor prioridad que e2
}

int IgualPrioridad(Elem e1, Elem e2){
	return e1==e2;
}
