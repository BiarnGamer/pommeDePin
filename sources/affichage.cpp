#include "../entetes/affichage.h" 

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
    else {cout << "Cet Animal n'existe pas." << endl;}
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
    else {cout << "Cet Enclos n'existe pas." << endl;}
    return iRangEnclos;
}

void afficheAnimauxParc(const Parc & Parc1) {
    system("clear");
    int iNbAnimaux = Parc1.getNbAnimaux();

    cout << "Affichage de tous les animaux du parc" << endl;

    for(int i=0; i<iNbAnimaux; i++) {
        cout << *(Parc1.getAnimal(i)) << endl;
    }
}

void afficherTauxRemplissageEnclos(const Parc &Parc1){
	system("clear");
	for (int i=0; i<Parc1.getNbEnclos(); i++)
		cout << "Parc n " << i << " : " << Parc1.getEnclos(i).getOccupation() << "/" << Parc1.getEnclos(i).getCapacite() << endl;
}

void afficherDetailDeTousLesEnclos(const Parc &Parc1){
	system("clear");
	for (int i=0; i<Parc1.getNbEnclos(); i++)
		cout << Parc1.getEnclos(i) << endl;
}

void afficherDetailEnclosEtAnimaux(const Parc &Parc1){
	int irang = rechercheEnclos(Parc1);
	for (int i=0; i<Parc1.getNbAnimaux(); i++)
		cout << Parc1.getEnclos(irang).getAnimal(i) << endl;
}

void afficherDetailEtAnimauxDeTousLesEnclos(const Parc &Parc1){
	for (int i=0; i<Parc1.getNbEnclos(); i++)
		for (int j=0; j<Parc1.getEnclos(i).getOccupation() ; j++)
			cout << Parc1.getEnclos(i).getAnimal(j) << endl;
}
