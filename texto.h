#ifndef TEXTO_H
#define TEXTO_H

// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// texto.h
// Modulo de especificacion de texto.
// Un texto es una secuencia de 0 o mas lineas numeradas desde 1.
// Representacion: lista doblemente encadenada de lineas con punteros a la
// primera y a la ultima, y contador (InsertarLinea es O(1) peor caso).
//
// Convencion de nombres: las operaciones llevan el MISMO nombre que en la
// letra. No chocan con las de editor.h porque C++ permite sobrecargar
// funciones con parametros distintos (aca reciben linea/texto/etc., no editor).

#include "definiciones.h"
#include "linea.h"

typedef struct nodo_texto * texto;


texto CrearTexto();
// Crea un texto vacio (0 lineas).

unsigned int CantLineas(texto t);
// Retorna la cantidad de lineas de t (0 si es vacio).
// Una posicion p existe en t si 1 <= p <= CantLineas(t).

void InsertarLinea(texto &t);
// Letra: op. 1 InsertarLinea (Tipo 1).
// Agrega una linea vacia al final de t. O(1) peor caso.

bool InsertarLineaEnPosicion(texto &t, Posicion p);
// Letra: op. 2 InsertarLineaEnPosicion (Tipo 1).
// Inserta una linea vacia en la posicion p, corriendo las siguientes.
// Retorna false (sin modificar t) si p no es valida: 1 <= p <= cant + 1.

bool BorrarLinea(texto &t, Posicion p);
// Letra: op. 3 BorrarLinea (Tipo 2).
// Elimina la linea p (y sus palabras), corriendo las siguientes.
// Retorna false si p no existe en t.

void BorrarTodo(texto &t);
// Letra: op. 4 BorrarTodo (Tipo 2).
// Elimina todas las lineas de t. Si t era vacio queda igual.

linea LineaEnPosicion(texto t, Posicion p);
// Retorna la linea p de t (sin copiarla) para operar sobre ella con el
// modulo linea (ops. 5, 8, 9, 10, 11, 15).
// Pre: p existe en t.

void ImprimirTexto(texto t);
// Letra: op. 6 ImprimirTexto (Tipo 1).
// Imprime cada linea como "n: palabras". Si t es vacio imprime "Texto vacio".

texto DestruirTexto(texto t);
// Destruye t y libera toda la memoria asociada. Retorna NULL.

#endif
