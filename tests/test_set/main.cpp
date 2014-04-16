#include <iostream>
#include "../../entetes/set.h"

using namespace std;


int main() {

    Set <int> Set1, Set2, Set3;

    cout << endl << "************************************************************************" << endl;
    cout << "*********       Test de l'implémentation du type des Set       *********";
    cout << endl << "************************************************************************" << endl;

    cout << "Création de Set1 = {1; 45; 62; 0; -65; 12}" << endl;
    Set1.ajouter(1);
    Set1.ajouter(45);
    Set1.ajouter(62);
    Set1.ajouter(0);
    Set1.ajouter(-65);
    Set1.ajouter(12);

    cout << "Création de Set2 = {} et Set3 = {}" << endl;

    cout << endl;
    afficheSiAppartient(Set2,2,14);

    afficheSiVide(Set2,2);
    afficheSiEgaux(Set1, 1, Set2, 2);
    afficheSiEgaux(Set2, 2, Set3, 3);
    afficheSiInlcut(Set1, 1, Set2, 2);
    afficheSiInlcut(Set2, 2, Set1, 1);
    afficheSiInlcut(Set2, 2, Set3, 3);

    cout << endl;

    cout << "Set2 <- Set1" << endl;
    Set2 = Set1;

    afficheSiInlcut(Set1, 1, Set2, 2);
    afficheSiInlcut(Set2, 2, Set1, 1);
    afficheSiEgaux(Set1, 1, Set2, 2);

    cout << endl << "Création de Set3 = {4; 42; 545; 85; 63}" << endl;
    cout  << "Création de Set4 à partir de Set3" << endl;
    Set3.ajouter(4);
    Set3.ajouter(42);
    Set3.ajouter(545);
    Set3.ajouter(85);
    Set3.ajouter(63);
    Set <int> Set4(Set3);
    afficheSiInlcut(Set2, 2, Set3, 3);

    cout << endl;

    affiche(Set1,1);
    affiche(Set2,2);
    affiche(Set3,3);
    affiche(Set4,4);

    cout << endl << "Retirons 42 de Set3" << endl;
    cout << "Retirons 42 de Set1" << endl;
    cout << "Ajoutons 45 à Set1" << endl;
    cout << "Retirons 45 à Set3" << endl;
    Set3.enlever(42);
    Set1.enlever(42);
    Set1.ajouter(45);
    Set3.ajouter(45);

    cout << endl;

    afficheSiVide(Set1,1);
    afficheSiAppartient(Set1,1,42);
    afficheSiAppartient(Set1,1,45);
    afficheSiAppartient(Set1,1,65);
    afficheSiAppartient(Set1,1,1);
    afficheSiAppartient(Set3,3,42);
    afficheSiAppartient(Set3,3,45);


    cout << endl;

    affiche(Set1,1);
    affiche(Set2,2);
    affiche(Set3,3);
    affiche(Set4,4);

    return 0;
}
