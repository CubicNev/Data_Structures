/*
	Carlos Nevarez
	Hanoi
*/

Pila meter(int n, Pila p){
	while(n!=0){
		p = push(n,p);
		n = n-1;
	}
	return p;
}

void ImpTorres(Pila o, Pila d, Pila a){
	printf("O:\n");
	ImpPila(o);
	printf("D:\n");
	ImpPila(d);
	printf("A:\n");
	ImpPila(a);
}


void Hanoi(int n, Pila *o, Pila *d, Pila *a){//discos, origen, destino, auxiliar
	if(n==1){
		//Mover n de o a d
		*d = push(top(*o),*d);
		*o = pop(*o);
		/*printf("\n m vale %d Las tores son:\n",n);
		ImpTorres(*o,*d,*a);*/
	} else {
		Hanoi(n-1,o,a,d);
		/*printf("\n Se hizo con n-1=%d Las torres son\n",n-1);
		ImpTorres(*o,*d,*a);*/
		//Mover n de o a d
		*d = push(top(*o),*d);
		*o = pop(*o);
		/*printf("\n Se paso el elemento de o a d las torres son:\n");
		ImpTorres(*o,*d,*a);*/
		Hanoi(n-1,a,d,o);
		/*printf("\n Se paso de auxiliar a destino n-1 vale %d:\n",n-1);
		ImpTorres(*o,*d,*a);*/
	} 
}

