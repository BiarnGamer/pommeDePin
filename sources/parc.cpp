#include "../entetes/parc.h"
#include <cstdlib>
#include <ctime>

using namespace std;


/**************************************/
/**************************************/
/**************************************/
/**                                  **/
/**     STRUCTURE PROIE              **/
/**                                  **/
/**************************************/
/**************************************/
/**************************************/

bool operator==(const Proie & p1, const Proie & p2) {
    if(p1.iCodeProie == p2.iCodeProie) {
        return true;
    } else {
        return false;
    }
}


/**************************************/
/**************************************/
/**************************************/
/**                                  **/
/**     MÉTHODES PRIVÉES             **/
/**                                  **/
/**************************************/
/**************************************/
/**************************************/
void Parc::initTabProies() {
    // Si le tableau n'a pas déjà été créé
    if(tabProies.getNbElem() == 0) {
        // Initialisation des variables
        Set <Proie> setVide;
        Set <Proie> proiesEspece;
        Proie proie1, proie2, proie3, proie4, proie5, proie6;

        // Proies de la girafe : aucune
        tabProies.inserer(proiesEspece,0);

        // Proies du tigre
        // girafe
        proie1.iCodeProie = 0;
        proie1.iSeuil1 = 4;
        proie1.iSeuil2 = 15;
        // basque
        proie2.iCodeProie = 2;
        proie2.iSeuil1 = 50;
        proie2.iSeuil2 = 36542;
        // marmotte
        proie3.iCodeProie = 3;
        proie3.iSeuil1 = 50;
        proie3.iSeuil2 = 400;
        // elephant
        proie4.iCodeProie = 4;
        proie4.iSeuil1 = 3;
        proie4.iSeuil2 = 8;
        // loutre
        proie5.iCodeProie = 7;
        proie5.iSeuil1 = 50;
        proie5.iSeuil2 = 400;
        // lapin
        proie6.iCodeProie = 9;
        proie6.iSeuil1 = 50;
        proie6.iSeuil2 = 400;
        // Ajout des proies
        proiesEspece.ajouter(proie1);
        proiesEspece.ajouter(proie2);
        proiesEspece.ajouter(proie3);
        proiesEspece.ajouter(proie4);
        proiesEspece.ajouter(proie5);
        proiesEspece.ajouter(proie6);
        // Enregistrement et initialisation de proiesEspece
        tabProies.inserer(proiesEspece,1);
        proiesEspece = setVide;

        // Proies des Basque, Marmotte, Elephant, Aigle, Tortue, Loutre : acune
        tabProies.inserer(proiesEspece,2);
        tabProies.inserer(proiesEspece,3);
        tabProies.inserer(proiesEspece,4);
        tabProies.inserer(proiesEspece,5);
        tabProies.inserer(proiesEspece,6);
        tabProies.inserer(proiesEspece,7);

        // Proies du crocodile
        // girafe
        proie1.iCodeProie = 0;
        proie1.iSeuil1 = 4;
        proie1.iSeuil2 = 18;
        // basque
        proie2.iCodeProie = 2;
        proie2.iSeuil1 = 50;
        proie2.iSeuil2 = 36542;
        // marmotte
        proie3.iCodeProie = 3;
        proie3.iSeuil1 = 50;
        proie3.iSeuil2 = 400;
        // elephant
        proie4.iCodeProie = 4;
        proie4.iSeuil1 = 1;
        proie4.iSeuil2 = 4;
        // loutre
        proie5.iCodeProie = 7;
        proie5.iSeuil1 = 50;
        proie5.iSeuil2 = 400;
        // lapin
        proie6.iCodeProie = 9;
        proie6.iSeuil1 = 50;
        proie6.iSeuil2 = 400;
        // Ajout des proies
        proiesEspece.ajouter(proie1);
        proiesEspece.ajouter(proie2);
        proiesEspece.ajouter(proie3);
        proiesEspece.ajouter(proie4);
        proiesEspece.ajouter(proie5);
        proiesEspece.ajouter(proie6);
        // Enregistrement et éinitialisation de proiesEspece
        tabProies.inserer(proiesEspece,8);
        proiesEspece = setVide;

        // Proies du lapin : aucune
        tabProies.inserer(proiesEspece,9);
    }
}





