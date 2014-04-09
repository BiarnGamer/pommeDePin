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
Animal::Animal():iID(-1), saitVoler(false), saitNager(false), sNom("Nom indéfini"), iEspece(0) {}

Animal::Animal(const string & nom, const int & espece, const bool vole, const bool nage, const int ID):
    iID(ID), saitVoler(vole), saitNager(nage), sNom(nom), iEspece(espece) {}

Animal::Animal(const Animal & a) {
    iID = a.iID;
    saitVoler = a.saitVoler;
    saitNager = a.saitNager;
    sNom = a.sNom;
    iEspece = a.iEspece;
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

int Animal::getEspece() const {
    return iEspece;
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

void Animal::setEspece(const int & e) {
    iEspece = e;
}


// Surcharges d'opérateurs
Animal & Animal::operator=(const Animal & a) {
    iID = a.iID;
    saitVoler = a.saitVoler;
    saitNager = a.saitNager;
    sNom = a.sNom;
    iEspece = a.iEspece;
    return *this;
}

// Ici, on regarde tous les attributs, cela servira lors d'une recherche dans un tableau par exemple donc on veut une égalité entre tous les attributs
bool Animal::operator==(const Animal & a) {
    if( iID == a.iID
        && saitVoler == a.saitVoler
        && saitNager == a.saitNager
        && sNom == a.sNom
        && iEspece == a.iEspece
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
        || iEspece != a.iEspece
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
   setEspece(1);
 }

 Tigre::Tigre(const float fGarot, const int iNbVict, const string & nom, const int ID)
   :Animal(nom, 1, false, true, ID), fHauteurGarot(fGarot), iNbGazellesCroquees(iNbVict) {}

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
   flot << "Espèce : Tigre" << endl;
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
   setEspece(2);
}

 Basque::Basque(const float flBeret, const float fCuisson, const int iNbVictoires, const int iNbRicard, const string & nom, const int ID)
   :Animal(nom, 2, false, true, ID), fLargeurBeret(flBeret), fTempsDeCuisson(fCuisson), iNbPartiesPeloteGagnees(iNbVictoires), iNbRicardBus(iNbRicard) {}

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
   flot << "Espèce : Basque" << endl;
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
   setEspece(3);
}

 Marmotte::Marmotte(const float taille, const int iNbTablettes, const string & nom, const int ID)
   :Animal(nom, 3, false, true, ID), fTaille(taille), iNbTablettesChocolatEmballees(iNbTablettes) {}

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
   flot << "Espèce : Marmotte" << endl;
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
   setEspece(4);
}

 Elephant::Elephant(const float poids, const float lTrompe, const int iNbVict, const string & nom, const int ID)
   :Animal(nom, 4, false, true, ID), fPoids(poids), fLongueurTrompe(lTrompe), iNbBraconniersEmpales(iNbVict) {}

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
   flot << "Espèce : Éléphant" << endl;
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
   setEspece(5);
}

 Aigle::Aigle(const float bec, const int loopings, const string & nom, const int ID)
   :Animal(nom, 5, true, false, ID), fLongueurBec(bec), iNbLoopings(loopings) {}

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
   flot << "Espèce : Aigle" << endl;
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
    
    Tortue::Tortue(const int iVitesseMax vit, const int iAge age, const string sCouleur couleur, const string & nom, const int ID = -1):Animal(nom,true,false,ID),iVitesseMax(vit), iAge(age), sCouleur(couleur){}
    
    Tortue::Tortue(const Tortue &);
    Tortue::~Tortue();

    int Tortue::getVitesseMax() const;
    int Tortue::getAge() const;
    string Tortue::getCouleur() const;

    void Tortue::setVitesseMax(const int);
    void Tortue::setAge(const int);
    void Tortue::setCouleur(const string);

    Tortue & Tortue::operator=(const Tortue &);
    bool Tortue::operator==(const Tortue &);
    bool Tortue::operator!=(const Tortue &);

    friend ostream & operator<<(ostream &, const Tortue &);

/***************************************************************/
/***************************************************************/
/**      Classe Loutre                                         **/
/***************************************************************/
/***************************************************************/

Loutre();
    Loutre(const int iNbAmis, const float fTaille, const string & nom, const int ID = -1);
    Loutre(const Loutre &);
    ~Loutre();

    int getNbAmis() const;
    float getTaille() const;

    void setTaille(const float);
    void setNbAmis(const int);

    Loutre & operator=(const Loutre &);
    bool operator==(const Loutre &);
    bool operator!=(const Loutre &);

    friend ostream & operator<<(ostream &, const Loutre &);

/***************************************************************/
/***************************************************************/
/**      Classe Crocodile                                         **/
/***************************************************************/
/***************************************************************/

Crocodile();
    Crocodile(const int iEnfantMange, const int iNbDents, const string & nom, const int ID = -1);
    Crocodile(const Crocodile &);
    ~Crocodile();

    int getEnfantMange() const;
    int getNbDents() const;

    void setEnfantMange(const int);
    void setNbDents(const int);

    Crocodile & operator=(const Crocodile &);
    bool operator==(const Crocodile &);
    bool operator!=(const Crocodile &);

    friend ostream & operator<<(ostream &, const Crocodile &);

/***************************************************************/
/***************************************************************/
/**      Classe Lapin                                         **/
/***************************************************************/
/***************************************************************/

Lapin();
    Lapin(const int iNbCarotteMange, const string sCouleur, const string & nom, const int ID = -1);
    Lapin(const Lapin &);
    ~Lapin();

    int getNbCarotteMange() const;
    string getCouleur() const;

    void setNbCarotteMange(const int);
    void setCouleur(const string);

    Lapin & operator=(const Lapin &);
    bool operator==(const Lapin &);
    bool operator!=(const Lapin &);

    friend ostream & operator<<(ostream &, const Lapin &);
    
/***************************************************************/
/***************************************************************/
/**      Classe Girafe                                         **/
/***************************************************************/
/***************************************************************/

Girafe();
    Girafe(const float fTaille, const int iNbTaches, const string & nom, const int ID = -1);
    Girafe(const Girafe &);
    ~Girafe();

    float getTaille() const;
    int getNbTaches() const;

    void setTaille(const float);
    void setNbTaches(const int);

    Girafe & operator=(const Girafe &);
    bool operator==(const Girafe &);
    bool operator!=(const Girafe &);

    friend ostream & operator<<(ostream &, const Girafe &);
    
  
