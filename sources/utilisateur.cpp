#include "../entetes/utilisateur.h"

/**********************/
/****** POUR ENCLOS ***/
/**********************/


void videBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<int>::max(), '\n');
}

void creationEnclos(Parc & Parc1) {
    system("clear");
    cout << "******************************" << endl;
    cout << "***  Création d'un enclos  ***" << endl;
    cout << "******************************" << endl << endl;

    string sNom = "";
    int iType;
    int iCapacite;

    cout << "Nom de l'Enclos : ";
    videBuffer();
    getline(cin, sNom);

    cout << "Type de l'enclos ("<< ENCLOS << " : Enclos, " << BASSIN << " : Bassin, "<< CAGE <<" : Cage) : ";
    cin >> iType;
    while (iType != ENCLOS && iType != BASSIN && iType != CAGE) {
        cout << "Erreur de Saisie, veuillez recommencer." << endl;
        cout << "Type de l'enclos ( "<< ENCLOS << " : Enclos, " << BASSIN << " : Bassin, "<< CAGE <<" : Cage) : ";
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

int selectionChoixAnimal() {
    system("clear");
    cout << "*****************************" << endl;
    cout << "***  Capture d'un animal  ***" << endl;
    cout << "*****************************" << endl << endl;

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
    while (iChoix <0 || iChoix > 9) {
        system("clear");
        cout << "*****************************" << endl;
        cout << "***  Capture d'un animal  ***" << endl;
        cout << "*****************************" << endl << endl;
        cout << "Erreur de saisie, veuillez recommencer." << endl << endl;
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
    cout << endl;
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
        iIDEnclos = choixEnclos(Parc1,g1);
        //Création de l'animal dans l'enclos
        if (iIDEnclos != -1) {
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
        iIDEnclos = choixEnclos(Parc1,t1);
        //Création de l'animal dans l'enclos
        if (iIDEnclos != -1) {
            Parc1.creerAnimal(t1, iIDEnclos);
            cout << "L'animal a bien été capturé et mis dans l'enclos." << endl;
        }
        break;
    case BASQUE :
        Basque * b1;
        b1 = creerBasque();
        // Choix de l'enclos
        //Gestion d'erreur car choixEnclos peut retourner -1
        iIDEnclos = choixEnclos(Parc1,b1);
        //Création de l'animal dans l'enclos
        if (iIDEnclos != -1) {
            Parc1.creerAnimal(b1, iIDEnclos);
            cout << "L'animal a bien été capturé et mis dans l'enclos." << endl;
        }
        break;
    case MARMOTTE :
        Marmotte * m1;
        m1 = creerMarmotte();
        // Choix de l'enclos
        //Gestion d'erreur car choixEnclos peut retourner -1
        iIDEnclos = choixEnclos(Parc1,m1);
        //Création de l'animal dans l'enclos
        if (iIDEnclos != -1) {
            Parc1.creerAnimal(m1, iIDEnclos);
            cout << "L'animal a bien été capturé et mis dans l'enclos." << endl;
        }
        break;
    case ELEPHANT :
        Elephant * E1;
        E1 = creerElephant();
        // Choix de l'enclos
        //Gestion d'erreur car choixEnclos peut retourner -1
        iIDEnclos = choixEnclos(Parc1,E1);
        //Création de l'animal dans l'enclos
        if (iIDEnclos != -1) {
            Parc1.creerAnimal(E1, iIDEnclos);
            cout << "L'animal a bien été capturé et mis dans l'enclos." << endl;
        }
        break;
    case AIGLE :
        Aigle * a1;
        a1 = creerAigle();
        // Choix de l'enclos
        //Gestion d'erreur car choixEnclos peut retourner -1
        iIDEnclos = choixEnclos(Parc1,a1);
        //Création de l'animal dans l'enclos
        if (iIDEnclos != -1) {
            Parc1.creerAnimal(a1, iIDEnclos);
            cout << "L'animal a bien été capturé et mis dans l'enclos." << endl;
        }
        break;
    case TORTUE :
        Tortue * T1;
        T1 = creerTortue();
        // Choix de l'enclos
        //Gestion d'erreur car choixEnclos peut retourner -1
        iIDEnclos = choixEnclos(Parc1,T1);
        //Création de l'animal dans l'enclos
        if (iIDEnclos != -1) {
            Parc1.creerAnimal(T1, iIDEnclos);
            cout << "L'animal a bien été capturé et mis dans l'enclos." << endl;
        }
        break;
    case LOUTRE :
        Loutre * L1;
        L1 = creerLoutre();
        // Choix de l'enclos
        //Gestion d'erreur car choixEnclos peut retourner -1
        iIDEnclos = choixEnclos(Parc1,L1);
        //Création de l'animal dans l'enclos
        if (iIDEnclos != -1) {
            Parc1.creerAnimal(L1, iIDEnclos);
            cout << "L'animal a bien été capturé et mis dans l'enclos." << endl;
        }
        break;
    case CROCODILE :
        Crocodile * C1;
        C1 = creerCrocodile();
        // Choix de l'enclos
        //Gestion d'erreur car choixEnclos peut retourner -1
        iIDEnclos = choixEnclos(Parc1,C1);
        //Création de l'animal dans l'enclos
        if (iIDEnclos != -1) {
            Parc1.creerAnimal(C1, iIDEnclos);
            cout << "L'animal a bien été capturé et mis dans l'enclos." << endl;
        }
        break;
    case LAPIN :
        Lapin * l1;
        l1 = creerLapin();
        // Choix de l'enclos
        //Gestion d'erreur car choixEnclos peut retourner -1
        iIDEnclos = choixEnclos(Parc1,l1);
        //Création de l'animal dans l'enclos
        if (iIDEnclos != -1) {
            Parc1.creerAnimal(l1, iIDEnclos);
            cout << "L'animal a bien été capturé et mis dans l'enclos." << endl;
        }
        break;
    }
}


int choixEnclos(Parc & Parc1, Animal * a) {
    system("clear");
    cout << "***************************" << endl;
    cout << "***  Choix d'un enclos  ***" << endl;
    cout << "***************************" << endl << endl;

    string sChoix;
    int iIDEnclos;
	 int iIDDernierEnclos;
    int consequence;
    bool valide = false;
    int existe = -1;
    int j=0;
    int iNbEnclos = Parc1.getNbEnclos();

    // On va compter combien il ya d'enclos non plein
    int iNbEnclosNonPlein = 0;
    for (int i =0; i < Parc1.getNbEnclos() ; i++) {
        if (Parc1.getEnclos(i).getOccupation() < Parc1.getEnclos(i).getCapacite()) {
            iNbEnclosNonPlein ++;
        }
    }

    // S'il y a des enclos avec de la place
    if (iNbEnclosNonPlein !=0) {
      do {
         // Affiche la liste des enclos disponibles et demande du choix
         cout << "Enclos disponibles : " << endl;
         for (int i=0; i< iNbEnclos; i++) {
            if (Parc1.getEnclos(i).getOccupation() < Parc1.getEnclos(i).getCapacite()) {
                cout << "- ID : " << Parc1.getEnclos(i).getID() << " - " << Parc1.getEnclos(i).getNom() << " - Occupation : " << Parc1.getEnclos(i).getOccupation() << " / " << Parc1.getEnclos(i).getCapacite() << endl;
            }
         }
         cout << endl << "Entrez l'ID de l'enclos choisi ou -5 pour en créer un nouveau : ";
         cin >> iIDEnclos;
         existe = Parc1.rechercherEnclos(iIDEnclos);


         // Si on décide de créer un nouvel enclos et on le choisi pour y mettre l'animal
         if (iIDEnclos == -5) {
           creationEnclos(Parc1);

           // On vérifie les conséquences
           iIDEnclos = Parc1.getIDEnclos() -1;
           consequence = Parc1.consequenceDeplacementAnimal(a,iIDEnclos);
           switch (consequence) {
           case 2 :
               cout << "L'animal se noiera, voulez vous choisir un autre enclos ? (O / N) : ";
               break;
           case 3 :
               cout << "L'animal s'envolera, voulez vous choisir un autre enclos ? (O / N) : ";
               break;
           default :
               valide = true;
               break;
           }
           // Si on demande confirmation, on saisi la réponse de l'utilisateur
           if(consequence == 2 || consequence == 3) {
               if(choix()) {
                  valide = false;
                  system("clear");
               }
               else {
                  valide = true;
               }
           }
         }
         // Si l'enclos choisi n'existe pas
         else if (existe == -1) {
             system("clear");
             cout << "Erreur de saisie (enclos non trouvé), veuillez recommencer." << endl;
             valide = false;
         }
         // Si on a choisi un enclos dans la liste
         else {
            // On regarde les conséquences
           consequence = Parc1.consequenceDeplacementAnimal(a,iIDEnclos);
           switch (consequence) {
           case -1 :
               // L'enclos n'existe pas, impossible
               break;
           case 0 :
               // Tout est ok
               valide = true;
               break;
           case 1 :
               valide = false;
               system("clear");
               cout << "L'enclos est plein, veuillez en choisir un autre." << endl << endl;
               break;
           case 2 :
               cout << "L'animal se noiera, voulez vous choisir un autre enclos ? (O / N) : ";
               break;
           case 3 :
               cout << "L'animal s'envolera, voulez vous choisir un autre enclos ? (O / N) : ";
               break;
           case 4 :
               cout << "L'animal possède des prédateurs dans l'enclos de destination, voulez vous choisir un autre enclos ? (O / N) : ";
               break;
           case 5 :
               cout << "L'animal possède des proies dans l'enclos de destination, voulez vous choisir un autre enclos ? (O / N) : ";
               break;
           case 6 :
               cout << "L'animal possède des proies et des prédateurs dans l'enclos de destination, voulez vous choisir un autre enclos ? (O / N) : ";
               break;
           default :
               //impossible
               break;
           }
           // Si on demande confirmation, on saisi la réponse de l'utilisateur
           if(consequence == 2 || consequence == 3 || consequence == 4 || consequence == 5 || consequence == 6) {
               if(choix()) {
                  valide = false;
                  system("clear");
               }
               else {
                  valide = true;
               }
           }

         }
      } while (!valide);
      return iIDEnclos;

    // Cas ou aucun enclos n'est disponible
    } else {
        cout << "Aucun enclos n'est disponible, il vous faut en creer un." << endl;
        // On crée alors un enclos
        creationEnclos(Parc1);
        do {
            iIDDernierEnclos = Parc1.getIDEnclos() -1;
            consequence = Parc1.consequenceDeplacementAnimal(a,iIDDernierEnclos);
            switch (consequence) {
            case 2 :
                cout << "L'animal se noiera, voulez vous choisir un autre enclos ? (O / N) : ";
                break;
            case 3 :
                cout << "L'animal s'envolera, voulez vous choisir un autre enclos ? (O / N) : ";
                break;
            default :
                valide = true;
                break;
            }
            if(consequence == 2 || consequence == 3) {
               if(choix()) {
                  valide = false;
               }
               else {
                  valide = true;
               }
            }
            if (!valide) {
                system("clear");
                cout << "Faites Attention dans le type d'enclos choisi. " << endl << endl;
                creationEnclos(Parc1);
            }
        } while (!valide);
        return (iIDDernierEnclos);
    }
}

bool choix() {
   string sChoix;
   do {
        cin >> sChoix;
        if (!(sChoix == "o" || sChoix == "O" || sChoix == "n" || sChoix == "N"))
            cout << "Erreur de saisie, veuillez recommencer." << endl;
    } while(!(sChoix == "o" || sChoix == "O" || sChoix == "n" || sChoix == "N"));
    if (sChoix == "o" || sChoix == "O")
        return true;
    else {
        return false;
    }
}

Girafe * creerGirafe() {
    float fTaille;
    int iNbTaches;
    string sNom;

    cout << "Entrez le nom de l'animal : ";
    videBuffer();
    getline(cin,sNom);
    cout << "Entrez sa taille en m (entre 0 et 10) : ";
    cin >> fTaille;
    if (fTaille < 0 || fTaille > 10) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez sa taille en m (entre 0 et 10) : ";
            cin >> fTaille;
        } while (fTaille < 0 || fTaille > 10);
    }
    cout << "Entrez le nombre de tâche de l'animal : ";
    cin >> iNbTaches;
    if (iNbTaches < 0) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez le nombre de tâche de l'animal : ";
            cin >> iNbTaches;
        } while (iNbTaches < 0);
    }
    Girafe * g;
    g = new Girafe(fTaille,iNbTaches,sNom);
    return g;
}

