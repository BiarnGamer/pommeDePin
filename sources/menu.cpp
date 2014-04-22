#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>

#include "../entetes/menu.h"
#include "../entetes/utilisateur.h"
#include "../entetes/enclos.h"


using namespace std;


/***********************************************************/
/*********** Declaration des variables *********************/
/***********************************************************/


int iChoixAnimal;


void retourMenu() {
    cout << "Appuyez sur entrée pour revenir au menu précédent.";
    scanf("%*c");
}



void menuPrincipal(Parc &Parc1){
    int iChoix;
    do {
        system("clear");
        cout << Parc1 << endl;
        cout << "************************" << endl;
        cout << "***  Menu principal  ***" << endl;
        cout << "************************" << endl << endl;
        cout << MENU_PRINCIPAL_GESTION << ". Gestion des enclos et des animaux" << endl;
        cout << MENU_PRINCIPAL_AFFICHAGE_ENCLOS << ". Affichage des informations sur les enclos" << endl;
        cout << MENU_PRINCIPAL_AFFICHAGE_ANIMAUX << ". Affichage des informations sur les animaux" << endl;
        cout << MENU_PRINCIPAL_SAUVEGARDE << ". Sauvegarder le parc" << endl;
        cout << MENU_PRINCIPAL_CHARGER << ". Charger un parc" << endl;
        cout << MENU_PRINCIPAL_QUITTER << ". Quitter" << endl;

        do {
            cout << "Choix : ";
            cin >> iChoix;
        } while( iChoix != MENU_PRINCIPAL_GESTION
                 && iChoix != MENU_PRINCIPAL_AFFICHAGE_ENCLOS
                 && iChoix != MENU_PRINCIPAL_AFFICHAGE_ANIMAUX
                 && iChoix != MENU_PRINCIPAL_SAUVEGARDE
                 && iChoix != MENU_PRINCIPAL_CHARGER
                 && iChoix != MENU_PRINCIPAL_QUITTER);

        switch (iChoix) {
        case MENU_PRINCIPAL_GESTION:
            menuGestion(Parc1);
            break;
        case MENU_PRINCIPAL_AFFICHAGE_ENCLOS:
            menuAffichageEnclos(Parc1);
            break;
        case MENU_PRINCIPAL_AFFICHAGE_ANIMAUX:
            menuAffichageAnimaux(Parc1);
            break;
        case MENU_PRINCIPAL_SAUVEGARDE:
            //parc.sauvegarde();
            retourMenu();
            break;
        case MENU_PRINCIPAL_CHARGER:
            //parc.charger();
            retourMenu();
            break;
        }
    } while(iChoix != MENU_PRINCIPAL_QUITTER);
}

void menuGestion(Parc &Parc1) {
    int iIDEnclos;
    int iChoix;
    do {
        system("clear");
        cout << "*******************************************" << endl;
        cout << "***  Gestion des enclos et des animaux  ***" << endl;
        cout << "*******************************************" << endl << endl;
        cout << MENU_GESTION_CREER_ENCLOS << ". Créer un enclos" << endl;
        cout << MENU_GESTION_SUPPR_ENCLOS << ". Supprimer un enclos" << endl;
        cout << MENU_GESTION_MODIF_ENCLOS << ". Modifier un enclos" << endl;
        cout << MENU_GESTION_BARNEY << ". Demander à Barney de capturer un animal" << endl;
        cout << MENU_GESTION_MODIF_ANIMAL << ". Modifier les informations d'un animal" << endl;
        cout << MENU_GESTION_DEPLACER << ". Déplacer un animal" << endl;
        cout << MENU_GESTION_RELACHER << ". Relâcher un animal" << endl;
        cout << MENU_GESTION_RETOUR << ". Retour" << endl;

        do {
            cout << "Choix : ";
            cin >> iChoix;
        } while( iChoix != MENU_GESTION_CREER_ENCLOS
                 && iChoix != MENU_GESTION_SUPPR_ENCLOS
                 && iChoix != MENU_GESTION_MODIF_ENCLOS
                 && iChoix != MENU_GESTION_BARNEY
                 && iChoix != MENU_GESTION_MODIF_ANIMAL
                 && iChoix != MENU_GESTION_DEPLACER
                 && iChoix != MENU_GESTION_RELACHER
                 && iChoix != MENU_GESTION_RETOUR);

        switch (iChoix) {
        case MENU_GESTION_CREER_ENCLOS:
            creationEnclos(Parc1);
            retourMenu();
            break;
        case MENU_GESTION_SUPPR_ENCLOS:
            supprimerEnclos(Parc1);
            retourMenu();
            break;
        case MENU_GESTION_MODIF_ENCLOS:
            modifierEnclos(Parc1);
            retourMenu();
            break;
        case MENU_GESTION_BARNEY:
            Barney(Parc1);
            retourMenu();
            break;
        case MENU_GESTION_MODIF_ANIMAL:
            retourMenu();
            break;
        case MENU_GESTION_DEPLACER:
            deplacerAnimal(Parc1);
            retourMenu();
            break;
        case MENU_GESTION_RELACHER:
            supprimerAnimal(Parc1);
            retourMenu();
            break;
        }
    } while(iChoix != MENU_GESTION_RETOUR);
}

