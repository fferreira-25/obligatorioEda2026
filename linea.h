#ifndef LINEA_H
#define LINEA_H

// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// linea.h
// Modulo de especificacion de linea.
// Una linea tiene entre 0 y MAX_CANT_PALABRAS_X_LINEA palabras en
// posiciones consecutivas desde la 1. Las palabras se guardan tal cual
// se ingresan y se comparan ignorando mayusculas (strcasecmp).
//
// Convencion de nombres: las operaciones llevan el MISMO nombre que en la
// letra. No chocan con las de editor.h porque C++ permite sobrecargar
// funciones con parametros distintos (aca reciben linea/texto/etc., no editor).

#include "definiciones.h"

typedef struct nodo_linea * linea;


linea CrearLinea();
// Crea una linea vacia.

unsigned int CantPalabras(linea l);
// Retorna la cantidad de palabras de l (0 si es vacia).

bool LineaLlena(linea l);
// Retorna true si l tiene MAX_CANT_PALABRAS_X_LINEA palabras.

Cadena PalabraEnPosicion(linea l, Posicion p);
// Retorna la palabra de la posicion p de l (sin copiarla).
// Pre: 1 <= p <= CantPalabras(l).

void InsertarPalabra(linea &l, Posicion p, Cadena palabra);
// Letra: op. 8 InsertarPalabra (Tipo 1) - parte que ocurre dentro de la linea.
// Inserta una COPIA de palabra en la posicion p, corriendo una posicion
// hacia adelante a las palabras desde p. El desborde a la linea siguiente
// lo resuelve el editor usando QuitarPalabra.
// Pre: 1 <= p <= CantPalabras(l) + 1 y !LineaLlena(l).

Cadena QuitarPalabra(linea &l, Posicion p);
// Letra: op. 8 InsertarPalabra (desborde) y op. 7 ComprimirTexto.
// Quita la palabra de la posicion p y la retorna SIN liberarla, corriendo
// las posteriores hacia atras. Quien llama la libera (delete []) o la reubica.
// Pre: 1 <= p <= CantPalabras(l).

void BorrarPalabra(linea &l, Posicion p);
// Letra: op. 9 BorrarPalabra (Tipo 1).
// Borra la palabra de la posicion p (libera su memoria) y corre las
// posteriores hacia atras.
// Pre: 1 <= p <= CantPalabras(l).

void BorrarOcurrenciasPalabraEnLinea(linea &l, Cadena palabra);
// Letra: op. 10 BorrarOcurrenciasPalabraEnLinea (Tipo 1) y op. 5 (Tipo 1).
// Borra todas las ocurrencias de palabra en l (ignorando mayusculas).
// Si no esta, l queda igual.

void ImprimirLinea(linea l);
// Letra: op. 11 ImprimirLinea y op. 6 ImprimirTexto (Tipo 1).
// Imprime las palabras separadas por un espacio, SIN numero de linea y
// SIN salto de linea. Si l es vacia no imprime nada.

linea DestruirLinea(linea l);
// Destruye l y libera la memoria de sus palabras. Retorna NULL.

#endif
