CPPFLAGS= -c -Iinc -std=c++11 -Wall -pedantic

zad8: obj/main.o obj/graf.o obj/lista.o obj/stoper.o
	g++ -std=c++11 -Wall -pedantic -o zad5 obj/main.o obj/lista.o obj/graf.o obj/stoper.o
obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp
obj/graf.o: src/graf.cpp inc/graf.hh
	g++ ${CPPFLAGS} -o obj/graf.o src/graf.cpp
obj/lista.o: src/lista.cpp inc/lista.hh
	g++ ${CPPFLAGS} -o obj/lista.o src/lista.cpp
obj/stoper.o: src/stoper.cpp inc/stoper.h
	g++ ${CPPFLAGS} -o obj/stoper.o src/stoper.cpp
make clean:
	rm obj/*.o zad8

