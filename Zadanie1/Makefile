zad1: main.o
	g++ -o zad1 main.o tabd.o stoper.o
main.o: interfejs.hme stoper.h tabd.h stoper.cpp main.cpp tabd.cpp
	g++ -c main.cpp tabd.cpp stoper.cpp
tabd.o: tabd.cpp tabd.h interfejs.h stoper.h
	g++ -c tabd.cpp
stoper.o: stoper.cpp stoper.h
	g++ -c stoper.cpp
make clean:
	rm *.o zad1
