// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// linea.c
// Modulo de implementacion de linea.

#include "linea.h"
#include "palabra.h"
#include <string.h>
#include <iostream>

using namespace std;

struct nodo_linea{
	palabra primera;
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
	palabra actual = l->primera;
	while(p > 1){
		actual = ObtenerSiguientePalabra(actual);
		p--;
	}
	return ObtenerCadena(actual);
}

void InsertarPalabra(linea &l, Posicion p, Cadena palabraAIngresar){
// Letra: op. 8 InsertarPalabra (Tipo 1) - parte que ocurre dentro de la linea.
// Inserta una COPIA de palabra en la posicion p, corriendo una posicion
// hacia adelante a las palabras desde p. El TestDesborde a la linea siguiente
// lo resuelve el editor usando QuitarPalabra.
// Pre: 1 <= p <= CantPalabras(l) + 1 y !LineaLlena(l).
	palabra nuevo = CrearPalabra(palabraAIngresar);

	if(p == 1){
		AsignarSiguientePalabra(nuevo, l->primera);
		l->primera = nuevo;
	}else{
		palabra ant = l->primera;
		while(p > 2 && ObtenerSiguientePalabra(ant) != NULL){
			ant = ObtenerSiguientePalabra(ant);
			p--;
		}
		AsignarSiguientePalabra(nuevo, ObtenerSiguientePalabra(ant));
		AsignarSiguientePalabra(ant, nuevo);
	}
	l->cant++;
}

Cadena QuitarPalabra(linea &l, Posicion p){
// Obtengo la palabra "sobrante"

	//Validaciones
	if(l == NULL || l->primera == NULL || p < 1 || p > l->cant){
		return NULL;
	}

	palabra aBorrar = NULL;

	// es la primer palabra de la linea?
	if(p == 1){
		aBorrar = l->primera;
		l->primera = ObtenerSiguientePalabra(l->primera);
	}else{
		// si no es la primera, recorro hasta la anterior a la que voy a suplantar (p-1)
		palabra ant = l->primera;
		while(p > 2 && ObtenerSiguientePalabra(ant) != NULL){
			ant = ObtenerSiguientePalabra(ant);
			p--;
		}

		// la siguiente va a ser la que voy a borrar
		aBorrar = ObtenerSiguientePalabra(ant);
		// la siguiente de la que voy a borrar va a ser la nueva siguiente.
		AsignarSiguientePalabra(ant, ObtenerSiguientePalabra(aBorrar));
	}

	// Extraigo la palabra sobrante para reengancharla en otra linea (desborde o compresion)
	Cadena palabraRetorno = ExtraerCadena(aBorrar);
	l->cant--;
	return palabraRetorno;
}

void BorrarPalabra(linea &l, Posicion p){
// Letra: op. 9 BorrarPalabra (Tipo 1).
// Pre: 1 <= p <= CantPalabras(l).
	Cadena cad = QuitarPalabra(l, p);
	if(cad != NULL){
		delete [] cad;
	}
}

void BorrarOcurrenciasPalabraEnLinea(linea &l, Cadena palabraABorrar){
// Letra: op. 10 BorrarOcurrenciasPalabraEnLinea y op. 5 (Tipo 1).
	if(l == NULL || l->primera == NULL) return;

	palabra actual = l->primera;
	palabra ant = NULL;

	while(actual != NULL){
		if(strcasecmp(ObtenerCadena(actual), palabraABorrar) == 0){
			palabra aBorrar = actual;
			if(ant == NULL){
				l->primera = ObtenerSiguientePalabra(actual);
				actual = l->primera;
			}else{
				AsignarSiguientePalabra(ant, ObtenerSiguientePalabra(actual));
				actual = ObtenerSiguientePalabra(ant);
			}
			DestruirPalabra(aBorrar);
			l->cant--;
		}else{
			ant = actual;
			actual = ObtenerSiguientePalabra(actual);
		}
	}
}

void ImprimirLinea(linea l){
// Letra: op. 11 ImprimirLinea y op. 6 ImprimirTexto (Tipo 1).
	if(l != NULL){
		palabra actual = l->primera;
		while(actual != NULL){
			cout << ObtenerCadena(actual);
			if(ObtenerSiguientePalabra(actual) != NULL){
				cout << " ";
			}
			actual = ObtenerSiguientePalabra(actual);
		}
	}
}

linea DestruirLinea(linea l){
// Destruye l y libera la memoria de sus palabras. Retorna NULL.
	if(l != NULL){
		palabra actual = l->primera;
		while(actual != NULL){
			palabra aBorrar = actual;
			actual = ObtenerSiguientePalabra(actual);
			DestruirPalabra(aBorrar);
		}
		delete l;
	}
	return NULL;
}
