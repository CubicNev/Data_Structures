/*
 Carlos Nevárez
 25-02-19
 Cola: Primero en entrar, primero en salir.
 Construimos la cola sobre la lista UwUr
*/
#include "Elem.h"
#include "Lista.h"

typedef Lista Cola;

int esnueva(Cola q){
    return esvacia(q);
}

Cola nueva(){
    return vacia();
}

Cola formar(Cola q, Elem e){
    if(esvacia(q))
        return cons(e,q);
    else
        return cons(cabeza(q), formar(resto(q),e));
}

Elem primero(Cola q){
    return cabeza(q);
}

Cola desformar(Cola q){
    return resto(q);
}
