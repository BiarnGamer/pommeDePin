#include <iostream>
#include <stdio.h>
#include <cstdlib>

//Afin d'utiliser les constantes ENCLOS
#include "../entetes/enclos.h"
#include "../entetes/parc.h"

using namespace std;

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
int choixEnclosCreerAnimal(Parc & Parc1);