#ifndef PARC_H
#define PARC_H

#include "enclos.h"
#include "animal.h"
#include "set.h"

using namespace std;

typedef struct {
    int iCodeProie;
    int iSeuil1;
    int iSeuil2;
} Proie;

class Parc {
private:

    /*********************/
    /**   ATTRIBUTS     **/
    /*********************/
    int iNbAnimaux;
    int iNbEnclos;
    int iIDAnimaux;
    int iIDEnclos;
    Set <Enclos *> listeEnclos;

    // Chaque animal est ajouté dans listeAnimaux et dans sa liste.
    // Ça permet de conserver les infos de chaque animal et d'avoir quand même une seule liste pour les traitements généraux

    Set <Animal *> listeAnimaux;
    Set <Tigre *> listeTigre;
    Set <Basque *> listeBasque;
    Set <Marmotte *> listeMarmotte;
    Set <Elephant *> listeElephant;
    Set <Aigle *> listeAigle;
    Set <Tortue *> listeTortue;
    Set <Crocodile *> listeCrocodile;
    Set <Girafe *> listeGirafe;
    Set <Loutre *> listeLoutre;
    Set <Lapin *> listeLapin;

    Set <Set <Proie> > tabProies;

    /************************/
    /**  MÉTHODES PRIVÉES  **/
    /************************/
    // Ici, on utilise directement les pointeurs, comme ces fonctions seront appelées par la classe, on aura cette information
    void ajouterAnimalDansEnclos(Animal * animalAPlacer, Enclos * enclosDAccueil);
    void enleverAnimalEnclos(Animal * animalAEnlever, Enclos * enclos);
    // Donne la relations qu'auront les proies et prédateurs indiqués
    int relationsProiesPredateurs(const int iCodePredateur, const int iNbPredateurs, const int iCodeProie, const int iNbProies);
    // Parcours les animaux d'un enclos et tue les prédateurs/proies de l'espèce indiquée ou alors les animaux de l'espèce
    // indiquée selon ce que dit relationsProiesPredateurs
    void animauxMangesOuTuesDansEnclos(const int iCodeEspeceModifiee, Enclos * ptrEnclos);
    // Initialise le tableau de proie
    void initTabProies();

    // Retourne le rang de l'animal recherché dans la liste de son espèce
    int rechercherGirafe(const int ID) const;
    int rechercherTigre(const int ID) const;
    int rechercherBasque(const int ID) const;
    int rechercherMarmotte(const int ID) const;
    int rechercherAigle(const int ID) const;
    int rechercherElephant(const int ID) const;
    int rechercherTortue(const int ID) const;
    int rechercherLoutre(const int ID) const;
    int rechercherCrocodile(const int ID) const;
    int rechercherLapin(const int ID) const;

public:

    /**************************/
    /**  MÉTHODES PUBLIQUES  **/
    /**************************/
    Parc();
    Parc(const Parc &);
    ~Parc();

    int getNbAnimaux() const;
    int getNbEnclos() const;
    int getIDAnimaux() const;
    int getIDEnclos() const;

    Enclos getEnclos(int i) const;
    // Retourne un pointeur sur un animal constant, ainsi on ne peut pas le modifier
    Animal const * getAnimal(int i) const;

    // On crée un enclos en se basant sur celui donné en paramètres. On crée un enclos du même
    // type et avec les mêmes informations, en pensant à mettre le bon Identifiant et pas celui
    // de l'enclos passé en paramètres. L'enclos créé sera vide peut-importe l'informations contenue
    // dans l'enclos passé en paramètres
    void creerEnclos(const string & nom, const int type, const int capacite);

    // Supprime tous les animaux contenus dans l'enclos indiqué, puis supprime l'enclos
    void supprimerEnclos(const int ID);

    // Modifie le nom de l'enclos dont l'ID est indiqué, c'est la seule donnée modifiable.
    void mofidierEnclos(const int IDEnclosAModifier, const string nom);

    // Retourne le rang dans la liste de l'enclos dont l'ID est donné. Gestion erreur si absent
    int rechercherEnclos(const int ID) const;

