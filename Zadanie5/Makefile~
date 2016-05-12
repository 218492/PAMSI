CPPFLAGS= -c -Iinc -std=c++11 -Wall -pedantic

zad5: obj/main.o obj/hasz.o obj/lista.o obj/stoper.o
	g++ -std=c++11 -Wall -pedantic -o zad5 obj/main.o obj/lista.o obj/hasz.o obj/stoper.o
obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp
obj/hasz.o: src/hasz.cpp inc/hasz.h
	g++ ${CPPFLAGS} -o obj/hasz.o src/hasz.cpp
obj/lista.o: src/lista.cpp inc/lista.h
	g++ ${CPPFLAGS} -o obj/lista.o src/lista.cpp
obj/stoper.o: src/stoper.cpp inc/stoper.h
	g++ ${CPPFLAGS} -o obj/stoper.o src/stoper.cpp
make clean:
	rm obj/*.o zad5

