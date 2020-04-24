/*
 Carlos Nevarez
 21-03-2019
 Ejecutable que gestiona procesos por prioridades haciendo uso de el tiempo real.
*/

# include <stdio.h>
# include <stdlib.h>
# include "Elem.h"
# include "ColaP.h"

int GenNumProcesos();
int GenId();
int GenTiempo();
int GenNuevoTiempo();
int GenPrioridad();

int main(){
	 srand (getpid());//Funcion para que el random funcione correctamenteque
	 int NumProc = GenNumProcesos();
	 
	 
	return 0;
}

int GenNumProcesos(){
	return rand() % (10-5+1) + 5;
}

int GenId(){
	return rand() % (2800-1500+1) + 1500;
}

int GenTiempo(){
	return rand() % (30-15+1) + 15;
}

int GenNuevoTiempo(){
	return rand() % (25-5+1) + 5;
}

int GenPrioridad(){
	return rand() % (10-1+1) + 1;
}

