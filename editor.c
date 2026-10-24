// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// editor.c
// Modulo de implementacion de editor.
// El editor solo usa las operaciones de texto, linea, diccionario y
// ultimas; nunca accede a su representacion.

#include "editor.h"
#include "texto.h"
#include "linea.h"
#include "diccionario.h"
#include "ultimas.h"
#include <string.h>
#include <iostream>

using namespace std;

struct nodo_editor{
	texto t;        // las lineas del documento
	diccionario d;  // diccionario ortografico (ABB)
	ultimas u;      // ultimas palabras ingresadas al texto (op. 16)
};


editor CrearEditor(){
// Crea la estructura editor.
	editor e = new(nodo_editor);
	e->t = CrearTexto();
	e->d = CrearDiccionario();
	e->u = CrearUltimas();
	return e;
}

// ---------------------------------------------------------------
// OPERACIONES RELATIVAS A LAS LINEAS (AL DOCUMENTO)
// ---------------------------------------------------------------

TipoRetorno InsertarLinea(editor & e){
// Letra: op. 1 (Tipo 1). Inserta una linea vacia al final. O(1) peor caso.
// Siempre retorna OK.
	// TODO: InsertarLinea(e->t); return OK;
	return NO_IMPLEMENTADA;
}

TipoRetorno InsertarLineaEnPosicion(editor & e, Posicion posicionLinea){
// Letra: op. 2 (Tipo 1). Inserta una linea vacia en la posicion indicada.
// ERROR si la posicion no es valida (1..cant+1).
	// TODO: return InsertarLineaEnPosicion(e->t, posicionLinea) ? OK : ERROR;
	return NO_IMPLEMENTADA;
}

TipoRetorno BorrarLinea(editor & e, Posicion posicionLinea){
// Letra: op. 3 (Tipo 2). Borra la linea indicada. ERROR si no existe.
	// TODO: return BorrarLinea(e->t, posicionLinea) ? OK : ERROR;
	return NO_IMPLEMENTADA;
}

TipoRetorno BorrarTodo(editor & e){
// Letra: op. 4 (Tipo 2). Borra todas las lineas. Siempre OK.
	// TODO: BorrarTodo(e->t); return OK;
	return NO_IMPLEMENTADA;
}

TipoRetorno BorrarOcurrenciasPalabraEnTexto(editor & e, Cadena palabraABorrar){
// Letra: op. 5 (Tipo 1). Borra todas las ocurrencias en todas las lineas.
// Solo corre palabras dentro de cada linea (no rellena desde la siguiente).
// Siempre OK, aunque no borre nada.
	// TODO: for p = 1..CantLineas(e->t):
	//   linea l = LineaEnPosicion(e->t, p); BorrarOcurrenciasPalabraEnLinea(l, palabraABorrar);
	return NO_IMPLEMENTADA;
}

TipoRetorno ImprimirTexto(editor & e){
// Letra: op. 6 (Tipo 1). "n: palabras" por linea, o "Texto vacio".
	// TODO: ImprimirTexto(e->t); return OK;
	return NO_IMPLEMENTADA;
}

TipoRetorno ComprimirTexto(editor & e){
// Letra: op. 7 (Opcional). Reubica las palabras para que todas las lineas
// (salvo quiza la ultima) queden llenas; no quedan lineas vacias.
// No debe generarse un nuevo documento.
	// TODO: dos cursores (linea destino, linea origen). Mientras la destino
	// no este llena: pal = QuitarPalabra(origen, 1);
	// InsertarPalabra(destino, cant+1, pal); delete [] pal.
	// Al final, BorrarLinea de las lineas vacias que queden.
	return NO_IMPLEMENTADA;
}

// ---------------------------------------------------------------
// OPERACIONES RELATIVAS A LAS PALABRAS
// ---------------------------------------------------------------

TipoRetorno InsertarPalabra(editor & e, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar){
// Letra: op. 8 (Tipo 1). Inserta la palabra en la linea y posicion dadas.
// Si la linea se desborda, la ultima palabra pasa a la posicion 1 de la
// siguiente, y asi sucesivamente; si no hay siguiente se crea una al final.
// ERROR si la linea no existe o posicionPalabra no esta en 1..cant+1.
	// TODO:
	//   1. validar: posicionLinea existe (1..CantLineas) y
	//      1 <= posicionPalabra <= CantPalabras(l) + 1.
	//   2. RegistrarPalabra(e->u, palabraAIngresar)   (op. 16).
	//   3. si LineaLlena(l): sobrante = QuitarPalabra(l, MAX) antes de insertar.
	//   4. InsertarPalabra(l, posicionPalabra, palabraAIngresar).
	//   5. mientras haya sobrante: pasar a la linea siguiente (InsertarLinea
	//      si no existe), repetir 3 y 4 con posicion 1; delete [] cada sobrante
	//      despues de insertarlo (InsertarPalabra lo copia).
	return NO_IMPLEMENTADA;
}

