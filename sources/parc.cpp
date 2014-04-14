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
   }
   else {
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
      tabProies.ajouter(proiesEspece);

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
      tabProies.ajouter(proiesEspece);
      proiesEspece = setVide;

      // Proies des Basque, Marmotte, Elephant, Aigle, Tortue, Loutre : acune
      tabProies.ajouter(proiesEspece);
      tabProies.ajouter(proiesEspece);
      tabProies.ajouter(proiesEspece);
      tabProies.ajouter(proiesEspece);
      tabProies.ajouter(proiesEspece);
      tabProies.ajouter(proiesEspece);

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
      tabProies.ajouter(proiesEspece);
      proiesEspece = setVide;

      // Proies du lapin : aucune
      tabProies.ajouter(proiesEspece);
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
Parc::Parc():iIDAnimaux(0), iIDEnclos(0), iNbAnimaux(0), iNbEnclos(0){initTabProies();}

Parc::Parc(const Parc & p) {
    iIDAnimaux = p.iIDAnimaux;
    iIDEnclos = p.iIDEnclos;
    iNbAnimaux = p.iNbAnimaux;
    iNbEnclos = p.iNbEnclos;
    listeAnimaux = p.listeAnimaux;
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
    // On vide le tableau de Proies pour libérer la mémoire
    while(tabProies.getNbElem() != 0) {
      tabProies.enlever(tabProies[0]);
    }
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
   if(0<=i && i<iNbEnclos) {
      return *listeEnclos[i];
   }
}

Animal const * Parc::getAnimal(int i) const {
   if(0<=i && i<iNbAnimaux) {
      return listeAnimaux[i];
   }
}

ostream & operator<<(ostream &, const Parc &);
