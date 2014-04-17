
void afficherTauxRemplissageEnclos(Parc &Parc1){
	for (int i=0; i<Parc1.getNbEnclos(); i++)
		cout << "Parc n " << i << " : " << Parc1.getEnclos(i).getOccupation() << "/" << Parc1.getEnclos(i).getCapacite() << endl;
}

void afficherDetailDeTousLesEnclos(Parc &Parc1){
	for (int i=0; i<Parc1.getNbEnclos(); i++)
		cout << Parc1.getEnclos(i) << end;
}