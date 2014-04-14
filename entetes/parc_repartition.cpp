


/**************************************************/
/******* VALENTIN     *****************************/
   void creerEnclos(const Enclos & e);
   void supprimerEnclos(const int ID);
   void mofidierEnclos(const int IDEnclosAModifier, const string nom);
   int rechercherEnclos(const int ID) const;
   void ajouterAnimalDansEnclos(Animal * animalAPlacer, Enclos * enclosDAccueil);
   void enleverAnimalEnclos(Animal * animalAEnlever, Enclos * enclos);
   void relationsProiesPredateurs(const int iCodePredateur, const int iNbPredateurs, const int iCodeProie, const int iNbProies);
   void deplacerAnimal(const int IDEnclosDepart, const int IDAnimal, const int IDEnclosArrivee);
   void consequenceDeplacementAnimal(const int iCodeEspece, const int IDEnclos) const;
/**************************************************/

/**************************************************/
/******* JB           *****************************/
   void creerAnimal(Animal const * a, const int IDEnclosAccueil);
   void creerAnimal(Animal const * a, const Enclos enclosDAccueil);
   void supprimerAnimal(const int ID);
   void modifierAnimal(const int IDAnimalAModifier, Animal const * nouvelAnimal);
   int rechercherAnimal(const int ID) const;
   void triAnimauxAlpha();
   void triAnimauxEspece();
   void triAnimauxAlpha(const int IDEnclos);
   void triAnimauxEspece(const int IDEnclos);
   void triEnclosAlpha();
   void triEnclosOccupation();
   void triEnclosCapacite();
   void triEnclosTauxOccupation();
/**************************************************/








   friend ostream & operator<<(ostream &, const Parc &);
};
