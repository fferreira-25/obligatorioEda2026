// Estructuras de Datos y Algoritmos - Obligatorio 2026
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// main.c
// Programa Principal Obligatorio

#include "editor.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h> 
#include <iostream>

using namespace std;

void comandos(){
// Imprime los comandos disponibles.
		cout << "\tInsertarLinea()\n";
		cout << "\tInsertarLineaEnPosicion(Posicion posicionLinea)\n";
		cout << "\tBorrarLinea(Posicion posicionLinea)\n";
		cout << "\tBorrarTodo()\n";
		cout << "\tBorrarOcurrenciasPalabraEnTexto(Cadena palabraABorrar)\n";
		cout << "\tImprimirTexto()\n";
		cout << "\tComprimirTexto()\n";
		cout << "\tInsertarPalabra(Posicion posicionLinea, Posicion posicionPalabra, Cadena palabraAIngresar)\n";
		cout << "\tBorrarPalabra(Posicion posicionLinea, Posicion posicionPalabra)\n";
		cout << "\tBorrarOcurrenciasPalabraEnLinea(Posicion posicionLinea, Cadena palabraABorrar)\n";
		cout << "\tImprimirLinea(Posicion posicionLinea)\n";
		cout << "\tIngresarPalabraDiccionario(Cadena palabraAIngresar)\n";
		cout << "\tBorrarPalabraDiccionario(Cadena palabraABorrar)\n";
		cout << "\tImprimirDiccionario()\n";
		cout << "\tImprimirTextoIncorrecto()\n";
		cout << "\tImprimirUltimasPalabras()\n";
		cout << "\tcomandos\n";
		cout << "\tsalir\n";
}

