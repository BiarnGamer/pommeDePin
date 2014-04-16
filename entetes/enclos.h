#ifndef ENCLOS_H
#define ENCLOS_H

#include <string>
#include "set.h"
#include "animal.h"

#define ENCLOS 1
#define BASSIN 2
#define CAGE 3


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
  //privé car on ne veut pas modifier le type ni les ID après
  void setTypeEnclos(const int &);
  void setID(const int &);

public:
  Enclos();
  Enclos(const string &,const int & type, const int& capacite, const int & ID);
  Enclos(const Enclos &);
  ~Enclos();
  int getID() const;
  int getType() const;
  int getCapacite() const;
  string getNom() const;
  int getOccupation() const;
  Animal getAnimal(const int &) const;
  Animal * getPtrAnimal(const int &) const;
  int getNombreAnimaux(const int &) const;
  void setNom(const string &);
  void ajoutAnimal(Animal * ptrAnimal);
  void supprimerAnimal(Animal * ptrAnimal);
  Enclos & operator=(const Enclos &);
  bool operator==(const Enclos &) const;
  bool operator!=(const Enclos &) const;
  friend ostream & operator<<(ostream & flot, const Enclos & e);
};




#endif
