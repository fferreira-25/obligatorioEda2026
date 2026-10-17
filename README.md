# Obligatorio EDA 2026 - Editor de texto

## Arquitectura

```
editor  (editor.c)  -> solo usa las operaciones de los modulos, nunca su representacion
  |- texto.h/.c       lista doblemente encadenada de lineas (primera, ultima, cant)
  |     '- linea.h/.c   arreglo de MAX_CANT_PALABRAS_X_LINEA cadenas + cant
  |- diccionario.h/.c ABB de cadenas (strcasecmp)
  '- ultimas.h/.c     arreglo circular de MAX_CANT_ULTIMAS_PALABRAS cadenas
```

Archivos que NO se tocan: `main.c`, `editor.h`, `definiciones.h`.
Cada funcion con `// TODO` esta por hacer; las demas ya estan.
Convencion: las funciones de los modulos llevan el MISMO nombre que la operacion de la letra
(ej. `InsertarPalabra(linea&, ...)`, `InsertarLinea(texto&)`, `IngresarPalabraDiccionario(diccionario, Cadena)`)
y cada una lleva un comentario `Letra: op. N (Tipo X)`. No chocan con las de `editor.h` porque C++
sobrecarga por tipo de parametro: la del editor recibe `editor&`, la del modulo recibe su propio tipo.

## Reglas comunes
- Compilar siempre con `make` y sin warnings (`-Wall`).
- Toda cadena que se guarda se COPIA (`new char[strlen(c)+1]` + `strcpy`) y se libera con `delete []`.
  El `pch` que pasa el main se pisa en el siguiente comando: nunca guardarlo directo.
- Comparar palabras con `strcasecmp` (ignora mayusculas); imprimir tal cual se ingreso.
- Respetar salidas exactas: `1: Palabra1 Palabra2`, `Texto vacio`, `Diccionario vacio`, `No se ingresaron palabras`.
- Especificacion comentada bajo cada firma, con Pre: cuando corresponda (estilo del curso).

## Reparto sugerido (3 integrantes)

| Integrante | Modulo(s) | Operaciones del editor | Para el control (25/10) |
|---|---|---|---|
| A | `linea.c` | 8 InsertarPalabra (con desborde), 9 BorrarPalabra, 10 BorrarOcurrenciasPalabraEnLinea, 11 ImprimirLinea | si |
| B | `texto.c` | 1 InsertarLinea, 2 InsertarLineaEnPosicion, 3 BorrarLinea, 4 BorrarTodo, 5 BorrarOcurrenciasPalabraEnTexto, 6 ImprimirTexto | si |
| C | `diccionario.c`, `ultimas.c` | 12, 13, 14 diccionario; 15 ImprimirTextoIncorrecto; 16 ImprimirUltimasPalabras; 7 ComprimirTexto (opcional) | 12 y 14 son Tipo 1; el resto despues |

Orden: B y A pueden avanzar en paralelo (texto usa linea solo a traves de linea.h).
A necesita `InsertarLinea` y `LineaEnPosicion` de B para el desborde de InsertarPalabra.

## Probar
```
make
./main < entrada
```
Comparar contra los ejemplos de la letra. Conviene que cada uno arme un archivo
de entrada propio para sus operaciones (ej. `entrada_linea`, `entrada_texto`, `entrada_dicc`).

## Fechas
- Control intermedio (op. 1-11): semana del 25/10/2026, coordinar con el docente.
- Entrega final (op. 1-16): 18/11/2026 23:59, Moodle + defensa.
