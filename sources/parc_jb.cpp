#include "../entetes/parc.h"


void Parc::creerAnimal(Animal * a, const int IDEnclosAccueil) {
    int iEspece = a->getEspece();
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    Enclos * ptrEnclos = listeEnclos[iRangEnclos];
    bool succes = true;

    if(ptrEnclos->getOccupation() < ptrEnclos->getCapacite()) {
        switch(iEspece) {
          case GIRAFE:
             listeAnimaux.ajouter(new Girafe(a->getTaille(), a->getNbTaches(), a->getNom(), iIDAnimaux++));
             iNbAnimaux++;
             break;
          case TIGRE:
             listeAnimaux.ajouter(new Tigre(a->getTaille(), a->getNbVictimes(), a->getNom(), iIDAnimaux++));
             iNbAnimaux++;
             break;
          case BASQUE:
             listeAnimaux.ajouter(new Basque(a->getLargeurBeret(), a->getTempsCuisson(), a->getNbVictoires(), a->getNbRicardBus(), a->getNom(), iIDAnimaux++));
             iNbAnimaux++;
             break;
          case MARMOTTE:
             listeAnimaux.ajouter(new Marmotte(a->getTaille(), a->getNbTabChocolat(), a->getNom(), iIDAnimaux++));
             iNbAnimaux++;
             break;
          case ELEPHANT:
             listeAnimaux.ajouter(new Elephant(a->getPoids(), a->getLongTrompe(), a->getNbVictimes(), a->getNom(), iIDAnimaux++));
             iNbAnimaux++;
             break;
          case AIGLE:
             listeAnimaux.ajouter(new Aigle(a->getLongueurBec(), a->getNbLoopings(), a->getNom(), iIDAnimaux++));
             iNbAnimaux++;
             break;
          case TORTUE:
             listeAnimaux.ajouter(new Tortue(a->getVitesseMax(), a->getAge(), a->getCouleur(), a->getNom(), iIDAnimaux++));
             iNbAnimaux++;
             break;
          case LOUTRE:
             listeAnimaux.ajouter(new Loutre(a->getNbAmis(), a->getTaille(), a->getNom(), iIDAnimaux++));
             iNbAnimaux++;
             break;
          case CROCODILE:
             listeAnimaux.ajouter(new Crocodile(a->getEnfantMange(), a->getNbDents(), a->getNom(), iIDAnimaux++));
             iNbAnimaux++;
             break;
          case LAPIN:
             listeAnimaux.ajouter(new Lapin(a->getNbCarotteMange(), a->getCouleur(), a->getNom(), iIDAnimaux++));
             iNbAnimaux++;
             break;
          default:
             succes = false;
             break;
        }

        if(succes) {
          ajouterAnimalDansEnclos(listeAnimaux[iNbAnimaux-1], ptrEnclos);
        }
        else {
            cout << "Erreur, espèce inconnue." << endl;
        }
    }
    else {
        cout << "Erreur, enclos plein." << endl;
    }
}


void Parc::supprimerAnimal(const int ID) {
    int iRangEnclos = rechercheEnclosAnimal(ID);
    if(iRangEnclos == -1) {
        cout << "Erreur, animal non trouvé." << endl;
    }
    else {
        Animal * ptrAnimal = listeAnimaux[rechercherAnimal(ID)];
        listeEnclos[iRangEnclos]->supprimerAnimal(ptrAnimal);
        listeAnimaux.enlever(ptrAnimal);
        delete ptrAnimal;
    }
}

