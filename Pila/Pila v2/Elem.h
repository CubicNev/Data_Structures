/*
	Carlos Nevarez
	Elemento para una pila
*/

typedef char Elem;

void ImpElem(Elem e){
	printf("%c",e);
}

/*Funciones para ver si un grupo de parentesis estan balanceados*/
int esParI(char p){
	return p == '(';
}

int esParD(char p){
	return p == ')';
}

/*Funciones para ver infix to posfix*/
int esDigito(char d){
	return (d>='0') && (d<='9');
}

int esLetra(char l){
	return ((l>='a')&&(l<='z')) || ((l>='A')&&(l<='Z'));
}

Elem esOperando(char o){
	return esDigito(o) || esLetra(o);
}

int precedencia(char x){
	switch(x){
		case '-':case '+':return 1;
		case '*': case '/':return 2;
		case '^':return 3;
	}
}
