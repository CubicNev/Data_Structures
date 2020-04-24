/*
	Carlos Nevarez
	10-03-2019
*/
# include <stdio.h>
# include <stdlib.h>
# include "ColaP.h"

int main(){
    ColaP p = nueva();
    ImpCola(p);
    p=formarP(p, 'a', 1);
    ImpCola(p);
    return 0;
}

