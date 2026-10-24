// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// linea.c
// Modulo de implementacion de linea.

#include "linea.h"
#include <string.h>
#include <iostream>

using namespace std;

struct nodo_palabra{
	Cadena palabra;
	nodo_palabra * sig;
};

struct nodo_linea{
	nodo_palabra * primera;
	unsigned int cant;
};


linea CrearLinea(){
// Crea una linea vacia.
	linea l = new(nodo_linea);
	l->primera = NULL;
	l->cant = 0;
	return l;
}

unsigned int CantPalabras(linea l){
// Retorna la cantidad de palabras de l.
	if(l != NULL){
		return l->cant;
	}else{
		return 0;
	}
}

bool LineaLlena(linea l){
// Retorna true si l tiene MAX_CANT_PALABRAS_X_LINEA palabras.
	if(l != NULL && l->cant == MAX_CANT_PALABRAS_X_LINEA){
		return true;
	}else{
		return false;
	}
}

Cadena PalabraEnPosicion(linea l, Posicion p){
// Retorna la palabra de la posicion p de l (sin copiarla).
// Pre: 1 <= p <= CantPalabras(l).
	nodo_palabra * actual = l->primera;
	while(p > 1){
		actual = actual->sig;
		p--;
	}
	return actual->palabra;
}

void InsertarPalabra(linea &l, Posicion p, Cadena palabra){
// Letra: op. 8 InsertarPalabra (Tipo 1) - parte que ocurre dentro de la linea.
// Inserta una COPIA de palabra en la posicion p, corriendo una posicion
// hacia adelante a las palabras desde p. El TestDesborde a la linea siguiente
// lo resuelve el editor usando QuitarPalabra.
// Pre: 1 <= p <= CantPalabras(l) + 1 y !LineaLlena(l).
	nodo_palabra * nuevo = new nodo_palabra;
	nuevo->palabra = new char[strlen(palabra) + 1];
	strcpy(nuevo->palabra, palabra);
	nuevo->sig = NULL;

	if(p == 1){
		nuevo->sig = l->primera;
		l->primera = nuevo;
	}else{
		nodo_palabra * ant = l->primera;
		while(p > 2 && ant->sig != NULL){
			ant = ant->sig;
			p--;
		}
		nuevo->sig = ant->sig;
		ant->sig = nuevo;
	}
	l->cant++;
}

Cadena QuitarPalabra(linea &l, Posicion p){
// Obtengo la palabra "sobrante"

	//Validaciones
	if(l == NULL || l->primera == NULL || p < 1 || p > l->cant){
		return NULL;
	}

	nodo_palabra * aBorrar = NULL;

	// es la primer palabra de la linea?
	if(p == 1){
		aBorrar = l->primera;
		l->primera = l->primera->sig;
	}else{
		// si no es la primera, recorro hasta la anterior a la que voy a suplantar (p-1)
		nodo_palabra * ant = l->primera;
		while(p > 2 && ant->sig != NULL){
			ant = ant->sig;
			p--;
		}

		// la siguiente va a ser la que voy a borrar
		aBorrar = ant->sig;
		// la siguiente de la que voy a borra va a ser la nueva siguiente.
		ant->sig = aBorrar->sig;
	}

	// Me quedo con la palabra para devolverla como sobrante y que se pueda manipular
	Cadena palabraRetorno = aBorrar->palabra;
	delete aBorrar;
	l->cant--;
	return palabraRetorno;
}

void BorrarPalabra(linea &l, Posicion p){
// Letra: op. 9 BorrarPalabra (Tipo 1).
// Pre: 1 <= p <= CantPalabras(l).
	Cadena palabra = QuitarPalabra(l, p);
	if(palabra != NULL){
		delete [] palabra;
	}
}

void BorrarOcurrenciasPalabraEnLinea(linea &l, Cadena palabra){
// Letra: op. 10 BorrarOcurrenciasPalabraEnLinea y op. 5 (Tipo 1).
	if(l == NULL || l->primera == NULL) return;

	nodo_palabra * actual = l->primera;
	nodo_palabra * ant = NULL;

	while(actual != NULL){
		if(strcasecmp(actual->palabra, palabra) == 0){
			nodo_palabra * aBorrar = actual;
			if(ant == NULL){
				l->primera = actual->sig;
				actual = l->primera;
			}else{
				ant->sig = actual->sig;
				actual = ant->sig;
			}
			delete [] aBorrar->palabra;
			delete aBorrar;
			l->cant--;
		}else{
			ant = actual;
			actual = actual->sig;
		}
	}
}

void ImprimirLinea(linea l){
// Letra: op. 11 ImprimirLinea y op. 6 ImprimirTexto (Tipo 1).
	if(l != NULL){
		nodo_palabra * actual = l->primera;
		while(actual != NULL){
			cout << actual->palabra;
			if(actual->sig != NULL){
				cout << " ";
			}
			actual = actual->sig;
		}
	}
}

linea DestruirLinea(linea l){
// Destruye l y libera la memoria de sus palabras. Retorna NULL.
	if(l != NULL){
		nodo_palabra * actual = l->primera;
		while(actual != NULL){
			nodo_palabra * aBorrar = actual;
			actual = actual->sig;
			delete [] aBorrar->palabra;
			delete aBorrar;
		}
		delete l;
	}
	return NULL;
}
