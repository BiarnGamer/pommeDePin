/************************************************/
/**                 VALENTIN                    */
/************************************************/

void Parc::creerEnclos(const string & nom, const int type, cons int capacite){
  // On crée l'enclos qui appartient à la classe car elle seule doit pouvoir le modifier
	Enclos * e1;
  e1 = new Enclos(nom, type, capacite, iIDEnclos);
  iIDEnclos++;
  //On ajoute l'enclos dans notre classe
  listeEnclos[iNbEnclos].ajouter(e1);
  iNbEnclos++;
}

int Parc::rechercherEnclos(const int ID) const{
  bool trouver=false;
  int i =0;
  while ( !trouver && i < getNbEnclos()){
   if (listeEnclos[i].getIDEnclos() == ID){
     trouver = true;
     return i;
   }
   else return -1;
  }
}

void Parc::supprimerEnclos(const int ID){
 int rang = rechercherEnclos(ID);
  if (rang == -1)
    cout >> "Cet ID d'enclos n'existe pas." << endl;
  else 
    listeEnclos.enlever(listeEnclos[rang]);
}

void Parc::mofidierEnclos(const int IDEnclosAModifier, const string nom){
  listeEnclos[rechercherEnclos(IDEnclosAModifier)]->setNom(nom);
}

void Parc::ajouterAnimalDansEnclos(Animal * animalAPlacer, Enclos * enclosDAccueil){
  enclosDAccueil->ajoutAnimal(animalAPlacer);
}

void Parc::enleverAnimalEnclos(Animal * animalAEnlever, Enclos * enclos){
  enclos->supprimerAnimal(animalAEnlever);
}

void Parc::relationsProiesPredateurs(const int iCodePredateur, const int iNbPredateurs, const int iCodeProie, const int iNbProies){
  // Retourne 1(les prédateurs mangent les proies) 2(rien ne se passe) ou 3(les proies se défendent et tues les prédateurs)
   // On vérifie que le prédateur et la proie donnés sont liés
   int resultatRand;
   bool trouve = false;
   int i=0;
   // on récupère le nombre de proies que peut tuer le prédateur
   int iNbProiesAnimal = tabProies[iCodePredateur].getNbElem();
   while(i<iNbProiesAnimal && !trouve){
	   // on regarde maintenant si une de ses proies correspond
      if(tabProies[iCodePredateur][i].iCodeProie == iCodeProie) {
         trouve = true;
      }
      else {
         i++;
      }
   }

   // Si ce n'est pas le cas ou si une espèce est en quantité nulle, on renvoie 2 pour dire qu'il ne se passe rien
   if(!trouve || iNbPredateurs==0 || iNbProies==0){
      return 2;
   }
   else {
      // On prend un nombre aléatoire dans [0; 100[
      srand(time(NULL));
      resultatRand = rand()%(100);
      // Cas où le prédateur mange la proie
      if(iNbProies < tabProies[iCodePredateur][i].iSeuil1*iNbPredateurs) {
         // on veut 75% de chances de le manger
	// 2 il ne se passe rien, 1 il le mange
         return (resultatRand > 75) ? 2 : 1;
      }
      // Cas où tout est possible
      else if(iNbProies < tabProies[iCodePredateur][i].iSeuil2*iNbPredateurs) {
         // 50% chances de sympatiser, 25% pour les deux autres cas
         if(resultatRand < 25) {
            return 1;
         }
         else if(resultatRand <= 75) {
            return 2;
         }
         else {
            return 3;
         }
      }
      // Cas où les proies se défendent
      else {
         // on veut 75% de chances de le tuer
         return (resultatRand > 75) ? 2 : 3;
      }
   }
}

// J'ai besoin de la recherche des animaux dans mon enclo afin de trouver son rang dans le tabAnimaux de l'enclo considéré.
int Parc::rechercheAnimalEnclos(const int IDEnclos, const int IDAnimal)){
	int iRangEnclos = rechercherEnclos(IDEnclos);
	bool trouver = false;
	int i=0;
	int iNbAnimaux = listeEnclos[iRangEnclos].getOccupation();
	// presque pas obligatoire de laisser la condition !trouver car s'il le trouve alors return stopera la boucle, mais on fait attention on le laisse quand même
	while (!trouver && i < iNbAnimaux){
		if (listeEnclos[iRangEnclos].tabAnimaux[i].getID == IDAnimal)
			return i;
		else 
			i++;
	}
	return -1;
}

// peut etre mettre directement animal * a1
void Parc::consequenceDeplacementAnimal(const int iCodeEspece, const int IDEnclos) const{
	/* 	Type Invalide (enclos inexistant et type faux ) : -1
		Tout est ok : 0
		Si l'enclos est plein : 1
		Animal se noit <=> ! saitNager && listeEnclos[iRangEnclos].getType() == BASSIN && ! saitVoler     (car s'il sait voler il s'échappe)        : 2
		Animal s'envole <=> saitVoler && listeEnclos[iRangEnclos].getType() == ENCLOS || listeEnclos[iRangEnclos].getType() == BASSIN (car le bassin n'est pas fermé) : 3
		Animal possède des prédateurs dans l'enclos : 4
		Animal possède des proies dans l'enclos : 5
		Animal possède des proies et des prédateurs dans l'enclos : 6
	*/
	int iRangEnclos = rechercherEnclos(IDEnclos);
  
}

void Parc::deplacerAnimal(const int IDEnclosDepart, const int IDAnimal, const int IDEnclosArrivee){
  // Je récupère l'enclos de départ (recherche) ainsi que celui d'arriver
	// Je récupère l'animal dans l'enclos de départ (pointeur)
	// Etant donné que ce sont des pointeurs et que l'animal à déjà été crée par la classe Parc il suffira d'ajouter le pointeur sur le nouvel enclos 
	// puis de supprimer dans l'ancien enclos. Pour cela les fonctions des sets suffisent.
	int iRangEnclosDepart = rechercherEnclos(IDEnclosDepart); //listeEnclos[iRangEnclosDepart]
	int iRangEnclosArrivee = rechercherEnclos(IDEnclosArrivee);
	// Il faut récupérér l'animal avec cet id dans listeanimaux car c'est le meme que dans l'enclos
	
	//int iRangAnimal = rechercheAnimalEnclos(IDAnimal); // listeEnclos[iRangEnclos].tabAnimaux[iRangAnimal] est l'animal considéré
	
	if (listeEnclos[iRangEnclosArrivee].getOccupation() < listeEnclos[iRangEnclosArrivee].getCapacite())
		listeEnclos[iRangEnclosArrivee].ajouterAnimal(listeEnclos[iRangEnclosDepart].getElem(iRangAnimal)); 
	// Par la suite on gère les conséquences des déplacements (erreur de type = se noie etc ou bien prédateurs etcs)   ATTENTION : On gère les conséquences dans l'enclos de départ ET celui d'arrivé !
	
}

