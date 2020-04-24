/*
 Carlos Nevarez
 21-03-19
 Ejecutable que sirve para formar con prioridades datos metidos por el usuario
*/

#include <stdio.h>
#include <stdlib.h>
#include "ColaP.h"

int menu();
int continuar();
ColaP InsertarElem(ColaP p);
ColaP CrearCola(ColaP p);
ColaP EliminarElem(ColaP p);

int main(){
	ColaP p = nueva();
	int opcion = 1;
	
	printf("\n --- INICIO DEL PROGRAMA --- \n");
	while(opcion != 4){
		fflush( stdin );
		switch(opcion = menu()){
			case 1:
				if(esnueva(p))
					p = CrearCola(p);
				else
					printf("\n Ya hay una cola creada.\n");
				break;
			case 2:
				if(esnueva(p))
					printf("\n Primero debe crear una cola.\n");
				else{
					p = (ColaP) InsertarElem(p);
					ImpCola(p);
				}
				break;
			case 3:
				if(esnueva(p))
					printf("\n Primero debe crear una cola.\n");
				else{
					p = EliminarElem(p);
					ImpCola(p);
				}
				break;
			case 4:
				printf("\n --- FIN DEL PROGRAMA ---\n");
				break;
			default:
				printf("\n ---- Seleccione una opcion correcta ----\n\n");
				opcion = 1;
				break;
		}
	}
	return 0;
}

int menu(){
	int opcion;
    printf("\n Selecciona una opcion: \n");
    printf("\t1) Crear cola.\n");
    printf("\t2) Insertar elemento.\n");
    printf("\t3) Eliminar elemento.\n");
    printf("\t4) Salir.\n");
    printf("\tOpcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int continuar(){
	int opcion;
	printf("\n Desea agregar otro dato? \n");
	printf(" Si - Ingrese 1\n");
	printf(" No - Ingrese 0\n");
	printf(" opcion: ");
	scanf("%d", &opcion);
	return opcion;
}

ColaP InsertarElem(ColaP p){
	Elem e;
	int dato, prioridad;
	printf("\n Ingrese un dato: ");
	scanf("%d",&dato);
	e.dato = dato;
	
	printf(" Ingrese su prioidad: ");
	scanf("%d", &prioridad);
	e.prioridad = prioridad;
	
	p = formarP(p, e);
	printf("\n Se ha agregado a la cola. \n");
	
	return p;
}

ColaP CrearCola(ColaP p){
	printf("\n Se ha creado a la cola. Empiece a agregar datos: ");
	do{
		p = InsertarElem(p);
	} while(continuar());
	
	printf("\n COLA CREADA EXITOSAMENTE \n ");
	ImpCola(p);
	
	return p;
}

ColaP EliminarElem(ColaP p){
	printf("\n Se ha eliminado el primer elemento.\n");
	return desformar(p);
}
