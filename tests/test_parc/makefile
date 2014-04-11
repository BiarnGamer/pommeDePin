all: ../../objets/animal.o  ../../objets/enclos.o ../../objets/parc.o ../../objets/main.o
	g++ ../../objets/animal.o  ../../objets/enclos.o ../../objets/parc.o ../../objets/main.o -o launch

../../objets/enclos.o: ../../entetes/enclos.h ../../sources/enclos.cpp
	g++ -c ../../sources/enclos.cpp -o ../../objets/enclos.o
	
../../objets/main.o: ../../entetes/enclos.h main.cpp
	g++ -c main.cpp -o ../../objets/main.o

../../objets/animal.o: ../../entetes/animal.h ../../sources/animal.cpp
	g++ -c ../../sources/animal.cpp -o ../../objets/animal.o

../../objets/parc.o: ../../entetes/animal.h ../../entetes/enclos.h ../../entetes/parc.h ../../sources/parc.cpp
	g++ -c ../../sources/parc.cpp -o ../../objets/parc.o
