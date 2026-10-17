#ifndef ULTIMAS_H
#define ULTIMAS_H

// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// ultimas.h
// Modulo de especificacion de ultimas palabras ingresadas al texto.
// Representacion: arreglo circular de MAX_CANT_ULTIMAS_PALABRAS cadenas,
// asi registrar es O(1) (sobrecarga constante sobre la op. 8).
//
// Convencion de nombres: las operaciones llevan el MISMO nombre que en la
// letra. No chocan con las de editor.h porque C++ permite sobrecargar
// funciones con parametros distintos (aca reciben linea/texto/etc., no editor).

#include "definiciones.h"

typedef struct nodo_ultimas * ultimas;


ultimas CrearUltimas();
// Crea la estructura sin palabras registradas.

void RegistrarPalabra(ultimas &u, Cadena palabra);
// Letra: op. 16 (Opcional) - se llama desde la op. 8 InsertarPalabra.
// Registra una COPIA de palabra como la ultima ingresada; si ya habia
// MAX_CANT_ULTIMAS_PALABRAS descarta (libera) la mas antigua. O(1).

void ImprimirUltimasPalabras(ultimas u);
// Letra: op. 16 ImprimirUltimasPalabras (Opcional).
// Imprime de la mas reciente a la mas antigua, una por renglon.
// Si nunca se registro ninguna imprime "No se ingresaron palabras".

ultimas DestruirUltimas(ultimas u);
// Destruye u y libera la memoria asociada. Retorna NULL.

#endif
