#include "../entetes/affichage.h"

int rechercheAnimal(const Parc & Parc1) {
    system("clear");
    int IDAnimal;
    int iRangAnimal;
    cout << "Recherche d'un animal" << endl;
    cout << "Identifiant de l'animal recherché : ";
    cin >> IDAnimal;

    iRangAnimal = Parc1.rechercherAnimal(IDAnimal);

    if(iRangAnimal != -1) {
        try {
            cout << endl << *(Parc1.getAnimal(iRangAnimal));
        }
        catch(const string & s) {
            cerr << s;
        }
    }
    else {
        cout << "Cet Animal n'existe pas." << endl;
    }
    return iRangAnimal;
}

int rechercheEnclos(const Parc & Parc1) {
    system("clear");
    int IDEnclos;
    int iRangEnclos;
    cout << "Recherche d'un enclos" << endl;
    cout << "Identifiant de l'enclos recherché : ";
    cin >> IDEnclos;

    iRangEnclos = Parc1.rechercherEnclos(IDEnclos);

    if(iRangEnclos != -1) {
        try {
            cout << endl << Parc1.getEnclos(iRangEnclos);
        }
        catch(string const& chaine) {
            cerr << chaine << endl;
        }
    }
    else {
        cout << "Cet enclos n'existe pas." << endl;
    }
    return iRangEnclos;
}

void afficheAnimauxParc(const Parc & Parc1) {
    system("clear");
    cout << "***************************************" << endl;
    cout << "***  Affichage des animaux du parc  ***" << endl;
    cout << "***************************************" << endl << endl;

    int iNbAnimaux = Parc1.getNbAnimaux();
    for(int i=0; i<iNbAnimaux; i++) {
        try {
            cout << *(Parc1.getAnimal(i)) << endl << endl;
        }
        catch(const string & s) {
            cerr << s;
        }
    }
}

void afficherTauxRemplissageEnclos(const Parc &Parc1) {
    system("clear");
    cout << "*****************************************************" << endl;
    cout << "***  Affichage du taux de remplissage des enclos  ***" << endl;
    cout << "*****************************************************" << endl << endl;

    for (int i=0; i<Parc1.getNbEnclos(); i++) {
        try {
            cout << "- " << Parc1.getEnclos(i).getNom() << " : " << Parc1.getEnclos(i).getOccupation() << "/" << Parc1.getEnclos(i).getCapacite() << endl;

            catch(string const& chaine) {
                cerr << chaine << endl;
            }
        }
    }

    void afficherDetailDeTousLesEnclos(const Parc &Parc1) {
        system("clear");
        cout << "***********************************************" << endl;
        cout << "***  Affichage des informations des enclos  ***" << endl;
        cout << "***********************************************" << endl << endl;

        for (int i=0; i<Parc1.getNbEnclos(); i++) {
            try {
                cout << Parc1.getEnclos(i) << endl;
            }
            catch(string const& chaine) {
                cerr << chaine << endl;
            }
        }
    }

    void afficherDetailEnclosEtAnimaux(const Parc &Parc1) {
        int irang = rechercheEnclos(Parc1);
        if(irang != -1) {
            cout << endl << "Animaux de cet enclos : " << endl;
            try {
                int iNbAnimaux = Parc1.getEnclos(irang).getOccupation();
                for (int i=0; i<iNbAnimaux; i++)
                  try {
                     cout << *(Parc1.getEnclos(irang).getPtrAnimal(i)) << endl;
                    }
                    catch(const string & s) {
                        cerr << s;
                    }
            }
            catch(string const& chaine) {
                cerr << chaine << endl;
            }
        }
    }

    void afficherDetailEtAnimauxDeTousLesEnclos(const Parc &Parc1) {
        system("clear");
        cout << "**************************************************************" << endl;
        cout << "***  Affichage des informations et des animaux des enclos  ***" << endl;
        cout << "**************************************************************" << endl << endl;

        int iNbAnimauxEnclos;

        for (int i=0; i<Parc1.getNbEnclos(); i++) {
            try {
                cout << Parc1.getEnclos(i);

                iNbAnimauxEnclos =Parc1.getEnclos(i).getOccupation();
                if(iNbAnimauxEnclos > 0) {
                    cout << endl << "Animaux de cet enclos : " << endl;
                }

                for (int j=0; j<iNbAnimauxEnclos ; j++) {
                   try {
                     cout << *(Parc1.getEnclos(i).getPtrAnimal(j)) << endl << endl;
                    }
                    catch(const string & s) {
                        cerr << s;
                    }
                }
                cout << endl << "*******************************************" << endl << endl;
            }
            catch(string const& chaine) {
                cerr << chaine << endl;
            }
        }

    }
