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
Animal::Animal():iID(-1), saitVoler(false), saitNager(false), sNom("Nom indéfini"), iEspece(-1) {}

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
bool Animal::operator==(const Animal & a)  const {
	if( iID == a.iID
			&& saitVoler == a.saitVoler
			&& saitNager == a.saitNager
			&& sNom == a.sNom
			&& iEspece == a.iEspece
	  ) {
		return true;
	} else {
		return false;
	}

}

bool Animal::operator!=(const Animal & a)  const {
	if( iID != a.iID
			|| saitVoler != a.saitVoler
			|| saitNager != a.saitNager
			|| sNom != a.sNom
			|| iEspece != a.iEspece
	  ) {
		return true;
	} else {
		return false;
	}
}

void Animal::affiche(ostream & flot) const {
	flot << "N° animal : " << getID() << endl;
	flot << "Nom : " << getNom() << endl;

	if(getSaitVoler()) {
		flot << "Vole : oui" << endl;
	} else {
		flot << "Vole : non" << endl;
	}

	if(getSaitNager()) {
		flot << "Nage : oui" << endl;
	} else {
		flot << "Nage : non" << endl;
	}
}

ostream& operator<<(ostream& flot, const Animal & a) {
	a.affiche(flot);
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
	setEspece(TIGRE);
}

Tigre::Tigre(const float fGarot, const int iNbVict, const string & nom, const int ID)
	:Animal(nom, TIGRE, false, true, ID), fHauteurGarot(fGarot), iNbGazellesCroquees(iNbVict) {}

Tigre::Tigre(const Tigre & t):Animal(t) {
	fHauteurGarot = t.fHauteurGarot;
	iNbGazellesCroquees = t.iNbGazellesCroquees;
}

Tigre::~Tigre() {}


