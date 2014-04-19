#include "../entetes/utilisateur.h"

/**********************/
/****** POUR ENCLOS ***/
/**********************/

// Fonction de demande à l'utilisateur

string selectionNomEnclos(){
	string sNom;
	cout << "Entrez le nom pour l'Enclos : ";
	cin >> sNom;
	return sNom;
}

int selectionTypeEnclos(){
	int iType;
	cout << "Entrez "<< ENCLOS << " pour un Enclos, " << BASSIN << " pour un Bassin ou "<< CAGE <<" pour une cage : ";
	cin >> iType;
	if (iType != ENCLOS && iType != BASSIN && iType != CAGE){
		do {
		cout << "Erreur de Saisie, veuillez recommencer." << endl;
		cout << "Entrez "<< ENCLOS << " pour un Enclos, " << BASSIN << " pour un Bassin ou "<< CAGE <<" pour une cage : ";
		cin >> iType;
		} while (iType != ENCLOS && iType != BASSIN && iType != CAGE);
		return iType;
	}
	else return (iType);
}

int selectionCapaciteEnclos(){
	int iCapacite;
	cout << "Entrez la valeur de la capacite de l'Enclos : ";
	cin >> iCapacite;
	if (iCapacite > 0)
		return iCapacite;
	else {
		do{
			cout << "Erreur de Saisie, veuillez recommencer." << endl;
			cout << "Entrez la valeur de la capacite de l'Enclos : ";
			cin >> iCapacite;
		}while (iCapacite <= 0);
		return iCapacite;
	}
}

int selectionChoixAnimal(){
	int iChoix = -1;
	cout << "Voici les choix possibles d'animaux : " << endl;
	cout << "Tapez 0 pour la Girafe" << endl;
	cout << "Tapez 1 pour le Tigre" << endl;
	cout << "Tapez 2 pour le Basque" << endl;
	cout << "Tapez 3 pour la Marmotte" << endl;
	cout << "Tapez 4 pour l'Elephant" << endl;
	cout << "Tapez 5 pour l'Aigle" << endl;
	cout << "Tapez 6 pour la Tortue" << endl;
	cout << "Tapez 7 pour la Loutre" << endl;
	cout << "Tapez 8 pour le Crocodile" << endl;
	cout << "Tapez 9 pour le Lapin" << endl;
	cout << "Votre choix : ";
	cin >> iChoix;
	if (iChoix >=0 && iChoix <10)
		return iChoix;
	else {
		do{
			cout << "Erreur de saisie, veuillez recommencer." << endl;
			cout << "Voici les choix possibles d'animaux : " << endl;
			cout << "Tapez 0 pour la Girafe" << endl;
			cout << "Tapez 1 pour le Tigre" << endl;
			cout << "Tapez 2 pour le Basque" << endl;
			cout << "Tapez 3 pour la Marmotte" << endl;
			cout << "Tapez 4 pour l'Elephant" << endl;
			cout << "Tapez 5 pour l'Aigle" << endl;
			cout << "Tapez 6 pour la Tortue" << endl;
			cout << "Tapez 7 pour la Loutre" << endl;
			cout << "Tapez 8 pour le Crocodile" << endl;
			cout << "Tapez 9 pour le Lapin" << endl;
			cout << "Votre choix : ";
			cin >> iChoix;
		}while (iChoix <0 || iChoix > 9);
		return iChoix;
	}
}

int choixEnclosCreerAnimal(){
	int iIDEnclos;
	bool existe = false;
	int j=0; 
	// Affichage des enclos et de leur occupation
	iNbEnclos = Parc1.getNbEnclos();
	for (int i=0; i< iNbEnclos; i++){
		cout << "Enclos " << i << " - ID : " << Parc1.getEnclos(i)->getID() << " - Taux Occupation : " Parc1.getEnclos(i)->getOccupation() << " / " << Parc1.getEnclos(i)->getCapacite() << endl;
	}
	// Choix de l'enclos
	cout <<"Entrez l'ID (ATTENTION choisissez l'identifiant) de l'enclos choisi : ";
	cin >> iIDEnclos;
	// vérification que l'ID existe
	while (!existe && j < iNbEnclos){
		if (Parc1.getEnclos(j)->getID() == iIDEnclos)
			existe=true;
		else j++;
	}
	if (existe)
		return iIDEnclos;
	else {
		cout << "Erreur de saisie, veuillez recommencer."
		do{
			for (int i=0; i< iNbEnclos; i++){
				cout << "Enclos " << i << " - ID : " << Parc1.getEnclos(i)->getID() << " - Taux Occupation : " Parc1.getEnclos(i)->getOccupation() << " / " << Parc1.getEnclos(i)->getCapacite() << endl;
			}
			cout <<"Entrez l'ID (ATTENTION choisissez l'identifiant) de l'enclos choisi : ";
			cin >> iIDEnclos;
			while (!existe && j < iNbEnclos){
				if (Parc1.getEnclos(j)->getID() == iIDEnclos)
					existe=true;
				else j++;
			}
			// Pas besoin de RAZ de existe car si on recommence c'est qu'il est toujours a faux
		}while (!existe);
		return iIDEnclos;
	}
}



Girafe * creerGirafe(){
	float fTaille;
	int iNbTaches;
	string sNom;
	
	cout << "Entrez le nom de l'animal : ";
	cin >> sNom;
	cout << "Entrez sa taille en m (entre 0 et 10) : ";
	cin >> fTaille;
	if (fTaille < 0 || fTaille > 10){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez sa taille en m (entre 0 et 10) : ";
			cin >> fTaille;
		}while (fTaille < 0 || fTaille > 10);
	}
	cout << "Entrez le nombre de tâche de l'animal : ";
	cin >> iNbTaches;
	if (iNbTaches < 0){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez le nombre de tâche de l'animal : ";
			cin >> iNbTaches;
		}while (iNbTaches < 0);
	}
	Girafe * g;
	g = new Girafe(fTaille,iNbTaches,sNom);
	return g;
}

Loutre * creerLoutre(){
	float fTaille;
	int iNbAmis;
	string sNom;
	
	cout << "Entrez le nom de l'animal : ";
	cin >> sNom;
	cout << "Entrez sa taille en cm (entre 0 et 500) : ";
	cin >> fTaille;
	if (fTaille < 0 || fTaille > 500){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez sa taille en cm (entre 0 et 500) : ";
			cin >> fTaille;
		}while (fTaille < 0 || fTaille > 500);
	}
	cout << "Entrez le nombre d'amis de l'animal : ";
	cin >> iNbAmis;
	if (iNbAmis < 0){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez le nombre d'amis de l'animal : ";
			cin >> iNbAmis;
		}while (iNbAmis < 0);
	}
	Loutre * l;
	l = new Loutre(fTaille,iNbAmis,sNom);
	return l;
}