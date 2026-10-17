#ifndef EDITOR_H
#define EDITOR_H

// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// editor.h
// Modulo de especificacion de editor.

#include "definiciones.h"

typedef struct nodo_editor * editor;


// Operaciones Relativas a las lineas (al documento)

editor CrearEditor();
// Crea la estructura editor.

TipoRetorno InsertarLinea(editor & e);
// Inserta una nueva línea vacía al final del texto.
// Este requerimiento debe ser resuelto en O(1) peor caso.
// Ver más detalles en la letra del obligatorio.

TipoRetorno InsertarLineaEnPosicion(editor & e, Posicion posicionLinea);
// Inserta una nueva línea vacía en la posición indicada.
// Ver más detalles en la letra del obligatorio.

TipoRetorno BorrarLinea(editor & e, Posicion posicionLinea);
// Borra la línea en la posición indicada.
// Ver más detalles en la letra del obligatorio.

TipoRetorno BorrarTodo(editor & e);
// Borra todas las líneas del texto.
// Ver más detalles en la letra del obligatorio.

TipoRetorno BorrarOcurrenciasPalabraEnTexto(editor & e, Cadena palabraABorrar);
// Borra todas las ocurrencias de una palabra en el texto.
// Ver más detalles en la letra del obligatorio.

TipoRetorno ImprimirTexto(editor & e);
// Imprime el texto por pantalla.
// Ver más detalles en la letra del obligatorio.

TipoRetorno ComprimirTexto(editor & e);
// Comprime las palabras del texto. Para implementar esta operación no debe generarse un nuevo documento.
// Ver más detalles en la letra del obligatorio.

TipoRetorno InsertarPalabra(editor & e, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar);
// Inserta una palabra en una línea.
// Ver más detalles en la letra del obligatorio.

TipoRetorno BorrarPalabra(editor & e, Posicion posicionLinea, Posicion posicionPalabra);
// Borra la palabra en la posición indicada.
// Ver más detalles en la letra del obligatorio.

TipoRetorno BorrarOcurrenciasPalabraEnLinea(editor & e, Posicion posicionLinea, Cadena palabraABorrar);
// Borra todas las ocurrencias de una palabra en la línea indicada.
// Ver más detalles en la letra del obligatorio.

TipoRetorno ImprimirLinea(editor & e, Posicion posicionLinea);
// Imprime la línea por pantalla.
// Ver más detalles en la letra del obligatorio.

TipoRetorno IngresarPalabraDiccionario(editor & e, Cadena palabraAIngresar);
// Agrega una palabra al diccionario.
// Esta operación debe realizarse en a lo sumo O(log n) promedio.
// Ver más detalles en la letra del obligatorio.

TipoRetorno BorrarPalabraDiccionario(editor & e, Cadena palabraABorrar);
// Borra una palabra del diccionario.
// Ver más detalles en la letra del obligatorio.

TipoRetorno ImprimirDiccionario(editor & e);
// Muestra las palabras del diccionario alfabéticamente.
// Esta operación debe realizarse en O(n) peor caso.
// Ver más detalles en la letra del obligatorio.

TipoRetorno ImprimirTextoIncorrecto(editor & e);
// Muestra las palabras del texto que no se encuentran en el diccionario.
// Ver más detalles en la letra del obligatorio.

TipoRetorno ImprimirUltimasPalabras(editor & e); 
// Imprime las últimas MAX_CANT_ULTIMAS_PALABRAS palabras ingresadas al texto.
// Ver más detalles en la letra del obligatorio.

TipoRetorno DestruirEditor(editor & e);
// Destruye la estructura editor y libera la memoria asociada.

#endif

