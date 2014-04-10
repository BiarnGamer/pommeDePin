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
  //privé car on ne veut pas modifier le type après
  void setTypeEnclos(int &);
  void setID(int &);
  
public: 
  Enclos();
  Enclos(string &, int & type, int& capacite, int & ID);
  Enclos(Enclos &);
  ~Enclos();
  int getID() const;
  int getType() const;
  int getCapacite() const;
  string getNom() const;
  int getOccupation() const;
  void setNom(string &);
  Enclos & operator=(Enclos &);
  bool operator==(Enclos &) const;
  bool operator!=(Enclos &) const;
  Animal getAnimal(int &) const;
  int getNombreAnimaux(int &) const;
};




#endif