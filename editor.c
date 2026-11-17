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
	if(InsertarLineaEnPosicion(e->t, posicionLinea)){
		return OK;
	}else{
		return ERROR;
	}
}

TipoRetorno BorrarLinea(editor & e, Posicion posicionLinea){
// Letra: op. 3 (Tipo 2). Borra la linea indicada. ERROR si no existe.
	if(BorrarLinea(e->t, posicionLinea)){
		return OK;
	}else{
		return ERROR;
	}
}

TipoRetorno BorrarTodo(editor & e){
// Letra: op. 4 (Tipo 2). Borra todas las lineas. Siempre OK.
	BorrarTodo(e->t);
	return OK;
}

TipoRetorno BorrarOcurrenciasPalabraEnTexto(editor & e, Cadena palabraABorrar){
// Letra: op. 5 (Tipo 1). Borra todas las ocurrencias en todas las lineas.
// Solo corre palabras dentro de cada linea (no rellena desde la siguiente).
// Siempre OK, aunque no borre nada.
	for(Posicion p = 1; p <= CantLineas(e->t); p++){
		linea l = LineaEnPosicion(e->t, p);
		BorrarOcurrenciasPalabraEnLinea(l, palabraABorrar);
	}
	return OK;
}

TipoRetorno ImprimirTexto(editor & e){
// Letra: op. 6 (Tipo 1). "n: palabras" por linea, o "Texto vacio".
	ImprimirTexto(e->t);
	return OK;
}

TipoRetorno ComprimirTexto(editor & e){
// Letra: op. 7 (Opcional). Reubica las palabras para que todas las lineas
// (salvo quiza la ultima) queden llenas; no quedan lineas vacias.
// No debe generarse un nuevo documento.
	if (e == NULL || e->t == NULL || CantLineas(e->t) == 0) {
		return OK;
	}

	// Iteradores de la posicion de las lineas
	Posicion lineaActual = 1;
	Posicion lineaBusqueda = 2;
	bool quedanPalabras = true;

	while (lineaActual <= CantLineas(e->t) && quedanPalabras) {
		linea lActual = LineaEnPosicion(e->t, lineaActual);

		if (LineaLlena(lActual)) {
			lineaActual++;
			if (lineaBusqueda <= lineaActual) {
				lineaBusqueda = lineaActual + 1;
			}
		} else {
			// Busco la siguiente linea con palabras
			while (lineaBusqueda <= CantLineas(e->t) && CantPalabras(LineaEnPosicion(e->t, lineaBusqueda)) == 0) {
				lineaBusqueda++;
			}

			// Si no hay mas palabras en todo el texto, apagamos la bandera
			if (lineaBusqueda > CantLineas(e->t)) {
				quedanPalabras = false;
			} else {
				linea lBusqueda = LineaEnPosicion(e->t, lineaBusqueda);
				Cadena pal = QuitarPalabra(lBusqueda, 1);
				InsertarPalabra(lActual, CantPalabras(lActual) + 1, pal);
				delete [] pal;
			}
		}
	}

	// Borrar las lineas que hayan quedado vacias al final
	while (CantLineas(e->t) > 0 && CantPalabras(LineaEnPosicion(e->t, CantLineas(e->t))) == 0) {
		BorrarLinea(e->t, CantLineas(e->t));
	}

	return OK;
}

// ---------------------------------------------------------------
// OPERACIONES RELATIVAS A LAS PALABRAS
// ---------------------------------------------------------------

TipoRetorno InsertarPalabra(editor & e, Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar){
// Inserta la cadena palabra en una posicion de la linea dada, y luego en una posicion de la palabra.

	cout << " - Insertando palabra : " << palabraAIngresar << endl;

	// Validar la posicion de la linea ingresada (Debe ser más grande que 0 y menor a la cantidad de lineas total)
	if(posicionLinea < 1 || posicionLinea > CantLineas(e->t)){
		cout << " - La linea que quieres ingresar está fuera de rango o no existe." << endl;
		return ERROR;
	}

	// me traigo la linea en la que se quiere ingresar la palabra
	linea lInicio = LineaEnPosicion(e->t, posicionLinea);
	if(posicionPalabra < 1 || posicionPalabra > CantPalabras(lInicio) + 1){
		cout << " - La palabra " << palabraAIngresar << " no se puede agregar en esa posición. " << endl;
		return ERROR;
	}

	// Op. 16: registro la palabra recien despues de validar (si da ERROR no cuenta).
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
	cout << " Borrando ocurrencias palabra ... " << endl;
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
// Letra: op. 12 (Tipo 1). O(log n) promedio. ERROR si ya existe.;

	cout << " Ingresando palabra al diccionario: " << palabraAIngresar << endl;
	if(PerteneceDiccionario(e->d, palabraAIngresar)){
		return ERROR;                              // ya estaba en el diccionario
	}
	e->d = IngresarPalabraDiccionario(e->d, palabraAIngresar);
	return OK;
}

TipoRetorno BorrarPalabraDiccionario(editor & e, Cadena palabraABorrar){
// Letra: op. 13 (Tipo 2). ERROR si la palabra no existe.
	// TODO: if !PerteneceDiccionario -> ERROR;
	// e->d = BorrarPalabraDiccionario(e->d, palabraABorrar); return OK;
	return NO_IMPLEMENTADA;
}

TipoRetorno ImprimirDiccionario(editor & e){
// Letra: op. 14 (Tipo 1). Alfabetico, O(n) peor caso.
	ImprimirDiccionario(e->d);
	return OK;
}

TipoRetorno ImprimirTextoIncorrecto(editor & e){
// Letra: op. 15 (Tipo 2). Muestra las lineas con solo las palabras que NO
// estan en el diccionario. "Texto vacio" si no hay lineas.
	// TODO: por cada linea: cout << n << ":"; por cada palabra p:
	// if !PerteneceDiccionario(e->d, PalabraEnPosicion(l, p)) cout << " " << palabra;
	// endl.

	// recorro todas las lineas del texto
	for (int i = 1; i <= CantLineas(e->t); i++) {

		// obtengo la linea en la posicion i
		linea l = LineaEnPosicion(e->t, i);

		if (CantPalabras(l) > 0) {

			// imprimo el indice de la linea
			cout << i + 1 << ":";
			for (int j = 0; j < CantPalabras(l); j++) {
				
				Cadena palabra = PalabraEnPosicion(l, j + 1);
				if (!PerteneceDiccionario(e->d, palabra)) {
					cout << " " << palabra;
				}
			}
			cout << endl;
		}
		
	} 


	return OK;
}

TipoRetorno ImprimirUltimasPalabras(editor & e){
// Letra: op. 16 (Opcional). Ultimas MAX_CANT_ULTIMAS_PALABRAS ingresadas.
	ImprimirUltimasPalabras(e->u);
	return OK;
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