int main(){
	char * comando = new(char[MAX_COMANDO]);
	TipoRetorno retorno;
	bool ejecutado = false;
	char * pch, * pch1, * pch2;
	
	editor e = CrearEditor();

	bool salir = false;

	comandos();


	do{

		fflush(stdin);
		ejecutado = false;
		cout << "> ";

		fgets (comando, MAX_COMANDO, stdin); // leo la linea entera del comando. 
		pch = strtok (comando,"( ,)\n");

		if (strcasecmp (pch, "InsertarLinea") == 0){
				retorno = InsertarLinea(e);
				ejecutado = true;
		}else if (strcasecmp (pch, "InsertarLineaEnPosicion") == 0){
			pch = strtok (NULL, "( ,)\n");
			if (pch != NULL){
				retorno = InsertarLineaEnPosicion(e, atoi(pch));
				ejecutado = true;
			}else
				cout << " - ERROR: Faltan Parametros.\n";
		}else if (strcasecmp (pch, "BorrarLinea") == 0){
			pch = strtok (NULL, "( ,)\n");
			if (pch != NULL){
				retorno = BorrarLinea(e, atoi(pch));
				ejecutado = true;
			}else
				cout << " - ERROR: Faltan Parametros.\n";
		}else if (strcasecmp (pch, "BorrarTodo") == 0){
			retorno = BorrarTodo(e);
			ejecutado = true;
		}else if (strcasecmp (pch, "BorrarOcurrenciasPalabraEnTexto") == 0){
			pch = strtok (NULL, "( ,)\n");
			if (pch != NULL){
				retorno = BorrarOcurrenciasPalabraEnTexto(e, pch);
				ejecutado = true;
			}else
				cout << " - ERROR: Faltan Parametros.\n";
		}else if (strcasecmp (pch, "ImprimirTexto") == 0){
			retorno = ImprimirTexto(e);
			ejecutado = true;
		}else if (strcasecmp (pch, "ComprimirTexto") == 0){
			retorno = ComprimirTexto(e);
			ejecutado = true;
		}else if (strcasecmp (pch, "InsertarPalabra") == 0){
			pch = strtok (NULL, "( ,)\n");
			if (pch != NULL){
				pch1 = strtok (NULL, "( ,)\n");
				if (pch1 != NULL){
					pch2 = strtok (NULL, "( ,)\n");
					if (pch2 != NULL){
						retorno = InsertarPalabra(e, atoi(pch), atoi(pch1), pch2);
						ejecutado = true;
					}else
						cout << " - ERROR: Faltan Parametros.\n";
				}else
					cout << " - ERROR: Faltan Parametros.\n";
			}else
				cout << " - ERROR: Faltan Parametros.\n";
		}else if (strcasecmp (pch, "BorrarPalabra") == 0){
			pch = strtok (NULL, "( ,)\n");
			if (pch != NULL){
				pch1 = strtok (NULL, "(,)\n");
				if (pch1 != NULL){
					retorno = BorrarPalabra(e, atoi(pch), atoi(pch1));
					ejecutado = true;
				}else
					cout << " - ERROR: Faltan Parametros.\n";
			}else
				cout << " - ERROR: Faltan Parametros.\n";
		}else if (strcasecmp (pch, "BorrarOcurrenciasPalabraEnLinea") == 0){
			pch = strtok (NULL, "( ,)\n");
			if (pch != NULL){
				pch1 = strtok (NULL, "(,)\n");
				if (pch1 != NULL){
					retorno = BorrarOcurrenciasPalabraEnLinea(e, atoi(pch), pch1);
					ejecutado = true;
				}else
					cout << " - ERROR: Faltan Parametros.\n";
			}else
				cout << " - ERROR: Faltan Parametros.\n";
		}else if (strcasecmp (pch, "ImprimirLinea") == 0){
			pch = strtok (NULL, "( ,)\n");
			if (pch != NULL){
				retorno = ImprimirLinea(e, atoi(pch));
				ejecutado = true;
			}else
				cout << " - ERROR: Faltan Parametros.\n";
		}else if (strcasecmp (pch, "IngresarPalabraDiccionario") == 0){
			pch = strtok (NULL, "( ,)\n");
			if (pch != NULL){
				retorno = IngresarPalabraDiccionario(e, pch);
				ejecutado = true;
			}else
				cout << " - ERROR: Faltan Parametros.\n";
		}else if (strcasecmp (pch, "BorrarPalabraDiccionario") == 0){
			pch = strtok (NULL, "( ,)\n");
			if (pch != NULL){
				retorno = BorrarPalabraDiccionario(e, pch);
				ejecutado = true;
			}else
				cout << " - ERROR: Faltan Parametros.\n";
		}else if (strcasecmp (pch, "ImprimirDiccionario") == 0){
			retorno = ImprimirDiccionario(e);
			ejecutado = true;
		}else if (strcasecmp (pch, "ImprimirTextoIncorrecto") == 0){
			retorno = ImprimirTextoIncorrecto(e);
			ejecutado = true;
		}else if (strcasecmp (pch, "ImprimirUltimasPalabras") == 0){
			retorno = ImprimirUltimasPalabras(e);
			ejecutado = true;
		}else if (strcasecmp (pch, "comandos") == 0){
			comandos();
		}else if (strcasecmp (pch, "salir") == 0){
			cout << "\t- CHAUUUUU!!!\n\n";
			salir = true;
		}else{
			cout << " - Comando Incorrecto.\n\n";
			retorno = ERROR;
		}
		if (ejecutado){
				if (retorno == OK)
					cout << " - OK\n\n";
				else if (retorno == ERROR)
					cout << " - ERROR\n\n";
				else
					cout << " - NO IMPLEMENTADA\n\n";
		}

	}while (!salir);
	
	retorno = DestruirEditor(e);
	if (retorno == OK)
		cout << " - Memoria liberada con exito.\n\n";
	else if (retorno == ERROR)
		cout << " - Error al liberar memoria.\n\n";
	else
		cout << " - Operacion DestruirEditor NO IMPLEMENTADA\n\n";

	delete [] comando;
}
