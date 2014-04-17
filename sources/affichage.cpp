#include <iostream>
#include <string>
#include <cstdlib>

#include "../entetes/animal.h"
#include "../entetes/enclos.h"
#include "../entetes/parc.h"

int rechercheAnimal(const Parc & Parc1) {
    system("clear");
    int IDAnimal;
    int iRangAnimal;
    cout << "Recherche d'un animal" << endl;
    cout << "Identifiant de l'animal recherché : ";
    cin >> IDAnimal;

    iRangAnimal = Parc1.rechercherAnimal(IDAnimal);

    if(iRangAnimal != -1) {
        cout << *(Parc1.getAnimal(iRangAnimal));
    }
    return iRangAnimal;
}

int rechercheEnclos(const Parc & Parc1) {
    system("clear");
    int IDEnclos;
    int iRangEnclos;
    cout << "Recherche d'un enclos" << endl;
    cout << "Identifiant de l'enclos recherché : ";
    cin >> IDEnclos;

    iRangEnclos = Parc1.rechercherAnimal(IDEnclos);

    if(iRangEnclos != -1) {
        cout << *(Parc1.getAnimal(iRangEnclos));
    }
    return iRangEnclos;
}

