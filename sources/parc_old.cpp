#include "../entetes/parc_old.h"
#include <cstdlib>
#include <ctime>

using namespace std;




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


void Parc::Barney() {
	bool succes = true;
	float fTaille;
	int iNbTaches;
	int iNbVict;
	float fBeret;
	float fCuisson;
	int iNbBelote;
	int iNbRicard;
	int iNbChocolat;
	float fTrompe;
	float fPoids;
	int iVitesse;
	int iAge;
	string sCouleur;
	int iNbAmis;
	float fTailleBec;
	int iNbLoopings;
	int iEnfants;
	int iDents;
	int iCarottes;

	string sNom;
	int iEspece;
	cout << "Espèce de l'animal : ";
	cin >> iEspece;
	cout << "Nom : ";
	cin >> sNom;

	switch(iEspece) {
	case 0:
		cout << "Taille (m) : ";
		cin >> fTaille;
		cout << "Nombre de tâches : ";
		cin >> iNbTaches;
		listeAnimaux.ajouter(new Girafe(fTaille, iNbTaches, sNom, iIDAnimaux++));
		iNbAnimaux++;
		break;
	case 1:
		cout << "Hauteur au garot (cm) : ";
		cin >> fTaille;
		cout << "Nombre de gazelles croquées : ";
		cin >> iNbVict;
		listeAnimaux.ajouter(new Tigre(fTaille, iNbVict, sNom, iIDAnimaux++));
		iNbAnimaux++;
		break;
	case 2:
		cout << "Largeur du béret (cm) : ";
		cin >> fBeret;
		cout << "Temps de cuisson (min) : ";
		cin >> fCuisson;
		cout << "Nombre de parties de belote gagnées : ";
		cin >> iNbBelote;
		cout << "Nombre de Ricards bus : ";
		cin >> iNbRicard;
		listeAnimaux.ajouter(new Basque(fBeret, fCuisson, iNbBelote, iNbRicard, sNom, iIDAnimaux++));
		iNbAnimaux++;
		break;
	case 3:
		cout << "Taille (cm) : ";
		cin >> fTaille;
		cout << "Nombre de tablettes de chocolat emballées : ";
		cin >> iNbChocolat;
		listeAnimaux.ajouter(new Marmotte(fTaille, iNbChocolat, sNom, iIDAnimaux++));
		iNbAnimaux++;
		break;
	case 4:
		cout << "Poids (kg) : ";
		cin >> fPoids;
		cout << "Longueur de la trompe (cm) : ";
		cin >> fTrompe;
		cout << "Nombre de braconniers empalés: ";
		cin >> iNbVict;
		listeAnimaux.ajouter(new Elephant(fPoids, fTrompe, iNbVict, sNom, iIDAnimaux++));
		iNbAnimaux++;
		break;
	case 5:
		cout << "Longueur du bec (cm) : ";
		cin >> fTailleBec;
		cout << "Nombre de loopings en vol : ";
		cin >> iNbLoopings;
		listeAnimaux.ajouter(new Aigle(fTailleBec, iNbLoopings, sNom, iIDAnimaux++));
		iNbAnimaux++;
		break;
	case 6:
		cout << "Vitesse (km/h) : ";
		cin >> iVitesse;
		cout << "Age : ";
		cin >> iAge;
		cout << "Couleur : ";
		cin >> sCouleur;
		listeAnimaux.ajouter(new Tortue(iVitesse, iAge, sCouleur, sNom, iIDAnimaux++));
		iNbAnimaux++;
		break;
	case 7:
		cout << "Taille (cm) : ";
		cin >> fTaille;
		cout << "Nombre d'amis : ";
		cin >> iNbAmis;
		listeAnimaux.ajouter(new Loutre(iNbAmis, fTaille, sNom, iIDAnimaux++));
		iNbAnimaux++;
		break;
	case 8:
		cout << "Nombre d'enfants mangés : ";
		cin >> iEnfants;
		cout << "Nombre de dents: ";
		cin >> iDents;
		listeAnimaux.ajouter(new Crocodile(iEnfants, iDents, sNom, iIDAnimaux++));
		iNbAnimaux++;
		break;
	case 9:
		cout << "Nombre de carottes mangées : ";
		cin >> iCarottes;
		cout << "Couleur : ";
		cin >> sCouleur;
		listeAnimaux.ajouter(new Lapin(iCarottes, sCouleur, sNom, iIDAnimaux++));
		iNbAnimaux++;
		break;
	default:
		succes = false;
		break;
	}

	if(succes) {
		choixEnclos(listeAnimaux[listeAnimaux.getNbElem()-1]);
	}
}

