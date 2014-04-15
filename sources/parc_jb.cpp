#include "../entetes/parc.h"

/******************************************************/
/******************************************************/
/**                                                  **/
/**    FONCTIONS DE CRÉATION D'ANIMAUX               **/
/**                                                  **/
/******************************************************/
/******************************************************/

void Parc::creerAnimal(Girafe const * a, const int IDEnclosAccueil) {
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    Enclos * ptrEnclos = listeEnclos[iRangEnclos];

    if(ptrEnclos->getOccupation() < ptrEnclos->getCapacite()) {
         listeGirafe.ajouter(new Girafe(a->getTaille(), a->getNbTaches(), a->getNom(), iIDAnimaux++));
         listeAnimaux.ajouter(listeGirafe[listeGirafe.getNbElem()-1]);
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
         listeTigre.ajouter(new Tigre(a->getGarot(), a->getNbVictimes(), a->getNom(), iIDAnimaux++));
         listeAnimaux.ajouter(listeTigre[listeTigre.getNbElem()-1]);
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
         listeBasque.ajouter(new Basque(a->getLargeurBeret(), a->getTempsCuisson(), a->getNbVictoires(), a->getNbRicard(), a->getNom(), iIDAnimaux++));
         listeAnimaux.ajouter(listeBasque[listeBasque.getNbElem()-1]);
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
         listeMarmotte.ajouter(new Marmotte(a->getTaille(), a->getNbTabChocolat(), a->getNom(), iIDAnimaux++));
         listeAnimaux.ajouter(listeMarmotte[listeMarmotte.getNbElem()-1]);
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
         listeElephant.ajouter(new Elephant(a->getPoids(), a->getLongTrompe(), a->getNbVictimes(), a->getNom(), iIDAnimaux++));
         listeAnimaux.ajouter(listeElephant[listeElephant.getNbElem()-1]);
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
         listeAigle.ajouter(new Aigle(a->getLongueurBec(), a->getNbLoopings(), a->getNom(), iIDAnimaux++));
         listeAnimaux.ajouter(listeAigle[listeAigle.getNbElem()-1]);
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
         listeTortue.ajouter(new Tortue(a->getVitesseMax(), a->getAge(), a->getCouleur(), a->getNom(), iIDAnimaux++));
         listeAnimaux.ajouter(listeTortue[listeTortue.getNbElem()-1]);
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
         listeLoutre.ajouter(new Loutre(a->getNbAmis(), a->getTaille(), a->getNom(), iIDAnimaux++));
         listeAnimaux.ajouter(listeLoutre[listeLoutre.getNbElem()-1]);
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
         listeCrocodile.ajouter(new Crocodile(a->getEnfantMange(), a->getNbDents(), a->getNom(), iIDAnimaux++));
         listeAnimaux.ajouter(listeCrocodile[listeCrocodile.getNbElem()-1]);
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
         listeLapin.ajouter(new Lapin(a->getNbCarotteMange(), a->getCouleur(), a->getNom(), iIDAnimaux++));
         listeAnimaux.ajouter(listeLapin[listeLapin.getNbElem()-1]);
         iNbAnimaux++;
         ajouterAnimalDansEnclos(listeAnimaux[iNbAnimaux-1], ptrEnclos);
    }
    else {
        cout << "Erreur, enclos plein." << endl;
    }
}


/******************************************************/
/******************************************************/
/**                                                  **/
/**    FONCTION DE SUPPRESSION D'ANIMAUX             **/
/**                                                  **/
/******************************************************/
/******************************************************/

