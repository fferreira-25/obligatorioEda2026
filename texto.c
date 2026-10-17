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
	// TODO: new nodo con lin = CrearLinea(), engancharlo despues de ultima.
	// Caso borde: texto vacio (primera == NULL).
}

bool InsertarLineaEnPosicion(texto &t, Posicion p){
// Letra: op. 2 InsertarLineaEnPosicion (Tipo 1).
	// TODO: validar 1 <= p <= cant + 1. Si p == cant + 1: InsertarLinea.
	// Si p == 1: insertar al principio. Si no: recorrer hasta la linea p e
	// insertar antes (actualizar los 4 punteros).
	return false;
}

bool BorrarLinea(texto &t, Posicion p){
// Letra: op. 3 BorrarLinea (Tipo 2).
	// TODO: casos borde: unica linea, primera, ultima, del medio.
	// DestruirLinea + delete del nodo. Actualizar primera/ultima/cant.
	return false;
}

void BorrarTodo(texto &t){
// Letra: op. 4 BorrarTodo (Tipo 2).
	// TODO
}

linea LineaEnPosicion(texto t, Posicion p){
// Retorna la linea p de t. Pre: p existe en t.
	// TODO: recorrer desde primera p-1 veces.
	return NULL;
}

void ImprimirTexto(texto t){
// Letra: op. 6 ImprimirTexto (Tipo 1).
	// TODO: si cant == 0 "Texto vacio". Si no, por cada linea:
	// cout << n << ":"; si tiene palabras cout << " " y ImprimirLinea; endl.
}

texto DestruirTexto(texto t){
// Destruye t y libera toda la memoria asociada. Retorna NULL.
	// TODO: BorrarTodo y delete t.
	return NULL;
}
