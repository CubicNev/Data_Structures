/*
 Carlos Nevarez
 28-02-09
*/
# include <stdio.h>
# include <stdlib.h>
# include "Elem.h"
# include "Cola.h"

int GenNumProcesos();
int GenId();
int GenTiempo();
int GenNuevoTiempo();
Cola AsignarProcesos(Cola q);

struct proceso{
	int id;
	int tiempo;
} *e;

int main(){
	 srand (getpid());//Funcion para que el rendom funcione correctamenteque 
	 Cola Procesos = nueva();
	 int NumProc = GenNumProcesos();
	 
	 printf("\n El numero de procesos es %d. Los procesos son:\n",NumProc);
	 
	 /*Procesos = AsignarProceso(Procesos);
	 ImpCola(Procesos);*/
	 
	return 0;
}

int GenNumProcesos(){
	return rand() % (10-5+1) + 5;
}

int GenId(){
	return rand() % (2800-1500+1) + 1500;
}

int GenTiempo(){
	return rand() % (32-8+1) + 8;
}

int GenNuevoTiempo(){
	return rand() % (25-5+1) + 5;
}

Cola AsignarProcesos(Cola q){
	e->id = GenId();
	e->tiempo = GenTiempo();
	return AsignarProcesos;
}