/**************************************/
/**************************************/
/**************************************/
/**                                  **/
/**     MÉTHODES PUBLIQUES           **/
/**                                  **/
/**************************************/
/**************************************/
/**************************************/



/*************************************/
/**  constructeurs / destructeurs   **/
/*************************************/
Parc::Parc():iIDAnimaux(1), iIDEnclos(1), iNbAnimaux(0), iNbEnclos(0) {
    initTabProies();
}

Parc::Parc(const Parc & p) {
    iIDAnimaux = p.iIDAnimaux;
    iIDEnclos = p.iIDEnclos;
    iNbAnimaux = p.iNbAnimaux;
    iNbEnclos = p.iNbEnclos;
    listeAnimaux = p.listeAnimaux;
    listeGirafe = p.listeGirafe;
    listeTigre = p.listeTigre;
    listeTortue = p.listeTortue;
    listeMarmotte = p.listeMarmotte;
    listeLoutre = p.listeLoutre;
    listeLapin = p.listeLapin;
    listeBasque = p.listeBasque;
    listeCrocodile = p.listeCrocodile;
    listeElephant = p.listeElephant;
    listeAigle = p.listeAigle;
    listeEnclos = p.listeEnclos;
    tabProies = p.tabProies;
}

Parc::~Parc() {
    for (int i=0; i<iNbAnimaux; i++) {
        delete listeAnimaux[i];
    }
    for (int i=0; i<iNbEnclos; i++) {
        delete listeEnclos[i];
    }
    // Chose bizarre ci-dessous ; coredumped quand décommenté (double free or corruption)
    // On vide le tableau de Proies pour libérer la mémoire
    /** Attention, légère fuite mémoire ici. Les tableau dynamiques des Sets ne sont pas libérés.
    Il faudrait faire une set de pointeurs sur set pour résoudre le souci **/
   /* while(tabProies.getNbElem() != 0) {
        tabProies.enlever(tabProies[0]);
    }*/
}


/*******************/
/**  accesseurs   **/
/*******************/
int Parc::getIDAnimaux() const {
    return iIDAnimaux;
}

int Parc::getIDEnclos() const {
    return iIDEnclos;
}

int Parc::getNbAnimaux() const {
    return iNbAnimaux;
}

int Parc::getNbEnclos() const {
    return iNbEnclos;
}

Enclos Parc::getEnclos(int i) const {
    if(0<=i && i<getNbEnclos()) {
        return *listeEnclos[i];
    }
    Enclos e1;
    return e1;
}

Animal const * Parc::getAnimal(int i) const {
    if(0<=i && i<iNbAnimaux) {
        return listeAnimaux[i];
    }
    Animal * a1 = new Animal;
	return a1;
}

ostream & operator<<(ostream &, const Parc &);

/***************************************/
/***             Valentin              */
/***************************************/

void Parc::creerEnclos(const string & nom, const int type, const int capacite) {
    // On crée l'enclos qui appartient à la classe car elle seule doit pouvoir le modifier
    Enclos * e1;
    e1 = new Enclos(nom, type, capacite, iIDEnclos);
    iIDEnclos++;
    //On ajoute l'enclos dans notre classe
    listeEnclos.ajouter(e1);
    iNbEnclos++;
}

int Parc::rechercherEnclos(const int ID) const {
   for(int i=0; i < getNbEnclos(); i++) {
        if (listeEnclos[i]->getID() == ID) {
            return i;
        }
    }
    return -1;
}

// Supprime tous les animaux contenus dans l'enclos puis supprime l'enclos
void Parc::supprimerEnclos(const int ID) {
    int rang = rechercherEnclos(ID);
    if (rang == -1) {
        cout << "Cet ID d'enclos n'existe pas." << endl;
    }
    else {
        Enclos * ptrEnclos = listeEnclos[rang];
        // Suppression des animaux, sans gérer les conséquences car on les tue tous
        while(ptrEnclos->getOccupation() != 0) {
            supprimerAnimalSansControle(ptrEnclos->getAnimal(0).getID());
        }
        // Suppression de l'enclos
        listeEnclos.enlever(ptrEnclos);
        delete ptrEnclos;
        iNbEnclos--;
    }
}

