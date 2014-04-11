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
   int iActionAFaire;
   int iCodeProie;
   for(int i=0; i<NB_ESPECES; i++) {
      for(int j=0; j<tabProies[i].getNbElem(); j++) {

         iCodeProie = tabProies[i][j].iCodeProie;
         if(iCodeEspeceModifiee==i || iCodeEspeceModifiee==iCodeProie) {
            iActionAFaire = predateurMangeProie(i, iCodeProie, ptrEnclos->getNombreAnimaux(i), ptrEnclos->getNombreAnimaux(iCodeProie));

            if(iActionAFaire == 1){
               cout << "Les prédateurs mangent les proies" << endl;
               for(int k=0; k<ptrEnclos->getOccupation(); k++) {
                  if(ptrEnclos->getAnimal(k).getEspece() == iCodeProie) {
                     ptrEnclos->supprimerAnimal(ptrEnclos->getPtrAnimal(k));
                  }
               }
            }
            else if(iActionAFaire == 2){
               cout << "Prédateurs et proies s'entendent" << endl;
            }
            else {
               cout << "Les proies se défendent et tuent leurs prédateurs" << endl;
               for(int k=0; k<ptrEnclos->getOccupation(); k++) {
                  if(ptrEnclos->getAnimal(k).getEspece() == i) {
                     ptrEnclos->supprimerAnimal(ptrEnclos->getPtrAnimal(k));
                  }
               }
            }
         }
      }
   }
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

void Parc::choixEnclos(Animal * ptrAnimal) {
    // Note : proposer de créer un nouvel enclos ou de relâcher l'animal
    // Appelé après création animal ou avant déplacement pour choisir le nouvel enclos
    // Dans ce dernier cas, ne pas proposer l'enclos actuel !
    cout << "Voici les enclos disponibles --- AFFICHER CEUX QUI NE SONT PAS PLEINS ET PROPOSER TRI" << endl;
    verifChoixEnclos(ptrAnimal, listeEnclos[0]);
    listeEnclos[0]->ajoutAnimal(ptrAnimal);
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

   // Si ce n'est pas le cas ou si une espèce est en quantité nulle, on renvoie 2 pour dire qu'il ne se passe rien
   if(!trouve || iNbPredateurs==0 || iNbProies==0){
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
