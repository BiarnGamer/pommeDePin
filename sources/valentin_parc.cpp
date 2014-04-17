
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

