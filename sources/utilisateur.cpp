#include "../entetes/utilisateur.h"

/**********************/
/****** POUR ENCLOS ***/
/**********************/


void videBuffer() {
   cin.clear();
   cin.ignore(numeric_limits<int>::max(), '\n');
}

void creationEnclos(Parc & Parc1) {
   string sNom = "";
   int iType;
   int iCapacite;

   cout << "Nom de l'Enclos : ";
   videBuffer();
	getline(cin, sNom);

   cout << "Entrez "<< ENCLOS << " pour un Enclos, " << BASSIN << " pour un Bassin ou "<< CAGE <<" pour une cage : ";
	cin >> iType;
	while (iType != ENCLOS && iType != BASSIN && iType != CAGE){
		cout << "Erreur de Saisie, veuillez recommencer." << endl;
		cout << "Entrez "<< ENCLOS << " pour un Enclos, " << BASSIN << " pour un Bassin ou "<< CAGE <<" pour une cage : ";
		cin >> iType;
	}

	cout << "Capacite de l'Enclos : ";
	cin >> iCapacite;
	while (iCapacite <= 0) {
      cout << "Erreur de Saisie, veuillez recommencer." << endl;
      cout << "Capacite de l'Enclos : ";
      cin >> iCapacite;
	}

   Parc1.creerEnclos(sNom,iType,iCapacite);

   // GESTION D'ERREUR ICI
   cout << "L'enclos a bien été crée. " << endl;
}

int selectionChoixAnimal(){
	int iChoix = -1;
	cout << "Voici les choix possibles d'animaux : " << endl;
	cout << "Tapez " << GIRAFE << " pour la Girafe" << endl;
	cout << "Tapez " << TIGRE << " pour le Tigre" << endl;
	cout << "Tapez " << BASQUE << " pour le Basque" << endl;
	cout << "Tapez " << MARMOTTE << " pour la Marmotte" << endl;
	cout << "Tapez " << ELEPHANT << " pour l'Elephant" << endl;
	cout << "Tapez " << AIGLE << " pour l'Aigle" << endl;
	cout << "Tapez " << TORTUE << " pour la Tortue" << endl;
	cout << "Tapez " << LOUTRE << " pour la Loutre" << endl;
	cout << "Tapez " << CROCODILE << " pour le Crocodile" << endl;
	cout << "Tapez " << LAPIN << " pour le Lapin" << endl;
	cout << "Votre choix : ";
	cin >> iChoix;
	while (iChoix <0 || iChoix > 9){
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
   }
   return iChoix;
}

