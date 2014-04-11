#include <iostream>
#include <string>

#include "../../entetes/enclos.h"

using namespace std;

int main() {
   /* *************************** */
   /* CRÉATION D'UN ENCLOS        */
   /* *************************** */
   cout << "*************************" << endl;
   cout << "* CRÉATION D'UN ENCLOS  *" << endl;
   cout << "*************************" << endl;
   // Par défaut, normal, recopie
   cout << "*** Par défaut, normal, recopie ***" << endl;
    Enclos Zozo;
    Enclos Zoo("Mon bel enclos", 1, 23 , 1);
    Enclos Zoro(Zoo);
    cout << Zozo << endl;
    cout << Zoo << endl;
    cout << Zoro << endl;

    // Test égalité/différence
    cout << endl <<  "*** Tests égalité / différence ****" << endl;
    if(Zozo == Zoo) {cout << "Égalité (ERREUR)" << endl;}
    else {cout << "Pas égalité (OK)" << endl;}

    if(Zoo == Zoro) {cout << "Égalité (OK)" << endl;}
    else {cout << "Pas égalité (ERREUR)" << endl;}

    if(Zozo != Zoo) {cout << "Différence (OK)" << endl;}
    else {cout << "Pas différence (ERREUR)" << endl;}

    if(Zoro != Zoo) {cout << "Différence (ERREUR)" << endl;}
    else {cout << "Pas différence (OK)" << endl;}

    // Affectation
    cout << endl << "*** Affectation ****" << endl;
    Zozo = Zoo;
    cout << Zozo << endl;

    // Redéfinition de tous les attributs
    Animal toto;
    cout << endl << "*** Setters ***" << endl;
    Zozo.setNom("Paul, l'enclos");
   Zozo.ajoutAnimal(&toto);
   Zozo.ajoutAnimal(&toto);
    cout << Zozo << endl;
    cout << Zozo.getAnimal(0);
    Zozo.supprimerAnimal(&toto);
    Zozo.supprimerAnimal(&toto);
    Zozo.supprimerAnimal(&toto);
    cout << Zozo << endl;

    return 0;
}
