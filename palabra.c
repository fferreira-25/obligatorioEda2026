// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// palabra.c
// Modulo de implementacion de palabra.

#include "palabra.h"
#include <string.h>

struct nodo_palabra{
	Cadena palabra;
	nodo_palabra * sig;
};

palabra CrearPalabra(Cadena texto){
// Crea un nodo palabra con una COPIA de texto y sig = NULL.
	palabra p = new nodo_palabra;
	p->palabra = new char[strlen(texto) + 1];
	strcpy(p->palabra, texto);
	p->sig = NULL;
	return p;
}

Cadena ObtenerCadena(palabra p){
// Retorna la cadena almacenada en el nodo p (sin copiarla).
	if(p == NULL) return NULL;
	return p->palabra;
}

palabra ObtenerSiguientePalabra(palabra p){
// Retorna el siguiente nodo palabra.
	if(p == NULL) return NULL;
	return p->sig;
}

void AsignarSiguientePalabra(palabra p, palabra sig){
// Asigna sig como el siguiente nodo de p.
	if(p != NULL){
		p->sig = sig;
	}
}

Cadena ExtraerCadena(palabra &p){
// Extrae y retorna la cadena de texto de p sin liberarla, destruyendo el nodo.
// Permite "enganchar" y transferir la palabra a otra linea (desborde o compresion).
	if(p == NULL) return NULL;
	Cadena c = p->palabra;
	delete p;
	p = NULL;
	return c;
}

void DestruirPalabra(palabra &p){
// Libera la memoria de la cadena y del nodo p, dejando p = NULL.
	if(p != NULL){
		delete [] p->palabra;
		delete p;
		p = NULL;
	}
}