void Barney(Parc & Parc1) {
   int iChoixAnimal = selectionChoixAnimal();
   int iIDEnclos;
   switch (iChoixAnimal) {
      case GIRAFE:
         //créer une girafe
         Girafe * g1;
         g1 = creerGirafe();
         // Choix de l'enclos
                                       //Gestion d'erreur car choixEnclos peut retourner -1
         iIDEnclos = choixEnclosCreerAnimal(Parc1);
         //Création de l'animal dans l'enclos
         if (iIDEnclos != -1){
            Parc1.creerAnimal(g1, iIDEnclos);
            cout << "L'animal a bien été capturé et mis dans l'enclos." << endl;
         }
         break;
      case TIGRE :
         //créer un tigre
         Tigre * t1;
         t1 = creerTigre();
         // Choix de l'enclos
                                       //Gestion d'erreur car choixEnclos peut retourner -1
         iIDEnclos = choixEnclosCreerAnimal(Parc1);
         //Création de l'animal dans l'enclos
         if (iIDEnclos != -1){
            Parc1.creerAnimal(t1, iIDEnclos);
            cout << "L'animal a bien été capturé et mis dans l'enclos." << endl;
         }
         break;
      case BASQUE :
         Basque * b1;
         b1 = creerBasque();
         // Choix de l'enclos
                                       //Gestion d'erreur car choixEnclos peut retourner -1
         iIDEnclos = choixEnclosCreerAnimal(Parc1);
         //Création de l'animal dans l'enclos
         if (iIDEnclos != -1){
            Parc1.creerAnimal(b1, iIDEnclos);
            cout << "L'animal a bien été capturé et mis dans l'enclos." << endl;
         }
         break;
      case MARMOTTE :
         Marmotte * m1;
         m1 = creerMarmotte();
         // Choix de l'enclos
                                       //Gestion d'erreur car choixEnclos peut retourner -1
         iIDEnclos = choixEnclosCreerAnimal(Parc1);
         //Création de l'animal dans l'enclos
         if (iIDEnclos != -1){
            Parc1.creerAnimal(m1, iIDEnclos);
            cout << "L'animal a bien été capturé et mis dans l'enclos." << endl;
         }
         break;
      case ELEPHANT :
         Elephant * E1;
         E1 = creerElephant();
         // Choix de l'enclos
                                       //Gestion d'erreur car choixEnclos peut retourner -1
         iIDEnclos = choixEnclosCreerAnimal(Parc1);
         //Création de l'animal dans l'enclos
         if (iIDEnclos != -1){
            Parc1.creerAnimal(E1, iIDEnclos);
            cout << "L'animal a bien été capturé et mis dans l'enclos." << endl;
         }
         break;
      case AIGLE :
         Aigle * a1;
         a1 = creerAigle();
         // Choix de l'enclos
                                       //Gestion d'erreur car choixEnclos peut retourner -1
         iIDEnclos = choixEnclosCreerAnimal(Parc1);
         //Création de l'animal dans l'enclos
         if (iIDEnclos != -1){
            Parc1.creerAnimal(a1, iIDEnclos);
            cout << "L'animal a bien été capturé et mis dans l'enclos." << endl;
         }
         break;
      case TORTUE :
         Tortue * T1;
         T1 = creerTortue();
         // Choix de l'enclos
                                       //Gestion d'erreur car choixEnclos peut retourner -1
         iIDEnclos = choixEnclosCreerAnimal(Parc1);
         //Création de l'animal dans l'enclos
         if (iIDEnclos != -1){
            Parc1.creerAnimal(T1, iIDEnclos);
            cout << "L'animal a bien été capturé et mis dans l'enclos." << endl;
         }
         break;
      case LOUTRE :
         Loutre * L1;
         L1 = creerLoutre();
         // Choix de l'enclos
                                       //Gestion d'erreur car choixEnclos peut retourner -1
         iIDEnclos = choixEnclosCreerAnimal(Parc1);
         //Création de l'animal dans l'enclos
         if (iIDEnclos != -1){
            Parc1.creerAnimal(L1, iIDEnclos);
            cout << "L'animal a bien été capturé et mis dans l'enclos." << endl;
         }
         break;
      case CROCODILE :
         Crocodile * C1;
         C1 = creerCrocodile();
         // Choix de l'enclos
                                       //Gestion d'erreur car choixEnclos peut retourner -1
         iIDEnclos = choixEnclosCreerAnimal(Parc1);
         //Création de l'animal dans l'enclos
         if (iIDEnclos != -1){
            Parc1.creerAnimal(C1, iIDEnclos);
            cout << "L'animal a bien été capturé et mis dans l'enclos." << endl;
         }
         break;
      case LAPIN :
         Lapin * l1;
         l1 = creerLapin();
         // Choix de l'enclos
                                       //Gestion d'erreur car choixEnclos peut retourner -1
         iIDEnclos = choixEnclosCreerAnimal(Parc1);
         //Création de l'animal dans l'enclos
         if (iIDEnclos != -1){
            Parc1.creerAnimal(l1, iIDEnclos);
            cout << "L'animal a bien été capturé et mis dans l'enclos." << endl;
         }
         break;
   }
}


