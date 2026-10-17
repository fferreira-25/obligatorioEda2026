// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// diccionario.c
// Modulo de implementacion de diccionario (ABB de cadenas).

#include "diccionario.h"
#include <string.h>
#include <iostream>

using namespace std;

struct nodo_diccionario{
	Cadena palabra;
	diccionario izq; // palabras menores (strcasecmp < 0)
	diccionario der; // palabras mayores
};


diccionario CrearDiccionario(){
// Crea un diccionario vacio.
	return NULL;
}

bool PerteneceDiccionario(diccionario d, Cadena palabra){
// Retorna true si palabra esta en d (ignorando mayusculas).
	// TODO: recursivo. PB: d == NULL -> false. PI: strcasecmp y bajar.
	return false;
}

diccionario IngresarPalabraDiccionario(diccionario d, Cadena palabra){
// Letra: op. 12 IngresarPalabraDiccionario (Tipo 1). O(log n) promedio.
// Pre: !PerteneceDiccionario(d, palabra).
	// TODO: PB: d == NULL -> new nodo con la copia, izq = der = NULL.
	// PI: d->izq = ...(d->izq) o d->der = ...(d->der); return d.
	return d;
}

diccionario BorrarPalabraDiccionario(diccionario d, Cadena palabra){
// Letra: op. 13 BorrarPalabraDiccionario (Tipo 2).
// Pre: PerteneceDiccionario(d, palabra).
	// TODO: al encontrar el nodo: hoja / un hijo / dos hijos (reemplazar por
	// el maximo del subarbol izquierdo y eliminar ese).
	return d;
}

void ImprimirDiccionario(diccionario d){
// Letra: op. 14 ImprimirDiccionario (Tipo 1). O(n) peor caso.
	// TODO: si d == NULL "Diccionario vacio"; si no, in-order (izq, nodo, der)
	// con una auxiliar recursiva.
}

diccionario DestruirDiccionario(diccionario d){
// Destruye d y libera la memoria asociada. Retorna NULL.
	// TODO: post-order: destruir izq, der, delete [] palabra, delete d.
	return NULL;
}
