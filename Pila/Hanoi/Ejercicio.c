/*
	Carlos Nevarez
	Torres de janoi: Mover n discos de una torre a otrs, un disco a la vez
	1: mover de alguna manera n-1 discos a la torre auxiliar.
	2: Muevo el disco mas gande (el n-esimo) a la torre destino.
	3: Los discos de la torre auxiliar los paso a la torre destino obedeciendo las reglas.
*/

#include <stdio.h>
#include <stdlib.h>
#include "ElemHanoi.h"
#include "Pila.h"
#include "Hanoi.h"

int main(){
	 Pila *po, *pd, *pa;
	 Pila o = empty(); //Origen. Donde hay discos.
	 Pila d = empty(); //Destino
	 Pila a = empty(); //Auxiliar. La que esta vacia.
	 po = &o;
	 pd = &d;
	 pa = &a;
	 int n;
	 
	 //Pedimos datos
	 printf("\n Cuantos elementos necesitas: "); scanf("%d",&n);
	 o = meter(n,o);
	 printf("\n La torres son:\n");
	 ImpTorres(o,d,a);
	 //Empieza el algoritmo
	 printf("\n Aplicando el algoritmo ahora son:\n");
	 Hanoi(n,po,pd,pa);
	 printf("\n R:\n");
	 ImpTorres(o,d,a);
	return 0;
}