Loutre * creerLoutre() {
    float fTaille;
    int iNbAmis;
    string sNom;

    cout << "Entrez le nom de l'animal : ";
    videBuffer();
    getline(cin,sNom);
    cout << "Entrez sa taille en cm (entre 0 et 500) : ";
    cin >> fTaille;
    if (fTaille < 0 || fTaille > 500) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez sa taille en cm (entre 0 et 500) : ";
            cin >> fTaille;
        } while (fTaille < 0 || fTaille > 500);
    }
    cout << "Entrez le nombre d'amis de l'animal : ";
    cin >> iNbAmis;
    if (iNbAmis < 0) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez le nombre d'amis de l'animal : ";
            cin >> iNbAmis;
        } while (iNbAmis < 0);
    }
    Loutre * l;
    l = new Loutre(fTaille,iNbAmis,sNom);
    return l;
}


Crocodile * creerCrocodile() {
    int iEnfantMange;
    int iNbDent;
    string sNom;

    cout << "Entrez le nom de l'animal : ";
    videBuffer();
    getline(cin,sNom);
    cout << "Entrez le nombre d'enfant mangé par le crocodile : ";
    cin >> iEnfantMange;
    if (iEnfantMange < 0) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez le nombre d'enfant mangé par le crocodile : ";
            cin >> iEnfantMange;
        } while (iEnfantMange < 0);
    }
    cout << "Entrez le nombre de dents de l'animal : ";
    cin >> iNbDent;
    if (iNbDent < 0) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez le nombre de dents de l'animal : ";
            cin >> iNbDent;
        } while (iNbDent < 0);
    }
    Crocodile * l;
    l = new Crocodile(iEnfantMange,iNbDent,sNom);
    return l;
}

