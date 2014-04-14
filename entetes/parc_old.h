#ifndef PARC_H
#define PARC_H

#include "set.h"
#include "animal.h"
#include "enclos.h"
#include <iostream>

using namespace std;

/*class Proie {
    public:
    int iCodeProie;
    int iSeuil1;
    int iSeuil2;
    Proie & operator=(const Proie & p);
    bool operator==(const Proie & p);
};*/

typedef struct{
    int iCodeProie;
    int iSeuil1;
    int iSeuil2;
}Proie;

class Parc {
    private:
    int iIDAnimaux;
    int iIDEnclos;
    int iNbAnimaux;
    int iNbEnclos;
    Set <Animal *> listeAnimaux;
    Set <Enclos *> listeEnclos;
    Set <Set <Proie> > tabProies;

    void animauxMangesOuTuesDansEnclos(const int iCodeEspeceModifiee, Enclos * ptrEnclos);

    void supprimerUnAnimal(Animal * ptrAnimal);
    // Supprimme l'animal indiqué. Cette fonction est appelée après la suppr peut  intervenir après la noyade, bouffée, mort d'un animal,
    // libération/évasion d'un animal. L'animal ne fait donc plus parti d'un enclos à ce moment là.
    // C'EST TRÈS IMPORTANT DE RESPECTER LE POINT CI-DESSUS, SINON CORE DUMP ASSURÉ

    void initTabProies();
    // Pour chaque espèce,
       // on crée une structure Proie pour chacune de ses proies
       // on ajoute toutes ces Proies dans un set
       // on ajoute ce set dans tabProie
       // on réinitialise les variables temporaires locales
    // Ainsi, dans le Set de plus haut niveau, on a un set de proies par animal. La position de ces set correspond au code de l'espèce concernée

    public:
    Parc();
    Parc(const Parc &);
    ~Parc();

    int getIDAnimaux() const;
    int getIDEnclos() const;
    int getNbAnimaux() const;
    int getNbEnclos() const;
    // On permet un accès aux enclos "en lecture seule"
    Enclos getEnclos(int) const;

    void creerUnEnclos(const string &,const int & type, const int& capacite);

    void supprimerUnEnclos(Enclos * ptrEnclos);
    // Attention : retirer l'enclos du Set ne libère pas la mémoire associée.
    // Il faut donc faire un delete de l'enclos avant d'appeler cette fonction.
    // Et il faut aussi déplacer ou relacher les animaux !

    void ajoutAnimalEnclos(Animal * ptrAnimal, Enclos * ptrEnclos);
    // Cette fonction place dans l'enclos indiqué l'animal indiqué. La création
    // de l'animal, la sélection de l'enclos et les vérifications de la faisabilité
    // de l'opération (prédateurs/proies, animal qui vole, qui sait nager, place
    // dispo dans l'enclos, etc.) sont faites en amont. On vérifiera tout de même
    // que l'occupation est < à la capacité.

    void Barney();
    // Demande les informations nécessaires à la création de l'animal. D'abord tout ce
    // qui est commun (classe Animal), puis ce qui est spécifique à la classe de l'animal
    // que l'on veut créer. On vérifie toutes les valeurs saisies (gestion erreurs).
    // Crée ensuite l'animal demandé, l'ajoute à la liste des animaux du parc et appelle
    // la fonction permettant le choix de l'enclos, puis la fonction ajoutAnimalEnclos.

    void choixEnclos(Animal * ptrAnimal);
    // Fonction qui demande à l'utilisateur dans quel enclos mettre l'animal créé. Elle
    // affiche pour cela la liste des enclos avec leur détail mais sans les animaux.
    // Elle demande soit le n°enclos dans la liste, soit l'ID de l'enclos, à voir...
    // Une fois choisi, elle appelle la fonction verifChoixEnclos (après recherche de
    // l'enclos correspondant au choix) et s'il n'y a pas d'alerte appelle
    // ajoutAnimalEnclos. Sinon on informe l'utilisateur des risques encourus et on lui
    // propose un autre choix. On propose toujours de créer un nouvel Enclos.

    void verifChoixEnclos(Animal * ptrAnimal, Enclos * ptrEnclos);
    // Retourne un code indiquant ce qu'il se passerait si on ajoute l'animal dans
    // l'enclos choisi (rien, noyade, évasion (s'envole), bouffe des animaux (présence
    // de proie suffit à cette alerte), se fait bouffer (présence de prédateurs). Ce
    // code sera utilisé par la fonction de choix d'enclos pour informer l'utilisateur
    // des conséquences de ses actes et éventuellement changer d'enclos.

    void deplacerUnAnimal(Animal * ptrAnimal, Enclos * ptrEnclosDepart, Enclos * ptrEnclosArrivee);
    // Supprime l'animal de l'enclos de départ et l'ajoute dans celui d'arrivée.

    int predateurMangeProie(const int iCodePredateur, const int iCodeProie, const int iNbPredateurs, const int iNbProies) const;
    // On recherche la proie dans le tableau Proies du prédateur et on dit si les
    // prédateurs mangent les proies, s'ils sympatisent ou se font tuer par les
    // proies (retourne 1, 2 ou 3 selon le cas)Appelé à chaque modification de la
    // liste d'animaux d'un enclos, pour chaque proie de chaque prédateur (voir comment
    // réduire le nombre de cas à tester en s'aidant des modification effectuées)

    /***********************************************/
    /***********************************************/
    /**                                           **/
    /** DIVERSES FONCTIONS DE RECHERCHE À AJOUTER **/
    /**                                           **/
    /***********************************************/
    /***********************************************/

    friend ostream & operator<<(ostream &, const Parc &);
};

#endif