int choixEnclosCreerAnimal(Parc & Parc1){
	int iIDEnclos;
	bool existe = false;
	int j=0;
	// Affichage des enclos et de leur occupation
	int iNbEnclos = Parc1.getNbEnclos();
	if (iNbEnclos !=0){
		for (int i=0; i< iNbEnclos; i++){
			cout << "Enclos " << i << " - ID : " << Parc1.getEnclos(i).getID() << " - Taux Occupation : " << Parc1.getEnclos(i).getOccupation() << " / " << Parc1.getEnclos(i).getCapacite() << endl;
		}
		// Choix de l'enclos
		cout <<"Entrez l'ID (ATTENTION choisissez l'identifiant) de l'enclos choisi : ";
		cin >> iIDEnclos;
		// vérification que l'ID existe
		while (!existe && j < iNbEnclos){
			if (Parc1.getEnclos(j).getID() == iIDEnclos)
				existe=true;
			else j++;
		}
		if (existe)
			return iIDEnclos;
		else {
			cout << "Erreur de saisie, veuillez recommencer.";
			do{
				for (int i=0; i< iNbEnclos; i++){
					cout << "Enclos " << i << " - ID : " << Parc1.getEnclos(i).getID() << " - Taux Occupation : " << Parc1.getEnclos(i).getOccupation() << " / " << Parc1.getEnclos(i).getCapacite() << endl;
				}
				cout <<"Entrez l'ID (ATTENTION choisissez l'identifiant) de l'enclos choisi : ";
				cin >> iIDEnclos;
				//Ne pas oublier de réinitialiser j a zéro pour le parcours de vérification
				j=0;
				while (!existe && j < iNbEnclos){
					if (Parc1.getEnclos(j).getID() == iIDEnclos)
						existe=true;
					else j++;
				}
				// Pas besoin de RAZ de existe car si on recommence c'est qu'il est toujours a faux
			}while (!existe);
			return iIDEnclos;
		}
	}
	else{
		cout << "Il n'existe aucun enclos." << endl;
		return -1;
	}
}



Girafe * creerGirafe(){
	float fTaille;
	int iNbTaches;
	string sNom;

	cout << "Entrez le nom de l'animal : ";
   videBuffer();
   getline(cin,sNom);
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
   videBuffer();
   getline(cin,sNom);
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


Crocodile * creerCrocodile(){
	int iEnfantMange;
	int iNbDent;
	string sNom;

	cout << "Entrez le nom de l'animal : ";
	videBuffer();
   getline(cin,sNom);
	cout << "Entrez le nombre d'enfant mangé par le crocodile : ";
	cin >> iEnfantMange;
	if (iEnfantMange < 0){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez le nombre d'enfant mangé par le crocodile : ";
			cin >> iEnfantMange;
		}while (iEnfantMange < 0);
	}
	cout << "Entrez le nombre de dents de l'animal : ";
	cin >> iNbDent;
	if (iNbDent < 0){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez le nombre de dents de l'animal : ";
			cin >> iNbDent;
		}while (iNbDent < 0);
	}
	Crocodile * l;
	l = new Crocodile(iEnfantMange,iNbDent,sNom);
	return l;
}

Tortue * creerTortue(){
	int iVitesseMax;
	int iAge;
	string sCouleur;
	string sNom;

	cout << "Entrez le nom de l'animal : ";
	videBuffer();
   getline(cin,sNom);
	cout << "Entrez la couleur de l'animal : ";
	cin >> sCouleur;
	cout << "Entrez la vitesse maximal de la tortue en km/h  : ";
	cin >> iVitesseMax;
	if (iVitesseMax < 0){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez la vitesse maximal de la tortue en km/h  : ";
			cin >> iVitesseMax;
		}while (iVitesseMax < 0);
	}
	cout << "Entrez l'age l'animal : ";
	cin >> iAge;
	if (iAge < 0){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez l'age l'animal : ";
			cin >> iAge;
		}while (iAge < 0);
	}
	Tortue * l;
	l = new Tortue(iVitesseMax,iAge,sCouleur,sNom);
	return l;
}

Aigle * creerAigle(){
	float fLong;
	int iNb;
	string sNom;

	cout << "Entrez le nom de l'animal : ";
	videBuffer();
   getline(cin,sNom);
	cout << "Entrez le nombre de Looping de l'aigle  : ";
	cin >> iNb;
	if (iNb < 0){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez le nombre de Looping de l'aigle  : ";
			cin >> iNb;
		}while (iNb < 0);
	}
	cout << "Entrez la longueur du bec de l'aigle : ";
	cin >> fLong;
	if (fLong < 0){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez la longueur du bec de l'aigle : ";
			cin >> fLong;
		}while (fLong < 0);
	}
	Aigle * l;
	l = new Aigle(fLong,iNb,sNom);
	return l;
}


Tigre * creerTigre(){
	float fLong;
	int iNb;
	string sNom;

	cout << "Entrez le nom de l'animal : ";
	videBuffer();
   getline(cin,sNom);
	cout << "Entrez le nombre de gazelles croquées : ";
	cin >> iNb;
	if (iNb < 0){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez le nombre de gazelles croquées : ";
			cin >> iNb;
		}while (iNb < 0);
	}
	cout << "Entrez la hauteur du tigre au garot en cm : ";
	cin >> fLong;
	if (fLong < 0){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez la hauteur du tigre au garot en cm : ";
			cin >> fLong;
		}while (fLong < 0);
	}
	Tigre * l;
	l = new Tigre(fLong,iNb,sNom);
	return l;
}