Tortue * creerTortue() {
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
    if (iVitesseMax < 0) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez la vitesse maximal de la tortue en km/h  : ";
            cin >> iVitesseMax;
        } while (iVitesseMax < 0);
    }
    cout << "Entrez l'age l'animal : ";
    cin >> iAge;
    if (iAge < 0) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez l'age l'animal : ";
            cin >> iAge;
        } while (iAge < 0);
    }
    Tortue * l;
    l = new Tortue(iVitesseMax,iAge,sCouleur,sNom);
    return l;
}

Aigle * creerAigle() {
    float fLong;
    int iNb;
    string sNom;

    cout << "Entrez le nom de l'animal : ";
    videBuffer();
    getline(cin,sNom);
    cout << "Entrez le nombre de Looping de l'aigle  : ";
    cin >> iNb;
    if (iNb < 0) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez le nombre de Looping de l'aigle  : ";
            cin >> iNb;
        } while (iNb < 0);
    }
    cout << "Entrez la longueur du bec de l'aigle : ";
    cin >> fLong;
    if (fLong < 0) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez la longueur du bec de l'aigle : ";
            cin >> fLong;
        } while (fLong < 0);
    }
    Aigle * l;
    l = new Aigle(fLong,iNb,sNom);
    return l;
}