    // On crée un animal en se basant sur l'animal donné en paramètres. On crée un animal de la même
    // espèce et avec les mêmes informations, en pensant à mettre le bon Identifiant et pas celui
    // de l'animal passé en paramètres. On ajoute ensuite l'animal dans l'enclos dont l'ID est donné
    // (si cela est possible). Si l'enclos est plein, on ne fait rien, on ne crée même pas l'animal et
    // on fait de la gestion d'erreur.
    void creerAnimal(Girafe const * a, const int IDEnclosAccueil);
    void creerAnimal(Tigre const * a, const int IDEnclosAccueil);
    void creerAnimal(Marmotte const * a, const int IDEnclosAccueil);
    void creerAnimal(Basque const * a, const int IDEnclosAccueil);
    void creerAnimal(Elephant const * a, const int IDEnclosAccueil);
    void creerAnimal(Aigle const * a, const int IDEnclosAccueil);
    void creerAnimal(Tortue const * a, const int IDEnclosAccueil);
    void creerAnimal(Loutre const * a, const int IDEnclosAccueil);
    void creerAnimal(Lapin const * a, const int IDEnclosAccueil);
    void creerAnimal(Crocodile const * a, const int IDEnclosAccueil);


    // Supprime l'animal indiqué, s'il existe. On commence par le virer de son enclos (après recherche)
    // Puis on dégage l'animal du jardin d'Eden)
    void supprimerAnimal(const int ID);

    // Modifie l'animal dont l'ID est indiqué en recopiant les informations de l'animal donné en paramètres
    // On recherche l'animal à modifier, si on le trouve on modifie, sinon gestion erreurs. On vérifie que
    // l'espèce est bien la bonne. On autorise à modifier : nom et infos propres à chaque espèce.
    void modifierAnimal(const int IDAnimalAModifier, Girafe const * nouvelAnimal);
    void modifierAnimal(const int IDAnimalAModifier, Tigre const * nouvelAnimal);
    void modifierAnimal(const int IDAnimalAModifier, Basque const * nouvelAnimal);
    void modifierAnimal(const int IDAnimalAModifier, Marmotte const * nouvelAnimal);
    void modifierAnimal(const int IDAnimalAModifier, Aigle const * nouvelAnimal);
    void modifierAnimal(const int IDAnimalAModifier, Elephant const * nouvelAnimal);
    void modifierAnimal(const int IDAnimalAModifier, Tortue const * nouvelAnimal);
    void modifierAnimal(const int IDAnimalAModifier, Loutre const * nouvelAnimal);
    void modifierAnimal(const int IDAnimalAModifier, Crocodile const * nouvelAnimal);
    void modifierAnimal(const int IDAnimalAModifier, Lapin const * nouvelAnimal);

    // Retourne le rang dans la liste de l'animal dont l'ID est donné. Gestion erreur si absent
    int rechercherAnimal(const int ID) const;

    // Retourne le rang de l'enclos dans lequel est l'animal
    int rechercheEnclosAnimal(const int ID);

    // Déplace un animal d'un enclos A vers un enclos B. Ici, on vérifie uniquement si l'enclos B a de la place pour
    // recevoir un animal supplémentaire. On déplace l'animal, on regarde s'il se noit, s'échappe et s'il faut, on
    // regarde ses relations avec les autres espèces pour savoir qui mange qui, et on applique les conséquences de l'ajout.
    // On enlève ensuite l'animal de l'enclos de départ et on regarde aussi les conséquences du déplacement sur l'enclos
    // de départ, là aussi pour savoir qui mange qui.
    void deplacerAnimal(const int IDEnclosDepart, const int IDAnimal, const int IDEnclosArrivee);

    // On reçoit en paramètres le code espèce de l’animal et l’ID de l’enclos où on veut le mettre.
    // On effectue ensuite les tests appropriés et on retourne une valeur pour chacun des cas suivants :
    // - Si l’enclos ou le type ne sont pas valide (enclos inexistant ou type faux) : -1
    // - Si tout est OK : 0
    // - Si l’enclos est plein : 1
    // - Si l’animal se noierait : 2
    // - Si l’animal s’envolerait : 3
    // - Si l’animal possède des prédateurs dans l’enlcos : 4
    // - Si l’animal possède des proies dans l’enclos : 5
    // - Si l’animal poss`de des proies et des pr ́dateurs dans l’enclos : 6
    int consequenceDeplacementAnimal(Animal const *, const int IDEnclos) const;


    // Les fonctions suivantes trient la liste d'animaux/d'enclos selon le critère indiqué
    void triAnimauxAlpha();
    void triAnimauxEspece();
    // Trient la liste des animaux de l'enclos indiqué
    void triAnimauxAlpha(const int IDEnclos);
    void triAnimauxEspece(const int IDEnclos);

    void triEnclosAlpha();
    void triEnclosOccupation();
    void triEnclosCapacite();
    void triEnclosTauxOccupation();

    friend ostream & operator<<(ostream &, const Parc &);
};
#endif