void Parc::modifierAnimal(const int IDAnimalAModifier, Animal * nouvelAnimal) {
    // FAIRE GESTION ERREUR ICI !!
    int iRangAnimal = rechercheAnimal(IDAnimalAModifier);
    if(iRangAnimal == -1) {
        cout << "Erreur, animal non trouvé."<< endl;
    }
    else {
        Animal * ptrAnimal = listeAnimaux[iRangAnimal];
        int iEspece = ptrAnimal->getEspece();
        if(iEspece != nouvelAnimal->getEspece()) {
            cout << "Erreur, l'animal à modifier n'est pas de la bonne espèce." << endl;
        }
        else {
            ptrAnimal->setNom(nouvelAnimal->getNom());
            switch(iEspece) {
              case GIRAFE:
                ptrAnimal->setTaille(nouvelAnimal->getTaille());
                ptrAnimal->setNbTaches(nouvelAnimal->getNbTaches());
                break;
              case TIGRE:
                ptrAnimal->setTaille(nouvelAnimal->getTaille());
                ptrAnimal->setNbVictimes(nouvelAnimal->getNbVictimes());
                break;
              case BASQUE:
                ptrAnimal->setLargeurBeret(nouvelAnimal->getLargeurBeret());
                ptrAnimal->setTempsCuisson(nouvelAnimal->getTempsCuisson());
                ptrAnimal->setNbVictoires(nouvelAnimal->getNbVictoires());
                ptrAnimal->setNbRicardBus(nouvelAnimal->getNbRicardBus());
                break;
              case MARMOTTE:
                ptrAnimal->setTaille(nouvelAnimal->getTaille());
                ptrAnimal->setNbTabChocolat(nouvelAnimal->getNbTabChocolat());
                break;
              case ELEPHANT:
                ptrAnimal->setPoids(nouvelAnimal->getPoids());
                ptrAnimal->setLongTrompe(nouvelAnimal->getLongTrompe());
                ptrAnimal->setNbVictimes(nouvelAnimal->getNbVictimes());
                break;
              case AIGLE:
                ptrAnimal->setLongueurBec(nouvelAnimal->getLongueurBec());
                ptrAnimal->setNbLoopings(nouvelAnimal->getNbLoopings());
                break;
              case TORTUE:
                ptrAnimal->setVitesseMax(nouvelAnimal->getVitesseMax());
                ptrAnimal->setAge(nouvelAnimal->getAge());
                ptrAnimal->setCouleur(nouvelAnimal->getCouleur());
                break;
              case LOUTRE:
                ptrAnimal->setNbAmis(nouvelAnimal->getNbAmis());
                ptrAnimal->setTaille(nouvelAnimal->getTaille());
                break;
              case CROCODILE:
                ptrAnimal->setEnfantMange(nouvelAnimal->getEnfantMange());
                ptrAnimal->setNbDents(nouvelAnimal->getNbDents());
                break;
              case LAPIN:
                ptrAnimal->setNbCarotteMange(nouvelAnimal->getNbCarotteMange());
                ptrAnimal->setCouleur(nouvelAnimal->getCouleur());
                break;
              default:
                break;
            }

        }
    }
}

int Parc::rechercherAnimal(const int ID) const {
    for(int i=0; i<iNbAnimaux; i++) {
        if(listeAnimaux[i]->getID() == ID) {
            return i;
        }
    }
    return -1;
}

int Parc::rechercheEnclosAnimal(const int ID) {
    bool enclosTrouve = false;
    int i=0;
    int j=0;
    // Parcours chaque enclos
    while(i<iNbEnclos && !enclosTrouve) {
        j=0;
        // Parcours chaque animal de cet enclos
        while(j<listeEnclos[i]->getOccupation() && !enclosTrouve) {
            if(listeEnclos[i]->getAnimal(j).getID() == ID) {
                enclosTrouve = true;
            }
            else {
                j++;
            }
        }
        if(!enclosTrouve) {
            i++;
        }
    }
    if(enclosTrouve) {
        return i;
    }
    else {
        return -1;
    }
}


// tri par sélection du minimum
void Parc::triAnimauxAlpha() {
    Animal tmp;
    int iRangMin = 0;
    for(int i=0; i<iNbAnimaux-1; i++) {
        iRangMin = i;
        for(int j=i+1; j<iNbAnimaux; j++) {
            if(listeAnimaux[j]->getNom() < listeAnimaux[iRangMin]->getNom()) {
                iRangMin = j;
            }
        }
        // Ici, on échange les contenus des pointeurs
        tmp = *listeAnimaux[i];
        *listeAnimaux[i] = *listeAnimaux[iRangMin];
        *listeAnimaux[iRangMin] = tmp;
    }
}

// tri par sélection du minimum -> À VÉRIFIER CAR DOUBLE CRITÈRE DE TRI !
void Parc::triAnimauxEspece() {
    Animal tmp;
    int iRangMin = 0;
    for(int i=0; i<iNbAnimaux-1; i++) {
        iRangMin = i;
        for(int j=i+1; j<iNbAnimaux; j++) {
            if( listeAnimaux[j]->getEspece() <= listeAnimaux[iRangMin]->getEspece()
                && listeAnimaux[j]->getNom() < listeAnimaux[iRangMin]->getNom()
               ) {
                iRangMin = j;
            }
        }
        // Ici, on échange les contenus des pointeurs
        tmp = *listeAnimaux[i];
        *listeAnimaux[i] = *listeAnimaux[iRangMin];
        *listeAnimaux[iRangMin] = tmp;
    }
}


/*// tri par sélection du minimum
void Parc::triAnimauxAlpha(const int IDEnclos) {
    int iRangEnclos = rechercherEnclos(IDEnclos);
    if(iRangEnclos == -1) {
        cout << "Erreur, enclos introuvable." << endl;
    }
    else {
        Enclos * ptrEnclos = listeEnclos[iRangEnclos];
        Animal tmp;
        int iRangMin = 0;
        int iNbAnimaux = ptrEnclos->getOccupation();
        for(int i=0; i<iNbAnimaux-1; i++) {
            iRangMin = i;
            for(int j=i+1; j<iNbAnimaux; j++) {
                if(ptrEnclos->getAnimal(j).getNom() < ptrEnclos->getAnimal(iRangMin).getNom()) {
                    iRangMin = j;
                }
            }
            // Ici, on échange les contenus des pointeurs
            tmp = *(ptrEnclos->getAnimal(i));
            *(ptrEnclos->getAnimal(i)) = *(ptrEnclos->getAnimal(iRangMin));
            *(ptrEnclos->getAnimal(iRangMin) = tmp;
        }
    }
}*/