Tigre * creerTigre() {
    float fLong;
    int iNb;
    string sNom;

    cout << "Entrez le nom de l'animal : ";
    videBuffer();
    getline(cin,sNom);
    cout << "Entrez le nombre de gazelles croquées : ";
    cin >> iNb;
    if (iNb < 0) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez le nombre de gazelles croquées : ";
            cin >> iNb;
        } while (iNb < 0);
    }
    cout << "Entrez la hauteur du tigre au garot en cm : ";
    cin >> fLong;
    if (fLong < 0) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez la hauteur du tigre au garot en cm : ";
            cin >> fLong;
        } while (fLong < 0);
    }
    Tigre * l;
    l = new Tigre(fLong,iNb,sNom);
    return l;
}

Elephant * creerElephant() {
    float fLong;
    float fTromp;
    int iNb;
    string sNom;

    cout << "Entrez le nom de l'animal : ";
    videBuffer();
    getline(cin,sNom);
    cout << "Entrez le nombre de braconniers empalés : ";
    cin >> iNb;
    if (iNb < 0) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez le nombre de braconniers empalés : ";
            cin >> iNb;
        } while (iNb < 0);
    }
    cout << "Entrez la longueur de la trompe en cm : ";
    cin >> fTromp;
    if (fTromp < 0) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez la longueur de la trompe en cm : ";
            cin >> fTromp;
        } while (fTromp < 0);
    }
    cout << "Entrez le poids de l'éléphant en kg : ";
    cin >> fLong;
    if (fLong < 0) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez le poids de l'éléphant en kg : ";
            cin >> fLong;
        } while (fLong < 0);
    }
    Elephant * l;
    l = new Elephant(fLong,fTromp,iNb,sNom);
    return l;
}

