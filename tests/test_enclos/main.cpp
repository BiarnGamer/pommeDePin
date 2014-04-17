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
    if(Zozo == Zoo) {
        cout << "Égalité (ERREUR)" << endl;
    }
    else {
        cout << "Pas égalité (OK)" << endl;
    }

    if(Zoo == Zoro) {
        cout << "Égalité (OK)" << endl;
    }
    else {
        cout << "Pas égalité (ERREUR)" << endl;
    }

    if(Zozo != Zoo) {
        cout << "Différence (OK)" << endl;
    }
    else {
        cout << "Pas différence (ERREUR)" << endl;
    }

    if(Zoro != Zoo) {
        cout << "Différence (ERREUR)" << endl;
    }
    else {
        cout << "Pas différence (OK)" << endl;
    }

    // Affectation
    cout << endl << "*** Affectation ****" << endl;
    Zozo = Zoo;
    cout << Zozo << endl;

    // Redéfinition de tous les attributs
    Tigre toto(14,15,"diego",4), titi(25,12,"robert",5);
    Elephant tata(41,52,125,"babar",2);
    cout << endl << "*** Setters ***" << endl;
    Zozo.setNom("Paul, l'enclos");
    Zozo.ajoutAnimal(&toto);
    Zozo.ajoutAnimal(&toto);
    Zozo.ajoutAnimal(&titi);
    Zozo.ajoutAnimal(&tata);
    cout << Zozo << endl;

    // Test des getters sur Animal et comptage des espèces
    cout << endl << "*** Animaux 0 et 2 ***" << endl;
    cout << *(Zozo.getPtrAnimal(0)) << endl;
    cout << *(Zozo.getPtrAnimal(2));

    cout << endl << "*** Comptage espèces ***" << endl;
    cout << "Nombre de tigres : " << Zozo.getNombreAnimaux(1) << endl;
    cout << "Nombre d'éléphants : " << Zozo.getNombreAnimaux(4) << endl;
    cout << "Nombre de girafes : " << Zozo.getNombreAnimaux(3) << endl;
    cout << "Nombre de on sait pas quoi : " << Zozo.getNombreAnimaux(25) << endl;

    // On interverti
    cout << endl << "*** Interverti 0 et 1, affiche 0 puis 1 ***" << endl;
    Zozo.intervertir(Zozo.getPtrAnimal(0), Zozo.getPtrAnimal(1));
    cout << *(Zozo.getPtrAnimal(0)) << endl;
    cout << *(Zozo.getPtrAnimal(1));

    // Suppression
    cout << endl << "*** Suppression d'un animal (un tigre : diego) ***" << endl;
    Zozo.supprimerAnimal(&toto);
    Zozo.supprimerAnimal(&toto);
    Zozo.supprimerAnimal(&toto);
    cout << Zozo << endl;
    cout << "Nombre de tigres : " << Zozo.getNombreAnimaux(1) << endl;
    cout << "Nombre d'éléphants : " << Zozo.getNombreAnimaux(4) << endl;
    cout << "Nombre de girafes : " << Zozo.getNombreAnimaux(3) << endl;

     cout << endl << "*** Animaux 0 et 1 ***" << endl;
    cout << *(Zozo.getPtrAnimal(0)) << endl;
    cout << *(Zozo.getPtrAnimal(1));
    return 0;
}
