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
 Tigre::Tigre():Animal(),fHauteurGarot(0),iNbGazellesCroquees(0) {
   setSaitVoler(false);
   setSaitNager(true);
   setEstCarnivore(true);
 }

 Tigre::Tigre(const float fGarot, const int iNbVict, const string & nom, const int ID)
   :Animal(nom, false, true, true, ID), fHauteurGarot(fGarot), iNbGazellesCroquees(iNbVict) {}

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
   return *this;
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
 Basque::Basque():Animal(), fLargeurBeret(0), fTempsDeCuisson(0), iNbPartiesPeloteGagnees(0), iNbRicardBus(0){
   setSaitVoler(false);
   setSaitNager(true);
   setEstCarnivore(true);
}

 Basque::Basque(const float flBeret, const float fCuisson, const int iNbVictoires, const int iNbRicard, const string & nom, const int ID)
   :Animal(nom, false, true, true, ID), fLargeurBeret(flBeret), fTempsDeCuisson(fCuisson), iNbPartiesPeloteGagnees(iNbVictoires), iNbRicardBus(iNbRicard) {}

 Basque::Basque(const Basque & b):Animal(b){
   fLargeurBeret = b.fLargeurBeret;
   fTempsDeCuisson = b.fTempsDeCuisson;
   iNbPartiesPeloteGagnees = b.iNbPartiesPeloteGagnees;
   iNbRicardBus = b.iNbRicardBus;
 }

 Basque::~Basque(){}

 float Basque::getLargeurBeret() const{
   return fLargeurBeret;
 }

 float Basque::getTempsCuisson() const{
   return fTempsDeCuisson;
 }

 int Basque::getNbVictoires() const{
   return iNbPartiesPeloteGagnees;
 }

 int Basque::getNbRicard() const{
   return iNbRicardBus;
 }


 void Basque::setLargeurBeret(const float beret){
   fLargeurBeret = beret;
 }

 void Basque::setTempsCuisson(const float cuisson){
   fTempsDeCuisson = cuisson;
 }

 void Basque::setNbVictoires(const int victoires){
   iNbPartiesPeloteGagnees = victoires;
 }

 void Basque::setNbRicard(const int ricard){
   iNbRicardBus = ricard;
 }


 Basque & Basque::operator=(const Basque & b){
   Animal::operator=(b);
   fLargeurBeret = b.fLargeurBeret;
   fTempsDeCuisson = b.fTempsDeCuisson;
   iNbPartiesPeloteGagnees = b.iNbPartiesPeloteGagnees;
   iNbRicardBus = b.iNbRicardBus;
   return *this;
 }

 bool Basque::operator==(const Basque & b){
   if(Animal::operator==(b)
      && fLargeurBeret == b.fLargeurBeret
      && fTempsDeCuisson == b.fTempsDeCuisson
      && iNbPartiesPeloteGagnees == b.iNbPartiesPeloteGagnees
      && iNbRicardBus == b.iNbRicardBus) {
      return true;
   }
   else {
      return false;
   }
 }

 bool Basque::operator!=(const Basque & b){
   if(Animal::operator!=(b)
      || fLargeurBeret != b.fLargeurBeret
      || fTempsDeCuisson != b.fTempsDeCuisson
      || iNbPartiesPeloteGagnees != b.iNbPartiesPeloteGagnees
      || iNbRicardBus != b.iNbRicardBus) {
      return true;
   }
   else {
      return false;
   }
 }


 ostream & operator<<(ostream & flot, const Basque & b){
   flot << (Animal&)b;
   flot << "Largeur du béret : " << b.getLargeurBeret() << "cm" << endl;
   flot << "Temps de cuisson : " << b.getTempsCuisson() << "min" << endl;
   flot << "Nombre de parties de pelotes gagnées : " << b.getNbVictoires() << endl;
   flot << "Nombre de Ricards bus : " << b.getNbRicard() << endl;
   return flot;
 }



/***************************************************************/
/***************************************************************/
/**      Classe Marmotte                                      **/
/***************************************************************/
/***************************************************************/
float fTaille;
    int iNbTablettesChocolatEmballees;
Marmotte::Marmotte():Animal(),fTaille(0),iNbTablettesChocolatEmballees(0) {
   setSaitVoler(false);
   setSaitNager(true);
   setEstCarnivore(false);
}

 Marmotte::Marmotte(const float taille, const int iNbTablettes, const string & nom, const int ID)
   :Animal(nom, false, true, false, ID), fTaille(taille), iNbTablettesChocolatEmballees(iNbTablettes) {}

 Marmotte::Marmotte(const Marmotte & t):Animal(t) {
   fTaille = t.fTaille;
   iNbTablettesChocolatEmballees = t.iNbTablettesChocolatEmballees;
 }

 Marmotte::~Marmotte() {}


 float Marmotte::getTaille()const{
   return fTaille;
 }

 int Marmotte::getNbTabChocolat() const {
   return iNbTablettesChocolatEmballees;
 }


 void Marmotte::setTaille(const float taille) {
   fTaille = taille;
 }

 void Marmotte::setNbTabChocolat(const int chocolat) {
   iNbTablettesChocolatEmballees = chocolat;
 }


 Marmotte & Marmotte::operator=(const Marmotte & t) {
   Animal::operator=(t);
   fTaille = t.fTaille;
   iNbTablettesChocolatEmballees = t.iNbTablettesChocolatEmballees;
   return *this;
 }

 bool Marmotte::operator==(const Marmotte & t) {
    if(Animal::operator==(t)
       && fTaille == t.fTaille
       && iNbTablettesChocolatEmballees == t.iNbTablettesChocolatEmballees
       ) {
      return true;
   }
   else {
      return false;
   }
 }

 bool Marmotte::operator!=(const Marmotte & t) {
   if(Animal::operator!=(t)
      || fTaille != t.fTaille
      || iNbTablettesChocolatEmballees != t.iNbTablettesChocolatEmballees
      ){
      return true;
   }
   else {
      return false;
   }
 }

 ostream & operator<<(ostream & flot, const Marmotte & t) {
   flot << (Animal&)t;
   flot << "Taille : " << t.getTaille() << "cm" << endl;
   flot << "Nombre de plaquettes de chocolat emballées : " << t.getNbTabChocolat() << endl;
   return flot;
 }