Lapin * creerLapin() {
    string sCouleur;
    int iNb;
    string sNom;

    cout << "Entrez le nom de l'animal : ";
    videBuffer();
    getline(cin,sNom);
    cout << "Entrez le nombre de carotte mangées par le lapin: ";
    cin >> iNb;
    if (iNb < 0) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez le nombre de carotte mangées par le lapin: ";
            cin >> iNb;
        } while (iNb < 0);
    }
    cout << "Entrez la couleur du lapin : ";
    cin >> sCouleur;
    Lapin * l;
    l = new Lapin(iNb,sCouleur,sNom);
    return l;
}

Marmotte * creerMarmotte() {
    float fLong;
    int iNb;
    string sNom;

    cout << "Entrez le nom de l'animal : ";
    videBuffer();
    getline(cin,sNom);
    cout << "Entrez le nombre de tablettes de chocolat emballées (on ne comptera que les Milka's) : ";
    cin >> iNb;
    if (iNb < 0) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez le nombre de tablettes de chocolat emballées (on ne comptera que les Milka's) : ";
            cin >> iNb;
        } while (iNb < 0);
    }
    cout << "Entrez la taille de la marmotte en cm : ";
    cin >> fLong;
    if (fLong < 0) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez la taille de la marmotte en cm : ";
            cin >> fLong;
        } while (fLong < 0);
    }
    Marmotte * l;
    l = new Marmotte(fLong,iNb,sNom);
    return l;
}

Basque * creerBasque() {
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
    if (iNbRicard < 0) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez le nombre de Ricard bu par le basque : ";
            cin >> iNbRicard;
        } while (iNbRicard < 0);
    }
    cout << "Entrez le nombre de parties de pelotte gagnées : ";
    cin >> iNbPartie;
    if (iNbPartie < 0) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez le nombre de parties de pelotte gagnées : ";
            cin >> iNbPartie;
        } while (iNbPartie < 0);
    }
    cout << "Entrez la taille de la largeur du beret en cm : ";
    cin >> fLong;
    if (fLong < 0) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez la taille de la largeur du beret en cm : ";
            cin >> fLong;
        } while (fLong < 0);
    }
    cout << "Entrez le temps de cuisson du basque en minute(s): ";
    cin >> fTemps;
    if (fTemps < 0) {
        do {
            cout << "Erreur de saisie, veuillez recommencer." << endl;
            cout << "Entrez le temps de cuisson du basque en minute(s): ";
            cin >> fTemps;
        } while (fTemps < 0);
    }
    Basque * l;
    l = new Basque(fLong,fTemps,iNbRicard,iNbPartie,sNom);
    return l;
}


