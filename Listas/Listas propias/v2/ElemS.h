/*
 Carlos Nevarez
 14-02-2019
*/
# include <string.h>

typedef char *Elem;

void ImpElem(Elem e){ 
	printf("%s\n",e); 
}

int EsMenor(Elem e1, Elem e2){
	if(strcmp(e1,e2)<0)
		return 1;
	else
		return 0;
}

int EsIgual(Elem e1, Elem e2){
	if(strcmp(e1,e2)==0)
		return 1;
	else
		return 0;
}

//18-02-19
void ImpElemA(Elem e, FILE *a){ 
	fprintf(a,"%s\n",e); 
}
