#include "../entetes/parc.h"


void Parc::creerAnimal(Girafe const * a, const int IDEnclosAccueil) {
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    Enclos * ptrEnclos = listeEnclos[iRangEnclos];

    if(ptrEnclos->getOccupation() < ptrEnclos->getCapacite()) {
         listeAnimaux.ajouter(new Girafe(a->getTaille(), a->getNbTaches(), a->getNom(), iIDAnimaux++));
         iNbAnimaux++;
         ajouterAnimalDansEnclos(listeAnimaux[iNbAnimaux-1], ptrEnclos);
    }
    else {
        cout << "Erreur, enclos plein." << endl;
    }
}


void Parc::creerAnimal(Tigre const * a, const int IDEnclosAccueil) {
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    Enclos * ptrEnclos = listeEnclos[iRangEnclos];

    if(ptrEnclos->getOccupation() < ptrEnclos->getCapacite()) {
         listeAnimaux.ajouter(new Tigre(a->getGarot(), a->getNbVictimes(), a->getNom(), iIDAnimaux++));
         iNbAnimaux++;
         ajouterAnimalDansEnclos(listeAnimaux[iNbAnimaux-1], ptrEnclos);
    }
    else {
        cout << "Erreur, enclos plein." << endl;
    }
}

void Parc::creerAnimal(Basque const * a, const int IDEnclosAccueil) {
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    Enclos * ptrEnclos = listeEnclos[iRangEnclos];

    if(ptrEnclos->getOccupation() < ptrEnclos->getCapacite()) {
         listeAnimaux.ajouter(new Basque(a->getLargeurBeret(), a->getTempsCuisson(), a->getNbVictoires(), a->getNbRicard(), a->getNom(), iIDAnimaux++));
         iNbAnimaux++;
         ajouterAnimalDansEnclos(listeAnimaux[iNbAnimaux-1], ptrEnclos);
    }
    else {
        cout << "Erreur, enclos plein." << endl;
    }
}

void Parc::creerAnimal(Marmotte const * a, const int IDEnclosAccueil) {
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    Enclos * ptrEnclos = listeEnclos[iRangEnclos];

    if(ptrEnclos->getOccupation() < ptrEnclos->getCapacite()) {
         listeAnimaux.ajouter(new Marmotte(a->getTaille(), a->getNbTabChocolat(), a->getNom(), iIDAnimaux++));
         iNbAnimaux++;
         ajouterAnimalDansEnclos(listeAnimaux[iNbAnimaux-1], ptrEnclos);
    }
    else {
        cout << "Erreur, enclos plein." << endl;
    }
}

void Parc::creerAnimal(Elephant const * a, const int IDEnclosAccueil) {
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    Enclos * ptrEnclos = listeEnclos[iRangEnclos];

    if(ptrEnclos->getOccupation() < ptrEnclos->getCapacite()) {
         listeAnimaux.ajouter(new Elephant(a->getPoids(), a->getLongTrompe(), a->getNbVictimes(), a->getNom(), iIDAnimaux++));
         iNbAnimaux++;
         ajouterAnimalDansEnclos(listeAnimaux[iNbAnimaux-1], ptrEnclos);
    }
    else {
        cout << "Erreur, enclos plein." << endl;
    }
}

void Parc::creerAnimal(Aigle const * a, const int IDEnclosAccueil) {
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    Enclos * ptrEnclos = listeEnclos[iRangEnclos];

    if(ptrEnclos->getOccupation() < ptrEnclos->getCapacite()) {
         listeAnimaux.ajouter(new Aigle(a->getLongueurBec(), a->getNbLoopings(), a->getNom(), iIDAnimaux++));
         iNbAnimaux++;
         ajouterAnimalDansEnclos(listeAnimaux[iNbAnimaux-1], ptrEnclos);
    }
    else {
        cout << "Erreur, enclos plein." << endl;
    }
}

void Parc::creerAnimal(Tortue const * a, const int IDEnclosAccueil) {
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    Enclos * ptrEnclos = listeEnclos[iRangEnclos];

    if(ptrEnclos->getOccupation() < ptrEnclos->getCapacite()) {
         listeAnimaux.ajouter(new Tortue(a->getVitesseMax(), a->getAge(), a->getCouleur(), a->getNom(), iIDAnimaux++));
         iNbAnimaux++;
         ajouterAnimalDansEnclos(listeAnimaux[iNbAnimaux-1], ptrEnclos);
    }
    else {
        cout << "Erreur, enclos plein." << endl;
    }
}