void Parc::supprimerAnimal(const int ID) {
    int iRangEnclos = rechercheEnclosAnimal(ID);
    if(iRangEnclos == -1) {
        cout << "Erreur, enclos de l'animal non trouvé." << endl;
    }
    else {
        Animal * ptrAnimal = listeAnimaux[rechercherAnimal(ID)];
        Girafe * ptrGirafe = NULL;
        Tigre * ptrTigre = NULL;
        Basque * ptrBasque = NULL;
        Marmotte * ptrMarmotte = NULL;
        Elephant * ptrElephant = NULL;
        Aigle * ptrAigle = NULL;
        Tortue * ptrTortue = NULL;
        Loutre * ptrLoutre = NULL;
        Crocodile * ptrCrocodile = NULL;
        Lapin * ptrLapin = NULL;

        // Supprime l'animal de son enclos
        listeEnclos[iRangEnclos]->supprimerAnimal(ptrAnimal);

        // Supprime l'animal de son tableau d'espèce
        int iEspece = ptrAnimal->getEspece();
        switch (iEspece) {
            case GIRAFE:
                ptrGirafe = listeGirafe[rechercherGirafe(ID)];
                listeGirafe.enlever(ptrGirafe);
                break;
            case TIGRE:
                ptrTigre = listeTigre[rechercherTigre(ID)];
                listeTigre.enlever(ptrTigre);
                break;
            case BASQUE:
                ptrBasque = listeBasque[rechercherBasque(ID)];
                listeBasque.enlever(ptrBasque);
                break;
            case MARMOTTE:
                ptrMarmotte = listeMarmotte[rechercherMarmotte(ID)];
                listeMarmotte.enlever(ptrMarmotte);
                break;
            case ELEPHANT:
                ptrElephant = listeElephant[rechercherElephant(ID)];
                listeElephant.enlever(ptrElephant);
                break;
            case AIGLE:
                ptrAigle = listeAigle[rechercherAigle(ID)];
                listeAigle.enlever(ptrAigle);
                break;
            case TORTUE:
                ptrTortue = listeTortue[rechercherTortue(ID)];
                listeTortue.enlever(ptrTortue);
                break;
            case LOUTRE:
                ptrLoutre = listeLoutre[rechercherLoutre(ID)];
                listeLoutre.enlever(ptrLoutre);
                break;
            case CROCODILE:
                ptrCrocodile = listeCrocodile[rechercherCrocodile(ID)];
                listeCrocodile.enlever(ptrCrocodile);
                break;
            case LAPIN:
                ptrLapin = listeLapin[rechercherLapin(ID)];
                listeLapin.enlever(ptrLapin);
                break;
        }

        // Supprime l'animal
        listeAnimaux.enlever(ptrAnimal);
        delete ptrAnimal;
    }
}


/******************************************************/
/******************************************************/
/**                                                  **/
/**    FONCTIONS DE MODIFICATION D'ANIMAUX           **/
/**                                                  **/
/******************************************************/
/******************************************************/

void Parc::modifierAnimal(const int IDAnimalAModifier, Girafe const * nouvelAnimal) {
    // FAIRE GESTION ERREUR ICI !!
    int iRangAnimal = rechercherGirafe(IDAnimalAModifier);
    if(iRangAnimal == -1) {
        cout << "Erreur, animal non trouvé."<< endl;
    }
    else {
        Girafe * ptrAnimal = listeGirafe[iRangAnimal];
        ptrAnimal->setNom(nouvelAnimal->getNom());
        ptrAnimal->setTaille(nouvelAnimal->getTaille());
        ptrAnimal->setNbTaches(nouvelAnimal->getNbTaches());

    }
}

void Parc::modifierAnimal(const int IDAnimalAModifier, Tigre const * nouvelAnimal) {
    // FAIRE GESTION ERREUR ICI !!
    int iRangAnimal = rechercherTigre(IDAnimalAModifier);
    if(iRangAnimal == -1) {
        cout << "Erreur, animal non trouvé."<< endl;
    }
    else {
        Tigre * ptrAnimal = listeTigre[iRangAnimal];
        ptrAnimal->setGarot(nouvelAnimal->getGarot());
        ptrAnimal->setNbVictimes(nouvelAnimal->getNbVictimes());
    }
}

void Parc::modifierAnimal(const int IDAnimalAModifier, Basque const * nouvelAnimal) {
    // FAIRE GESTION ERREUR ICI !!
    int iRangAnimal = rechercherBasque(IDAnimalAModifier);
    if(iRangAnimal == -1) {
        cout << "Erreur, animal non trouvé."<< endl;
    }
    else {
        Basque * ptrAnimal = listeBasque[iRangAnimal];
        ptrAnimal->setLargeurBeret(nouvelAnimal->getLargeurBeret());
        ptrAnimal->setTempsCuisson(nouvelAnimal->getTempsCuisson());
        ptrAnimal->setNbVictoires(nouvelAnimal->getNbVictoires());
        ptrAnimal->setNbRicard(nouvelAnimal->getNbRicard());

    }
}

void Parc::modifierAnimal(const int IDAnimalAModifier, Marmotte const * nouvelAnimal) {
    // FAIRE GESTION ERREUR ICI !!
    int iRangAnimal = rechercherMarmotte(IDAnimalAModifier);
    if(iRangAnimal == -1) {
        cout << "Erreur, animal non trouvé."<< endl;
    }
    else {
        Marmotte * ptrAnimal = listeMarmotte[iRangAnimal];
        ptrAnimal->setTaille(nouvelAnimal->getTaille());
        ptrAnimal->setNbTabChocolat(nouvelAnimal->getNbTabChocolat());

    }
}

