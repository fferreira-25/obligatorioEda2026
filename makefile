todo: main.o editor.o texto.o linea.o diccionario.o ultimas.o
	g++ -Wall -o main main.o editor.o texto.o linea.o diccionario.o ultimas.o
main.o: main.c editor.h definiciones.h
	g++ -Wall -c main.c
editor.o: editor.c editor.h texto.h linea.h diccionario.h ultimas.h definiciones.h
	g++ -Wall -c editor.c
texto.o: texto.c texto.h linea.h definiciones.h
	g++ -Wall -c texto.c
linea.o: linea.c linea.h definiciones.h
	g++ -Wall -c linea.c
diccionario.o: diccionario.c diccionario.h definiciones.h
	g++ -Wall -c diccionario.c
ultimas.o: ultimas.c ultimas.h definiciones.h
	g++ -Wall -c ultimas.c
clean:
	rm -f main
	rm -f *.o
