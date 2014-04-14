#ifndef MENU_H
#define MENU_H

#define MENU_PRINCIPAL_GESTION 1
#define MENU_PRINCIPAL_AFFICHAGE_ENCLOS 2
#define MENU_PRINCIPAL_AFFICHAGE_ANIMAUX 3
#define MENU_PRINCIPAL_SAUVEGARDE 4
#define MENU_PRINCIPAL_CHARGER 5
#define MENU_PRINCIPAL_QUITTER 9

#define MENU_GESTION_CREER_ENCLOS 1
#define MENU_GESTION_SUPPR_ENCLOS 2
#define MENU_GESTION_BARNEY 3
#define MENU_GESTION_DEPLACER 4
#define MENU_GESTION_RELACHER 5
#define MENU_GESTION_RETOUR 9

#define MENU_AFFICHE_ENCLOS_TAUX 1
#define MENU_AFFICHE_ENCLOS_DETAIL_UN 2
#define MENU_AFFICHE_ENCLOS_DETAIL_TOUS 3
#define MENU_AFFICHE_ENCLOS_ANIMAUX_UN 4
#define MENU_AFFICHE_ENCLOS_ANIMAUX_TOUS 5
#define MENU_AFFICHE_ENCLOS_RETOUR 9

#define MENU_AFFICHE_ANIMAUX_UN 1
#define MENU_AFFICHE_ANIMAUX_TOUS_ENCLOS 2
#define MENU_AFFICHE_ANIMAUX_TOUS_PARC 3
#define MENU_AFFICHE_ANIMAUX_RETOUR 9

    void retourMenu();
    void menuPrincipal();
    void menuGestion();
    void menuAffichageEnclos();
    void menuAffichageAnimaux();
#endif