void menuAffichageEnclos(Parc &Parc1) {
    int iChoix;
    do {
        system("clear");
        cout << "***************************************************" << endl;
        cout << "***  Affichage des informations sur les enclos  ***" << endl;
        cout << "***************************************************" << endl << endl;
        cout << MENU_AFFICHE_ENCLOS_TAUX << ". Afficher le taux de remplissage des enclos" << endl;
        cout << MENU_AFFICHE_ENCLOS_DETAIL_UN << ". Afficher le détail d'un enclos" << endl;
        cout << MENU_AFFICHE_ENCLOS_DETAIL_TOUS << ". Afficher le détail de tous les enclos" << endl;
        cout << MENU_AFFICHE_ENCLOS_ANIMAUX_UN << ". Afficher le détail et les animaux d'un enclos" << endl;
        cout << MENU_AFFICHE_ENCLOS_ANIMAUX_TOUS << ". Afficher le détail et les animaux de tous les enclos" << endl;
        cout << MENU_AFFICHE_ENCLOS_RETOUR << ". Retour" << endl;

        do {
            cout << "Choix : ";
            cin >> iChoix;
        } while( iChoix != MENU_AFFICHE_ENCLOS_TAUX
                 && iChoix != MENU_AFFICHE_ENCLOS_DETAIL_UN
                 && iChoix != MENU_AFFICHE_ENCLOS_DETAIL_TOUS
                 && iChoix != MENU_AFFICHE_ENCLOS_ANIMAUX_UN
                 && iChoix != MENU_AFFICHE_ENCLOS_ANIMAUX_TOUS
                 && iChoix != MENU_AFFICHE_ENCLOS_RETOUR);

        switch (iChoix) {
        case MENU_AFFICHE_ENCLOS_TAUX:
            trisDesEnclos(Parc1);
            afficherTauxRemplissageEnclos(Parc1);
            retourMenu();
            break;
        case MENU_AFFICHE_ENCLOS_DETAIL_UN:
            rechercheEnclos(Parc1);
            retourMenu();
            break;
        case MENU_AFFICHE_ENCLOS_DETAIL_TOUS:
            trisDesEnclos(Parc1);
            afficherDetailDeTousLesEnclos(Parc1);
            retourMenu();
            break;
        case MENU_AFFICHE_ENCLOS_ANIMAUX_UN:
            afficherDetailEnclosEtAnimaux(Parc1);
            retourMenu();
            break;
        case MENU_AFFICHE_ENCLOS_ANIMAUX_TOUS:
           trisDesEnclos(Parc1);
            afficherDetailEtAnimauxDeTousLesEnclos(Parc1);
            retourMenu();
            break;
        }
    } while(iChoix != MENU_AFFICHE_ENCLOS_RETOUR);
}

void menuAffichageAnimaux(Parc &Parc1) {
    int iChoix;
    do {
        system("clear");
        cout << "****************************************************" << endl;
        cout << "***  Affichage des informations sur les animaux  ***" << endl;
        cout << "****************************************************" << endl << endl;
        cout << MENU_AFFICHE_ANIMAUX_UN << ". Afficher le détail d'un animal" << endl;
        cout << MENU_AFFICHE_ANIMAUX_TOUS_ENCLOS << ". Afficher le détail de tous les animaux d'un enclos" << endl;
        cout << MENU_AFFICHE_ANIMAUX_TOUS_PARC << ". Afficher le détail de tous les animaux du parc" << endl;
        cout << MENU_AFFICHE_ANIMAUX_RETOUR << ". Retour" << endl;

        do {
            cout << "Choix : ";
            cin >> iChoix;
        } while( iChoix != MENU_AFFICHE_ANIMAUX_UN
                 && iChoix != MENU_AFFICHE_ANIMAUX_TOUS_ENCLOS
                 && iChoix != MENU_AFFICHE_ANIMAUX_TOUS_PARC
                 && iChoix != MENU_AFFICHE_ANIMAUX_RETOUR
               );

        switch (iChoix) {
        case MENU_AFFICHE_ANIMAUX_UN:
            rechercheAnimal(Parc1);
            retourMenu();
            break;
        case MENU_AFFICHE_ANIMAUX_TOUS_ENCLOS:
            afficherDetailEnclosEtAnimaux(Parc1);
            retourMenu();
            break;
        case MENU_AFFICHE_ANIMAUX_TOUS_PARC:
            trisDesAnimaux(Parc1);
            afficheAnimauxParc(Parc1);
            retourMenu();
            break;
        }
    } while(iChoix != MENU_AFFICHE_ANIMAUX_RETOUR);
}