/*
// tri par sélection du minimum -> À VÉRIFIER CAR DOUBLE CRITÈRE DE TRI !
void Parc::triAnimauxEspece(const int IDEnclos) {
    int iRangEnclos = rechercherEnclos(IDEnclos);
    if(iRangEnclos == -1) {
        cout << "Erreur, enclos introuvable." << endl;
    }
    else {
        Enclos * ptrEnclos = listeEnclos[iRangEnclos];
        Animal tmp;
        int iRangMin = 0;
        int iNbAnimaux = ptrEnclos->getOccupation();
        for(int i=0; i<iNbAnimaux-1; i++) {
            iRangMin = i;
            for(int j=i+1; j<iNbAnimaux; j++) {
                if( ptrEnclos->tabAnimaux[j]->getEspece() <= ptrEnclos->tabAnimaux[iRangMin]->getEspece()
                    && ptrEnclos->tabAnimaux[j]->getNom() < ptrEnclos->tabAnimaux[iRangMin]->getNom()
                   ) {
                    iRangMin = j;
                }
            }
            // Ici, on échange les contenus des pointeurs
            tmp = *(ptrEnclos->tabAnimaux[i]);
            *(ptrEnclos->tabAnimaux[i]) = *(ptrEnclos->tabAnimaux[iRangMin]);
            *(ptrEnclos->tabAnimaux[iRangMin]) = tmp;
        }
    }
}*/

// tri par sélection du minimum
void Parc::triEnclosAlpha() {
    Enclos tmp;
    int iRangMin = 0;
    for(int i=0; i<iNbEnclos-1; i++) {
        iRangMin = i;
        for(int j=i+1; j<iNbEnclos; j++) {
            if(listeEnclos[j]->getNom() < listeEnclos[iRangMin]->getNom()) {
                iRangMin = j;
            }
        }
        // Ici, on échange les contenus des pointeurs
        tmp = *listeEnclos[i];
        *listeEnclos[i] = *listeEnclos[iRangMin];
        *listeEnclos[iRangMin] = tmp;
    }
}

// tri par sélection du minimum
void Parc::triEnclosOccupation() {
    Enclos tmp;
    int iRangMin = 0;
    for(int i=0; i<iNbEnclos-1; i++) {
        iRangMin = i;
        for(int j=i+1; j<iNbEnclos; j++) {
            if(listeEnclos[j]->getOccupation() < listeEnclos[iRangMin]->getOccupation()) {
                iRangMin = j;
            }
        }
        // Ici, on échange les contenus des pointeurs
        tmp = *listeEnclos[i];
        *listeEnclos[i] = *listeEnclos[iRangMin];
        *listeEnclos[iRangMin] = tmp;
    }
}

// tri par sélection du minimum
void Parc::triEnclosCapacite() {
    Enclos tmp;
    int iRangMin = 0;
    for(int i=0; i<iNbEnclos-1; i++) {
        iRangMin = i;
        for(int j=i+1; j<iNbEnclos; j++) {
            if(listeEnclos[j]->getCapacite() < listeEnclos[iRangMin]->getCapacite()) {
                iRangMin = j;
            }
        }
        // Ici, on échange les contenus des pointeurs
        tmp = *listeEnclos[i];
        *listeEnclos[i] = *listeEnclos[iRangMin];
        *listeEnclos[iRangMin] = tmp;
    }
}

// tri par sélection du minimum
void Parc::triEnclosTauxOccupation() {
    Enclos tmp;
    int iRangMin = 0;
    int iTauxOccMin = 0;
    int iTauxOcc = 0;
    for(int i=0; i<iNbEnclos-1; i++) {
        iRangMin = i;
        iTauxOccMin = listeEnclos[iRangMin]->getOccupation() / listeEnclos[iRangMin]->getCapacite();
        for(int j=i+1; j<iNbEnclos; j++) {
            iTauxOcc = listeEnclos[j]->getOccupation() / listeEnclos[j]->getCapacite();
            if(iTauxOcc < iTauxOccMin) {
                iRangMin = j;
                iTauxOccMin = listeEnclos[iRangMin]->getOccupation() / listeEnclos[iRangMin]->getCapacite();
            }
        }
        // Ici, on échange les contenus des pointeurs
        tmp = *listeEnclos[i];
        *listeEnclos[i] = *listeEnclos[iRangMin];
        *listeEnclos[iRangMin] = tmp;
    }
}
