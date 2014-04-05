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
    if(Diego == Helico) {cout << "Égalité (ERREUR)" << endl;}
    else {cout << "Pas égalité (OK)" << endl;}

    if(Helico == RRRrrrr) {cout << "Égalité (OK)" << endl;}
    else {cout << "Pas égalité (ERREUR)" << endl;}

    if(Diego != Helico) {cout << "Différence (OK)" << endl;}
    else {cout << "Pas différence (ERREUR)" << endl;}

    if(RRRrrrr != Helico) {cout << "Différence (ERREUR)" << endl;}
    else {cout << "Pas différence (OK)" << endl;}

    // Affectation
    cout << endl << "*** Affectation ****" << endl;
    Diego = Helico;
    cout << Diego << endl;

    // Redéfinition de tous les attributs (sauf ID qui est privé et dans Animal
    cout << endl << "*** Setters ***" << endl;
    Diego.setEspece("Écureil");
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
    if(Pantxica == Xabi) {cout << "Égalité (ERREUR)" << endl;}
    else {cout << "Pas égalité (OK)" << endl;}

    if(Xabi == Solaberrieta) {cout << "Égalité (OK)" << endl;}
    else {cout << "Pas égalité (ERREUR)" << endl;}

    if(Pantxica != Xabi) {cout << "Différence (OK)" << endl;}
    else {cout << "Pas différence (ERREUR)" << endl;}

    if(Solaberrieta != Xabi) {cout << "Différence (ERREUR)" << endl;}
    else {cout << "Pas différence (OK)" << endl;}
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
    if(Milka == Miam) {cout << "Égalité (ERREUR)" << endl;}
    else {cout << "Pas égalité (OK)" << endl;}

    if(Miam == Shakira) {cout << "Égalité (OK)" << endl;}
    else {cout << "Pas égalité (ERREUR)" << endl;}

    if(Milka != Miam) {cout << "Différence (OK)" << endl;}
    else {cout << "Pas différence (ERREUR)" << endl;}

    if(Shakira != Miam) {cout << "Différence (ERREUR)" << endl;}
    else {cout << "Pas différence (OK)" << endl;}
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
    if(MamamDeValentin == Pikachu) {cout << "Égalité (ERREUR)" << endl;}
    else {cout << "Pas égalité (OK)" << endl;}

    if(Pikachu == Picasso) {cout << "Égalité (OK)" << endl;}
    else {cout << "Pas égalité (ERREUR)" << endl;}

    if(MamamDeValentin != Pikachu) {cout << "Différence (OK)" << endl;}
    else {cout << "Pas différence (ERREUR)" << endl;}

    if(Picasso != Pikachu) {cout << "Différence (ERREUR)" << endl;}
    else {cout << "Pas différence (OK)" << endl;}
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
    if(Roucarnage == Piafabec) {cout << "Égalité (ERREUR)" << endl;}
    else {cout << "Pas égalité (OK)" << endl;}

    if(Piafabec == Nirondelle) {cout << "Égalité (OK)" << endl;}
    else {cout << "Pas égalité (ERREUR)" << endl;}

    if(Roucarnage != Piafabec) {cout << "Différence (OK)" << endl;}
    else {cout << "Pas différence (ERREUR)" << endl;}

    if(Nirondelle != Piafabec) {cout << "Différence (ERREUR)" << endl;}
    else {cout << "Pas différence (OK)" << endl;}
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

    return 0;
}
