// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// ultimas.c
// Modulo de implementacion de ultimas palabras (arreglo circular).

#include "ultimas.h"
#include <string.h>
#include <iostream>

using namespace std;

struct nodo_ultimas{
	Cadena palabras[MAX_CANT_ULTIMAS_PALABRAS];
	unsigned int prox; // indice donde se escribe la proxima (0..MAX-1)
	unsigned int cant; // cuantas hay registradas (0..MAX)
};


ultimas CrearUltimas(){
// Crea la estructura sin palabras registradas.
	ultimas u = new(nodo_ultimas);
	u->prox = 0;
	u->cant = 0;
	return u;
}

void RegistrarPalabra(ultimas &u, Cadena palabra){
// Letra: op. 16 (Opcional) - se llama desde la op. 8. O(1).
	// TODO: si cant == MAX, delete [] palabras[prox]. Guardar la copia en
	// palabras[prox]; prox = (prox + 1) % MAX; si cant < MAX, cant++.
}

void ImprimirUltimasPalabras(ultimas u){
// Letra: op. 16 ImprimirUltimasPalabras (Opcional).
	// TODO: si cant == 0 "No se ingresaron palabras". La mas reciente esta
	// en (prox - 1 + MAX) % MAX; retroceder cant veces.
}

ultimas DestruirUltimas(ultimas u){
// Destruye u y libera la memoria asociada. Retorna NULL.
	// TODO: delete [] de las cant palabras registradas y delete u.
	return NULL;
}