void Parc::mofidierEnclos(const int IDEnclosAModifier, const string nom) {
    int iRang = rechercherEnclos(IDEnclosAModifier);
    if(iRang == -1) {
        cout << "Cet ID d'enclos n'existe pas." << endl;
    }
    else {
        listeEnclos[iRang]->setNom(nom);
    }
}

void Parc::ajouterAnimalDansEnclos(Animal * animalAPlacer, Enclos * enclosDAccueil) {
    if(enclosDAccueil->getOccupation() == enclosDAccueil->getCapacite()) {
        cout << "Erreur, enclos plein." << endl;
    }
    else {
        enclosDAccueil->ajoutAnimal(animalAPlacer);

        // Maintenant on regarde si l'animal se noit ou s'envole
        if(animalAPlacer->getSaitVoler() && (enclosDAccueil->getType() == ENCLOS || enclosDAccueil->getType() == BASSIN) ) {
            supprimerAnimalSansControle(animalAPlacer->getID());
        }
        else if (!animalAPlacer->getSaitNager() && enclosDAccueil->getType() == BASSIN) {
            supprimerAnimalSansControle(animalAPlacer->getID());
        }

        // gestion des conséquences de cet ajout (notre animal se fait manger par ses prédateurs ou mange ses proies)
        animauxMangesOuTuesDansEnclos(animalAPlacer->getEspece(), enclosDAccueil);
    }
}

void Parc::enleverAnimalEnclos(Animal * animalAEnlever, Enclos * enclos) {
    enclos->supprimerAnimal(animalAEnlever);
    // gestion des conséquences de ce retrait
    animauxMangesOuTuesDansEnclos(animalAEnlever->getEspece(), enclos);
}

int Parc::relationsProiesPredateurs(const int iCodePredateur, const int iNbPredateurs, const int iCodeProie, const int iNbProies) {
    // Retourne 1(les prédateurs mangent les proies) 2(rien ne se passe) ou 3(les proies se défendent et tuent les prédateurs)
    // On vérifie que le prédateur et la proie donnés sont liés
    int resultatRand;
    bool trouve = false;
    int i=0;
    // on récupère le nombre de proies le prédateur a
    int iNbProiesAnimal = tabProies[iCodePredateur].getNbElem();
    while(i<iNbProiesAnimal && !trouve) {
        // on regarde maintenant si une de ses proies correspond
        if(tabProies[iCodePredateur][i].iCodeProie == iCodeProie) {
            trouve = true;
        } else {
            i++;
        }
    }
    // Si ce n'est pas le cas ou si une espèce est en quantité nulle, on renvoie 2 pour dire qu'il ne se passe rien
    if(!trouve || iNbPredateurs==0 || iNbProies==0) {
        return 2;
    }
    else {
        // On prend un nombre aléatoire dans [0; 100[

        resultatRand = rand()%(100);

        // Cas où le prédateur mange la proie
        if(iNbProies < tabProies[iCodePredateur][i].iSeuil1 * iNbPredateurs) {
            // on veut 75% de chances de le manger
            // 2 il ne se passe rien, 1 il le mange
            return (resultatRand > 75) ? 2 : 1;
        }

        // Cas où tout est possible
        else if(iNbProies < tabProies[iCodePredateur][i].iSeuil2 * iNbPredateurs) {
            // 50% chances de sympatiser, 25% pour les deux autres cas
            if(resultatRand < 25) {
                return 1;
            }
            else if(resultatRand <= 75) {
                return 2;
            }
            else {
                return 3;
            }
        }

        // Cas où les proies se défendent
        else {
            // on veut 75% de chances de le tuer
            return (resultatRand > 75) ? 2 : 3;
        }
    }
}



