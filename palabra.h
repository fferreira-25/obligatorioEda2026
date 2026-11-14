#ifndef PALABRA_H
#define PALABRA_H

// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// palabra.h
// Modulo de especificacion de palabra (nodo de lista de palabras).

#include "definiciones.h"

typedef struct nodo_palabra * palabra;

palabra CrearPalabra(Cadena texto);
// Crea un nodo palabra con una COPIA de texto y sig = NULL.

Cadena ObtenerCadena(palabra p);
// Retorna la cadena almacenada en el nodo p (sin copiarla).
// Pre: p != NULL.

palabra ObtenerSiguientePalabra(palabra p);
// Retorna el siguiente nodo palabra.
// Pre: p != NULL.

void AsignarSiguientePalabra(palabra p, palabra sig);
// Asigna sig como el siguiente nodo de p.
// Pre: p != NULL.

Cadena ExtraerCadena(palabra &p);
// Extrae y retorna la cadena de texto almacenada en p sin liberarla,
// destruyendo unicamente la estructura del nodo y dejando p = NULL.
// Se utiliza en QuitarPalabra (desborde al insertar y comprimir texto) para
// poder "enganchar" o reubicar la palabra en otra linea sin destruirla
// ni duplicar memoria innecesariamente. Quien la recibe es responsable de
// su posterior liberacion.
// Pre: p != NULL.

void DestruirPalabra(palabra &p);
// Libera la memoria de la cadena y del nodo p, dejando p = NULL.

#endif
