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
	// Si el arreglo esta lleno, en prox esta la mas antigua: la libero.
	if(u->cant == MAX_CANT_ULTIMAS_PALABRAS){
		delete [] u->palabras[u->prox];
	}else{
		u->cant++;
	}
	// Guardo una COPIA (el main pisa la cadena en el proximo comando).
	u->palabras[u->prox] = new char[strlen(palabra) + 1];
	strcpy(u->palabras[u->prox], palabra);
	// Avanzo en circulo: despues del ultimo indice vuelve al 0.
	u->prox = (u->prox + 1) % MAX_CANT_ULTIMAS_PALABRAS;
}

void ImprimirUltimasPalabras(ultimas u){
// Letra: op. 16 ImprimirUltimasPalabras (Opcional).
// Imprime de la mas reciente a la mas antigua, una por renglon.
	if(u->cant == 0){
		cout << "No se ingresaron palabras" << endl;
		return;
	}
	// La mas reciente esta una posicion antes de prox.
	unsigned int i = u->prox;
	unsigned int faltan = u->cant;
	while(faltan > 0){
		// Retrocedo en circulo: sumo MAX antes de restar para no bajar de 0.
		i = (i + MAX_CANT_ULTIMAS_PALABRAS - 1) % MAX_CANT_ULTIMAS_PALABRAS;
		cout << u->palabras[i] << endl;
		faltan--;
	}
}

ultimas DestruirUltimas(ultimas u){
// Destruye u y libera la memoria asociada. Retorna NULL.
	if(u != NULL){
		// Las cant palabras registradas estan en las cant posiciones anteriores a prox.
		unsigned int i = u->prox;
		unsigned int faltan = u->cant;
		while(faltan > 0){
			i = (i + MAX_CANT_ULTIMAS_PALABRAS - 1) % MAX_CANT_ULTIMAS_PALABRAS;
			delete [] u->palabras[i];
			faltan--;
		}
		delete u;
	}
	return NULL;
}
