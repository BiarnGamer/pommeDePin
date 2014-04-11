#include "../entetes/parc.h"
#include <cstdlib>
#include <ctime>

using namespace std;

bool operator==(const Proie p1, const Proie p2) {
   if(p1.iCodeProie == p2.iCodeProie) {
      return true;
   }
   else {
      return false;
   }
}

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
}

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


void Parc::animauxMangesOuTuesDansEnclos(const int iCodeEspeceModifiee, Enclos * ptrEnclos)  {

}

void Parc::creerUnEnclos(const string & nom,const int & type, const int& capacite) {
    Enclos * enclosTmp = new Enclos(nom, type, capacite, iIDEnclos++);
    iNbEnclos++;
    listeEnclos.ajouter(enclosTmp);
}

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

void Parc::ajoutAnimalEnclos(Animal * ptrAnimal, Enclos * ptrEnclos) {
    ptrEnclos->ajoutAnimal(ptrAnimal);
}

void Parc::Barney() {

    iNbAnimaux++;
}

void Parc::choixEnclos(Animal * ptrAnimal) {
    // Note : proposer de créer un nouvel enclos ou de relâcher l'animal
    // Appelé après création animal ou avant déplacement pour choisir le nouvel enclos
    // Dans ce dernier cas, ne pas proposer l'enclos actuel !
}

void Parc::verifChoixEnclos(Animal * ptrAnimal, Enclos * ptrEnclos) {

}

void Parc::supprimerUnAnimal(Animal * ptrAnimal) {
    listeAnimaux.enlever(ptrAnimal);
    delete ptrAnimal;
    iNbAnimaux--;
}

void Parc::deplacerUnAnimal(Animal * ptrAnimal, Enclos * ptrEnclosDepart, Enclos * ptrEnclosArrivee) {
    ptrEnclosDepart->supprimerAnimal(ptrAnimal);
    ptrEnclosArrivee->ajoutAnimal(ptrAnimal);
}

int Parc::predateurMangeProie(const int iCodePredateur, const int iCodeProie, const int iNbPredateurs, const int iNbProies) const {
   // On vérifie que le prédateur et la proie donnés sont liés
   int resultatRand;
   bool trouve = false;
   int i=0;
   int iNbProiesAnimal = tabProies[iCodePredateur].getNbElem();
   while(i<iNbProiesAnimal && !trouve){
      if(tabProies[iCodePredateur][i].iCodeProie == iCodeProie) {
         trouve = true;
      }
      else {
         i++;
      }
   }

   // Si ce n'est pas le cas, on renvoie 2 pour dire qu'il ne se passe rien
   if(!trouve) {
      return 2;
   }
   else {
      // On prend un nombre aléatoire dans [0; 100[
      srand(time(NULL));
      resultatRand = rand()%(100);
      // Cas où le prédateur mange la proie
      if(iNbProies < tabProies[iCodePredateur][i].iSeuil1) {
         // on veut 75% de chances de le manger
         return (resultatRand > 75) ? 2 : 1;
      }
      // Cas où tout est possible
      else if(iNbProies < tabProies[iCodePredateur][i].iSeuil1) {
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
      // Enregistrement et éinitialisation de proiesEspece
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

ostream & operator<<(ostream &, const Parc &);
