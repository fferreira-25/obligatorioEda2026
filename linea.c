// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// linea.c
// Modulo de implementacion de linea.

#include "linea.h"
#include <string.h>
#include <iostream>

using namespace std;

struct nodo_linea{
	Cadena palabras[MAX_CANT_PALABRAS_X_LINEA]; // palabras[0] es la posicion 1
	unsigned int cant;
};


linea CrearLinea(){
// Crea una linea vacia.
	linea l = new(nodo_linea);
	l->cant = 0;
	return l;
}

unsigned int CantPalabras(linea l){
// Retorna la cantidad de palabras de l.
	return l->cant;
}

bool LineaLlena(linea l){
// Retorna true si l tiene MAX_CANT_PALABRAS_X_LINEA palabras.
	return (l->cant == MAX_CANT_PALABRAS_X_LINEA);
}

Cadena PalabraEnPosicion(linea l, Posicion p){
// Retorna la palabra de la posicion p de l (sin copiarla).
// Pre: 1 <= p <= CantPalabras(l).
	return l->palabras[p - 1];
}

void InsertarPalabra(linea &l, Posicion p, Cadena palabra){
// Letra: op. 8 InsertarPalabra (Tipo 1) - parte dentro de la linea.
// Pre: 1 <= p <= CantPalabras(l) + 1 y !LineaLlena(l).
	// TODO: copia = new char[strlen(palabra) + 1]; strcpy(copia, palabra);
	// correr palabras[p-1 .. cant-1] un lugar a la derecha; guardar; cant++.
}

Cadena QuitarPalabra(linea &l, Posicion p){
// Letra: op. 8 (desborde) y op. 7 ComprimirTexto.
// Pre: 1 <= p <= CantPalabras(l).
	// TODO: guardar palabras[p-1], correr las posteriores a la izquierda,
	// cant--, retornar la guardada.
	return NULL;
}

void BorrarPalabra(linea &l, Posicion p){
// Letra: op. 9 BorrarPalabra (Tipo 1).
// Pre: 1 <= p <= CantPalabras(l).
	// TODO: delete [] QuitarPalabra(l, p);
}

void BorrarOcurrenciasPalabraEnLinea(linea &l, Cadena palabra){
// Letra: op. 10 BorrarOcurrenciasPalabraEnLinea y op. 5 (Tipo 1).
	// TODO: recorrer con strcasecmp. Al borrar NO avanzar la posicion
	// (la siguiente palabra se corrio a ese lugar).
}

void ImprimirLinea(linea l){
// Letra: op. 11 ImprimirLinea y op. 6 ImprimirTexto (Tipo 1).
	// TODO: formato exacto "Palabra1 Palabra2".
}

linea DestruirLinea(linea l){
// Destruye l y libera la memoria de sus palabras. Retorna NULL.
	// TODO: delete [] de cada palabra y delete l.
	return NULL;
}
