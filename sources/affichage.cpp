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

void afficherTauxRemplissageEnclos(Parc &Parc1){
	for (int i=0; i<Parc1.getNbEnclos(); i++)
		cout << "Parc n " << i << " : " << Parc1.getEnclos(i).getOccupation() << "/" << Parc1.getEnclos(i).getCapacite() << endl;
}

void afficherDetailDeTousLesEnclos(Parc &Parc1){
	for (int i=0; i<Parc1.getNbEnclos(); i++)
		cout << Parc1.getEnclos(i) << end;
}
