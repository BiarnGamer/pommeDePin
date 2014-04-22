#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "../entetes/animal.h"
//Déja inclut dans menu.h
//#include "../entetes/enclos.h"
#include "../entetes/set.h"
#include "../entetes/parc.h"
#include "../entetes/menu.h"
#include "../entetes/affichage.h"
// Pas besoin de utilisateur.h car il est inclut dans menu.h
//#include "../entetes/utilisateur.h"



using namespace std;



void chargerJeuTest(Parc & Parc1) {
    /* *************************** */
    /* CRÉATION D'ANIMAUX          */
    /* *************************** */
    Tigre Helico(105, 654, "Diego", 1);
    Tigre Paul(241, 3321, "Pau'Pol", 2);
    Tigre Paul2(541, 12, "Chicos", 2);

    Basque Xabi(125, 63, 1, 9999999, "Xabi", 3);
    Basque Ninicolas(12, 125, 14, 4419, "Nicolas Belloir", 4);
    Basque Solaberrieta(36, 4512, 124, 874, "Vincent Solaberrieta", 4);

    Marmotte Miam(95, 6544, "Shakira", 5);
    Marmotte Tekitoi(245, 20, "Rihanna", 6);
    Marmotte pipicaca(42, 874, "Roberta", 6);

    Elephant Pikachu(1021, 365, 102, "Valentin", 74);
    Elephant PHP(412, 35, 212, "C++", 744);
    Elephant Elephanto(874, 384, 784, "Chabal", 744);

    Aigle Piafabec(95, 6544, "Poussin", 51);
    Aigle Roucarnage(652, 474, "Pousse pousse", 11);
    Aigle Nirondelle(412, 24, "Envole Moi", 11);

    Lapin Valou(64, "Rouge", "Mimie Matti", 26);
    Lapin Tuture(205, "Blanche", "GTi", 205);
    Lapin Lapine(412, "Invisible", "Nom temporaire en attendant d'avoir des parents inspirés", 205);

    Tortue Toto(35, 1201, "Arc-end-ciel", "Speedy Gonzalez", 7);
    Tortue Toutou(135, 11, "La même que toi", "Faut pas pousser mes mail dans les ordis !", 17);
    Tortue TordreTue(42, 8751, "Transparent", "Wall-E", 17);

    Crocodile GrosseDent(3045, 124, "Mange de l'herbe", 8);
    Crocodile MoiJaiFaim(212345, 542, "Trotro Rigolo !", 84);
    Crocodile Grr(4577, 697, "RRRrrrr", 84);

    Girafe PetiteB(120, 5412, "Gigi", 9);
    Girafe QuiVeutDesTalons(21, 6854, "Tour Eiffel", 19);
    Girafe Torticoli(784, 124, "TeCognePas!", 19);

    Loutre loulou(12,14,"Moi j'ai des amis !", 110);
    Loutre PasDeSequelles(1,4,"Gnééé !", 150);
    Loutre Gneeee(174,474,"Gogo Gadgeto !", 150);

    /* *************************** */
    /* CRÉATION D'ENCLOS           */
    /* *************************** */
    Parc1.creerEnclos("Attrapez-les tous !",1,23);
    Parc1.creerEnclos("Zone 51",3,2);
    Parc1.creerEnclos("Ça peut dégénérer en liste...",2,53);
    Parc1.creerEnclos("La planète des singes",3,5);
    Parc1.creerEnclos("Qwerty",1,21);
    Parc1.creerEnclos("Hasta la victoria siempre",3,4);
    Parc1.creerEnclos("La pension",2,85);
    Parc1.creerEnclos("Pikachu Island",2,3);
    Parc1.creerEnclos("Enclos R2D2",1,42);
    Parc1.creerEnclos("Coin des développeurs",1,64);

    /* *************************** */
    /* AJOUT D'ANIMAUX             */
    /* *************************** */

    /* Répartition des animaux : aléatoire, en respectant ces quotas :
    3 et 5 : vides
    1:4
    2:3
    4:5
    6:2
    7:1
    8:6
    9:4
    10:5
    */

    Parc1.creerAnimal(&Helico,1);
    Parc1.creerAnimal(&Paul,1);
    Parc1.creerAnimal(&Paul2,4);

    Parc1.creerAnimal(&Xabi,6);
    Parc1.creerAnimal(&Ninicolas,2);
    Parc1.creerAnimal(&Solaberrieta,4);

    Parc1.creerAnimal(&Miam,7);
    Parc1.creerAnimal(&Tekitoi,9);
    Parc1.creerAnimal(&pipicaca,6);

    Parc1.creerAnimal(&Piafabec,10);
    Parc1.creerAnimal(&Roucarnage,8);
    Parc1.creerAnimal(&Nirondelle,10);

    Parc1.creerAnimal(&Valou,4);
    Parc1.creerAnimal(&Tuture,1);
    Parc1.creerAnimal(&Lapine,8);

    Parc1.creerAnimal(&Toto,8);
    Parc1.creerAnimal(&Toutou,10);
    Parc1.creerAnimal(&TordreTue,9);

    Parc1.creerAnimal(&GrosseDent,8);
    Parc1.creerAnimal(&MoiJaiFaim,1);
    Parc1.creerAnimal(&Grr,10);

    Parc1.creerAnimal(&PetiteB,10);
    Parc1.creerAnimal(&Torticoli,9);
    Parc1.creerAnimal(&QuiVeutDesTalons,8);

    Parc1.creerAnimal(&loulou,2);
    Parc1.creerAnimal(&PasDeSequelles,2);
    Parc1.creerAnimal(&Gneeee,9);

    Parc1.creerAnimal(&Pikachu,4);
    Parc1.creerAnimal(&PHP,4);
    Parc1.creerAnimal(&Elephanto,8);
}

int main() {
    /** POUR DE L'ALÉATOIRE **/
    srand(time(NULL));

    Parc Parc1;
    chargerJeuTest(Parc1);
    menuPrincipal(Parc1);

    return 0;
}
