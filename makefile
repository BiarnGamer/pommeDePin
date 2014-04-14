all: objets/animal.o objets/enclos.o objets/parc.o objets/menu.o objets/main.o
	g++  objets/animal.o objets/enclos.o objets/parc.o objets/menu.o objets/main.o -o launch


objets/animal.o: entetes/animal.h sources/animal.cpp
	g++ -c sources/animal.cpp -o objets/animal.o

objets/enclos.o: entetes/enclos.h sources/enclos.cpp
	g++ -c sources/enclos.cpp -o objets/enclos.o


objets/parc.o: entetes/parc.h sources/parc.cpp
	g++ -c sources/parc.cpp -o objets/parc.o


objets/menu.o: entetes/menu.h sources/menu.cpp
	g++ -c sources/menu.cpp -o objets/menu.o

	
objets/main.o: entetes/animal.h sources/main.cpp
	g++ -c sources/main.cpp -o objets/main.o
