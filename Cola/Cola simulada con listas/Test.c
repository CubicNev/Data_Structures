/*
 Carlos Nevárez
 25-02-19
 Implementacion de cola.
*/

#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"

int main(){
     Cola q = nueva();
     q = formar(formar(formar(formar(q,1),2),3),4);
     ImpElem(primero(q));
     ImpElem(primero(desformar(q)));
     
     
    return 0;
}
