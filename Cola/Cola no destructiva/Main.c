/*
 Carlos Nevarez
 28-02-09
*/
# include <stdio.h>
# include <stdlib.h>
# include "Elem.h"
# include "Cola.h"

int main(){
	 Cola q = nueva();
	 q = formar(formar(formar(formar(formar(q,1),2),3),4),5);
	 ImpCola(q);
	 printf("\n");
	 ImpCola(desformar(q));
	 printf("\n");
	 ImpCola(q);
	 printf("\n");
	 ImpCola(formar(q,6));
	 printf("\n");
	 ImpCola(q);
	 printf("\n");
	 ImpCola(formar(q=formar(q,6),7));
	 printf("\n");
	 ImpCola(q);
	return 0;
}