Elephant * creerElephant(){
	float fLong;
	float fTromp;
	int iNb;
	string sNom;

	cout << "Entrez le nom de l'animal : ";
	videBuffer();
   getline(cin,sNom);
	cout << "Entrez le nombre de braconniers empalés : ";
	cin >> iNb;
	if (iNb < 0){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez le nombre de braconniers empalés : ";
			cin >> iNb;
		}while (iNb < 0);
	}
	cout << "Entrez la longueur de la trompe en cm : ";
	cin >> fTromp;
	if (fTromp < 0){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez la longueur de la trompe en cm : ";
			cin >> fTromp;
		}while (fTromp < 0);
	}
	cout << "Entrez le poids de l'éléphant en kg : ";
	cin >> fLong;
	if (fLong < 0){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez le poids de l'éléphant en kg : ";
			cin >> fLong;
		}while (fLong < 0);
	}
	Elephant * l;
	l = new Elephant(fLong,fTromp,iNb,sNom);
	return l;
}

Lapin * creerLapin(){
	string sCouleur;
	int iNb;
	string sNom;

	cout << "Entrez le nom de l'animal : ";
	videBuffer();
   getline(cin,sNom);
	cout << "Entrez le nombre de carotte mangées par le lapin: ";
	cin >> iNb;
	if (iNb < 0){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez le nombre de carotte mangées par le lapin: ";
			cin >> iNb;
		}while (iNb < 0);
	}
	cout << "Entrez la couleur du lapin : ";
	cin >> sCouleur;
	Lapin * l;
	l = new Lapin(iNb,sCouleur,sNom);
	return l;
}

Marmotte * creerMarmotte(){
	float fLong;
	int iNb;
	string sNom;

	cout << "Entrez le nom de l'animal : ";
	videBuffer();
   getline(cin,sNom);
	cout << "Entrez le nombre de tablettes de chocolat emballées (on ne comptera que les Milka's) : ";
	cin >> iNb;
	if (iNb < 0){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez le nombre de tablettes de chocolat emballées (on ne comptera que les Milka's) : ";
			cin >> iNb;
		}while (iNb < 0);
	}
	cout << "Entrez la taille de la marmotte en cm : ";
	cin >> fLong;
	if (fLong < 0){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez la taille de la marmotte en cm : ";
			cin >> fLong;
		}while (fLong < 0);
	}
	Marmotte * l;
	l = new Marmotte(fLong,iNb,sNom);
	return l;
}

Basque * creerBasque(){
	float fLong;
	float fTemps;
	int iNbRicard;
	int iNbPartie;
	string sNom;

	cout << "Entrez le nom de l'animal : ";
	videBuffer();
   getline(cin,sNom);
	cout << "Entrez le nombre de Ricard bu par le basque : ";
	cin >> iNbRicard;
	if (iNbRicard < 0){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez le nombre de Ricard bu par le basque : ";
			cin >> iNbRicard;
		}while (iNbRicard < 0);
	}
	cout << "Entrez le nombre de parties de pelotte gagnées : ";
	cin >> iNbPartie;
	if (iNbPartie < 0){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez le nombre de parties de pelotte gagnées : ";
			cin >> iNbPartie;
		}while (iNbPartie < 0);
	}
	cout << "Entrez la taille de la largeur du beret en cm : ";
	cin >> fLong;
	if (fLong < 0){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez la taille de la largeur du beret en cm : ";
			cin >> fLong;
		}while (fLong < 0);
	}
	cout << "Entrez le temps de cuisson du basque en minute(s): ";
	cin >> fTemps;
	if (fTemps < 0){
		do{
			cout << "Erreur de saisie, veuillez recommencer.";
			cout << "Entrez le temps de cuisson du basque en minute(s): ";
			cin >> fTemps;
		}while (fTemps < 0);
	}
	Basque * l;
	l = new Basque(fLong,fTemps,iNbRicard,iNbPartie,sNom);
	return l;
}
