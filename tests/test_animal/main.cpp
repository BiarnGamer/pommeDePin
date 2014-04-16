#include <iostream>
#include <string>

#include "../../entetes/animal.h"

using namespace std;

int main() {
    /* *************************** */
    /* CRÉATION D'UN ANIMAL        */
    /* *************************** */
    cout << "*************************" << endl;
    cout << "* CRÉATION D'UN ANIMAL  *" << endl;
    cout << "*************************" << endl;
    // Par défaut
    Animal Moi;
    cout << Moi << endl << endl;


    /* *************************** */
    /* CRÉATION D'UN TIGRE         */
    /* *************************** */
    cout << "*************************" << endl;
    cout << "* CRÉATION D'UN TIGRE   *" << endl;
    cout << "*************************" << endl;
    // Par défaut, normal, recopie
    cout << "*** Par défaut, normal, recopie ***" << endl;
    Tigre Diego;
    Tigre Helico(105, 654, "Diego", 001);
    Tigre RRRrrrr(Helico);
    cout << Diego << endl;
    cout << Helico << endl;
    cout << RRRrrrr << endl;

    // Test égalité/différence
    cout << endl <<  "*** Tests égalité / différence ****" << endl;
    if(Diego == Helico) {
        cout << "Égalité (ERREUR)" << endl;
    }
    else {
        cout << "Pas égalité (OK)" << endl;
    }

    if(Helico == RRRrrrr) {
        cout << "Égalité (OK)" << endl;
    }
    else {
        cout << "Pas égalité (ERREUR)" << endl;
    }

    if(Diego != Helico) {
        cout << "Différence (OK)" << endl;
    }
    else {
        cout << "Pas différence (ERREUR)" << endl;
    }

    if(RRRrrrr != Helico) {
        cout << "Différence (ERREUR)" << endl;
    }
    else {
        cout << "Pas différence (OK)" << endl;
    }

    // Affectation
    cout << endl << "*** Affectation ****" << endl;
    Diego = Helico;
    cout << Diego << endl;

    // Redéfinition de tous les attributs (sauf ID qui est privé et dans Animal
    cout << endl << "*** Setters ***" << endl;
    Diego.setNom("Paul");
    Diego.setGarot(452.3);
    Diego.setNbVictimes(12);
    cout << Diego << endl;




    /* *************************** */
    /* CRÉATION D'UN BASQUE        */
    /* *************************** */
    cout << "*************************" << endl;
    cout << "* CRÉATION D'UN BASQUE  *" << endl;
    cout << "*************************" << endl;
    // Par défaut, normal, recopie
    cout << "*** Par défaut, normal, recopie ***" << endl;
    Basque Pantxica;
    Basque Xabi(125, 63, 1, 9999999, "Xabi", 2);
    Basque Solaberrieta(Xabi);
    cout << Pantxica << endl;
    cout << Xabi << endl;
    cout << Solaberrieta << endl;

    // Test égalité/différence
    cout << endl <<  "*** Tests égalité / différence ****" << endl;
    if(Pantxica == Xabi) {
        cout << "Égalité (ERREUR)" << endl;
    }
    else {
        cout << "Pas égalité (OK)" << endl;
    }

    if(Xabi == Solaberrieta) {
        cout << "Égalité (OK)" << endl;
    }
    else {
        cout << "Pas égalité (ERREUR)" << endl;
    }

    if(Pantxica != Xabi) {
        cout << "Différence (OK)" << endl;
    }
    else {
        cout << "Pas différence (ERREUR)" << endl;
    }

    if(Solaberrieta != Xabi) {
        cout << "Différence (ERREUR)" << endl;
    }
    else {
        cout << "Pas différence (OK)" << endl;
    }
    cout << endl;

    // Affectation
    cout << endl << "*** Affectation ****" << endl;
    Pantxica = Solaberrieta;
    cout << Pantxica << endl;

    // Redéfinition des attributs de la classe
    cout << endl << "*** Setters ***" << endl;
    Xabi.setLargeurBeret(12.2);
    Xabi.setTempsCuisson(63.2);
    Xabi.setNbVictoires(0);
    Xabi.setNbRicard(-6);
    cout << Xabi << endl;


    /* *************************** */
    /* CRÉATION D'UNE MARMOTTE     */
    /* *************************** */
    cout << "***************************" << endl;
    cout << "* CRÉATION D'UNE MARMOTTE *" << endl;
    cout << "***************************" << endl;
    // Par défaut, normal, recopie
    cout << "*** Par défaut, normal, recopie ***" << endl;
    Marmotte Milka;
    Marmotte Miam(95, 6544, "Purée", 3);
    Marmotte Shakira(Miam);
    cout << Milka << endl;
    cout << Miam << endl;
    cout << Shakira << endl;

    // Test égalité/différence
    cout << endl <<  "*** Tests égalité / différence ****" << endl;
    if(Milka == Miam) {
        cout << "Égalité (ERREUR)" << endl;
    }
    else {
        cout << "Pas égalité (OK)" << endl;
    }

    if(Miam == Shakira) {
        cout << "Égalité (OK)" << endl;
    }
    else {
        cout << "Pas égalité (ERREUR)" << endl;
    }

    if(Milka != Miam) {
        cout << "Différence (OK)" << endl;
    }
    else {
        cout << "Pas différence (ERREUR)" << endl;
    }

    if(Shakira != Miam) {
        cout << "Différence (ERREUR)" << endl;
    }
    else {
        cout << "Pas différence (OK)" << endl;
    }
    cout << endl;

    // Affectation
    cout << endl << "*** Affectation ****" << endl;
    Shakira = Milka;
    cout << Shakira << endl;

    // Redéfinition des attributs de la classe
    cout << endl << "*** Setters ***" << endl;
    Shakira.setTaille(165);
    Shakira.setNbTabChocolat(2048);
    cout << Shakira << endl;
    cout << endl;



    /* *************************** */
    /* CRÉATION D'UN ELEPHANT      */
    /* *************************** */
    cout << "***************************" << endl;
    cout << "* CRÉATION D'UN ÉLEPHANT  *" << endl;
    cout << "***************************" << endl;
    // Par défaut, normal, recopie
    cout << "*** Par défaut, normal, recopie ***" << endl;
    Elephant MamamDeValentin;
    Elephant Pikachu(1021, 365, 102, "Valentin", 4);
    Elephant Picasso(Pikachu);
    cout << MamamDeValentin << endl;
    cout << Pikachu << endl;
    cout << Picasso << endl;

    // Test égalité/différence
    cout << endl <<  "*** Tests égalité / différence ****" << endl;
    if(MamamDeValentin == Pikachu) {
        cout << "Égalité (ERREUR)" << endl;
    }
    else {
        cout << "Pas égalité (OK)" << endl;
    }

    if(Pikachu == Picasso) {
        cout << "Égalité (OK)" << endl;
    }
    else {
        cout << "Pas égalité (ERREUR)" << endl;
    }

    if(MamamDeValentin != Pikachu) {
        cout << "Différence (OK)" << endl;
    }
    else {
        cout << "Pas différence (ERREUR)" << endl;
    }

    if(Picasso != Pikachu) {
        cout << "Différence (ERREUR)" << endl;
    }
    else {
        cout << "Pas différence (OK)" << endl;
    }
    cout << endl;

    // Affectation
    cout << endl << "*** Affectation ****" << endl;
    MamamDeValentin = Picasso;
    cout << MamamDeValentin << endl;

    // Redéfinition des attributs de la classe
    cout << endl << "*** Setters ***" << endl;
    Picasso.setPoids(14543451.36);
    Picasso.setLongTrompe(1245);
    Picasso.setNbVictimes(4);
    cout << Picasso << endl;
    cout << endl;



    /* *************************** */
    /* CRÉATION D'UN AIGLE         */
    /* *************************** */
    cout << "***************************" << endl;
    cout << "* CRÉATION D'UN AIGLE     *" << endl;
    cout << "***************************" << endl;
    // Par défaut, normal, recopie
    cout << "*** Par défaut, normal, recopie ***" << endl;
    Aigle Roucarnage;
    Aigle Piafabec(95, 6544, "Poussin", 5);
    Aigle Nirondelle(Piafabec);
    cout << Roucarnage << endl;
    cout << Piafabec << endl;
    cout << Nirondelle << endl;

    // Test égalité/différence
    cout << endl <<  "*** Tests égalité / différence ****" << endl;
    if(Roucarnage == Piafabec) {
        cout << "Égalité (ERREUR)" << endl;
    }
    else {
        cout << "Pas égalité (OK)" << endl;
    }

    if(Piafabec == Nirondelle) {
        cout << "Égalité (OK)" << endl;
    }
    else {
        cout << "Pas égalité (ERREUR)" << endl;
    }

    if(Roucarnage != Piafabec) {
        cout << "Différence (OK)" << endl;
    }
    else {
        cout << "Pas différence (ERREUR)" << endl;
    }

    if(Nirondelle != Piafabec) {
        cout << "Différence (ERREUR)" << endl;
    }
    else {
        cout << "Pas différence (OK)" << endl;
    }
    cout << endl;

    // Affectation
    cout << endl << "*** Affectation ****" << endl;
    Roucarnage = Nirondelle;
    cout << Roucarnage << endl;

    // Redéfinition des attributs de la classe
    cout << endl << "*** Setters ***" << endl;
    Roucarnage.setLongueurBec(428);
    Roucarnage.setNbLoopings(1);
    cout << Roucarnage << endl;
    cout << endl;
    cout << endl;


    /* *************************** */
    /* CRÉATION D'UN LAPIN         */
    /* *************************** */
    cout << "***************************" << endl;
    cout << "* CRÉATION D'UN LAPIN     *" << endl;
    cout << "***************************" << endl;
    // Par défaut, normal, recopie
    cout << "*** Par défaut, normal, recopie ***" << endl;
    Lapin Lapine;
    Lapin Valou(64, "Rouge", "Mimie Matti", 6);
    Lapin BuggsBunny(Valou);
    cout << Lapine << endl;
    cout << Valou << endl;
    cout << BuggsBunny << endl;

    // Test égalité/différence
    cout << endl <<  "*** Tests égalité / différence ****" << endl;
    if(Lapine == Valou) {
        cout << "Égalité (ERREUR)" << endl;
    }
    else {
        cout << "Pas égalité (OK)" << endl;
    }

    if(Valou == BuggsBunny) {
        cout << "Égalité (OK)" << endl;
    }
    else {
        cout << "Pas égalité (ERREUR)" << endl;
    }

    if(Lapine != Valou) {
        cout << "Différence (OK)" << endl;
    }
    else {
        cout << "Pas différence (ERREUR)" << endl;
    }

    if(BuggsBunny != Valou) {
        cout << "Différence (ERREUR)" << endl;
    }
    else {
        cout << "Pas différence (OK)" << endl;
    }
    cout << endl;

    // Affectation
    cout << endl << "*** Affectation ****" << endl;
    Lapine = BuggsBunny;
    cout << Lapine << endl;

    // Redéfinition des attributs de la classe
    cout << endl << "*** Setters ***" << endl;
    Lapine.setNbCarotteMange(428);
    Lapine.setCouleur("Gris");
    cout << Lapine << endl;
    cout << endl;
    cout << endl;



    /* *************************** */
    /* CRÉATION D'UNE TORTUE       */
    /* *************************** */
    cout << "***************************" << endl;
    cout << "* CRÉATION D'UNE TORTUE   *" << endl;
    cout << "***************************" << endl;
    // Par défaut, normal, recopie
    cout << "*** Par défaut, normal, recopie ***" << endl;
    Tortue Franklin;
    Tortue Toto(35, 1201, "Arc-end-ciel", "Speedy Gonzalez", 7);
    Tortue Chirac(Toto);
    cout << Franklin << endl;
    cout << Toto<< endl;
    cout << Chirac << endl;

    // Test égalité/différence
    cout << endl <<  "*** Tests égalité / différence ****" << endl;
    if(Franklin == Toto) {
        cout << "Égalité (ERREUR)" << endl;
    }
    else {
        cout << "Pas égalité (OK)" << endl;
    }

    if(Toto == Chirac) {
        cout << "Égalité (OK)" << endl;
    }
    else {
        cout << "Pas égalité (ERREUR)" << endl;
    }

    if(Franklin != Toto) {
        cout << "Différence (OK)" << endl;
    }
    else {
        cout << "Pas différence (ERREUR)" << endl;
    }

    if(Chirac != Toto) {
        cout << "Différence (ERREUR)" << endl;
    }
    else {
        cout << "Pas différence (OK)" << endl;
    }
    cout << endl;

    // Affectation
    cout << endl << "*** Affectation ****" << endl;
    Franklin = Chirac;
    cout << Franklin << endl;

    // Redéfinition des attributs de la classe
    cout << endl << "*** Setters ***" << endl;
    Franklin.setVitesseMax(362);
    Franklin.setAge(23);
    Franklin.setCouleur("Vert");
    cout << Franklin << endl;
    cout << endl;
    cout << endl;





    /* *************************** */
    /* CRÉATION D'UN CROCODILE     */
    /* *************************** */
    cout << "***************************" << endl;
    cout << "* CRÉATION D'UN CROCODILE *" << endl;
    cout << "***************************" << endl;
    // Par défaut, normal, recopie
    cout << "*** Par défaut, normal, recopie ***" << endl;
    Crocodile Crocro;
    Crocodile GrosseDent(3045, 124, "Mange de l'herbe", 8);
    Crocodile Chicos(GrosseDent);
    cout << Crocro << endl;
    cout << GrosseDent<< endl;
    cout << Chicos << endl;

    // Test égalité/différence
    cout << endl <<  "*** Tests égalité / différence ****" << endl;
    if(Crocro == GrosseDent) {
        cout << "Égalité (ERREUR)" << endl;
    }
    else {
        cout << "Pas égalité (OK)" << endl;
    }

    if(GrosseDent == Chicos) {
        cout << "Égalité (OK)" << endl;
    }
    else {
        cout << "Pas égalité (ERREUR)" << endl;
    }

    if(Crocro != GrosseDent) {
        cout << "Différence (OK)" << endl;
    }
    else {
        cout << "Pas différence (ERREUR)" << endl;
    }

    if(Chicos != GrosseDent) {
        cout << "Différence (ERREUR)" << endl;
    }
    else {
        cout << "Pas différence (OK)" << endl;
    }
    cout << endl;

    // Affectation
    cout << endl << "*** Affectation ****" << endl;
    Crocro = Chicos;
    cout << Crocro << endl;

    // Redéfinition des attributs de la classe
    cout << endl << "*** Setters ***" << endl;
    Crocro.setEnfantMange(362);
    Crocro.setNbDents(4);
    cout << Crocro << endl;
    cout << endl;
    cout << endl;





    /* *************************** */
    /* CRÉATION D'UNE LOUTRE       */
    /* *************************** */
    cout << "***************************" << endl;
    cout << "* CRÉATION D'UNE LOUTRE   *" << endl;
    cout << "***************************" << endl;
    // Par défaut, normal, recopie
    cout << "*** Par défaut, normal, recopie ***" << endl;
    Loutre Loulou;
    Loutre Coucou(28, 205, "Doudou", 9);
    Loutre Toutou(Coucou);
    cout << Loulou << endl;
    cout << Coucou<< endl;
    cout << Toutou << endl;

    // Test égalité/différence
    cout << endl <<  "*** Tests égalité / différence ****" << endl;
    if(Loulou == Coucou) {
        cout << "Égalité (ERREUR)" << endl;
    }
    else {
        cout << "Pas égalité (OK)" << endl;
    }

    if(Coucou == Toutou) {
        cout << "Égalité (OK)" << endl;
    }
    else {
        cout << "Pas égalité (ERREUR)" << endl;
    }

    if(Loulou != Coucou) {
        cout << "Différence (OK)" << endl;
    }
    else {
        cout << "Pas différence (ERREUR)" << endl;
    }

    if(Toutou != Coucou) {
        cout << "Différence (ERREUR)" << endl;
    }
    else {
        cout << "Pas différence (OK)" << endl;
    }
    cout << endl;

    // Affectation
    cout << endl << "*** Affectation ****" << endl;
    Loulou = Toutou;
    cout << Loulou << endl;

    // Redéfinition des attributs de la classe
    cout << endl << "*** Setters ***" << endl;
    Loulou.setTaille(362);
    Loulou.setNbAmis(4);
    cout << Loulou << endl;
    cout << endl;
    cout << endl;




    /* *************************** */
    /* CRÉATION D'UNE GIRAFE       */
    /* *************************** */
    cout << "***************************" << endl;
    cout << "* CRÉATION D'UNE GIRAFE   *" << endl;
    cout << "***************************" << endl;
    // Par défaut, normal, recopie
    cout << "*** Par défaut, normal, recopie ***" << endl;
    Girafe LongCoup;
    Girafe PetiteB(120, 5412, "Gigi", 9);
    Girafe Gneeee(PetiteB);
    cout << LongCoup << endl;
    cout << PetiteB<< endl;
    cout << Gneeee << endl;

    // Test égalité/différence
    cout << endl <<  "*** Tests égalité / différence ****" << endl;
    if(LongCoup == PetiteB) {
        cout << "Égalité (ERREUR)" << endl;
    }
    else {
        cout << "Pas égalité (OK)" << endl;
    }

    if(PetiteB == Gneeee) {
        cout << "Égalité (OK)" << endl;
    }
    else {
        cout << "Pas égalité (ERREUR)" << endl;
    }

    if(LongCoup != PetiteB) {
        cout << "Différence (OK)" << endl;
    }
    else {
        cout << "Pas différence (ERREUR)" << endl;
    }

    if(Gneeee != PetiteB) {
        cout << "Différence (ERREUR)" << endl;
    }
    else {
        cout << "Pas différence (OK)" << endl;
    }
    cout << endl;

    // Affectation
    cout << endl << "*** Affectation ****" << endl;
    LongCoup = Gneeee;
    cout << LongCoup << endl;

    // Redéfinition des attributs de la classe
    cout << endl << "*** Setters ***" << endl;
    LongCoup.setTaille(362);
    LongCoup.setNbTaches(4);
    cout << LongCoup << endl;
    cout << endl;
    cout << endl;

    return 0;
}
