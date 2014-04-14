/************************************************/
/**                 VALENTIN                    */
/************************************************/

void Parc::creerEnclos(const Enclos & e){
  // On crée l'enclos qui appartient à la classe
  Enclos e1(e.getNom(), e.getType(), e.getCapacite(), iIDEnclos);
  iIDEnclos++;
  //On ajoute l'enclos dans notre classe
  listeEnclos[iNbEnclos].ajouter(*e1);
  iNbEnclos++;
}

int Parc::rechercherEnclos(const int ID) const{
  bool trouver=false;
  while ( !trouver && i < getNbEnclos(){
   if (listeEnclos[i].getIDEnclos() == ID){
     trouver = true;
     return i;
   }
   else return -1;
  }
}

void Parc::supprimerEnclos(const int ID){
  if (rechercherEnclos(ID) == -1)
    cout >> "Cet ID d'enclos n'existe pas." << endl;
  else 
    listeEnclos.enlever(listeEnclos[rechercherEnclos(ID)]);
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
   int iNbProiesAnimal = tabProies[iCodePredateur].getNbElem();
   while(i<iNbProiesAnimal && !trouve){
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
      if(iNbProies < tabProies[iCodePredateur][i].iSeuil1) {
         // on veut 75% de chances de le manger
	// 2 il ne se passe rien, 1 il le mange
         return (resultatRand > 75) ? 2 : 1;
      }
      // Cas où tout est possible
      else if(iNbProies < tabProies[iCodePredateur][i].iSeuil2) {
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

void Parc::deplacerAnimal(const int IDEnclosDepart, const int IDAnimal, const int IDEnclosArrivee){
  
}

void Parc::consequenceDeplacementAnimal(const int iCodeEspece, const int IDEnclos) const{
  
}