int Parc::consequenceDeplacementAnimal(Animal const * a1, const int IDEnclos) const {
    /* 	Invalide (enclos inexistant) : -1
    	Tout est ok : 0
    	Si l'enclos est plein : 1
    	Animal se noit <=> ! saitNager && listeEnclos[iRangEnclos].getType() == BASSIN      : 2
    	Animal s'envole <=> saitVoler && (listeEnclos[iRangEnclos].getType() == ENCLOS || listeEnclos[iRangEnclos].getType() == BASSIN) (car le bassin n'est pas fermé) : 3
    	Animal possède des prédateurs dans l'enclos : 4
    	Animal possède des proies dans l'enclos : 5
    	Animal possède des proies et des prédateurs dans l'enclos : 6
    */
    int iRangEnclos = rechercherEnclos(IDEnclos);
    bool YaTilDesProies = false;
    bool YaTilDesPredateurs =false;
    int nbProiesDeAnimal = tabProies[a1->getEspece()].getNbElem();
    int iEspeceA = a1->getEspece();
    int nbElemTabProies = tabProies.getNbElem();
    int nbElem;

    if (iRangEnclos == -1) {
        return -1;
    }
    else if (listeEnclos[iRangEnclos]->getOccupation() == listeEnclos[iRangEnclos]->getCapacite() ) {
        return 1;
    }
    else if (a1->getSaitVoler() && (listeEnclos[iRangEnclos]->getType() == ENCLOS || listeEnclos[iRangEnclos]->getType() == BASSIN) ) {
        return 3;
    }
    else if (!a1->getSaitNager() && listeEnclos[iRangEnclos]->getType() == BASSIN) {
        return 2;
    }
    else {
        // Pour chacune des espèces dans l'enclos, regarder si c'est un prédateur de a1 et s'il est présent
        // je pour quels espèces a1 est une proie et je vérifie si l'animal est présent, si oui bool = true sinon on continue jusqu'a bool = true ou fin du tableau
        // Pour chaque espèce
        for (int j = 0; j < nbElemTabProies; j++) {
            nbElem = tabProies[j].getNbElem();
            // Pour chaque proie de cette espèce
            for(int k = 0; k < nbElem; k++) {
                // Si c'est un prédateur de a1
                if (tabProies[j][k].iCodeProie == a1->getEspece()) {
                    // On regarde maintenant si le prédateur est présent dans l'enclos
                    if (listeEnclos[iRangEnclos]->getNombreAnimaux(tabProies[j][k].iCodeProie) != 0)
                        YaTilDesPredateurs = true;
                }
            }
        }

        // maintenant je cherche s'il y a des proies de notre animal
        for (int j = 0; j  < nbProiesDeAnimal; j++) {
            // pour chaque proies, on regarde si elle est présente dans le tableau
            if (listeEnclos[iRangEnclos]->getNombreAnimaux(tabProies[iEspeceA][j].iCodeProie) != 0)
                YaTilDesProies = true;
        }
        // maintenant on sait si y'a des proies et si y'a des prédateurs
        if (YaTilDesPredateurs && YaTilDesProies)
            return 6;
        else if (YaTilDesPredateurs)
            return 4;
        else if (YaTilDesProies)
            return 5;
        else
            return 0;
    }
}

int Parc::consequenceDansEnclosDepartDeplacementAnimal(Animal const * a1, const int IDEnclos) const {
    /* 	Invalide (enclos inexistant) : -1
    	Tout est ok : 0
    	Animal possède proies et/ou prédateurs : 1
    */
    int iRangEnclos = rechercherEnclos(IDEnclos);
    int nbProiesDeAnimal = tabProies[a1->getEspece()].getNbElem();
    int iEspeceA = a1->getEspece();
    int nbElemTabProies = tabProies.getNbElem();
    int nbElem;

   // Si enclos non trouvé
    if (iRangEnclos == -1) {
        return -1;
    }
    // Si l'animal est le dernier de son espèce, pas de souci
    else if (listeEnclos[iRangEnclos]->getNombreAnimaux(a1->getEspece()) <= 1) {
      return 0;
    }
    // Sinon, on cherche s'il a au moins un prédateur ou au moins une proie
    else {
        // Pour chacune des espèces dans l'enclos, regarder si c'est un prédateur de a1 et s'il est présent
        // je pour quels espèces a1 est une proie et je vérifie si l'animal est présent, si oui returne 1 sinon on continue
        // Pour chaque espèce
        for (int j = 0; j < nbElemTabProies; j++) {
            nbElem = tabProies[j].getNbElem();
            // Pour chaque proie de cette espèce
            for(int k = 0; k < nbElem; k++) {
                // Si c'est un prédateur de a1
                if (tabProies[j][k].iCodeProie == a1->getEspece()) {
                    // On regarde maintenant si le prédateur est présent dans l'enclos
                    if (listeEnclos[iRangEnclos]->getNombreAnimaux(tabProies[j][k].iCodeProie) != 0)
                        return 1;
                }
            }
        }

        // maintenant je cherche s'il y a des proies de notre animal
        for (int j = 0; j  < nbProiesDeAnimal; j++) {
            // pour chaque proies, on regarde si elle est présente dans le tableau
            if (listeEnclos[iRangEnclos]->getNombreAnimaux(tabProies[iEspeceA][j].iCodeProie) != 0)
                return 1;
        }
    }

    return 0;
}

