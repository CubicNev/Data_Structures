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
Cola AsignarIds(Cola q, int n, int contador);
Cola AsignarTiempos(Cola q, int n, int contador);
void ImprimirProcesos(Cola p, Cola t);
void GestionarProcesos(Cola p, Cola t, int segundos);

int main(){
	 srand (getpid());//Funcion para que el rendom funcione correctamenteque 
	 Cola Procesos = nueva(), Tiempos = nueva();
	 int NumProc = GenNumProcesos();
	 
	 printf("\n El numero de procesos es %d. Los procesos son:\n",NumProc);
	 
	 Procesos = AsignarIds(Procesos,NumProc,1);
	 /*printf("\n Los id's de los procesos son:\n");
	 ImpIds(Procesos);*/
	 
	 Tiempos = AsignarTiempos(Tiempos,NumProc,1);
	 /*printf("\n Los tiempos de los procesos son:\n");
	 ImpTiempos(Tiempos);*/
	 ImprimirProcesos(Procesos, Tiempos);
	 
	 printf("\n\n --Iniciando gestion de procesos--\n\n");
	 GestionarProcesos(Procesos, Tiempos, 5);
	 
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

Cola AsignarIds(Cola q, int n, int contador){
	if(n>0){
		//printf(" La id del espacio %d es %d\n", contador, GenId());
		return AsignarIds(q=formar(q,GenId()),n-1,contador+1);
	} else{
		return q;
	}
}

Cola AsignarTiempos(Cola q, int n, int contador){
	if(n>0){
		//printf(" El tiempo del proceso %d es %d\n", contador, GenTiempo());
		return AsignarTiempos(q=formar(q,GenTiempo()),n-1,contador+1);
	} else{
		return q;
	}
}

void ImprimirProcesos(Cola p, Cola t){
	Cola copiaP = nueva(), copiaT = nueva();
	copiaP->prim = p->prim, copiaT->prim = t->prim;
	copiaP->ult = p->ult, copiaT->ult = t->ult;
	
	if((!esnueva(copiaP)) && !esnueva(copiaT)){
		ImpId(primero(copiaP));
		ImpTiempo(primero(copiaT));
		ImprimirProcesos(desformar(copiaP),desformar(copiaT));
	}
}

void GestionarProcesos(Cola p, Cola t, int segundos){
	int NProc, NTiem;
	if(segundos==30){
		NProc = GenId();
		NTiem = GenNuevoTiempo();
		printf(" Se genero el proceso: [%d|%d]\n",NProc,NTiem);
		return GestionarProcesos(p = formar(p, NProc), t = formar(t, NTiem), 0);
		
	}else if((!esnueva(p)) && !esnueva(t)){
		if(primero(t)<=5){
			printf(" Se termino el proceso: ");
			ImpElem(primero(p));
			printf("\n");
			return GestionarProcesos(p=desformar(p), t=desformar(t), segundos+5);
		
		}
		else{
			ImpId(primero(p));
			ImpTiempo(primero(t)-5);
			return GestionarProcesos(p=formar(desformar(p),primero(p)), t=formar(desformar(t),primero(t)-5), segundos+5);
		
		}
		
	} else if(esnueva(p) && esnueva(t)){
		printf("\n --- Se han gestionado todos los Procesos ---\n");
	}
}

