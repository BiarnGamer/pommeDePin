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
  
public: 
  void setID(int &);
  Enclos();
  Enclos(string &, int & type, int& capacite, int & ID);
  Enclos(Enclos &);
  ~Enclos();
  int getID();
  int getType();
  string getNom();
  int getOccupation();
  void setSaitNager(bool &);
  void setSaitVoler(bool &);
  void setNom(string &);
  void setEspece(int &);
  Enclos & operator=(Enclos &);
  bool operator==(Enclos &);
  bool operator!=(Enclos &);
  Animal getAnimal(int &);
  int getNbAnimal(int &);
  int getNombreAnimaux(int &);
};




#endif