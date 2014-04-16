#include <iostream>
#include <string>

#include "../../entetes/parc.h"

using namespace std;

int main() {
    /* *************************** */
    /* CRÉATION D'UN PARC          */
    /* *************************** */
    cout << "*************************" << endl;
    cout << "* CRÉATION D'UN PARC    *" << endl;
    cout << "*************************" << endl;
    // Par défaut
    cout << "*** Par défaut ***" << endl;
    Parc Parc1;

    // Création d'un enclos
    Parc1.creerUnEnclos("Mon enclos",1, 25);
    cout << Parc1.getEnclos(0) << endl;

    Parc1.creerUnEnclos("Mon autre enclos", 2, 32);
    cout << Parc1.getEnclos(1);
    cout << Parc1.getNbEnclos() << endl;

    Tigre t(44,4,"Diego",1);
    Animal * p = &t;

    cout << *p;

    Parc1.Barney();


    cout << Parc1.getEnclos(0);
    cout << *Parc1.getEnclos(0).getPtrAnimal(0);
    int a;
    cin >> a;

    return 0;
}
