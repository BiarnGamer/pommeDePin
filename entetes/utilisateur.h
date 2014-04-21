#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <limits>
#include <string>

//Afin d'utiliser les constantes ENCLOS
#include "../entetes/enclos.h"
#include "../entetes/parc.h"

using namespace std;

void creationEnclos(Parc & Parc1);
void videBuffer();
void Barney(Parc & Parc1);
bool choix();


string selectionNomEnclos();
int selectionTypeEnclos();
int selectionCapaciteEnclos();
int selectionChoixAnimal();
Loutre * creerLoutre();
Girafe * creerGirafe();
Crocodile * creerCrocodile();
Tortue * creerTortue();
Aigle * creerAigle();
Tigre * creerTigre();
Elephant * creerElephant();
Lapin * creerLapin();
Marmotte * creerMarmotte();
Basque * creerBasque();
int choixEnclos(Parc & Parc1,Animal * a);