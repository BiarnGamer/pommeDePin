#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "../../entetes/parc.h"

using namespace std;

int main() {


    /** POUR DE L'ALÉATOIRE **/
    srand(time(NULL));




    /* *************************** */
    /* CRÉATION D'ANIMAUX          */
    /* *************************** */
    Tigre Helico(105, 654, "Diego", 1);
    Tigre Paul(241, 3321, "Pau'Pol", 2);

    Basque Xabi(125, 63, 1, 9999999, "Xabi", 3);
    Basque Ninicolas(12, 125, 14, 4419, "Nicolas Belloir", 4);

    Marmotte Miam(95, 6544, "Shakira", 5);
    Marmotte Tekitoi(245, 20, "Rihanna", 6);

    Elephant Pikachu(1021, 365, 102, "Valentin", 74);
    Elephant PHP(412, 35, 212, "C++", 744);

    Aigle Piafabec(95, 6544, "Poussin", 51);
    Aigle Roucarnage(652, 474, "Pousse pousse", 11);

    Lapin Valou(64, "Rouge", "Mimie Matti", 26);
    Lapin Tuture(205, "Blanche", "GTi", 205);

    Tortue Toto(35, 1201, "Arc-end-ciel", "Speedy Gonzalez", 7);
    Tortue Toutou(135, 11, "Invisible", "Faut pas pousser mes mail dans les ordis !", 17);

    Crocodile GrosseDent(3045, 124, "Mange de l'herbe", 8);
    Crocodile MoiJaiFaim(212345, 542, "Trotro Rigolo !", 84);

    Girafe PetiteB(120, 5412, "Gigi", 9);
    Girafe QuiVeutDesTalons(21, 6854, "Tour Eiffel", 19);

    Loutre loulou(12,14,"Moi j'ai des amis !", 110);
    Loutre PasDeSequelles(1,4,"Gnééé !", 150);


    /* *************************** */
    /* CRÉATION D'ENCLOS           */
    /* *************************** */
    Enclos parcSafari("Attrapez-les tous !", 1, 23 , 1);
    Enclos paysBasque("Zone 51", 3, 2 , 4);
    Enclos UPPA("Ça peut dégénérer en liste...", 2, 53 , 41);
    Enclos monkeyIsland("La planète des singes", 3, 5 , 11);
    Enclos azerty("Qwerty", 1, 2233 , 21);
    Enclos ocean("Hasta la victoria siempre", 3, 64 , 31);



    /* *************************** */
    /* CRÉATION D'UN PARC          */
    /* *************************** */
    cout << "*************************" << endl;
    cout << "* CRÉATION D'UN PARC    *" << endl;
    cout << "*************************" << endl;
    Parc Parc1;


    /* *************************** */
    /* AJOUT D'ENCLOS              */
    /* *************************** */
    cout << "*************************" << endl;
    cout << "* AJOUT D'ENCLOS        *" << endl;
    cout << "*************************" << endl;
    Parc1.creerEnclos("Attrapez-les tous !",1,23);
    Parc1.creerEnclos("Zone 51",3,2);
    Parc1.creerEnclos("Ça peut dégénérer en liste...",2,53);
    Parc1.creerEnclos("La planète des singes",3,5);
    Parc1.creerEnclos("Qwerty",1,21);
    Parc1.creerEnclos("Hasta la victoria siempre",3,64);

    cout << Parc1 << endl;

    for(int i=0; i<Parc1.getNbEnclos(); i++) {
        cout << Parc1.getEnclos(i) << endl;
    }


    /* *************************** */
    /* SUPPRESSION D'UN ENCLOS     */
    /* *************************** */
    cout << "***********************************" << endl;
    cout << "* SUPPRESSION D'UN ENCLOS (ID=4)  *" << endl;
    cout << "***********************************" << endl;
    Parc1.supprimerEnclos(4);
    for(int i=0; i<Parc1.getNbEnclos(); i++) {
        cout << Parc1.getEnclos(i) << endl;
    }


    /* *************************** */
    /* AJOUT D'ANIMAUX             */
    /* *************************** */
    cout << "********************" << endl;
    cout << "* AJOUT D'ANIMAUX  *" << endl;
    cout << "********************" << endl;


    /* ******************************* */
    /* Ajout d'un animal dans 1 enclos */
    /* ******************************* */
    cout << "***********************************" << endl;
    cout << "* Ajout d'un animal dans 1 enclos *" << endl;
    cout << "***********************************" << endl;
    Parc1.creerAnimal(&Helico, 1);
    cout << Parc1.getEnclos(0) << endl;
    cout << Parc1.getEnclos(0).getAnimal(0) << endl;


    /* ******************** */
    /* Surpeupler un enclos */
    /* ******************** */
    cout << "************************" << endl;
    cout << "* Surpeupler un enclos *" << endl;
    cout << "************************" << endl;
    Parc1.creerAnimal(&Pikachu, 2);
    Parc1.creerAnimal(&Tuture, 2);
    Parc1.creerAnimal(&Valou, 2);
    Parc1.creerAnimal(&PetiteB, 2);
    cout << Parc1.getEnclos(1) << endl;
    cout << Parc1.getEnclos(1).getAnimal(0) << endl;
    cout << Parc1.getEnclos(1).getAnimal(1) << endl;


    /* ******************************* */
    /* Ajout d'un animal qui s'échappe */
    /* ******************************* */
    cout << "***********************************" << endl;
    cout << "* Ajout d'un animal qui s'échappe *" << endl;
    cout << "***********************************" << endl;
    Parc1.creerAnimal(&Roucarnage, 1);
    Parc1.creerAnimal(&Roucarnage, 1);
    cout << Parc1.getEnclos(0) << endl;
    cout << Parc1.getEnclos(0).getAnimal(0) << endl;


    /* ******************************* */
    /* Test ajout proie dans enclos 1 */
    /* ******************************* */
    cout << "*****************************************************" << endl;
    cout << "* Ajout d'une proie qui se fait manger 75% des fois *" << endl;
    cout << "*****************************************************" << endl;
    Parc1.creerAnimal(&Valou, 1);
    cout << Parc1.getEnclos(0) << endl;
    cout << Parc1.getEnclos(0).getAnimal(0) << endl;
    if(Parc1.getEnclos(0).getOccupation() == 2) {cout << Parc1.getEnclos(0).getAnimal(1) << endl;}



    /* ************************************** */
    /* Tests nombreuses proies se font manger */
    /* ************************************** */
    cout << "*********************************************" << endl;
    cout << "* De nombreuses proies vont se faire manger *" << endl;
    cout << "*********************************************" << endl;
    Parc1.creerAnimal(&Xabi, 6);
    Parc1.creerAnimal(&Ninicolas, 6);
    Parc1.creerAnimal(&Ninicolas, 6);
    Parc1.creerAnimal(&Ninicolas, 6);
    Parc1.creerAnimal(&Xabi, 6);
    Parc1.creerAnimal(&Xabi, 6);
    Parc1.creerAnimal(&Ninicolas, 6);
    Parc1.creerAnimal(&Ninicolas, 6);
    Parc1.creerAnimal(&Xabi, 6);

    cout << "Enclos avant ajout prédateur : " << endl;
    cout << Parc1.getEnclos(4) << endl;


    Parc1.creerAnimal(&Paul, 6);

    cout << "Enclos après ajout prédateur : " << endl;
    cout << Parc1.getEnclos(4) << endl;
    cout << *Parc1.getEnclos(4).getPtrAnimal(0) << endl;


    /* ************************ */
    /* Test situation équilibre */
    /* ************************ */
    cout << "****************************************************" << endl;
    cout << "* Situation d'équilibre entre proies et prédateurs *" << endl;
    cout << "****************************************************" << endl;
    Parc1.creerAnimal(&QuiVeutDesTalons, 5);
    Parc1.creerAnimal(&QuiVeutDesTalons, 5);
    Parc1.creerAnimal(&PetiteB, 5);
    Parc1.creerAnimal(&PetiteB, 5);
    Parc1.creerAnimal(&QuiVeutDesTalons, 5);
    Parc1.creerAnimal(&PetiteB, 5);
    Parc1.creerAnimal(&QuiVeutDesTalons, 5);

    cout << "Enclos avant ajout prédateur : " << endl;
    cout << Parc1.getEnclos(3) << endl;


    Parc1.creerAnimal(&Paul, 5);

    cout << "Enclos après ajout prédateur : " << endl;
    cout << Parc1.getEnclos(3) << endl;
    cout << *Parc1.getEnclos(3).getPtrAnimal(0) << endl;


    /* ******************************* */
    /* Test proies doivent se défendre */
    /* ******************************* */
    cout << "************************************" << endl;
    cout << "* Tel est pris qui croyait prendre *" << endl;
    cout << "************************************" << endl;
    Parc1.creerAnimal(&PHP, 3);
    Parc1.creerAnimal(&PHP, 3);
    Parc1.creerAnimal(&Pikachu, 3);
    Parc1.creerAnimal(&Pikachu, 3);
    Parc1.creerAnimal(&Pikachu, 3);

    cout << "Enclos avant ajout prédateur : " << endl;
    cout << Parc1.getEnclos(2) << endl;

    Parc1.creerAnimal(&MoiJaiFaim, 3);

    cout << "Enclos après ajout prédateur : " << endl;
    cout << Parc1.getEnclos(2) << endl;
    cout << *Parc1.getEnclos(2).getPtrAnimal(0) << endl;



/** Prochains tets :
- déplacement sans conséquence
- déplacement avec envol/noyade animal
- déplacement avec conséquences au départ et à l'arrivée

- suppression animal sans conséquence
- suppression animal avec conséquence

- déplacement/suppression animaux/enclos inexistants

- modifier enclos

- supprimer enclos contenant des animaux

- fonction conséquences déplacement

- tri des listes d'animaux (donc listes suffisament variées) et affichage complet à chaque fois

- setters : modifier un animal de chaque espèce et l'afficher
**/


    //cout << *Parc1.getEnclos(2).getPtrAnimal(1) << endl;
   // Parc1.creerAnimal(&Helico, 5);
    //
    //cout << Parc1.getEnclos(0).getAnimal(1) << endl;
   // int a;
   // cin >> a;
    return 0;
}
