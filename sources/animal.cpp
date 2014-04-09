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
Animal::Animal():iID(-1), saitVoler(false), saitNager(false), sNom("Nom indéfini"), sEspece("Espèce indéfinie") {}

Animal::Animal(const string & nom, const string & espece, const bool vole, const bool nage, const int ID):
    iID(ID), saitVoler(vole), saitNager(nage), sNom(nom), sEspece(espece) {}

Animal::Animal(const Animal & a) {
    iID = a.iID;
    saitVoler = a.saitVoler;
    saitNager = a.saitNager;
    sNom = a.sNom;
    sEspece = a.sEspece;
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

string Animal::getNom() const {
    return sNom;
}

string Animal::getEspece() const {
    return sEspece;
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

void Animal::setNom(const string & n) {
    sNom = n;
}

void Animal::setEspece(const string & e) {
    sEspece = e;
}


// Surcharges d'opérateurs
Animal & Animal::operator=(const Animal & a) {
    iID = a.iID;
    saitVoler = a.saitVoler;
    saitNager = a.saitNager;
    sNom = a.sNom;
    sEspece = a.sEspece;
    return *this;
}

// Ici, on regarde tous les attributs, cela servira lors d'une recherche dans un tableau par exemple donc on veut une égalité entre tous les attributs
bool Animal::operator==(const Animal & a) {
    if( iID == a.iID
        && saitVoler == a.saitVoler
        && saitNager == a.saitNager
        && sNom == a.sNom
        && sEspece == a.sEspece
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
        || sNom != a.sNom
        || sEspece != a.sEspece
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
    flot << "Espèce : " << a.getEspece() << endl;
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
   setEspece("Tigre");
 }

 Tigre::Tigre(const float fGarot, const int iNbVict, const string & nom, const int ID)
   :Animal(nom, "Tigre", false, true, ID), fHauteurGarot(fGarot), iNbGazellesCroquees(iNbVict) {}

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
   setEspece("Basque");
}

 Basque::Basque(const float flBeret, const float fCuisson, const int iNbVictoires, const int iNbRicard, const string & nom, const int ID)
   :Animal(nom, "Basque", false, true, ID), fLargeurBeret(flBeret), fTempsDeCuisson(fCuisson), iNbPartiesPeloteGagnees(iNbVictoires), iNbRicardBus(iNbRicard) {}

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
Marmotte::Marmotte():Animal(),fTaille(0),iNbTablettesChocolatEmballees(0) {
   setSaitVoler(false);
   setSaitNager(true);
   setEspece("Marmotte");
}

 Marmotte::Marmotte(const float taille, const int iNbTablettes, const string & nom, const int ID)
   :Animal(nom, "Marmotte", false, true, ID), fTaille(taille), iNbTablettesChocolatEmballees(iNbTablettes) {}

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




/***************************************************************/
/***************************************************************/
/**      Classe Elephant                                      **/
/***************************************************************/
/***************************************************************/
Elephant::Elephant():Animal(),fPoids(0),fLongueurTrompe(0),iNbBraconniersEmpales(0) {
   setSaitVoler(false);
   setSaitNager(true);
   setEspece("Élephant");
}

 Elephant::Elephant(const float poids, const float lTrompe, const int iNbVict, const string & nom, const int ID)
   :Animal(nom, "Éléphant", false, true, ID), fPoids(poids), fLongueurTrompe(lTrompe), iNbBraconniersEmpales(iNbVict) {}

 Elephant::Elephant(const Elephant & t):Animal(t) {
   fPoids = t.fPoids;
   fLongueurTrompe = t.fLongueurTrompe;
   iNbBraconniersEmpales = t.iNbBraconniersEmpales;
 }

 Elephant::~Elephant() {}


 float Elephant::getPoids()const{
   return fPoids;
 }

 float Elephant::getLongTrompe()const{
   return fLongueurTrompe;
 }

 int Elephant::getNbVictimes() const {
   return iNbBraconniersEmpales;
 }


 void Elephant::setPoids(const float poids) {
   fPoids = poids;
 }

void Elephant::setLongTrompe(const float trompe) {
   fLongueurTrompe = trompe;
 }

 void Elephant::setNbVictimes(const int vict) {
   iNbBraconniersEmpales = vict;
 }


 Elephant & Elephant::operator=(const Elephant & t) {
   Animal::operator=(t);
   fLongueurTrompe = t.fLongueurTrompe;
   fPoids = t.fPoids;
   iNbBraconniersEmpales = t.iNbBraconniersEmpales;
   return *this;
 }

 bool Elephant::operator==(const Elephant & t) {
    if(Animal::operator==(t)
       && fPoids == t.fPoids
       && iNbBraconniersEmpales == t.iNbBraconniersEmpales
       && fLongueurTrompe == t.fLongueurTrompe
       ) {
      return true;
   }
   else {
      return false;
   }
 }

 bool Elephant::operator!=(const Elephant & t) {
   if(Animal::operator!=(t)
      || fPoids != t.fPoids
      || iNbBraconniersEmpales != t.iNbBraconniersEmpales
      || fLongueurTrompe != t.fLongueurTrompe
      ){
      return true;
   }
   else {
      return false;
   }
 }

 ostream & operator<<(ostream & flot, const Elephant & t) {
   flot << (Animal&)t;
   flot << "Poids : " << t.getPoids() << "Kg" << endl;
   flot << "Longueur de la trompe : " << t.getLongTrompe() << "cm" << endl;
   flot << "Nombre de braconniers empalés : " << t.getNbVictimes() << endl;
   return flot;
 }




/***************************************************************/
/***************************************************************/
/**      Classe Aigle                                         **/
/***************************************************************/
/***************************************************************/
 float fLongueurBec;
    int iNbLoopings;
Aigle::Aigle():Animal(),fLongueurBec(0),iNbLoopings(0) {
   setSaitVoler(true);
   setSaitNager(false);
   setEspece("Aigle");
}

 Aigle::Aigle(const float bec, const int loopings, const string & nom, const int ID)
   :Animal(nom, "Aigle", true, false, ID), fLongueurBec(bec), iNbLoopings(loopings) {}

 Aigle::Aigle(const Aigle & t):Animal(t) {
   fLongueurBec = t.fLongueurBec;
   iNbLoopings = t.iNbLoopings;
 }

 Aigle::~Aigle() {}


 float Aigle::getLongueurBec()const{
   return fLongueurBec;
 }

 int Aigle::getNbLoopings() const {
   return iNbLoopings;
 }


 void Aigle::setLongueurBec(const float bec) {
   fLongueurBec = bec;
 }

 void Aigle::setNbLoopings(const int loopings) {
   iNbLoopings = loopings;
 }


 Aigle & Aigle::operator=(const Aigle & t) {
   Animal::operator=(t);
   fLongueurBec = t.fLongueurBec;
   iNbLoopings = t.iNbLoopings;
   return *this;
 }

 bool Aigle::operator==(const Aigle & t) {
    if(Animal::operator==(t)
       && fLongueurBec == t.fLongueurBec
       && iNbLoopings == t.iNbLoopings
       ) {
      return true;
   }
   else {
      return false;
   }
 }

 bool Aigle::operator!=(const Aigle & t) {
   if(Animal::operator!=(t)
      || fLongueurBec != t.fLongueurBec
      || iNbLoopings != t.iNbLoopings
      ){
      return true;
   }
   else {
      return false;
   }
 }

 ostream & operator<<(ostream & flot, const Aigle & t) {
   flot << (Animal&)t;
   flot << "Longueur du bec : " << t.getLongueurBec() << "cm" << endl;
   flot << "Nombre de loopings en vol : " << t.getNbLoopings() << endl;
   return flot;
 }

 
  /***************************************************************/
/***************************************************************/
/**      Classe Tortue                                         **/
/***************************************************************/
/***************************************************************/

    Tortue::Tortue():Animal(),iVitesseMax(0),iAge(0),sCouleur("Inconnue"){
     setSaitNager(true);
     setSaitVoler(false);
    }
    
    Tortue::Tortue(const int vit, const int age, const string couleur, const string & nom, const int ID = -1):Animal(nom,true,false,ID),iVitesseMax(vit), iAge(age), sCouleur(couleur){}
    
    Tortue::Tortue(const Tortue &){}
    Tortue::~Tortue(){}

    int Tortue::getVitesseMax() const{}
    int Tortue::getAge() const{}
    string Tortue::getCouleur() const{}

    void Tortue::setVitesseMax(const int){}
    void Tortue::setAge(const int){}
    void Tortue::setCouleur(const string){}

    Tortue & Tortue::operator=(const Tortue &){}
    bool Tortue::operator==(const Tortue &){}
    bool Tortue::operator!=(const Tortue &){}

    friend ostream & operator<<(ostream &, const Tortue &){}

/***************************************************************/
/***************************************************************/
/**      Classe Loutre                                         **/
/***************************************************************/
/***************************************************************/

Loutre::Loutre(){}
    Loutre::Loutre(const int iNbAmis, const float fTaille, const string & nom, const int ID = -1){}
    Loutre::Loutre(const Loutre &){}
    Loutre::~Loutre(){}

    int Loutre::getNbAmis() const{}
    float Loutre::getTaille() const{}

    void Loutre::setTaille(const float){}
    void Loutre::setNbAmis(const int){}

    Loutre & Loutre::operator=(const Loutre &){}
    bool Loutre::operator==(const Loutre &){}
    bool Loutre::operator!=(const Loutre &){}

    friend ostream & operator<<(ostream &, const Loutre &){}

/***************************************************************/
/***************************************************************/
/**      Classe Crocodile                                         **/
/***************************************************************/
/***************************************************************/

Crocodile::Crocodile(){}
    Crocodile::Crocodile(const int iEnfantMange, const int iNbDents, const string & nom, const int ID = -1){}
    Crocodile::Crocodile(const Crocodile &){}
    Crocodile::~Crocodile(){}

    int Crocodile::getEnfantMange() const{}
    int Crocodile::getNbDents() const{}

    void Crocodile::setEnfantMange(const int){}
    void Crocodile::setNbDents(const int){}

    Crocodile & Crocodile::operator=(const Crocodile &){}
    bool Crocodile::operator==(const Crocodile &){}
    bool Crocodile::operator!=(const Crocodile &){}

    friend ostream & operator<<(ostream &, const Crocodile &){}

/***************************************************************/
/***************************************************************/
/**      Classe Lapin                                         **/
/***************************************************************/
/***************************************************************/

Lapin::Lapin(){}
    Lapin::Lapin(const int iNbCarotteMange, const string sCouleur, const string & nom, const int ID = -1){}
    Lapin::Lapin(const Lapin &){}
    Lapin::~Lapin(){}

    int Lapin::getNbCarotteMange() const{}
    string Lapin::getCouleur() const{}

    void Lapin::setNbCarotteMange(const int){}
    void Lapin::setCouleur(const string){}

    Lapin & Lapin::operator=(const Lapin &){}
    bool Lapin::operator==(const Lapin &){}
    bool Lapin::operator!=(const Lapin &){}

    friend ostream & operator<<(ostream &, const Lapin &){}
    
/***************************************************************/
/***************************************************************/
/**      Classe Girafe                                         **/
/***************************************************************/
/***************************************************************/

Girafe::Girafe(){}
    Girafe::Girafe(const float fTaille, const int iNbTaches, const string & nom, const int ID = -1){}
    Girafe::Girafe(const Girafe &){}
    Girafe::~Girafe(){}

    float Girafe::getTaille(){}
    int Girafe::getNbTaches(){}

    void Girafe::setTaille(const float){}
    void Girafe::setNbTaches(const int){}

    Girafe & Girafe::operator=(const Girafe &){}
    bool Girafe::operator==(const Girafe &){}
    bool Girafe::operator!=(const Girafe &){}

    friend ostream & operator<<(ostream &, const Girafe &){}
    
  