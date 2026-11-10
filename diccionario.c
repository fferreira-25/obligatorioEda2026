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
// Busqueda en ABB: O(log n) promedio.
// Pre:  -
// Pos:  retorna true si palabra pertenece a d, false en caso contrario.
	if(d == NULL){                                 // PB: arbol vacio -> no esta
		return false;
	}
	int cmp = strcasecmp(palabra, d->palabra);     // ignora mayus/minus
	if(cmp == 0){                                  // la encontre
		return true;
	}else if(cmp < 0){                             // es menor -> bajo a izq
		return PerteneceDiccionario(d->izq, palabra);
	}else{                                         // es mayor -> bajo a der
		return PerteneceDiccionario(d->der, palabra);
	}
}

diccionario IngresarPalabraDiccionario(diccionario d, Cadena palabra){
// Letra: op. 12 IngresarPalabraDiccionario (Tipo 1). O(log n) promedio.
// Inserta una COPIA de palabra manteniendo el orden del ABB.
// Pre:  !PerteneceDiccionario(d, palabra).
// Pos:  retorna el diccionario con palabra agregada.
	if(d == NULL){                                 // PB: lugar libre -> nodo nuevo
		diccionario nuevo = new(nodo_diccionario);
		nuevo->palabra = new char[strlen(palabra) + 1];
		strcpy(nuevo->palabra, palabra);           // guardo la palabra tal cual
		nuevo->izq = NULL;
		nuevo->der = NULL;
		return nuevo;
	}
	if(strcasecmp(palabra, d->palabra) < 0){       // PI: menor -> sigue por izq
		d->izq = IngresarPalabraDiccionario(d->izq, palabra);
	}else{                                         // mayor -> sigue por der
		d->der = IngresarPalabraDiccionario(d->der, palabra);
	}
	return d;
}

diccionario BorrarPalabraDiccionario(diccionario d, Cadena palabra){
// Letra: op. 13 BorrarPalabraDiccionario (Tipo 2).
// Pre: PerteneceDiccionario(d, palabra).
	// TODO: al encontrar el nodo: hoja / un hijo / dos hijos (reemplazar por
	// el maximo del subarbol izquierdo y eliminar ese).
	return d;
}

static void imprimirEnOrden(diccionario d){
// Auxiliar: recorrido in-order (izq, nodo, der) -> imprime ordenado.
	if(d != NULL){
		imprimirEnOrden(d->izq);
		cout << d->palabra << endl;
		imprimirEnOrden(d->der);
	}
}

void ImprimirDiccionario(diccionario d){
// Letra: op. 14 ImprimirDiccionario (Tipo 1). O(n) peor caso.
// Imprime las palabras de menor a mayor, una por renglon.
// Si d es vacio imprime "Diccionario vacio".
	if(d == NULL){
		cout << "Diccionario vacio" << endl;
	}else{
		imprimirEnOrden(d);                         // in-order = alfabetico
	}
}

diccionario DestruirDiccionario(diccionario d){
// Destruye d y libera la memoria asociada. Retorna NULL.
	// TODO: post-order: destruir izq, der, delete [] palabra, delete d.
	return NULL;
}