void Parc::creerAnimal(Loutre const * a, const int IDEnclosAccueil) {
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    Enclos * ptrEnclos = listeEnclos[iRangEnclos];

    if(ptrEnclos->getOccupation() < ptrEnclos->getCapacite()) {
         listeAnimaux.ajouter(new Loutre(a->getNbAmis(), a->getTaille(), a->getNom(), iIDAnimaux++));
         iNbAnimaux++;
         ajouterAnimalDansEnclos(listeAnimaux[iNbAnimaux-1], ptrEnclos);
    }
    else {
        cout << "Erreur, enclos plein." << endl;
    }
}

void Parc::creerAnimal(Crocodile const * a, const int IDEnclosAccueil) {
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    Enclos * ptrEnclos = listeEnclos[iRangEnclos];

    if(ptrEnclos->getOccupation() < ptrEnclos->getCapacite()) {
         listeAnimaux.ajouter(new Crocodile(a->getEnfantMange(), a->getNbDents(), a->getNom(), iIDAnimaux++));
         iNbAnimaux++;
         ajouterAnimalDansEnclos(listeAnimaux[iNbAnimaux-1], ptrEnclos);
    }
    else {
        cout << "Erreur, enclos plein." << endl;
    }
}

void Parc::creerAnimal(Lapin const * a, const int IDEnclosAccueil) {
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    Enclos * ptrEnclos = listeEnclos[iRangEnclos];

    if(ptrEnclos->getOccupation() < ptrEnclos->getCapacite()) {
         listeAnimaux.ajouter(new Lapin(a->getNbCarotteMange(), a->getCouleur(), a->getNom(), iIDAnimaux++));
         iNbAnimaux++;
         ajouterAnimalDansEnclos(listeAnimaux[iNbAnimaux-1], ptrEnclos);
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

void Parc::modifierAnimal(const int IDAnimalAModifier, Girafe const * nouvelAnimal) {
    // FAIRE GESTION ERREUR ICI !!
    int iRangAnimal = rechercheAnimal(IDAnimalAModifier);
    if(iRangAnimal == -1) {
        cout << "Erreur, animal non trouvé."<< endl;
    }
    else {
        Girafe * ptrAnimal = listeAnimaux[iRangAnimal];
        ptrAnimal->setNom(nouvelAnimal->getNom());
        ptrAnimal->setTaille(nouvelAnimal->getTaille());
        ptrAnimal->setNbTaches(nouvelAnimal->getNbTaches());

    }
}

void Parc::modifierAnimal(const int IDAnimalAModifier, Tigre const * nouvelAnimal) {
    // FAIRE GESTION ERREUR ICI !!
    int iRangAnimal = rechercheAnimal(IDAnimalAModifier);
    if(iRangAnimal == -1) {
        cout << "Erreur, animal non trouvé."<< endl;
    }
    else {
        Animal * ptrAnimal = listeAnimaux[iRangAnimal];
        ptrAnimal->setTaille(nouvelAnimal->getTaille());
        ptrAnimal->setNbVictimes(nouvelAnimal->getNbVictimes());
    }
}

void Parc::modifierAnimal(const int IDAnimalAModifier, Basque const * nouvelAnimal) {
    // FAIRE GESTION ERREUR ICI !!
    int iRangAnimal = rechercheAnimal(IDAnimalAModifier);
    if(iRangAnimal == -1) {
        cout << "Erreur, animal non trouvé."<< endl;
    }
    else {
        Animal * ptrAnimal = listeAnimaux[iRangAnimal];
        ptrAnimal->setLargeurBeret(nouvelAnimal->getLargeurBeret());
        ptrAnimal->setTempsCuisson(nouvelAnimal->getTempsCuisson());
        ptrAnimal->setNbVictoires(nouvelAnimal->getNbVictoires());
        ptrAnimal->setNbRicardBus(nouvelAnimal->getNbRicardBus());

    }
}

void Parc::modifierAnimal(const int IDAnimalAModifier, Marmotte const * nouvelAnimal) {
    // FAIRE GESTION ERREUR ICI !!
    int iRangAnimal = rechercheAnimal(IDAnimalAModifier);
    if(iRangAnimal == -1) {
        cout << "Erreur, animal non trouvé."<< endl;
    }
    else {
        Animal * ptrAnimal = listeAnimaux[iRangAnimal];
        ptrAnimal->setTaille(nouvelAnimal->getTaille());
        ptrAnimal->setNbTabChocolat(nouvelAnimal->getNbTabChocolat());

    }
}

void Parc::modifierAnimal(const int IDAnimalAModifier, Elephant const * nouvelAnimal) {
    // FAIRE GESTION ERREUR ICI !!
    int iRangAnimal = rechercheAnimal(IDAnimalAModifier);
    if(iRangAnimal == -1) {
        cout << "Erreur, animal non trouvé."<< endl;
    }
    else {
        Animal * ptrAnimal = listeAnimaux[iRangAnimal];
        ptrAnimal->setPoids(nouvelAnimal->getPoids());
        ptrAnimal->setLongTrompe(nouvelAnimal->getLongTrompe());
        ptrAnimal->setNbVictimes(nouvelAnimal->getNbVictimes());

    }
}

void Parc::modifierAnimal(const int IDAnimalAModifier, Aigle const * nouvelAnimal) {
    // FAIRE GESTION ERREUR ICI !!
    int iRangAnimal = rechercheAnimal(IDAnimalAModifier);
    if(iRangAnimal == -1) {
        cout << "Erreur, animal non trouvé."<< endl;
    }
    else {
        Animal * ptrAnimal = listeAnimaux[iRangAnimal];
        ptrAnimal->setLongueurBec(nouvelAnimal->getLongueurBec());
        ptrAnimal->setNbLoopings(nouvelAnimal->getNbLoopings());

    }
}

void Parc::modifierAnimal(const int IDAnimalAModifier, Tortue const * nouvelAnimal) {
    // FAIRE GESTION ERREUR ICI !!
    int iRangAnimal = rechercheAnimal(IDAnimalAModifier);
    if(iRangAnimal == -1) {
        cout << "Erreur, animal non trouvé."<< endl;
    }
    else {
        Animal * ptrAnimal = listeAnimaux[iRangAnimal];
        ptrAnimal->setVitesseMax(nouvelAnimal->getVitesseMax());
        ptrAnimal->setAge(nouvelAnimal->getAge());
        ptrAnimal->setCouleur(nouvelAnimal->getCouleur());

    }
}

void Parc::modifierAnimal(const int IDAnimalAModifier, Loutre const * nouvelAnimal) {
    // FAIRE GESTION ERREUR ICI !!
    int iRangAnimal = rechercheAnimal(IDAnimalAModifier);
    if(iRangAnimal == -1) {
        cout << "Erreur, animal non trouvé."<< endl;
    }
    else {
        Animal * ptrAnimal = listeAnimaux[iRangAnimal];
        ptrAnimal->setNbAmis(nouvelAnimal->getNbAmis());
        ptrAnimal->setTaille(nouvelAnimal->getTaille());

    }
}

void Parc::modifierAnimal(const int IDAnimalAModifier, Crocodile const * nouvelAnimal) {
    // FAIRE GESTION ERREUR ICI !!
    int iRangAnimal = rechercheAnimal(IDAnimalAModifier);
    if(iRangAnimal == -1) {
        cout << "Erreur, animal non trouvé."<< endl;
    }
    else {
        Animal * ptrAnimal = listeAnimaux[iRangAnimal];
        ptrAnimal->setEnfantMange(nouvelAnimal->getEnfantMange());
        ptrAnimal->setNbDents(nouvelAnimal->getNbDents());

    }
}

void Parc::modifierAnimal(const int IDAnimalAModifier, Lapin const * nouvelAnimal) {
    // FAIRE GESTION ERREUR ICI !!
    int iRangAnimal = rechercheAnimal(IDAnimalAModifier);
    if(iRangAnimal == -1) {
        cout << "Erreur, animal non trouvé."<< endl;
    }
    else {
        Animal * ptrAnimal = listeAnimaux[iRangAnimal];
        ptrAnimal->setNbCarotteMange(nouvelAnimal->getNbCarotteMange());
                ptrAnimal->setCouleur(nouvelAnimal->getCouleur());

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