float Tigre::getGarot() const {
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

bool Tigre::operator==(const Tigre & t)  const {
	if(Animal::operator==(t)
			&& fHauteurGarot == t.fHauteurGarot
			&& iNbGazellesCroquees == t.iNbGazellesCroquees
	  ) {
		return true;
	} else {
		return false;
	}
}

bool Tigre::operator!=(const Tigre & t)  const {
	if(Animal::operator!=(t)
			|| fHauteurGarot != t.fHauteurGarot
			|| iNbGazellesCroquees != t.iNbGazellesCroquees
	  ) {
		return true;
	} else {
		return false;
	}
}

void Tigre::affiche(ostream & flot) const {
	Animal::affiche(flot);
	flot << "Espèce : Tigre" << endl;
	flot << "Hauteur au garot : " << getGarot() << "cm" << endl;
	flot << "Nombre de gazelles croquées : " << getNbVictimes() << endl;
}

ostream& operator<<(ostream& flot, const Tigre & a) {
	a.affiche(flot);
	return flot;
}



/***************************************************************/
/***************************************************************/
/**      Classe Basque                                        **/
/***************************************************************/
/***************************************************************/
Basque::Basque():Animal(), fLargeurBeret(0), fTempsDeCuisson(0), iNbPartiesPeloteGagnees(0), iNbRicardBus(0) {
	setSaitVoler(false);
	setSaitNager(true);
	setEspece(BASQUE);
}

Basque::Basque(const float flBeret, const float fCuisson, const int iNbVictoires, const int iNbRicard, const string & nom, const int ID)
	:Animal(nom, BASQUE, false, true, ID), fLargeurBeret(flBeret), fTempsDeCuisson(fCuisson), iNbPartiesPeloteGagnees(iNbVictoires), iNbRicardBus(iNbRicard) {}

Basque::Basque(const Basque & b):Animal(b) {
	fLargeurBeret = b.fLargeurBeret;
	fTempsDeCuisson = b.fTempsDeCuisson;
	iNbPartiesPeloteGagnees = b.iNbPartiesPeloteGagnees;
	iNbRicardBus = b.iNbRicardBus;
}

Basque::~Basque() {}

float Basque::getLargeurBeret() const {
	return fLargeurBeret;
}

float Basque::getTempsCuisson() const {
	return fTempsDeCuisson;
}

int Basque::getNbVictoires() const {
	return iNbPartiesPeloteGagnees;
}

int Basque::getNbRicard() const {
	return iNbRicardBus;
}


void Basque::setLargeurBeret(const float beret) {
	fLargeurBeret = beret;
}

void Basque::setTempsCuisson(const float cuisson) {
	fTempsDeCuisson = cuisson;
}

void Basque::setNbVictoires(const int victoires) {
	iNbPartiesPeloteGagnees = victoires;
}

void Basque::setNbRicard(const int ricard) {
	iNbRicardBus = ricard;
}


Basque & Basque::operator=(const Basque & b) {
	Animal::operator=(b);
	fLargeurBeret = b.fLargeurBeret;
	fTempsDeCuisson = b.fTempsDeCuisson;
	iNbPartiesPeloteGagnees = b.iNbPartiesPeloteGagnees;
	iNbRicardBus = b.iNbRicardBus;
	return *this;
}

bool Basque::operator==(const Basque & b) const {
	if(Animal::operator==(b)
			&& fLargeurBeret == b.fLargeurBeret
			&& fTempsDeCuisson == b.fTempsDeCuisson
			&& iNbPartiesPeloteGagnees == b.iNbPartiesPeloteGagnees
			&& iNbRicardBus == b.iNbRicardBus) {
		return true;
	} else {
		return false;
	}
}

bool Basque::operator!=(const Basque & b) const {
	if(Animal::operator!=(b)
			|| fLargeurBeret != b.fLargeurBeret
			|| fTempsDeCuisson != b.fTempsDeCuisson
			|| iNbPartiesPeloteGagnees != b.iNbPartiesPeloteGagnees
			|| iNbRicardBus != b.iNbRicardBus) {
		return true;
	} else {
		return false;
	}
}

void Basque::affiche(ostream & flot) const {
	Animal::affiche(flot);
	flot << "Espèce : Basque" << endl;
	flot << "Largeur du béret : " << getLargeurBeret() << "cm" << endl;
	flot << "Temps de cuisson : " << getTempsCuisson() << "min" << endl;
	flot << "Nombre de parties de pelotes gagnées : " << getNbVictoires() << endl;
	flot << "Nombre de Ricards bus : " << getNbRicard() << endl;
}

ostream& operator<<(ostream& flot, const Basque & a) {
	a.affiche(flot);
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
	setEspece(MARMOTTE);
}

Marmotte::Marmotte(const float taille, const int iNbTablettes, const string & nom, const int ID)
	:Animal(nom, MARMOTTE, false, true, ID), fTaille(taille), iNbTablettesChocolatEmballees(iNbTablettes) {}

Marmotte::Marmotte(const Marmotte & t):Animal(t) {
	fTaille = t.fTaille;
	iNbTablettesChocolatEmballees = t.iNbTablettesChocolatEmballees;
}

Marmotte::~Marmotte() {}


float Marmotte::getTaille()const {
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

bool Marmotte::operator==(const Marmotte & t)  const {
	if(Animal::operator==(t)
			&& fTaille == t.fTaille
			&& iNbTablettesChocolatEmballees == t.iNbTablettesChocolatEmballees
	  ) {
		return true;
	} else {
		return false;
	}
}

bool Marmotte::operator!=(const Marmotte & t) const {
	if(Animal::operator!=(t)
			|| fTaille != t.fTaille
			|| iNbTablettesChocolatEmballees != t.iNbTablettesChocolatEmballees
	  ) {
		return true;
	} else {
		return false;
	}
}

void Marmotte::affiche(ostream & flot) const {
	Animal::affiche(flot);
	flot << "Espèce : Marmotte" << endl;
	flot << "Taille : " << getTaille() << "cm" << endl;
	flot << "Nombre de plaquettes de chocolat emballées : " << getNbTabChocolat() << endl;
}

ostream& operator<<(ostream& flot, const Marmotte & a) {
	a.affiche(flot);
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
	setEspece(ELEPHANT);
}

Elephant::Elephant(const float poids, const float lTrompe, const int iNbVict, const string & nom, const int ID)
	:Animal(nom, ELEPHANT, false, true, ID), fPoids(poids), fLongueurTrompe(lTrompe), iNbBraconniersEmpales(iNbVict) {}

Elephant::Elephant(const Elephant & t):Animal(t) {
	fPoids = t.fPoids;
	fLongueurTrompe = t.fLongueurTrompe;
	iNbBraconniersEmpales = t.iNbBraconniersEmpales;
}

Elephant::~Elephant() {}


float Elephant::getPoids()const {
	return fPoids;
}

float Elephant::getLongTrompe()const {
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

bool Elephant::operator==(const Elephant & t) const {
	if(Animal::operator==(t)
			&& fPoids == t.fPoids
			&& iNbBraconniersEmpales == t.iNbBraconniersEmpales
			&& fLongueurTrompe == t.fLongueurTrompe
	  ) {
		return true;
	} else {
		return false;
	}
}

bool Elephant::operator!=(const Elephant & t)  const {
	if(Animal::operator!=(t)
			|| fPoids != t.fPoids
			|| iNbBraconniersEmpales != t.iNbBraconniersEmpales
			|| fLongueurTrompe != t.fLongueurTrompe
	  ) {
		return true;
	} else {
		return false;
	}
}

void Elephant::affiche(ostream & flot) const {
	Animal::affiche(flot);
	flot << "Espèce : Éléphant" << endl;
	flot << "Poids : " << getPoids() << "Kg" << endl;
	flot << "Longueur de la trompe : " << getLongTrompe() << "cm" << endl;
	flot << "Nombre de braconniers empalés : " << getNbVictimes() << endl;
}

ostream& operator<<(ostream& flot, const Elephant & a) {
	a.affiche(flot);
	return flot;
}




/***************************************************************/
/***************************************************************/
/**      Classe Aigle                                         **/
/***************************************************************/
/***************************************************************/

Aigle::Aigle():Animal(),fLongueurBec(0),iNbLoopings(0) {
	setSaitVoler(true);
	setSaitNager(false);
	setEspece(AIGLE);
}

Aigle::Aigle(const float bec, const int loopings, const string & nom, const int ID)
	:Animal(nom, AIGLE, true, false, ID), fLongueurBec(bec), iNbLoopings(loopings) {}

Aigle::Aigle(const Aigle & t):Animal(t) {
	fLongueurBec = t.fLongueurBec;
	iNbLoopings = t.iNbLoopings;
}

Aigle::~Aigle() {}


float Aigle::getLongueurBec()const {
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

bool Aigle::operator==(const Aigle & t) const {
	if(Animal::operator==(t)
			&& fLongueurBec == t.fLongueurBec
			&& iNbLoopings == t.iNbLoopings
	  ) {
		return true;
	} else {
		return false;
	}
}

bool Aigle::operator!=(const Aigle & t) const {
	if(Animal::operator!=(t)
			|| fLongueurBec != t.fLongueurBec
			|| iNbLoopings != t.iNbLoopings
	  ) {
		return true;
	} else {
		return false;
	}
}

void Aigle::affiche(ostream & flot) const {
	Animal::affiche(flot);
	flot << "Espèce : Aigle" << endl;
	flot << "Longueur du bec : " << getLongueurBec() << "cm" << endl;
	flot << "Nombre de loopings en vol : " << getNbLoopings() << endl;
}

ostream& operator<<(ostream& flot, const Aigle & a) {
	a.affiche(flot);
	return flot;
}


/***************************************************************/
/***************************************************************/
/**      Classe Tortue                                         **/
/***************************************************************/
/***************************************************************/

Tortue::Tortue():Animal(),iVitesseMax(0),iAge(0),sCouleur("Inconnue") {
	setSaitNager(true);
	setSaitVoler(false);
	setEspece(TORTUE);
}

Tortue::Tortue(const int vit, const int age, const string couleur, const string & nom, const int ID)
	:Animal(nom,TORTUE ,false,true,ID), iVitesseMax(vit), iAge(age), sCouleur(couleur) {}

Tortue::Tortue(const Tortue & t):Animal(t) {
	iVitesseMax=t.iVitesseMax;
	iAge=t.iAge;
	sCouleur =t.sCouleur;
}

Tortue::~Tortue() {}

int Tortue::getVitesseMax() const {
	return iVitesseMax;
}
int Tortue::getAge() const {
	return iAge;
}
string Tortue::getCouleur() const {
	return sCouleur;
}

void Tortue::setVitesseMax(const int vit) {
	iVitesseMax=vit;
}
void Tortue::setAge(const int age) {
	iAge = age;
}
void Tortue::setCouleur(const string couleur) {
	sCouleur = couleur;
}

Tortue & Tortue::operator=(const Tortue & t) {
	// on reprend l'opérateur = de animal + les caractéristiques
	Animal::operator=(t);
	iVitesseMax=t.iVitesseMax;
	iAge=t.iAge;
	sCouleur=t.sCouleur;
	//on retourne donc le pointeur vers cet objet
	return *this;
}
bool Tortue::operator==(const Tortue & t) const {
	if(Animal::operator==(t)
			&& iVitesseMax == t.iVitesseMax
			&& sCouleur == t.sCouleur
			&& iAge == t.iAge
	  ) {
		return true;
	} else {
		return false;
	}
}

bool Tortue::operator!=(const Tortue & t) const {
	if(Animal::operator!=(t)
			|| iVitesseMax != t.iVitesseMax
			|| sCouleur != t.sCouleur
			|| iAge != t.iAge
	  ) {
		return true;
	} else {
		return false;
	}
}

void Tortue::affiche(ostream & flux) const {
	Animal::affiche(flux);
	flux << "Espèce : Tortue "<< endl;
	flux << "Vitesse max : " << getVitesseMax() << "km/h"<< endl;
	flux << "Couleur : " << getCouleur()<< endl;
	flux << "Age : " << getAge() << "ans" << endl;
}

ostream& operator<<(ostream& flux, const Tortue & a) {
	a.affiche(flux);
	return flux;
}

/***************************************************************/
/***************************************************************/
/**      Classe Loutre                                         **/
/***************************************************************/
/***************************************************************/

Loutre::Loutre():Animal(),fTaille(0), iNbAmis(0) {
	setSaitNager(true);
	setSaitVoler(false);
	setEspece(LOUTRE);
}

Loutre::Loutre(const int amis, const float taille, const string & nom, const int ID):Animal(nom, LOUTRE, false, true, ID),fTaille(taille), iNbAmis(amis) {}

Loutre::Loutre(const Loutre & l):Animal(l) {
	iNbAmis=l.iNbAmis;
	fTaille=l.fTaille;
}

Loutre::~Loutre() {}

int Loutre::getNbAmis() const {
	return iNbAmis;
}
float Loutre::getTaille() const {
	return fTaille;
}

void Loutre::setTaille(const float fa) {
	fTaille=fa;
}
void Loutre::setNbAmis(const int iAmis) {
	iNbAmis=iAmis;
}

Loutre & Loutre::operator=(const Loutre & l) {
	Animal::operator=(l);
	fTaille=l.fTaille;
	iNbAmis=l.iNbAmis;
	return *this;
}
bool Loutre::operator==(const Loutre & l) const {
	if(Animal::operator==(l)
			&& fTaille == l.fTaille
			&& iNbAmis == l.iNbAmis
	  ) {
		return true;
	} else {
		return false;
	}
}

bool Loutre::operator!=(const Loutre & l) const {
	if(Animal::operator!=(l)
			|| fTaille != l.fTaille
			|| iNbAmis != l.iNbAmis
	  ) {
		return true;
	} else {
		return false;
	}
}

void Loutre::affiche(ostream & flux) const {
	Animal::affiche(flux);
	flux << "Espèce : Loutre " <<endl;
	flux << "Nombre Amis : " << iNbAmis<< endl;
	flux << "Taille : " << fTaille << "cm" << endl;
}

ostream& operator<<(ostream& flux, const Loutre & a) {
	a.affiche(flux);
	return flux;
}

/***************************************************************/
/***************************************************************/
/**      Classe Crocodile                                         **/
/***************************************************************/
/***************************************************************/

Crocodile::Crocodile():Animal(),iNbDents(0),iEnfantMange(0) {
	setSaitNager(true);
	setSaitVoler(false);
	setEspece(CROCODILE);
}
Crocodile::Crocodile(const int Mange, const int Dents, const string & nom, const int ID):Animal(nom,CROCODILE,false,true,ID), iEnfantMange(Mange),iNbDents(Dents) {}

Crocodile::Crocodile(const Crocodile &c):Animal(c) {
	iNbDents=c.iNbDents;
	iEnfantMange=c.iEnfantMange;
}

Crocodile::~Crocodile() {}

int Crocodile::getEnfantMange() const {
	return iEnfantMange;
}
int Crocodile::getNbDents() const {
	return iNbDents;
}

void Crocodile::setEnfantMange(const int enfant) {
	iEnfantMange = enfant;
}
void Crocodile::setNbDents(const int dents) {
	iNbDents = dents;
}

Crocodile & Crocodile::operator=(const Crocodile & c) {
	Animal::operator=(c);
	iEnfantMange=c.iEnfantMange;
	iNbDents=c.iNbDents;
	return *this;
}

bool Crocodile::operator==(const Crocodile & c) const {
	if(Animal::operator==(c)
			&& iEnfantMange == c.iEnfantMange
			&& iNbDents == c.iNbDents
	  ) {
		return true;
	} else {
		return false;
	}
}
bool Crocodile::operator!=(const Crocodile & c) const {
	if(Animal::operator!=(c)
			|| iEnfantMange != c.iEnfantMange
			|| iNbDents != c.iNbDents
	  ) {
		return true;
	} else {
		return false;
	}
}

void Crocodile::affiche(ostream & flux) const {
	Animal::affiche(flux);
	flux << "Espèce : Crocodile"<< endl;
	flux << "Nombre de dents : " << getNbDents() << endl;
	flux << "Nombre d'enfant mangé : " << getEnfantMange() << endl;
}

ostream& operator<<(ostream& flux, const Crocodile & a) {
	a.affiche(flux);
	return flux;
}

/***************************************************************/
/***************************************************************/
/**      Classe Lapin                                         **/
/***************************************************************/
/***************************************************************/

Lapin::Lapin():Animal(),iNbCarotteMange(0),sCouleur("") {
	setSaitNager(false);
	setSaitVoler(false);
	setEspece(LAPIN);
}

Lapin::Lapin(const int carotte, const string couleur, const string & nom, const int ID):Animal(nom,LAPIN,false,false,ID),sCouleur(couleur),iNbCarotteMange(carotte) {}

Lapin::Lapin(const Lapin &l):Animal(l) {
	iNbCarotteMange=l.iNbCarotteMange;
	sCouleur=l.sCouleur;
}

Lapin::~Lapin() {}

int Lapin::getNbCarotteMange() const {
	return iNbCarotteMange;
}
string Lapin::getCouleur() const {
	return sCouleur;
}

void Lapin::setNbCarotteMange(const int nbcarotte) {
	iNbCarotteMange = nbcarotte;
}
void Lapin::setCouleur(const string sChaine) {
	sCouleur = sChaine;
}

Lapin & Lapin::operator=(const Lapin & l) {
	Animal::operator=(l);
	iNbCarotteMange=l.iNbCarotteMange;
	sCouleur=l.sCouleur;
	return *this;
}

bool Lapin::operator==(const Lapin & l) const {
	if(Animal::operator==(l)
			&& iNbCarotteMange==l.iNbCarotteMange
			&& sCouleur==l.sCouleur)
		return true;
	else return false;
}
bool Lapin::operator!=(const Lapin & l) const {
	if(Animal::operator!=(l)
			|| iNbCarotteMange!=l.iNbCarotteMange
			|| sCouleur!=l.sCouleur)
		return true;
	else return false;
}

void Lapin::affiche(ostream & flux) const {
	Animal::affiche(flux);
	flux << "Espèce : Lapin " << endl;
	flux << "Nombre de carotte(s) mangée(s) : " << getNbCarotteMange()<< endl;
	flux << "Couleur : " << getCouleur()<< endl;
}

ostream& operator<<(ostream& flux, const Lapin & a) {
	a.affiche(flux);
	return flux;
}

/***************************************************************/
/***************************************************************/
/**      Classe Girafe                                         **/
/***************************************************************/
/***************************************************************/

Girafe::Girafe():Animal(),fTaille(0),iNbTaches(0) {
	setSaitNager(false);
	setSaitVoler(false);
	setEspece(GIRAFE);
}
Girafe::Girafe(const float taille, const int taches, const string & nom, const int ID):Animal(nom,GIRAFE,false,false, ID),fTaille(taille),iNbTaches(taches) {}

Girafe::Girafe(const Girafe & g):Animal(g) {
	fTaille=g.fTaille;
	iNbTaches=g.iNbTaches;
}
Girafe::~Girafe() {}

float Girafe::getTaille() const {
	return fTaille;
}
int Girafe::getNbTaches() const {
	return iNbTaches;
}

void Girafe::setTaille(const float taille) {
	fTaille = taille;
}
void Girafe::setNbTaches(const int tache) {
	iNbTaches=tache;
}
Girafe & Girafe::operator=(const Girafe & g) {
	Animal::operator=(g);
	fTaille=g.fTaille;
	iNbTaches=g.iNbTaches;
	return *this;
}
bool Girafe::operator==(const Girafe & g) const {
	if(Animal::operator==(g)
			&& fTaille==g.fTaille
			&& iNbTaches==g.iNbTaches)
		return true;
	else return false;
}
bool Girafe::operator!=(const Girafe & g) const {
	if(Animal::operator!=(g)
			|| fTaille!=g.fTaille
			|| iNbTaches!=g.iNbTaches)
		return true;
	else return false;
}


void Girafe::affiche(ostream & flux) const {
	Animal::affiche(flux);
	flux << "Espèce : Girafe"<< endl;
	flux << "Taille : " << getTaille() << "m" << endl;
	flux << "iNbTaches " << getNbTaches()<< endl;
}

ostream& operator<<(ostream& flux, const Girafe & a) {
	a.affiche(flux);
	return flux;
}
