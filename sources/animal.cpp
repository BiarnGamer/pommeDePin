#include <iostream>
#include <string>
#include "../entetes/animal.h"

using namespace std;

/***************************************************************/
/***************************************************************/
/**      Classe Animal                                        **/
/***************************************************************/
/***************************************************************/

// Constructeurs et destructeur
Animal::Animal():iID(-1), saitVoler(false), saitNager(false), estCarnivore(false), sNom("Nom indéfini") {}

Animal::Animal(const string & nom, const bool vole, const bool nage, const bool carnivore, const int ID):
    iID(ID), saitVoler(vole), saitNager(nage), estCarnivore(carnivore), sNom(nom) {}

Animal::Animal(const Animal & a) {
    iID = a.iID;
    saitVoler = a.saitVoler;
    saitNager = a.saitNager;
    estCarnivore = a.estCarnivore;
    sNom = a.sNom;
}

Animal::~Animal() {};

// Getters
int Animal::getID() const {
    return iID;
}

bool Animal::getSaitNager() const {
    return saitNager;
}

bool Animal::getSaitVoler() const {
    return saitVoler;
}

bool Animal::getEstCarnivore() const {
    return estCarnivore;
}

string Animal::getNom() const {
    return sNom;
}


// Setters
void Animal::setID(const int i) {
    iID = i;
}

void Animal::setSaitNager(const bool nage) {
    saitNager = nage;
}

void Animal::setSaitVoler(const bool vole) {
    saitVoler = vole;
}


void Animal::setEstCarnivore(const bool carnivore) {
    estCarnivore = carnivore;
}

void Animal::setNom(const string & n) {
    sNom = n;
}


// Surcharges d'opérateurs
Animal & Animal::operator=(const Animal & a) {
    iID = a.iID;
    saitVoler = a.saitVoler;
    saitNager = a.saitNager;
    estCarnivore = a.estCarnivore;
    sNom = a.sNom;
    return *this;
}

// Ici, on regarde tous les attributs, cela servira lors d'une recherche dans un tableau par exemple donc on veut une égalité entre tous les attributs
bool Animal::operator==(const Animal & a) {
    if( iID == a.iID
        && saitVoler == a.saitVoler
        && saitNager == a.saitNager
        && estCarnivore == a.estCarnivore
        && sNom == a.sNom
    ) {
        return true;
    }
    else {
        return false;
    }

}

bool Animal::operator!=(const Animal & a) {
    if( iID != a.iID
        || saitVoler != a.saitVoler
        || saitNager != a.saitNager
        || estCarnivore != a.estCarnivore
        || sNom != a.sNom
    ) {
        return true;
    }
    else {
        return false;
    }
}


// Fonctions amies
ostream & operator<<(ostream & flot, const Animal & a) {
    flot << "N° animal : " << a.getID() << endl;
    flot << "Nom : " << a.getNom() << endl;

    if(a.getSaitVoler()) {
        flot << "Vole : oui" << endl;
    }
    else {
        flot << "Vole : non" << endl;
    }

    if(a.getSaitNager()) {
        flot << "Nage : oui" << endl;
    }
    else {
        flot << "Nage : non" << endl;
    }

    if(a.getEstCarnivore()) {
        flot << "Carnivore : oui" << endl;
    }
    else {
        flot << "Carnivore : non" << endl;
    }

    return flot;
}



/***************************************************************/
/***************************************************************/
/**      Classe Tigre                                         **/
/***************************************************************/
/***************************************************************/
 Tigre::Tigre():Animal(),fHauteurGarot(0),iNbGazellesCroquees(0) {}

 Tigre::Tigre(const float fGarot, const int iNbVict, const string & nom, const bool vole, const bool nage, const bool carnivore, const int ID)
   :Animal(nom, vole, nage, carnivore, ID), fHauteurGarot(fGarot), iNbGazellesCroquees(iNbVict) {}

 Tigre::Tigre(const Tigre & t):Animal(t) {
   fHauteurGarot = t.fHauteurGarot;
   iNbGazellesCroquees = t.iNbGazellesCroquees;
 }

 Tigre::~Tigre() {}


 float Tigre::getGarot() const{
   return fHauteurGarot;
 }

 int Tigre::getNbVictimes() const {
   return iNbGazellesCroquees;
 }


 void Tigre::setGarot(const float garot) {
   fHauteurGarot = garot;
 }

 void Tigre::setNbVictimes(const int nbVict) {
   iNbGazellesCroquees = nbVict;
 }


 Tigre & Tigre::operator=(const Tigre & t) {
   Animal::operator=(t);
   fHauteurGarot = t.fHauteurGarot;
   iNbGazellesCroquees = t.iNbGazellesCroquees;
 }

 bool Tigre::operator==(const Tigre & t) {
    if(Animal::operator==(t)
       && fHauteurGarot == t.fHauteurGarot
       && iNbGazellesCroquees == t.iNbGazellesCroquees
       ) {
      return true;
   }
   else {
      return false;
   }
 }

 bool Tigre::operator!=(const Tigre & t) {
   if(Animal::operator!=(t)
      || fHauteurGarot != t.fHauteurGarot
      || iNbGazellesCroquees != t.iNbGazellesCroquees
      ){
      return true;
   }
   else {
      return false;
   }
 }

 ostream & operator<<(ostream & flot, const Tigre & t) {
   flot << (Animal&)t;
   flot << "Hauteur au garot : " << t.getGarot() << "cm" << endl;
   flot << "Nombre de gazelles croquées : " << t.getNbVictimes() << endl;
   return flot;
 }




/***************************************************************/
/***************************************************************/
/**      Classe Basque                                        **/
/***************************************************************/
/***************************************************************/
