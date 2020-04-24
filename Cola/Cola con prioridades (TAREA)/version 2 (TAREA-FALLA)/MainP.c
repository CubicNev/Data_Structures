/*
	Carlos Nevarez
	10-03-2019
*/
# include <stdio.h>
# include <stdlib.h>
# include "ColaP.h"

int menu(int opcion);
ColaP CrearCola(ColaP p);
ColaP LlenarCola(ColaP p);
ColaP AgregarElem(ColaP p);
ColaP EliminarElem(ColaP p);
void Imprimir(ColaP p);

int main(){
    int opcion = 1;
    ColaP p = nueva();
    
	printf("\n ---- Inicio del programa ----\n\n");
	while(opcion!=4){
	    switch(opcion = menu(opcion)){
	        case 1:
	           p = CrearCola(p); 
	           Imprimir(p);
	        break;
	        case 2:
	           p = AgregarElem(p);
	           Imprimir(p);
	        break;
	        case 3:
	           p = EliminarElem(p);
	           Imprimir(p);
	        break;
	        case 4:
	            printf("\n ---- Fin del programa ----\n\n");
	        break;
	        default:
	            printf("\n ---- Seleccione un dato correcto ----\n\n");
	        break;
        }
    }
	return 0;
}

int menu(int opcion){
    printf(" Selecciona una opcion: \n");
    printf(" \t1) Crear cola.\n");
    printf(" \t2) Insertar elemento.\n");
    printf(" \t3) Eliminar elemento.\n");
    printf(" \t4) Salir.\n");
    printf(" \tOpcion: ");
    scanf("%d", &opcion);
    return opcion;
}


ColaP LlenarCola(ColaP p){
    char dato;
    int prioridad;
    fflush( stdin );
    
    printf("Ingrese un dato: ");
    dato = getchar();
	printf("Ingrese su prioridad: ");
	scanf("%d", &prioridad);
	
	return formarP(p, dato, prioridad);
}

ColaP CrearCola(ColaP p){
    if(esnueva(p)){
	    p = LlenarCola(p);
    } else {
        printf("\n ---- Ya hay una cola creada ----\n\n");
    }
    return p;
}

ColaP AgregarElem(ColaP p){
    if(!esnueva(p)){
        p = LlenarCola(p);
    }else{
        printf("\n ---- Primero crea una cola ----\n\n");
    }
    
    return p;
}

ColaP EliminarElem(ColaP p){
    if(!esnueva(p)){
        p = desformar(p);
    } else {
        printf("\n ---- Primero crea una cola ----\n\n");
    }
    
    return p;
}

void Imprimir(ColaP p){
    printf(" La cola es: \n");
    ImpCola(p);
}


