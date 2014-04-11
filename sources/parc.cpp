#include "../entetes/parc.h"

using namespace std;



Parc::Parc():iIDAnimaux(0), iIDEnclos(0), iNbAnimaux(0), iNbEnclos(0){}

Parc::Parc(const Parc & p) {
    iIDAnimaux = p.iIDAnimaux;
    iIDEnclos = p.iIDEnclos;
    iNbAnimaux = p.iNbAnimaux;
    iNbEnclos = p.iNbEnclos;
    listeAnimaux = p.listeAnimaux;
    listeEnclos = p.listeEnclos;
}

Parc::~Parc() {
    for (int i=0; i<iNbAnimaux; i++) {
        delete listeAnimaux[i];
    }
    for (int i=0; i<iNbEnclos; i++) {
        delete listeEnclos[i];
    }
}

int Parc::getIDAnimaux() const {
    return iIDAnimaux;
}

int Parc::getIDEnclos() const {
    return iIDEnclos;
}

int Parc::getNbAnimaux() const {
    return iNbAnimaux;
}

int Parc::getNbEnclos() const {
    return iNbEnclos;
}


void Parc::animauxMangesOuTuesDansEnclos(const int iCodeEspeceModifiee, Enclos * ptrEnclos)  {

}

void Parc::creerUnEnclos(const string & nom,const int & type, const int& capacite) {
    Enclos * enclosTmp = new Enclos(nom, type, capacite, iIDEnclos++);
    iNbEnclos++;
    listeEnclos.ajouter(enclosTmp);
}

void Parc::supprimerUnEnclos(Enclos * ptrEnclos) {
    if(iNbAnimaux != 0) {
        cout << "Attention, l'enclos n'est pas vide, veuillez déplacer ou relâcher les animaux." << endl;
        cout << "Il y en a " << getIDAnimaux() << "." << endl;
        for (int i=0; i<getIDAnimaux(); i++) {
            choixEnclos(listeAnimaux[i]);
        }
    }
    listeEnclos.enlever(ptrEnclos);
    delete ptrEnclos;
    iNbEnclos--;
}

void Parc::ajoutAnimalEnclos(Animal * ptrAnimal, Enclos * ptrEnclos) {
    ptrEnclos->ajoutAnimal(ptrAnimal);
}

void Parc::Barney() {

    iNbAnimaux++;
}

void Parc::choixEnclos(Animal * ptrAnimal) {
    // Note : proposer de créer un nouvel enclos ou de relâcher l'animal
    // Appelé après création animal ou avant déplacement pour choisir le nouvel enclos
    // Dans ce dernier cas, ne pas proposer l'enclos actuel !
}

void Parc::verifChoixEnclos(Animal * ptrAnimal, Enclos * ptrEnclos) {

}

void Parc::supprimerUnAnimal(Animal * ptrAnimal) {
    listeAnimaux.enlever(ptrAnimal);
    delete ptrAnimal;
    iNbAnimaux--;
}

void Parc::deplacerUnAnimal(Animal * ptrAnimal, Enclos * ptrEnclosDepart, Enclos * ptrEnclosArrivee) {
    ptrEnclosDepart->supprimerAnimal(ptrAnimal);
    ptrEnclosArrivee->ajoutAnimal(ptrAnimal);
}

int Parc::predateurMangeProie(const int iCodePredateur, const int iCodeProie, const int iNbPredateurs, const int iNbProies) const {

}

ostream & operator<<(ostream &, const Parc &);