TipoRetorno BorrarPalabra(editor & e, Posicion posicionLinea, Posicion posicionPalabra){
// Letra: op. 9 (Tipo 1). Borra la palabra indicada.
// ERROR si la linea o la palabra no existen.
	// TODO: validar; BorrarPalabra(l, posicionPalabra); return OK;
	return NO_IMPLEMENTADA;
}

TipoRetorno BorrarOcurrenciasPalabraEnLinea(editor & e, Posicion posicionLinea, Cadena palabraABorrar){
// Letra: op. 10 (Tipo 1). Borra todas las ocurrencias en la linea indicada.
// ERROR solo si la linea no existe.
	// TODO: validar; BorrarOcurrenciasPalabraEnLinea(l, palabraABorrar); return OK;
	return NO_IMPLEMENTADA;
}

TipoRetorno ImprimirLinea(editor & e, Posicion posicionLinea){
// Letra: op. 11 (Tipo 1). Imprime "n: palabras". ERROR si la linea no existe.
	// TODO: validar; cout << posicionLinea << ":"; si tiene palabras
	// cout << " " y ImprimirLinea(l); cout << endl; return OK;
	
	for(int i = 1; i <= CantLineas(e->t); i++){
		if(i == posicionLinea){
			cout << posicionLinea << ":";
			linea l = LineaEnPosicion(e->t, posicionLinea);
			if(CantPalabras(l) > 0){
				cout << " ";
				ImprimirLinea(l);
			}
			cout << endl;
			return OK;
		} else if(i > CantLineas(e->t)){
			cout << " - ERROR: La linea no existe.\n";
			return ERROR;
		}
	}

	return ERROR;
}

// ---------------------------------------------------------------
// OPERACIONES RELATIVAS AL DICCIONARIO
// ---------------------------------------------------------------

TipoRetorno IngresarPalabraDiccionario(editor & e, Cadena palabraAIngresar){
// Letra: op. 12 (Tipo 1). O(log n) promedio. ERROR si ya existe.
	// TODO: if PerteneceDiccionario -> ERROR;
	// e->d = IngresarPalabraDiccionario(e->d, palabraAIngresar); return OK;
	return NO_IMPLEMENTADA;
}

TipoRetorno BorrarPalabraDiccionario(editor & e, Cadena palabraABorrar){
// Letra: op. 13 (Tipo 2). ERROR si la palabra no existe.
	// TODO: if !PerteneceDiccionario -> ERROR;
	// e->d = BorrarPalabraDiccionario(e->d, palabraABorrar); return OK;
	return NO_IMPLEMENTADA;
}

TipoRetorno ImprimirDiccionario(editor & e){
// Letra: op. 14 (Tipo 1). Alfabetico, O(n) peor caso.
	// TODO: ImprimirDiccionario(e->d); return OK;
	return NO_IMPLEMENTADA;
}

TipoRetorno ImprimirTextoIncorrecto(editor & e){
// Letra: op. 15 (Tipo 2). Muestra las lineas con solo las palabras que NO
// estan en el diccionario. "Texto vacio" si no hay lineas.
	// TODO: por cada linea: cout << n << ":"; por cada palabra p:
	// if !PerteneceDiccionario(e->d, PalabraEnPosicion(l, p)) cout << " " << palabra;
	// endl.
	return NO_IMPLEMENTADA;
}

TipoRetorno ImprimirUltimasPalabras(editor & e){
// Letra: op. 16 (Opcional). Ultimas MAX_CANT_ULTIMAS_PALABRAS ingresadas.
	// TODO: ImprimirUltimasPalabras(e->u); return OK;
	return NO_IMPLEMENTADA;
}

TipoRetorno DestruirEditor(editor & e){
// Destruye la estructura editor y libera la memoria asociada.
	e->t = DestruirTexto(e->t);
	e->d = DestruirDiccionario(e->d);
	e->u = DestruirUltimas(e->u);
	delete e;
	e = NULL;
	return OK;
}
