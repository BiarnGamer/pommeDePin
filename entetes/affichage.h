#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <iostream>
#include <string>
#include <cstdlib>

#include "../entetes/animal.h"
#include "../entetes/enclos.h"
#include "../entetes/parc.h"

int rechercheAnimal(const Parc & Parc1);
int rechercheEnclos(const Parc & Parc1);
void afficheAnimauxParc(const Parc & Parc1);
void afficherTauxRemplissageEnclos(const Parc &Parc1);
void afficherDetailDeTousLesEnclos(const Parc &Parc1);
void afficherDetailEnclosEtAnimaux(const Parc &Parc1);
void afficherDetailEtAnimauxDeTousLesEnclos(const Parc &Parc1);

#endif
