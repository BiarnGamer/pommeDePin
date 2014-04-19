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



int main() {
    /** POUR DE L'ALÉATOIRE **/
    srand(time(NULL));

    Parc Parc1;
    menuPrincipal(Parc1);

    return 0;
}
