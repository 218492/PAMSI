zad4: main.o
	g++ -o zad4 main.o list.o queue.o sort2.o
main.o: queue.hpp list.hpp stoper.hpp queue.cpp list.cpp main.cpp sort2.cpp
	g++ -c main.cpp list.cpp queue.cpp sort2.cpp
sort2.o: sort2.cpp sort2.hpp
	g++ -c sort2.cpp
list.o: list.cpp list.hpp node.hpp
	g++ -c list.cpp
queue.o: queue.cpp list.hpp queue.hpp
	g++ -c kolejka.cpp
make clean:
	rm *.o zad4
