// peut etre mettre directement animal * a1
int Parc::consequenceDeplacementAnimal(Animal const * a1, const int IDEnclos) const {
    /* 	Type Invalide (enclos inexistant et type faux ) : -1
    	Tout est ok : 0
    	Si l'enclos est plein : 1
    	Animal se noit <=> ! saitNager && listeEnclos[iRangEnclos].getType() == BASSIN      : 2
    	Animal s'envole <=> saitVoler && (listeEnclos[iRangEnclos].getType() == ENCLOS || listeEnclos[iRangEnclos].getType() == BASSIN) (car le bassin n'est pas fermé) : 3
    	Animal possède des prédateurs dans l'enclos : 4
    	Animal possède des proies dans l'enclos : 5
    	Animal possède des proies et des prédateurs dans l'enclos : 6
    */
    int iRangEnclos = rechercherEnclos(IDEnclos);
	int i=0;
	bool YaTilDesProies = false;
	bool YaTilDesPredateurs =false;
	int nbProiesDeAnimal = tabProies[a1->getEspece()].getNbElem;
	int iEspeceA = a1->getEspece();
	int nbElemTabProies = tabProies.getNbElem();
	int nbElem;
	
	if (iRangEnclos == -1)
		return -1;
	else {
		if (listeEnclos[iRangEnclos]->getOccupation() == listeEnclos[iRangEnclos]->getCapacite() )
			return 1;
		else{
			if (a1->getSaitVoler && (listeEnclos[iRangEnclos].getType() == ENCLOS || listeEnclos[iRangEnclos].getType() == BASSIN) )
				return 3;
			else{
				if (!a1->getSaitNager() && listeEnclos[iRangEnclos].getType() == BASSIN)
					return 2;
				else {
					// Pour chacun des animaux dans l'enclos, regarder si l'animal a1 est une proie et si a1 possède des proies présentes
					while (i < listeEnclos[iRangEnclos].getOccupation() && !YaTilDesPredateurs){
						// je cherche dans quels tableaux a1 est une proie et je vérifie si l'animal est présent, si oui bool = true sinon on continue jusqu'a bool = true ou fin du tableau
						for (int j = 0; j < nbElemTabProies; j++){
							nbElem = tabProies[j].getNbElem();
							for(int k = 0; k < nbElem; k++){
								if (tabProies[j][k].iCodeProie == a1.getEspece()){
									// On regarde maintenant si le prédateur est présent dans l'enclos
									if (listeEnclos[iRangEnclos].getNombreAnimaux(tabProies[j][k].iCodeProie) != 0)
										YaTilDesPredateurs = true;
								}
							}
						}
						i++;
					}
					// maintenant je cherche donc si y'a des proies de notre animal
					for (int j = 0; j  < nbProiesDeAnimal; j++){
						// pour chaque proies, on regarde si elle est présente dans le tableau
						if (listeEnclos[iRangEnclos].getNombreAnimaux(tabProies[iEspeceA][j].iCodeEspece) != 0)
							YaTilDesProies = true;
					}
					// maintenant on sait si y'a des proies et si y'a des prédateurs
					if (YaTilDesPredateurs && YaTilDesProies)
						return 6;
					else
						if (YaTilDesPredateurs)
							return 4;
						else return 5;
				}
			}
		}
	}
}

void Parc::deplacerAnimal(const int IDEnclosDepart, const int IDAnimal, const int IDEnclosArrivee) {
    // Je récupère l'enclos de départ (recherche) ainsi que celui d'arriver
    // Je récupère l'animal dans l'enclos de départ (pointeur)
    // Etant donné que ce sont des pointeurs et que l'animal à déjà été crée par la classe Parc il suffira d'ajouter le pointeur sur le nouvel enclos
    // puis de supprimer dans l'ancien enclos. Pour cela les fonctions des sets suffisent.
    int iRangEnclosDepart = rechercherEnclos(IDEnclosDepart); //listeEnclos[iRangEnclosDepart]
    int iRangEnclosArrivee = rechercherEnclos(IDEnclosArrivee);
    // Il faut récupérér l'animal avec cet id dans listeanimaux car c'est le meme que dans l'enclos

    //int iRangAnimal = rechercheAnimalEnclos(IDAnimal); // listeEnclos[iRangEnclos].tabAnimaux[iRangAnimal] est l'animal considéré

    if (listeEnclos[iRangEnclosArrivee].getOccupation() < listeEnclos[iRangEnclosArrivee].getCapacite()){
        listeEnclos[iRangEnclosArrivee].ajouterAnimalDansEnclos(listeEnclos[iRangEnclosDepart].getElem(iRangAnimal));
		listeEnclos[iRangEnclosDepart].supprimerAnimal(listeEnclos[iRangEnclosDepart].getElem(iRangAnimal));
	}
    // Par la suite on gère les conséquences des déplacements (erreur de type = se noie etc ou bien prédateurs etcs)   ATTENTION : On gère les conséquences dans l'enclos de départ ET celui d'arrivé !

}

