CPPFLAGS= -c -Iinc -std=c++11 -Wall -pedantic

zad3: obj/main.o obj/lista.o obj/stos.o obj/stoper.o obj/kolejka.o 
	g++ -std=c++11 -Wall -pedantic -o zad3 obj/main.o obj/lista.o obj/stoper.o obj/kolejka.o obj/stos.o
obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp
obj/lista.o: src/lista.cpp inc/lista.hh inc/interfejs.hh
	g++ ${CPPFLAGS} -o obj/lista.o src/lista.cpp
obj/stoper.o: src/stoper.cpp inc/stoper.h
	g++ ${CPPFLAGS} -o obj/stoper.o src/stoper.cpp
obj/kolejka.o: src/kolejka.cpp inc/lista.hh inc/kolejka.hh inc/interfejsk.h
	g++ ${CPPFLAGS} -o obj/kolejka.o src/kolejka.cpp
obj/stos.o: src/stos.cpp inc/lista.hh inc/stos.h inc/interfejss.h
	g++ ${CPPFLAGS} -o obj/stos.o src/stos.cpp
make clean:
	rm obj/*.o zad3