void Parc::modifierAnimal(const int IDAnimalAModifier, Elephant const * nouvelAnimal) {
    // FAIRE GESTION ERREUR ICI !!
    int iRangAnimal = rechercherElephant(IDAnimalAModifier);
    if(iRangAnimal == -1) {
        cout << "Erreur, animal non trouvé."<< endl;
    }
    else {
        Elephant * ptrAnimal = listeElephant[iRangAnimal];
        ptrAnimal->setPoids(nouvelAnimal->getPoids());
        ptrAnimal->setLongTrompe(nouvelAnimal->getLongTrompe());
        ptrAnimal->setNbVictimes(nouvelAnimal->getNbVictimes());

    }
}

void Parc::modifierAnimal(const int IDAnimalAModifier, Aigle const * nouvelAnimal) {
    // FAIRE GESTION ERREUR ICI !!
    int iRangAnimal = rechercherAigle(IDAnimalAModifier);
    if(iRangAnimal == -1) {
        cout << "Erreur, animal non trouvé."<< endl;
    }
    else {
        Aigle * ptrAnimal = listeAigle[iRangAnimal];
        ptrAnimal->setLongueurBec(nouvelAnimal->getLongueurBec());
        ptrAnimal->setNbLoopings(nouvelAnimal->getNbLoopings());

    }
}

void Parc::modifierAnimal(const int IDAnimalAModifier, Tortue const * nouvelAnimal) {
    // FAIRE GESTION ERREUR ICI !!
    int iRangAnimal = rechercherTortue(IDAnimalAModifier);
    if(iRangAnimal == -1) {
        cout << "Erreur, animal non trouvé."<< endl;
    }
    else {
        Tortue * ptrAnimal = listeTortue[iRangAnimal];
        ptrAnimal->setVitesseMax(nouvelAnimal->getVitesseMax());
        ptrAnimal->setAge(nouvelAnimal->getAge());
        ptrAnimal->setCouleur(nouvelAnimal->getCouleur());

    }
}

void Parc::modifierAnimal(const int IDAnimalAModifier, Loutre const * nouvelAnimal) {
    // FAIRE GESTION ERREUR ICI !!
    int iRangAnimal = rechercherLoutre(IDAnimalAModifier);
    if(iRangAnimal == -1) {
        cout << "Erreur, animal non trouvé."<< endl;
    }
    else {
        Loutre * ptrAnimal = listeLoutre[iRangAnimal];
        ptrAnimal->setNbAmis(nouvelAnimal->getNbAmis());
        ptrAnimal->setTaille(nouvelAnimal->getTaille());

    }
}

void Parc::modifierAnimal(const int IDAnimalAModifier, Crocodile const * nouvelAnimal) {
    // FAIRE GESTION ERREUR ICI !!
    int iRangAnimal = rechercherCrocodile(IDAnimalAModifier);
    if(iRangAnimal == -1) {
        cout << "Erreur, animal non trouvé."<< endl;
    }
    else {
        Crocodile * ptrAnimal = listeCrocodile[iRangAnimal];
        ptrAnimal->setEnfantMange(nouvelAnimal->getEnfantMange());
        ptrAnimal->setNbDents(nouvelAnimal->getNbDents());

    }
}

void Parc::modifierAnimal(const int IDAnimalAModifier, Lapin const * nouvelAnimal) {
    // FAIRE GESTION ERREUR ICI !!
    int iRangAnimal = rechercherLapin(IDAnimalAModifier);
    if(iRangAnimal == -1) {
        cout << "Erreur, animal non trouvé."<< endl;
    }
    else {
        Lapin * ptrAnimal = listeLapin[iRangAnimal];
        ptrAnimal->setNbCarotteMange(nouvelAnimal->getNbCarotteMange());
                ptrAnimal->setCouleur(nouvelAnimal->getCouleur());

    }
}

/******************************************************/
/******************************************************/
/**                                                  **/
/**    FONCTIONS DE RECHERCHE D'ANIMAUX              **/
/**                                                  **/
/******************************************************/
/******************************************************/

int Parc::rechercherAnimal(const int ID) const {
    for(int i=0; i<iNbAnimaux; i++) {
        if(listeAnimaux[i]->getID() == ID) {
            return i;
        }
    }
    return -1;
}

int Parc::rechercherTigre(const int ID) const {
    int iNbAnimaux = listeTigre.getNbElem();
    for(int i=0; i<iNbAnimaux; i++) {
        if(listeTigre[i]->getID() == ID) {
            return i;
        }
    }
    return -1;
}


