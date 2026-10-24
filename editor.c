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
	cout << " - Insertando linea ..." << endl;
	InsertarLinea(e->t);
	return OK;
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
// Inserta la cadena palabra en una posicion de la linea dada, y luego en una posicion de la palabra.

	cout << " - Insertando palabra : " << palabraAIngresar << endl;

	// Validar la posicion de la linea ingresada (Debe ser más grande que 0 y menor a la cantidad de lineas total)
	if(posicionLinea < 1 || posicionLinea > CantLineas(e->t)){
		cout << " - Debes crear una linea previamente" << endl;
		return ERROR;
	}

	// me traigo la linea en la que se quiere ingresar la palabra
	linea lInicio = LineaEnPosicion(e->t, posicionLinea);
	if(posicionPalabra < 1 || posicionPalabra > CantPalabras(lInicio) + 1){
		cout << " - La palabra " << palabraAIngresar << " no se puede agregar en esa posición. " << endl;
		return ERROR;
	}

	// TODO: Debemos reigstrar la palabra en las ulitmas palabras ingresadas
	RegistrarPalabra(e->u, palabraAIngresar);

	// Chequeamos si desbordó
	Cadena palabraActual = palabraAIngresar;
	Posicion posActual = posicionPalabra;
	Posicion lineaActual = posicionLinea;
	bool esSobrante = false;

	while(palabraActual != NULL){

		// Se agrega una linea más en caso de que estén faltando
		if(lineaActual > CantLineas(e->t)){
			InsertarLinea(e->t);
		}

		// Obtengo la linea de la posicion lineaActual
		linea l = LineaEnPosicion(e->t, lineaActual);
		Cadena sobrante = NULL;

		// Si la linea ya tiene el maximo de palabras borro la palabra y me la traigo como sobrante
		if(LineaLlena(l)){
			sobrante = QuitarPalabra(l, CantPalabras(l));
		}

		// inserto la palabra en la posicion que quiero
		InsertarPalabra(l, posActual, palabraActual);

		if(esSobrante){
			delete [] palabraActual;
		}

		palabraActual = sobrante;
		posActual = 1;
		lineaActual++;
		esSobrante = true;
	}

	return OK;
}

TipoRetorno BorrarPalabra(editor & e, Posicion posicionLinea, Posicion posicionPalabra){
// Elimina palabra de una linea y una posición

	cout << " Borrando palabra ... " << endl;
 	if(posicionLinea < 1 || posicionLinea > CantLineas(e->t)){
		return ERROR;
	}
	linea l = LineaEnPosicion(e->t, posicionLinea);
	if(posicionPalabra < 1 || posicionPalabra > CantPalabras(l)){
		return ERROR;
	}
	BorrarPalabra(l, posicionPalabra);
	return OK;
}

TipoRetorno BorrarOcurrenciasPalabraEnLinea(editor & e, Posicion posicionLinea, Cadena palabraABorrar){
// Letra: op. 10 (Tipo 1). Borra todas las ocurrencias en la linea indicada.
// ERROR solo si la linea no existe.
	if(posicionLinea < 1 || posicionLinea > CantLineas(e->t)){
		return ERROR;
	}
	linea l = LineaEnPosicion(e->t, posicionLinea);
	BorrarOcurrenciasPalabraEnLinea(l, palabraABorrar);
	return OK;
}

TipoRetorno ImprimirLinea(editor & e, Posicion posicionLinea){
// Se imprime linea

	cout << " Linea";

	if(posicionLinea < 1 || posicionLinea > CantLineas(e->t)){
		cout << "- Linea invalida" << endl;
		return ERROR;
	}
	linea l = LineaEnPosicion(e->t, posicionLinea);
	cout << posicionLinea << ":";
	if(CantPalabras(l) > 0){
		cout << " ";
		ImprimirLinea(l);
	}
	cout << endl;
	return OK;
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
