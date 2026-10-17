#ifndef DICCIONARIO_H
#define DICCIONARIO_H

// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// diccionario.h
// Modulo de especificacion de diccionario.
// Conjunto de palabras sin repetidos (ignorando mayusculas).
// Representacion: arbol binario de busqueda (ABB) ordenado con strcasecmp:
// ingresar es O(log n) promedio y el recorrido in-order imprime ordenado
// en O(n), como pide la letra.
//
// Convencion de nombres: las operaciones llevan el MISMO nombre que en la
// letra. No chocan con las de editor.h porque C++ permite sobrecargar
// funciones con parametros distintos (aca reciben linea/texto/etc., no editor).

#include "definiciones.h"

typedef struct nodo_diccionario * diccionario;


diccionario CrearDiccionario();
// Crea un diccionario vacio.

bool PerteneceDiccionario(diccionario d, Cadena palabra);
// Retorna true si palabra esta en d (ignorando mayusculas). O(log n) promedio.
// Usada por las ops. 12, 13 (validacion) y 15 ImprimirTextoIncorrecto.

diccionario IngresarPalabraDiccionario(diccionario d, Cadena palabra);
// Letra: op. 12 IngresarPalabraDiccionario (Tipo 1). O(log n) promedio.
// Inserta una COPIA de palabra y retorna el diccionario resultante.
// Pre: !PerteneceDiccionario(d, palabra).

diccionario BorrarPalabraDiccionario(diccionario d, Cadena palabra);
// Letra: op. 13 BorrarPalabraDiccionario (Tipo 2).
// Elimina palabra (liberando su memoria) y retorna el resultante.
// Pre: PerteneceDiccionario(d, palabra).

void ImprimirDiccionario(diccionario d);
// Letra: op. 14 ImprimirDiccionario (Tipo 1). O(n) peor caso.
// Imprime las palabras ordenadas de menor a mayor, una por renglon.
// Si d es vacio imprime "Diccionario vacio".

diccionario DestruirDiccionario(diccionario d);
// Destruye d y libera la memoria asociada. Retorna NULL.

#endif
