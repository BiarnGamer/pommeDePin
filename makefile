all: objets/animal.o objets/main.o
	g++  objets/animal.o objets/main.o -o launch

objets/animal.o: entetes/animal.h sources/animal.cpp
	g++ -c sources/animal.cpp -o objets/animal.o
	
objets/main.o: entetes/animal.h sources/main.cpp
	g++ -c sources/main.cpp -o objets/main.o