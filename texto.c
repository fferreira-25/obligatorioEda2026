// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// texto.c
// Modulo de implementacion de texto.

#include "texto.h"
#include <iostream>

using namespace std;

// Nodo de la lista doblemente encadenada de lineas.
struct nodo_lista_lineas{
	linea lin;
	nodo_lista_lineas * sig;
	nodo_lista_lineas * ant;
};

struct nodo_texto{
	nodo_lista_lineas * primera; // NULL si el texto es vacio
	nodo_lista_lineas * ultima;  // para insertar al final en O(1)
	unsigned int cant;
};


texto CrearTexto(){
// Crea un texto vacio (0 lineas).
	texto t = new(nodo_texto);
	t->primera = NULL;
	t->ultima = NULL;
	t->cant = 0;
	return t;
}

unsigned int CantLineas(texto t){
// Retorna la cantidad de lineas de t.
	return t->cant;
}

void InsertarLinea(texto &t){
// Letra: op. 1 InsertarLinea (Tipo 1). O(1) peor caso.
	nodo_lista_lineas * nuevo = new nodo_lista_lineas;
	nuevo->lin = CrearLinea();
	nuevo->sig = NULL;
	nuevo->ant = t->ultima;

	if(t->primera == NULL){
		// si es la primer linea
		t->primera = nuevo;
		t->ultima = nuevo;
	}else{
		t->ultima->sig = nuevo;
		t->ultima = nuevo;
	}
	t->cant++;
}

bool InsertarLineaEnPosicion(texto &t, Posicion p){
// Letra: op. 2 InsertarLineaEnPosicion (Tipo 1).
// Inserta una linea vacia en la posicion p y corre una posicion hacia
// adelante a las lineas que estaban a partir de p.
// Retorna false (sin modificar t) si p no es valida: 1 <= p <= cant + 1.
	if(p < 1 || p > t->cant + 1){
		return false;
	}

	// Caso 1: va al final (incluye texto vacio, donde cant + 1 == 1).
	// Lo resuelve InsertarLinea, que ya actualiza primera/ultima/cant.
	if(p == t->cant + 1){
		InsertarLinea(t);
		return true;
	}

	// Caso 2 y 3: hay una linea en la posicion p que pasa a ser la siguiente
	// de la nueva. Busco ese nodo (p - 1 saltos desde la primera).
	nodo_lista_lineas * actual = t->primera;
	while(p > 1){
		actual = actual->sig;
		p--;
	}

	nodo_lista_lineas * nuevo = new nodo_lista_lineas;
	nuevo->lin = CrearLinea();
	nuevo->sig = actual;
	nuevo->ant = actual->ant;

	if(actual->ant == NULL){
		// Caso 2: era la primera linea; la nueva pasa a ser la primera.
		t->primera = nuevo;
	}else{
		// Caso 3: en el medio; el anterior apunta a la nueva.
		actual->ant->sig = nuevo;
	}
	actual->ant = nuevo;
	t->cant++;
	return true;
}

bool BorrarLinea(texto &t, Posicion p){
// Letra: op. 3 BorrarLinea (Tipo 2).
// Elimina la linea p (y sus palabras) y corre una posicion hacia atras
// a las lineas siguientes. Retorna false si p no existe en t.
	if(p < 1 || p > t->cant){
		return false;
	}

	// Busco el nodo de la posicion p (p - 1 saltos desde la primera).
	nodo_lista_lineas * aBorrar = t->primera;
	while(p > 1){
		aBorrar = aBorrar->sig;
		p--;
	}

	// Desengancho el nodo: el anterior y el siguiente se apuntan entre si.
	// Si no hay anterior era la primera; si no hay siguiente era la ultima
	// (si era la unica, pasan las dos cosas y el texto queda vacio).
	if(aBorrar->ant == NULL){
		t->primera = aBorrar->sig;
	}else{
		aBorrar->ant->sig = aBorrar->sig;
	}
	if(aBorrar->sig == NULL){
		t->ultima = aBorrar->ant;
	}else{
		aBorrar->sig->ant = aBorrar->ant;
	}

	// Libero la linea (con sus palabras) y despues el nodo.
	aBorrar->lin = DestruirLinea(aBorrar->lin);
	delete aBorrar;
	t->cant--;
	return true;
}

void BorrarTodo(texto &t){
// Letra: op. 4 BorrarTodo (Tipo 2).
// Elimina todas las lineas de t. Si t era vacio queda igual.
	// Borrar siempre la primera es O(1) por linea: no hay que recorrer.
	while(t->cant > 0){
		BorrarLinea(t, 1);
	}
}

linea LineaEnPosicion(texto t, Posicion p){
// Retorna la linea p de t. Pre: p existe en t.
	if(t == NULL || p < 1 || p > t->cant){
		return NULL;
	}
	nodo_lista_lineas * actual = t->primera;
	while(p > 1){
		actual = actual->sig;
		p--;
	}
	return actual->lin;
}

void ImprimirTexto(texto t){
// Letra: op. 6 ImprimirTexto (Tipo 1).
// Imprime cada linea como "n: palabras". Si t es vacio imprime "Texto vacio".
	if(t->cant == 0){
		cout << "Texto vacio" << endl;
		return;
	}
	nodo_lista_lineas * actual = t->primera;
	unsigned int n = 1;
	while(actual != NULL){
		cout << n << ":";
		if(CantPalabras(actual->lin) > 0){
			cout << " ";
			ImprimirLinea(actual->lin);
		}
		cout << endl;
		actual = actual->sig;
		n++;
	}
}

texto DestruirTexto(texto t){
// Destruye t y libera toda la memoria asociada. Retorna NULL.
	if(t != NULL){
		BorrarTodo(t);
		delete t;
	}
	return NULL;
}
