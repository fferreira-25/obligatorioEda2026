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

static void liberarNodo(diccionario n){
// Auxiliar: libera la palabra y el nodo n (no toca sus hijos).
	delete [] n->palabra;
	delete n;
}

static diccionario maximoSubarbol(diccionario d){
// Auxiliar: retorna el nodo con la palabra maxima del subarbol d.
// Pre: d != NULL.
	while(d->der != NULL){
		d = d->der;
	}
	return d;
}

diccionario BorrarPalabraDiccionario(diccionario d, Cadena palabra){
// Letra: op. 13 BorrarPalabraDiccionario (Tipo 2).
// Elimina la palabra (liberando su memoria) y retorna el diccionario resultante.
// Pre:  PerteneceDiccionario(d, palabra).
// Pos:  retorna d sin la palabra; conserva el orden del ABB.
	if(d == NULL){                                 // no existe: nada que borrar
		return NULL;
	}
	int cmp = strcasecmp(palabra, d->palabra);

	if(cmp < 0){                                   // la palabra esta a la izquierda
		d->izq = BorrarPalabraDiccionario(d->izq, palabra);
		return d;
	}
	if(cmp > 0){                                   // la palabra esta a la derecha
		d->der = BorrarPalabraDiccionario(d->der, palabra);
		return d;
	}

	// cmp == 0: este es el nodo a borrar. Casos:
	if(d->izq == NULL){                            // 1) sin hijo izq: lo reemplaza el der (o NULL)
		diccionario sub = d->der;
		liberarNodo(d);
		return sub;
	}
	if(d->der == NULL){                            // 2) sin hijo der: lo reemplaza el izq
		diccionario sub = d->izq;
		liberarNodo(d);
		return sub;
	}

	// 3) dos hijos: reemplazo la palabra por el maximo del subarbol izquierdo
	//    y elimino ese maximo (que no tiene hijo derecho).
	diccionario maxIzq = maximoSubarbol(d->izq);

	Cadena copia = new char[strlen(maxIzq->palabra) + 1];
	strcpy(copia, maxIzq->palabra);

	delete [] d->palabra;                          // libero la palabra vieja
	d->palabra = copia;                            // queda la del maximo
	d->izq = BorrarPalabraDiccionario(d->izq, maxIzq->palabra);
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
