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
    Parc1.creerAnimal(&PetiteB, 2);
    Parc1.creerAnimal(&Tuture, 2);
    Parc1.creerAnimal(&Valou, 2);
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


    /* ****************************** */
    /* Déplacements sans conséquence  */
    /* ****************************** */
    cout << "********************************" << endl;
    cout << "* Déplacement sans conséquence *" << endl;
    cout << "********************************" << endl;

    cout << "Enclos 1 avant déplacement :" << endl;
    cout << Parc1.getEnclos(0) << endl;
    cout << "Enclos 6 avant déplacement :" << endl;
    cout << Parc1.getEnclos(4) << endl;

    Parc1.deplacerAnimal(6,Parc1.getEnclos(4).getAnimal(0).getID(),145);

    cout << "Enclos 1 après déplacement :" << endl;
    cout << Parc1.getEnclos(0) << endl;
    cout << "Enclos 6 après déplacement :" << endl;
    cout << Parc1.getEnclos(4) << endl;

    // Note si l'enclos de départ ne correspond pas ou que l'enclos d'arrivée n'existe pas, le cas est bien géré


    /* *********************************** */
    /* Déplacements avec noyade / évasion  */
    /* *********************************** */
    cout << "*************************************" << endl;
    cout << "* Déplacement avec noyade / évasion *" << endl;
    cout << "*************************************" << endl;

    // Déplacement de la girafe de l'enclos 2 vers l'enclos 3

    cout << "Enclos 2 avant déplacement :" << endl;
    cout << Parc1.getEnclos(1) << endl;
    cout << "Enclos 3 avant déplacement :" << endl;
    cout << Parc1.getEnclos(2) << endl;

    Parc1.deplacerAnimal(2,Parc1.getEnclos(1).getAnimal(1).getID(),3);

    cout << "Enclos 2 après déplacement :" << endl;
    cout << Parc1.getEnclos(1) << endl;

    cout << "Enclos 3 après déplacement :" << endl;
    cout << Parc1.getEnclos(2) << endl;

    /* ****************************** */
    /* Déplacements avec conséquence  */
    /* ****************************** */
    cout << "********************************" << endl;
    cout << "* Déplacement avec conséquence *" << endl;
    cout << "********************************" << endl;

    // On crée un enclos avec 4 éléphants et 1 tigre
    // On crée un enclos avec 7 éléphants et 1 tigre
    // Ils sont en paix avec de la chance

    Parc1.creerEnclos("Ça va barder !",1,23);
    Parc1.creerEnclos("Nutella !!!",1,23);

    Parc1.creerAnimal(&PHP, 7);
    Parc1.creerAnimal(&PHP, 7);
    Parc1.creerAnimal(&PHP, 7);
    Parc1.creerAnimal(&PHP, 7);
    Parc1.creerAnimal(&Helico, 7);

    Parc1.creerAnimal(&PHP, 8);
    Parc1.creerAnimal(&PHP, 8);
    Parc1.creerAnimal(&PHP, 8);
    Parc1.creerAnimal(&PHP, 8);
    Parc1.creerAnimal(&PHP, 8);
    Parc1.creerAnimal(&PHP, 8);
    Parc1.creerAnimal(&PHP, 8);
    Parc1.creerAnimal(&Helico, 8);

    // On déplace un éléphant pour en avoir 3 d'un côté et 8 de l'autre : revirement de situation

    cout << "Enclos 7 avant déplacement :" << endl;
    cout << Parc1.getEnclos(5) << endl;
    cout << "Enclos 6 avant déplacement :" << endl;
    cout << Parc1.getEnclos(6) << endl;

    Parc1.deplacerAnimal(7,Parc1.getEnclos(5).getAnimal(0).getID(),8);

    cout << "Enclos 7 après déplacement :" << endl;
    cout << Parc1.getEnclos(5) << endl;

    cout << "Enclos 8 après déplacement :" << endl;
    cout << Parc1.getEnclos(6) << endl;

    cout << Parc1;
/** Prochains tets :


- suppression animal sans conséquence
- suppression animal avec conséquence

- déplacement/suppression animaux/enclos inexistants

- modifier enclos

- supprimer enclos contenant des animaux

- fonction conséquences déplacement
**/


