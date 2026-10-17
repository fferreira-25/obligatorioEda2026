#ifndef DEFINICIONES_H
#define DEFINICIONES_H

// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// definiciones.h
// Modulo para definiciones generales del proyecto como constantes, etc.

enum _retorno{
	OK, ERROR, NO_IMPLEMENTADA
};

typedef enum _retorno TipoRetorno;

typedef char* Cadena;

typedef unsigned int Posicion;


#define MAX_COMANDO 75
#define MAX_CANT_PALABRAS_X_LINEA 3
#define MAX_CANT_ULTIMAS_PALABRAS 3

#endif

