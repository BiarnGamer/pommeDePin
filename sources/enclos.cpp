#include <iostream>
#include <string>

#include "../entetes/enclos.h"


using namespace std;

  void Enclos::setID(const int & d){
    iID=d;
  }
  
  //Comment s'en débarasser ?
  Enclos::Enclos(){    
  iID=-1;
  iCapacite=0;
  iOccupation=0;
  iTypeEnclos=-1;
  sNom="";
  for (int i=0; i< NB_ESPECES; i++){
	tabComptageEspeces[i].iCodeEspece=i;
	tabComptageEspeces[i].iNombreAnimaux = 0;
    }
  }
  
  
  Enclos::Enclos(const string & nom, const int & type, const int& capacite, const int & ID){
    iOccupation = 0;
    sNom = nom;
    iTypeEnclos = type;
    iCapacite= capacite;
    iID=ID;
    for (int i=0; i< NB_ESPECES; i++){
	tabComptageEspeces[i].iCodeEspece=i;
	tabComptageEspeces[i].iNombreAnimaux = 0;
    }
  }
  
  Enclos::Enclos(const Enclos &e1){
    iOccupation = e1.iOccupation;
    sNom = e1.sNom;
    iTypeEnclos = e1.iTypeEnclos;
    iCapacite= e1.iCapacite;
    iID=e1.iID;
    for (int i=0; i<iOccupation; i++)
      tabAnimaux.ajouter(e1.tabAnimaux[i]);
    for (int i=0; i< NB_ESPECES; i++){
	tabComptageEspeces[i].iCodeEspece=i;
	tabComptageEspeces[i].iNombreAnimaux = e1.tabComptageEspeces[i].iNombreAnimaux;
    }
  }
  
  Enclos::~Enclos(){}
  
  int Enclos::getID() const{
    return iID;
  }
  
  int Enclos::getType() const{
    return iTypeEnclos;
  }
  
  string Enclos::getNom() const{
    return sNom;
  }
  
  int Enclos::getOccupation() const{
    return iOccupation;
  }
  
  void Enclos::setNom(const string &nom){
    sNom=nom;
  }
  
  int Enclos::getCapacite() const{
    return iCapacite;
  }
  
  void Enclos::setTypeEnclos(const int &type){
    iTypeEnclos=type;
  }
  
  Enclos & Enclos::operator=(const Enclos &e1){
    iOccupation = e1.iOccupation;
    sNom = e1.sNom;
    iTypeEnclos = e1.iTypeEnclos;
    iCapacite= e1.iCapacite;
    iID=e1.iID;
    for (int i=0; i<iOccupation; i++)
      tabAnimaux.ajouter(e1.tabAnimaux[i]);
    for (int i=0; i< NB_ESPECES; i++){
	tabComptageEspeces[i].iCodeEspece=i;
	tabComptageEspeces[i].iNombreAnimaux = e1.tabComptageEspeces[i].iNombreAnimaux;
    }
    return *this;
  }
  
  //On sait que les ID sont sémantiquement différent, on pourrait s'arreter à la vérification, mais 
  bool Enclos::operator==(const Enclos &e1) const{
    if(iOccupation == e1.iOccupation
    && sNom == e1.sNom 
    && iTypeEnclos == e1.iTypeEnclos
    && iCapacite== e1.iCapacite
    && iID==e1.iID
    &&   tabAnimaux==e1.tabAnimaux
    ){
      return true;
    }
      else {
	return false;
      }
  }
  
  bool Enclos::operator!=(const Enclos & e1) const{
    if(iOccupation != e1.iOccupation
    || sNom != e1.sNom 
    || iTypeEnclos != e1.iTypeEnclos
    || iCapacite!= e1.iCapacite
    || iID!=e1.iID
    ||   tabAnimaux!=e1.tabAnimaux
    ){
      return true;
    }
      else {
	return false;
      }
  }
  
  Animal Enclos::getAnimal(const int & rang) const{
    return *tabAnimaux[rang];
  }
  
  int Enclos::getNombreAnimaux(const int &codeEspece) const{
    return tabComptageEspeces[codeEspece].iNombreAnimaux;
  }
  
  ostream & operator<<(ostream & flot, const Enclos & e) {
      flot << "N° Enclos : " << e.getID() << endl;
      flot << "Nom : " << e.getNom() << endl;
      switch(e.getType()) {
	case 1:
	  flot << "Type : enclos" << endl;
	  break;
	case 2:
	  flot << "Type : bassin" << endl;
	  break;
	case 3:
	  flot << "Type : cage" << endl;
	  break;
	default:
	  flot << "Type : inconnu" << endl;
      }
      
      flot << "Capacité : " << e.getCapacite() << endl;
      flot << "Occupation : " << e.getOccupation() << endl;
      
      return flot;
  }