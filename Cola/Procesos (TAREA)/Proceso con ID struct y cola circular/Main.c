/*
 Carlos Nevarez
 21-03-2019
 Procesos con ID usando cola circular y Elem tipo struct
*/

# include <stdio.h>
# include <stdlib.h>
# include "Elem.h"
# include "ColaC.h"

int GenNumProcesos();
int GenId();
int GenTiempo();
int GenNuevoTiempo();
ColaC GenProcesos(ColaC c, int n);
void GestionarProcesos(ColaC c, int segundos);

int main(){
	 srand (getpid());//Funcion para que el random funcione correctamenteque
	 int NumProc = GenNumProcesos();
	 ColaC Procesos = nuevaC();
	 
	 printf("\n ---- INCIO DEL PROGRAMA ---\n");
	 
	 printf("\n El numero de procesos es %d. Los procesos son:\n ",NumProc);
	 Procesos = GenProcesos(Procesos,NumProc);
	 ImpColaC(Procesos);
	 
	 printf("\n\n --Iniciando gestion de procesos--\n\n");
	 GestionarProcesos(Procesos, 0);
	 
	 printf("\n ---- FIN DEL PROGRAMA ---\n");
	 
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

ColaC GenProcesos(ColaC c, int n){
	Elem proceso;
	
	if(n>0){
		proceso.id = GenId();
		proceso.tiempo =  GenTiempo();
		return GenProcesos(c = formarC(c,proceso),n-1);
	} else{
		return c;
	}
}

void GestionarProcesos(ColaC c, int segundos){
	Elem NueProc, e;
	if(segundos==30){
		NueProc.id = GenId();
		NueProc.tiempo = GenNuevoTiempo();
		printf(" Se ha generado un nuevo proceso. \n");
		c = formarC(c, NueProc);
		ImpColaC(c);
		getchar();
		return GestionarProcesos(c,0);
	} else if(!esnuevaC(c)){
		if(tiempo(primero(c)) <= 5){
			printf(" Se termino un proceso. \n");
			c = desformar(c);
			ImpColaC(c);
			getchar();
			return GestionarProcesos(c,segundos+5);
		} else{
			e.id = id(primero(c));
			e.tiempo = tiempo(primero(c)) - 5;
			c = formarC(desformar(c),e);
		
			/*setTiempo(primero(c),tiempo(primero(c)) - 5);
			c =  rotar(c);*/
			ImpColaC(c);
			getchar();
			return GestionarProcesos(c,segundos+5);
		}
	}
}
