CPPFLAGS= -c -Iinc -std=c++11 -Wall -pedantic

zad4: obj/main.o obj/sort2.o obj/list.o obj/queue.o
	g++ -std=c++11 -Wall -pedantic -o zad4 obj/main.o obj/list.o obj/queue.o obj/sort2.o
obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp
obj/sort2.o: src/sort2.cpp inc/sort2.hpp
	g++ ${CPPFLAGS} -o obj/sort2.o src/sort2.cpp
obj/list.o: src/list.cpp inc/list.hpp inc/node.hpp
	g++ ${CPPFLAGS} -o obj/list.o src/list.cpp
obj/queue.o: src/queue.cpp inc/list.hpp inc/queue.hpp
	g++ ${CPPFLAGS} -o obj/queue.o src/queue.cpp
make clean:
	rm obj/*.o zad4

