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
	}
}