int Parc::rechercherBasque(const int ID) const {
    int iNbAnimaux = listeBasque.getNbElem();
    for(int i=0; i<iNbAnimaux; i++) {
        if(listeBasque[i]->getID() == ID) {
            return i;
        }
    }
    return -1;
}


int Parc::rechercherMarmotte(const int ID) const {
    int iNbAnimaux = listeMarmotte.getNbElem();
    for(int i=0; i<iNbAnimaux; i++) {
        if(listeMarmotte[i]->getID() == ID) {
            return i;
        }
    }
    return -1;
}


int Parc::rechercherElephant(const int ID) const {
    int iNbAnimaux = listeElephant.getNbElem();
    for(int i=0; i<iNbAnimaux; i++) {
        if(listeElephant[i]->getID() == ID) {
            return i;
        }
    }
    return -1;
}


int Parc::rechercherAigle(const int ID) const {
    int iNbAnimaux = listeAigle.getNbElem();
    for(int i=0; i<iNbAnimaux; i++) {
        if(listeAigle[i]->getID() == ID) {
            return i;
        }
    }
    return -1;
}


int Parc::rechercherTortue(const int ID) const {
    int iNbAnimaux = listeTortue.getNbElem();
    for(int i=0; i<iNbAnimaux; i++) {
        if(listeTortue[i]->getID() == ID) {
            return i;
        }
    }
    return -1;
}


int Parc::rechercherLoutre(const int ID) const {
    int iNbAnimaux = listeLoutre.getNbElem();
    for(int i=0; i<iNbAnimaux; i++) {
        if(listeLoutre[i]->getID() == ID) {
            return i;
        }
    }
    return -1;
}


int Parc::rechercherCrocodile(const int ID) const {
    int iNbAnimaux = listeCrocodile.getNbElem();
    for(int i=0; i<iNbAnimaux; i++) {
        if(listeCrocodile[i]->getID() == ID) {
            return i;
        }
    }
    return -1;
}


int Parc::rechercherLapin(const int ID) const {
    int iNbAnimaux = listeLapin.getNbElem();
    for(int i=0; i<iNbAnimaux; i++) {
        if(listeLapin[i]->getID() == ID) {
            return i;
        }
    }
    return -1;
}

int Parc::rechercherGirafe(const int ID) const {
    int iNbAnimaux = listeGirafe.getNbElem();
    for(int i=0; i<iNbAnimaux; i++) {
        if(listeGirafe[i]->getID() == ID) {
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


/******************************************************/
/******************************************************/
/**                                                  **/
/**    FONCTIONS DE TRI                              **/
/**                                                  **/
/******************************************************/
/******************************************************/

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
        listeAnimaux.intervertir(listeAnimaux[iRangMin], listeAnimaux[i]);
        /*tmp = *listeAnimaux[i];
        *listeAnimaux[i] = *listeAnimaux[iRangMin];
        *listeAnimaux[iRangMin] = tmp;*/
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
        listeAnimaux.intervertir(listeAnimaux[iRangMin], listeAnimaux[i]);
/*        tmp = *listeAnimaux[i];
        *listeAnimaux[i] = *listeAnimaux[iRangMin];
        *listeAnimaux[iRangMin] = tmp;*/
    }
}


// tri dans un enclos impossible pour le moment, rajouter la méthode pour intervertir dans Enclos
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
        listeEnclos.intervertir(listeEnclos[iRangMin], listeEnclos[i]);
        /*tmp = *listeEnclos[i];
        *listeEnclos[i] = *listeEnclos[iRangMin];
        *listeEnclos[iRangMin] = tmp;*/
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
        listeEnclos.intervertir(listeEnclos[iRangMin], listeEnclos[i]);
/*        tmp = *listeEnclos[i];
        *listeEnclos[i] = *listeEnclos[iRangMin];
        *listeEnclos[iRangMin] = tmp;*/
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
        listeEnclos.intervertir(listeEnclos[iRangMin], listeEnclos[i]);
        /*tmp = *listeEnclos[i];
        *listeEnclos[i] = *listeEnclos[iRangMin];
        *listeEnclos[iRangMin] = tmp;*/
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
        listeEnclos.intervertir(listeEnclos[iRangMin], listeEnclos[i]);
/*        tmp = *listeEnclos[i];
        *listeEnclos[i] = *listeEnclos[iRangMin];
        *listeEnclos[iRangMin] = tmp;*/
    }
}