void deplacerAnimal(Parc & Parc1) {
   system("clear");
   cout << "*********************************" << endl;
   cout << "***  Déplacement d'un animal  ***" << endl;
   cout << "*********************************" << endl << endl;

   int iRangEnclos = -1;
   int iIDEnclos = 0;
   int iNbEnclos = 0;
   int iIDAnimal = 0;
   int iNbAnimaux = 0;
   int iIDEnclosArrivee = -1;
   bool animalExiste = false;
   bool annuler = false;
   int iConsequencesDansEnclosDepart;
   int j;
   Animal * ptrAnimal;


    // On le nombre d'enclos non vides
    int iNbEnclosNonVides = 0;
    for (int i =0; i < Parc1.getNbEnclos() ; i++) {
        if (Parc1.getEnclos(i).getOccupation() >0 ) {
            iNbEnclosNonVides ++;
        }
    }

    // S'il n'y en a aucun, on quitte
    if(iNbEnclosNonVides == 0) {
      cout << "Il n'y a aucun enclos avec des animaux à déplacer." << endl;
   }
   else {
      // Choix de l'enclos
      iNbEnclos =  Parc1.getNbEnclos();
      cout << "Veuillez choisir l'enclos dans lequel se trouve l'animal à déplacer : " << endl;
      cout << "Enclos disponibles : " << endl;
      for (int i=0; i< iNbEnclos; i++) {
         if( Parc1.getEnclos(i).getOccupation() > 0)
            cout << "- ID : " << Parc1.getEnclos(i).getID() << " - " << Parc1.getEnclos(i).getNom() << endl;
      }
      do{
         cout << endl << "Entrez l'ID de l'enclos choisi : ";
         cin >> iIDEnclos;
         iRangEnclos = Parc1.rechercherEnclos(iIDEnclos);
      }while(iRangEnclos == -1);

      // Choix de l'animal à déplacer
      iNbAnimaux = Parc1.getEnclos(iRangEnclos).getOccupation();
      cout << "Veuillez choisir l'animal à déplacer : " << endl;
      cout << "Animaux disponibles : " << endl;
      for (int i=0; i< iNbAnimaux; i++) {
         cout << "- ID : " << Parc1.getEnclos(iRangEnclos).getAnimal(i).getID() << " - " << Parc1.getEnclos(iRangEnclos).getAnimal(i).getNom() << endl;
      }
      do{
         cout << endl << "Entrez l'ID de l'animal choisi : ";
         cin >> iIDAnimal;
         j=0;
         while(!animalExiste && j<iNbAnimaux) {
            if(Parc1.getEnclos(iRangEnclos).getAnimal(j).getID() == iIDAnimal) {
               animalExiste = true;
            }
            else {
               j++;
            }
         }
      }while(!animalExiste);

      // Vérification des conséquences dans l'enclos de départ
      ptrAnimal = Parc1.getEnclos(iRangEnclos).getPtrAnimal(j);
      iConsequencesDansEnclosDepart = Parc1.consequenceDansEnclosDepartDeplacementAnimal(ptrAnimal, iIDEnclos);
      if(iConsequencesDansEnclosDepart == 1) {
         cout <<  endl << "Attention, cet animal possède des proies et/ou des prédateurs dans l'enclos. Il est possible que cela crée un déséquilibre et que des animaux s'entretuent dans cette enclos. Voulez-vous annuler ce déplacement ? (O / N)";
         annuler = choix();
      }

      if(!annuler) {
         // Choix de l'enclos d'arrivée
         iIDEnclosArrivee = choixEnclos(Parc1, ptrAnimal);

         // Déplacement
         Parc1.deplacerAnimal(iIDEnclos, iIDAnimal, iIDEnclosArrivee);

         cout << "L'animal a bien été déplacé. Les possibles conséquences de ce déplacement ont été prises en compte." << endl;
      }
   }
}