// Ici on vérifie que les trois éléments existent, que l'animal est bien dans l'enclos de départ et qu'il y a de la
// place dans celui d'arrivée
void Parc::deplacerAnimal(const int IDEnclosDepart, const int IDAnimal, const int IDEnclosArrivee) {
    int iRangEnclosDepart = rechercherEnclos(IDEnclosDepart);
    int iRangAnimal = rechercherAnimal(IDAnimal);
    int iRangEnclosArrivee = rechercherEnclos(IDEnclosArrivee);
    Enclos * ptrEnclosD = NULL;
    Animal * ptrAnimal = NULL;
    Enclos * ptrEnclosA = NULL;

    if(iRangEnclosDepart == -1
       || iRangAnimal == -1
       || iRangEnclosArrivee == -1
    ) {
       cout << "Erreur, enclos ou animal non trouvés." << endl;
    }
    else if(rechercheEnclosAnimal(IDAnimal) != iRangEnclosDepart) {
       cout << "Erreur, l'animal à déplacer n'est pas dans l'enclos indiqué." << endl;
    }
    else {
        ptrEnclosD = listeEnclos[iRangEnclosDepart];
        ptrAnimal = listeAnimaux[iRangAnimal];
        ptrEnclosA = listeEnclos[iRangEnclosArrivee];

        if(ptrEnclosA->getOccupation() == ptrEnclosA->getCapacite()) {
            cout << "Erreur, l'enclos de destination est plein." << endl;
        }
        else {
            enleverAnimalEnclos(ptrAnimal, ptrEnclosD);
            ajouterAnimalDansEnclos(ptrAnimal,ptrEnclosA);

        }
    }
}

void Parc::animauxMangesOuTuesDansEnclos(const int iCodeEspeceModifiee, Enclos * ptrEnclos)  {
    int iActionAFaire;
    int iCodeProie;
	int k=0;
    // Pour chaque espèce
    for(int i=0; i<NB_ESPECES; i++) {
        // Parcours son tableau de proies
        for(int j=0; j<tabProies[i].getNbElem(); j++) {

           iCodeProie = tabProies[i][j].iCodeProie;
           // Si l'espèce de l'animal ajouté/enlevé est une proie ou un prédateur
           if(iCodeEspeceModifiee==i || iCodeEspeceModifiee==iCodeProie) {
                // On demande quelles relations ont la proie et le prédateur considérés
                iActionAFaire = relationsProiesPredateurs(i, ptrEnclos->getNombreAnimaux(i), iCodeProie, ptrEnclos->getNombreAnimaux(iCodeProie));
                // Tue les proies
                if(iActionAFaire == 1) {
                    while (k < ptrEnclos->getOccupation()) {
					//for(int k=0; k<ptrEnclos->getOccupation(); k++) {
                        if(ptrEnclos->getAnimal(k).getEspece() == iCodeProie) {
                            // Enlève les animaux de l'enclos directement, sans passer par enleverAnimalEnclos
                            // On est obligé car enleverAnimalEnclos appelle cette fonction pour gérer les animaux
                            // à tuer, donc on tournerait un peu en rond
                            //ptrEnclos->supprimerAnimal(ptrEnclos->getPtrAnimal(k));
                            supprimerAnimalSansControle(ptrEnclos->getAnimal(k).getID());
							// on incrémente que si on ne supprime pas, car on décale tous les animaux non supprimés vers la gauche
                        }
                        else k++;
                    }
                }
                // Tue les prédateurs
                else if(iActionAFaire == 3) {
                    while (k < ptrEnclos->getOccupation()) {
                        if(ptrEnclos->getAnimal(k).getEspece() == i) {
                           supprimerAnimalSansControle(ptrEnclos->getAnimal(k).getID());
                        }
                        else {
                            k++;
                        }
                    }
                }
            }
        }
    }
}

