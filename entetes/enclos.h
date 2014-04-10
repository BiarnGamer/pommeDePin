#ifndef ENCLOS_H
#define ENCLOS_H

#include <string>
#include "set.h"
#include "animal.h"


using namespace std;

typedef struct{
  int iCodeEspece;
  int iNombreAnimaux;
}compteEspeces;

class Enclos{
  int iID;
  int iCapacite;
  int iOccupation;
  int iTypeEnclos;
  string sNom;
  Set <Animal *> tabAnimaux;
  compteEspeces tabComptageEspeces[NB_ESPECES];
}




#endif