void supprimerEnclos(Parc & Parc1) {
   system("clear");
   cout << "*********************************" << endl;
   cout << "***  Suppression d'un enclos  ***" << endl;
   cout << "*********************************" << endl << endl;


   int iRangEnclos = -1;
   int iIDEnclos = 0;
   int iNbEnclos = 0;
   int iNbAnimaux = 0;
   int iChoix = 0;
   bool iConfirmationSuppression = false;
   int iIDEnclosArrivee = -1;
   Animal * ptrAnimal;

   if(Parc1.getNbEnclos() == 0) {
      cout << "Aucun enclos à supprimer" << endl;
   }
   else {
      // Choix de l'enclos
      iNbEnclos =  Parc1.getNbEnclos();
      cout << "Veuillez choisir l'enclos à supprimer : " << endl;
      cout << "Enclos disponibles : " << endl;
      for (int i=0; i< iNbEnclos; i++) {
         cout << "- ID : " << Parc1.getEnclos(i).getID() << " - " << Parc1.getEnclos(i).getNom() << endl;
      }
      do{
         cout << endl << "Entrez l'ID de l'enclos choisi : ";
         cin >> iIDEnclos;
         iRangEnclos = Parc1.rechercherEnclos(iIDEnclos);
      }while(iRangEnclos == -1);


      // Demande confirmation
      cout << "Voulez-vous vraiment supprimer cet enclos ? (O / N)" << endl;
      iConfirmationSuppression = choix();

      if(iConfirmationSuppression) {
         // traite les animaux présents
         iNbAnimaux = Parc1.getEnclos(iRangEnclos).getOccupation();
         if(iNbAnimaux != 0) {
            cout << "Attention, l'enclos choisi contient " << iNbAnimaux << " animal(aux). Il faut les déplacer ou les relâcher. Comme il peut y avoir des conflits entre espèces, les déplacement ne peuvent pas être automatisés." << endl;
            cout << "1. Relâcher tous les animaux" << endl;
            cout << "2. Déplacer un à un les animaux" << endl;

            do {
               cout << "Choix :";
               cin >> iChoix;
            }while(iChoix != 1 && iChoix != 2);

            // Les animaux seront automatiquement relâché par Parc lors de la suppression

            if(iChoix == 2) {
               while(Parc1.getEnclos(iRangEnclos).getOccupation() != 0) {

                  ptrAnimal = Parc1.getEnclos(iRangEnclos).getPtrAnimal(0);

                  // Demande de l'action à effectuer
                  cout << "Animal à traiter : "<< endl;
                  cout << *ptrAnimal;
                  cout << endl << "Que faire ?" << endl;
                  cout << "1. Le relâcher" << endl;
                  cout << "2. Le déplacer" << endl;
                  do {
                     cout << "Choix :";
                     cin >> iChoix;
                  }while(iChoix != 1 && iChoix != 2);

                  // Si relacher
                  if(iChoix == 1) {
                     Parc1.supprimerAnimal(ptrAnimal->getID());
                  }
                  // Si on le déplace
                  else {
                     iIDEnclosArrivee = choixEnclos(Parc1, ptrAnimal);
                     Parc1.deplacerAnimal(iIDEnclos, ptrAnimal->getID(), iIDEnclosArrivee);
                  }
               }
            }
         }

         // Supprime l'enclos
         Parc1.supprimerEnclos(iIDEnclos);
         cout << "L'enclos a bien été supprimé." << endl;
      }
   }
}