/*****************************************/
/********		JB						*/
/****************************************/

/******************************************************/
/******************************************************/
/**                                                  **/
/**    FONCTIONS DE CRÉATION D'ANIMAUX               **/
/**                                                  **/
/******************************************************/
/******************************************************/

void Parc::creerAnimal(Girafe const * a, const int IDEnclosAccueil) {
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    if(iRangEnclos != -1){
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
    else {
        cout << "Erreur, enclos non trouvé." << endl;
    }
}
void Parc::creerAnimal(Tigre const * a, const int IDEnclosAccueil) {
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    if(iRangEnclos != -1){
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
    else {
        cout << "Erreur, enclos non trouvé." << endl;
    }
}

void Parc::creerAnimal(Basque const * a, const int IDEnclosAccueil) {
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    if(iRangEnclos != -1){
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
    else {
        cout << "Erreur, enclos non trouvé." << endl;
    }
}

void Parc::creerAnimal(Marmotte const * a, const int IDEnclosAccueil) {
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    if(iRangEnclos != -1){
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
    else {
        cout << "Erreur, enclos non trouvé." << endl;
    }
}

void Parc::creerAnimal(Elephant const * a, const int IDEnclosAccueil) {
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    if(iRangEnclos != -1){
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
    else {
        cout << "Erreur, enclos non trouvé." << endl;
    }
}

void Parc::creerAnimal(Aigle const * a, const int IDEnclosAccueil) {
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    if(iRangEnclos != -1){
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
    else {
        cout << "Erreur, enclos non trouvé." << endl;
    }
}

void Parc::creerAnimal(Tortue const * a, const int IDEnclosAccueil) {
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    if(iRangEnclos != -1){
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
    else {
        cout << "Erreur, enclos non trouvé." << endl;
    }
}

void Parc::creerAnimal(Loutre const * a, const int IDEnclosAccueil) {
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    if(iRangEnclos != -1){
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
    else {
        cout << "Erreur, enclos non trouvé." << endl;
    }
}

void Parc::creerAnimal(Crocodile const * a, const int IDEnclosAccueil) {
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    if(iRangEnclos != -1){
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
    else {
        cout << "Erreur, enclos non trouvé." << endl;
    }
}

void Parc::creerAnimal(Lapin const * a, const int IDEnclosAccueil) {
    int iRangEnclos = rechercherEnclos(IDEnclosAccueil);
    if(iRangEnclos != -1){
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
    else {
        cout << "Erreur, enclos non trouvé." << endl;
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

        // Supprime l'animal de son enclos et gère les conséquences de ce retrait
        enleverAnimalEnclos(ptrAnimal, listeEnclos[iRangEnclos]);

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
        iNbAnimaux--;
        delete ptrAnimal;
    }
}

// Méthode privée pour supprimer un animal sans gérer les conséquences sur les autres animaux
// Utile pour supprimer tous les animaux d'un enclos ou tous les animaux d'un enclos et de la même espèce
void Parc::supprimerAnimalSansControle(const int ID) {

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
        iNbAnimaux--;
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
    // Parcours chaque enclos
    for(int i=0; i<iNbEnclos; i++) {
        // Parcours chaque animal de cet enclos
        for(int j=0; j<listeEnclos[i]->getOccupation(); j++) {
            // Si on a trouvé l'animal cherché
            if(listeEnclos[i]->getAnimal(j).getID() == ID) {
                return i;
            }
        }
    }
    return -1;
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
    int iRangMin = 0;
    for(int i=0; i<iNbAnimaux-1; i++) {
        iRangMin = i;
        for(int j=i+1; j<iNbAnimaux; j++) {
            if(listeAnimaux[j]->getNom() < listeAnimaux[iRangMin]->getNom()) {
                iRangMin = j;
            }
        }
        listeAnimaux.intervertir(listeAnimaux[iRangMin], listeAnimaux[i]);
    }
}

// tri par sélection du minimum -> À VÉRIFIER CAR DOUBLE CRITÈRE DE TRI !
void Parc::triAnimauxEspece() {
    int iRangMin = 0;
    int iCodeEspeceMin = 0;

    for(int i=0; i<iNbAnimaux-1; i++) {
        iRangMin = i;
        iCodeEspeceMin = listeAnimaux[i]->getEspece();

        // recherche codeEspeceMin
        for(int j=i; j<iNbAnimaux; j++) {
            if(listeAnimaux[j]->getEspece() < iCodeEspeceMin) {
                iCodeEspeceMin = listeAnimaux[j]->getEspece();
                iRangMin = j;
            }
        }

        for(int j=i+1; j<iNbAnimaux; j++) {
            if( listeAnimaux[j]->getEspece() == iCodeEspeceMin
                && listeAnimaux[j]->getNom() < listeAnimaux[iRangMin]->getNom()
              ) {
                iRangMin = j;
            }
        }
         listeAnimaux.intervertir(listeAnimaux[i], listeAnimaux[iRangMin]);
    }
}


// tri dans un enclos impossible pour le moment, rajouter la méthode pour intervertir dans Enclos
// tri par sélection du minimum
void Parc::triAnimauxAlpha(const int IDEnclos) {
    int iRangEnclos = rechercherEnclos(IDEnclos);
    if(iRangEnclos == -1) {
        cout << "Erreur, enclos introuvable." << endl;
    }
    else {
        // On se garde ptrEnclos pour simplifier le code
        Enclos * ptrEnclos = listeEnclos[iRangEnclos];
        // On procède alors a l'échange des pointeurs
        int iRangMin = 0;
        int iNbAnimaux = ptrEnclos->getOccupation();

        for(int i=0; i<iNbAnimaux-1; i++) {
            iRangMin = i;
            for(int j=i+1; j<iNbAnimaux; j++) {
                if(ptrEnclos->getAnimal(j).getNom() < ptrEnclos->getAnimal(iRangMin).getNom()) {
                    iRangMin = j;
                }
            }
            // Ici, on échange les pointeurs et plus les contenus
            ptrEnclos->intervertir(ptrEnclos->getPtrAnimal(iRangMin),ptrEnclos->getPtrAnimal(i));
        }
    }
}


// tri par sélection du minimum -> À VÉRIFIER CAR DOUBLE CRITÈRE DE TRI !
// val : me parait bien pour ma part
void Parc::triAnimauxEspece(const int IDEnclos) {
    int iRangEnclos = rechercherEnclos(IDEnclos);
    if(iRangEnclos == -1) {
        cout << "Erreur, enclos introuvable." << endl;
    }
    else {
        Enclos * ptrEnclos = listeEnclos[iRangEnclos];
        int iRangMin = 0;
        int iNbAnimaux = ptrEnclos->getOccupation();
        int iCodeEspeceMin = 0;

        for(int i=0; i<iNbAnimaux-1; i++) {
            iRangMin = i;
            iCodeEspeceMin = ptrEnclos->getAnimal(i).getEspece();
            // recherche codeEspeceMin
            for(int j=i; j<iNbAnimaux; j++) {
                if(ptrEnclos->getAnimal(j).getEspece() < iCodeEspeceMin) {
                    iCodeEspeceMin = ptrEnclos->getAnimal(j).getEspece();
                    iRangMin = j;
                }
            }

            for(int j=i+1; j<iNbAnimaux; j++) {
                if( ptrEnclos->getAnimal(j).getEspece() == iCodeEspeceMin
                    && ptrEnclos->getAnimal(j).getNom() < ptrEnclos->getAnimal(iRangMin).getNom()
                  ) {
                    iRangMin = j;
                }
            }
             ptrEnclos->intervertir(ptrEnclos->getPtrAnimal(i), ptrEnclos->getPtrAnimal(iRangMin));
        }
    }
}

// tri par sélection du minimum
void Parc::triEnclosAlpha() {
    int iRangMin = 0;
    for(int i=0; i<iNbEnclos-1; i++) {
        iRangMin = i;
        for(int j=i+1; j<iNbEnclos; j++) {
            if(listeEnclos[j]->getNom() < listeEnclos[iRangMin]->getNom()) {
                iRangMin = j;
            }
        }
        listeEnclos.intervertir(listeEnclos[iRangMin], listeEnclos[i]);
    }
}

// tri par sélection du minimum
void Parc::triEnclosOccupation() {
    int iRangMin = 0;
    for(int i=0; i<iNbEnclos-1; i++) {
        iRangMin = i;
        for(int j=i+1; j<iNbEnclos; j++) {
            if(listeEnclos[j]->getOccupation() < listeEnclos[iRangMin]->getOccupation()) {
                iRangMin = j;
            }
        }
        listeEnclos.intervertir(listeEnclos[iRangMin], listeEnclos[i]);
    }
}

// tri par sélection du minimum
void Parc::triEnclosCapacite() {
    int iRangMin = 0;
    for(int i=0; i<iNbEnclos-1; i++) {
        iRangMin = i;
        for(int j=i+1; j<iNbEnclos; j++) {
            if(listeEnclos[j]->getCapacite() < listeEnclos[iRangMin]->getCapacite()) {
                iRangMin = j;
            }
        }
        listeEnclos.intervertir(listeEnclos[iRangMin], listeEnclos[i]);
    }
}

// tri par sélection du minimum
void Parc::triEnclosTauxOccupation() {
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
    }
}

ostream & operator<<(ostream & flot, const Parc & p) {
    flot << "***  Informations sur le parc  ***" << endl;
    flot << "Nombre d'animaux : " << p.getNbAnimaux()<< endl;
    flot << "Nombre d'enclos : " << p.getNbEnclos()<< endl;
    return flot;
}

Tigre const * Parc::getTigre(const int irang) const{
	if (irang >= 0 && irang < listeTigre.getNbElem())
		return listeTigre[irang];
	Tigre * t;
	t = new Tigre();
	return t;
}

Basque const * Parc::getBasque(const int irang) const{
	if (irang >= 0 && irang < listeBasque.getNbElem())
		return listeBasque[irang];
	Basque * t;
	t = new Basque();
	return t;
}


Marmotte const * Parc::getMarmotte(const int irang) const{
	if (irang >= 0 && irang < listeMarmotte.getNbElem())
		return listeMarmotte[irang];
	Marmotte * t;
	t = new Marmotte();
	return t;
}

Elephant const * Parc::getElephant(const int irang) const{
	if (irang >= 0 && irang < listeElephant.getNbElem())
		return listeElephant[irang];
	Elephant * t;
	t = new Elephant();
	return t;
}

Aigle const * Parc::getAigle(const int irang) const{
	if (irang >= 0 && irang < listeAigle.getNbElem())
		return listeAigle[irang];
	Aigle * t;
	t = new Aigle();
	return t;
}

Lapin const * Parc::getLapin(const int irang) const{
	if (irang >= 0 && irang < listeLapin.getNbElem())
		return listeLapin[irang];
	Lapin * t;
	t = new Lapin();
	return t;
}

Tortue const * Parc::getTortue(const int irang) const{
	if (irang >= 0 && irang < listeTortue.getNbElem())
		return listeTortue[irang];
	Tortue * t;
	t = new Tortue();
	return t;
}

Crocodile const * Parc::getCrocodile(const int irang) const{
	if (irang >= 0 && irang < listeCrocodile.getNbElem())
		return listeCrocodile[irang];
	Crocodile * t;
	t = new Crocodile();
	return t;
}

Girafe const * Parc::getGirafe(const int irang) const{
	if (irang >= 0 && irang < listeGirafe.getNbElem())
		return listeGirafe[irang];
	Girafe * t;
	t = new Girafe();
	return t;
}

Loutre const * Parc::getLoutre(const int irang) const{
	if (irang >= 0 && irang < listeLoutre.getNbElem())
		return listeLoutre[irang];
	Loutre * t;
	t = new Loutre();
	return t;
}


/*********************************/
/** Getters sur les != Animaux ***/
/*********************************/