// - setters : modifier un animal de chaque espèce et l'afficher
// Je me sert d'un enclos pour Moi
	cout << "************************************" << endl;
    cout << "* VALENTIN *" << endl;
    cout << "************************************" << endl;
	
	Parc Parc2;
	
	Parc2.creerEnclos("Viens", 3, 23);
	cout << Parc2 << endl;
	
	Tigre Helico1(105, 654, "Diego", 1);
    Basque Xabi1(125, 63, 1, 9999999, "Xabi", 3);
    Marmotte Miam1(95, 6544, "Shakira", 5);
	Elephant Pikachu1(1021, 365, 102, "Valentin", 74);
	Aigle Piafabec1(95, 6544, "Poussin", 51);
	Lapin Tuture1(205, "Blanche", "GTi", 205);
	Tortue Toutou1(135, 11, "Invisible", "Faut pas pousser mes mail dans les ordis !", 17);
	Crocodile MoiJaiFaim1(212345, 542, "Trotro Rigolo !", 84);
	Girafe QuiVeutDesTalons1(21, 6854, "Tour Eiffel", 19);
	Loutre PasDeSequelles1(1,4,"Gnééé !", 150);

	Parc2.creerAnimal(&MoiJaiFaim1, 1); // crocodile 
	Parc2.creerAnimal(&Helico1, 1);	    // tigre
	cout << Parc2.getEnclos(0) << endl;
	
	cout << " AVANT MODIFICATION " <<*Parc2.getEnclos(0).getPtrAnimal(1) <<endl;
	int ID = Parc2.getEnclos(0).getPtrAnimal(1)->getID();
	Tigre * t1;
	t1 = new Tigre(12.6465456, 125, "valou", ID);
	Parc2.modifierAnimal(ID,t1);
	cout << "APRES MODIFICAFICATION " << *Parc2.getEnclos(0).getPtrAnimal(1) <<endl;
	
	cout << "AVANT MODIFICATION " <<*Parc2.getEnclos(0).getPtrAnimal(0) <<endl;
	ID = Parc2.getEnclos(0).getPtrAnimal(0)->getID();
	Crocodile * c1;
	c1 = new Crocodile(12, 15, "moi", ID);
	Parc2.modifierAnimal(ID,c1);
	cout << "APRES MODIFICAFICATION " << *Parc2.getEnclos(0).getPtrAnimal(0) <<endl;
	
	Parc2.supprimerAnimal(1);
	Parc2.supprimerAnimal(2);

	cout << Parc2.getEnclos(0) << endl;
	cout << Parc2 << endl;
	
	// On fait les 8 derniers 
	Parc2.creerAnimal(&Xabi1, 1);
	Parc2.creerAnimal(&Miam1, 1);
	Parc2.creerAnimal(&Pikachu1, 1);
	Parc2.creerAnimal(&Piafabec1, 1);
	Parc2.creerAnimal(&Tuture1, 1);
	Parc2.creerAnimal(&Toutou1, 1);
	Parc2.creerAnimal(&QuiVeutDesTalons1, 1);
	Parc2.creerAnimal(&PasDeSequelles1, 1);
	
	cout << Parc2.getEnclos(0) << endl;
	
	cout << " AVANT MODIFICATION " <<*Parc2.getEnclos(0).getPtrAnimal(0) <<endl;
	ID = Parc2.getEnclos(0).getPtrAnimal(0)->getID();
	Basque * b1;
	b1 = new Basque(12.6465456, 125,1,5, "valou", ID);
	Parc2.modifierAnimal(ID,b1);
	cout << "APRES MODIFICAFICATION " << *Parc2.getEnclos(0).getPtrAnimal(0) <<endl;
	
	cout << " AVANT MODIFICATION " <<*Parc2.getEnclos(0).getPtrAnimal(1) <<endl;
	ID = Parc2.getEnclos(0).getPtrAnimal(1)->getID();
	Marmotte * m1;
	m1 = new Marmotte(12.6465456, 125, "valou", ID);
	Parc2.modifierAnimal(ID,m1);
	cout << "APRES MODIFICAFICATION " << *Parc2.getEnclos(0).getPtrAnimal(1) <<endl;
	
	cout << " AVANT MODIFICATION " <<*Parc2.getEnclos(0).getPtrAnimal(2) <<endl;
	ID = Parc2.getEnclos(0).getPtrAnimal(2)->getID();
	Elephant * e1;
	e1 = new Elephant(12.6465456, 125, 12, "valou", ID);
	Parc2.modifierAnimal(ID,e1);
	cout << "APRES MODIFICAFICATION " << *Parc2.getEnclos(0).getPtrAnimal(2) <<endl;
	
	cout << " AVANT MODIFICATION " <<*Parc2.getEnclos(0).getPtrAnimal(3) <<endl;
	ID = Parc2.getEnclos(0).getPtrAnimal(3)->getID();
	Aigle * A1;
	A1 = new Aigle(12.6465456, 125, "valou", ID);
	Parc2.modifierAnimal(ID,A1);
	cout << "APRES MODIFICAFICATION " << *Parc2.getEnclos(0).getPtrAnimal(3) <<endl;
	
	cout << " AVANT MODIFICATION " <<*Parc2.getEnclos(0).getPtrAnimal(4) <<endl;
	ID = Parc2.getEnclos(0).getPtrAnimal(4)->getID();
	Lapin * L1;
	L1 = new Lapin(12, "couleur", "valou", ID);
	Parc2.modifierAnimal(ID,L1);
	cout << "APRES MODIFICAFICATION " << *Parc2.getEnclos(0).getPtrAnimal(4) <<endl;
	
	cout << " AVANT MODIFICATION " <<*Parc2.getEnclos(0).getPtrAnimal(5) <<endl;
	ID = Parc2.getEnclos(0).getPtrAnimal(5)->getID();
	Tortue * T1;
	T1 = new Tortue (12, 125, "couleur", "valou", ID);
	Parc2.modifierAnimal(ID,T1);
	cout << "APRES MODIFICAFICATION " << *Parc2.getEnclos(0).getPtrAnimal(5) <<endl;
	
	cout << " AVANT MODIFICATION " <<*Parc2.getEnclos(0).getPtrAnimal(6) <<endl;
	ID = Parc2.getEnclos(0).getPtrAnimal(6)->getID();
	Girafe * g1;
	g1 = new Girafe(12.6465456, 125, "valou", ID);
	Parc2.modifierAnimal(ID,g1);
	cout << "APRES MODIFICAFICATION " << *Parc2.getEnclos(0).getPtrAnimal(6) <<endl;
	
	cout << " AVANT MODIFICATION " <<*Parc2.getEnclos(0).getPtrAnimal(7) <<endl;
	ID = Parc2.getEnclos(0).getPtrAnimal(7)->getID();
	Loutre * l1;
	l1 = new Loutre(125,12.6465456, "valou", ID);
	Parc2.modifierAnimal(ID,l1);
	cout << "APRES MODIFICAFICATION " << *Parc2.getEnclos(0).getPtrAnimal(7) <<endl;
	
	cout << Parc2.getEnclos(1)<<endl;
	
	
	//tri des listes d'animaux (donc listes suffisament variées) et affichage complet à chaque fois
	cout << "AU DEPART ************************ " << endl;
	for (int i=0; i< Parc2.getNbAnimaux() ; i++){
		cout << Parc2.getAnimal(i)->getNom() << endl;
	}
	cout << "******** TRI ALPHAAAAA ********" << endl;
	Parc2.triAnimauxAlpha();
	
	for (int i=0; i< Parc2.getNbAnimaux() ; i++){
		cout << Parc2.getAnimal(i)->getNom() << endl;
	}
	
	cout << "******** TRI ESPECE ********" << endl;
	Parc2.triAnimauxEspece();
	
	for (int i=0; i< Parc2.getNbAnimaux() ; i++){
		cout << Parc2.getAnimal(i)->getEspece() << endl;
	}
	
	cout << "******** TRI ALPHAAAAA d'un IDENCLOS ********" << endl;
	Parc1.triAnimauxAlpha(6);
	for (int i=0; i< Parc1.getEnclos(4).getOccupation() ; i++){
		cout << Parc1.getEnclos(4).getAnimal(i).getNom() << endl;
	}
	
	cout << "******** TRI ESPECE d'un IDENCLOS ********" << endl;
	Parc1.triAnimauxEspece(6);
	for (int i=0; i< Parc1.getEnclos(4).getOccupation() ; i++){
		cout << Parc1.getEnclos(4).getAnimal(i).getEspece() << endl;
	}
	/*
	cout << "******** TRI ENCLOS OCCUPATION ********" << endl;

	for (int i=0; i< Parc1.getNbAnimaux() ; i++){
		cout << Parc1.getAnimal(i)->getNom() << endl;
	}
	
	cout << "******** TRI ENCLOS CAPACITE ********" << endl;
	
	for (int i=0; i< Parc2.getNbAnimaux() ; i++){
		cout << Parc2.getAnimal(i)->getNom() << endl;
	}
	
	cout << "******** TRI ALPHAAAAA TAUX OCCUPATION ********" << endl;
	
	for (int i=0; i< Parc2.getNbAnimaux() ; i++){
		cout << Parc2.getAnimal(i)->getNom() << endl;
	}
	
	*/
    //cout << *Parc1.getEnclos(2).getPtrAnimal(1) << endl;
   // Parc1.creerAnimal(&Helico, 5);
    //
    //cout << Parc1.getEnclos(0).getAnimal(1) << endl;
   // int a;
   // cin >> a;
    return 0;
}
