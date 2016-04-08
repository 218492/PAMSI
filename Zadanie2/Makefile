zad2: main.o
	g++ -o zad2 main.o tabd.o stoper.o stos.o
main.o: interfejsstosu.h stoper.h tabd.h stos.h stoper.cpp main.cpp tabd.cpp stos.cpp
	g++ -c main.cpp tabd.cpp stoper.cpp stos.cpp
tabd.o: tabd.cpp tabd.h interfejsstosu.h stoper.h
	g++ -c tabd.cpp
stoper.o: stoper.cpp stoper.h
	g++ -c stoper.cpp
stos.o: stos.cpp stos.h tabd.h
	g++ -c stos.cpp
make clean:
	rm *.o zad2
