#include <iostream>
#include <string>

#include "../entetes/enclos.h"

  void setID(int & d){
    iID=d;
  }
  
  //Comment s'en débarasser ?
  Enclos(){    
  iID=-1;
  iCapacite=0;
  iOccupation=0;
  iTypeEnclos=-1;
  sNom="";
  for (int i=0; i< NB_ESPECES; i++){
	tabComptageEspeces[i].iCodeEspece=i;
	iNombreAnimaux = 0;
    }
  }
  
  
  Enclos(string & nom, int & type, int& capacite, int & ID){
    iOccupation = 0;
    sNom = nom;
    iTypeEnclos = type;
    iCapacite= capacite;
    iID=ID;
    for (int i=0; i< NB_ESPECES; i++){
	tabComptageEspeces[i].iCodeEspece=i;
	iNombreAnimaux = 0;
    }
  }
  
  Enclos(Enclos &e1){
    iOccupation = e1.iOccupation;
    sNom = e1.sNom;
    iTypeEnclos = e1.iTypeEnclos;
    iCapacite= e1.iCapacite;
    iID=e1.iID;
    for (int i=0; i<iOccupation; i++)
      tabAnimaux[i]=e1.tabAnimaux[i];
    for (int i=0; i< NB_ESPECES; i++){
	tabComptageEspeces[i].iCodeEspece=i;
	tabComptageEspeces[i].iNombreAnimaux = e1.iNombreAnimaux;
    }
  }
  
  ~Enclos(){}
  
  int getID() const{
    return iID;
  }
  
  int getType() const{
    return iTypeEnclos;
  }
  
  string getNom() const{
    return sNom;
  }
  
  int getOccupation() const{
    return iOccupation;
  }
  
  void setNom(string &nom){
    sNom=nom;
  }
  
  int getCapacite() const{
    return iCapacite;
  }
  
  void setTypeEnclos(int &type){
    iTypeEnclos=type;
  }
  
  Enclos & operator=(Enclos &e1){
    iOccupation = e1.iOccupation;
    sNom = e1.sNom;
    iTypeEnclos = e1.iTypeEnclos;
    iCapacite= e1.iCapacite;
    iID=e1.iID;
    for (int i=0; i<iOccupation; i++)
      tabAnimaux[i]=e1.tabAnimaux[i];
    for (int i=0; i< NB_ESPECES; i++){
	tabComptageEspeces[i].iCodeEspece=i;
	tabComptageEspeces[i].iNombreAnimaux = e1.iNombreAnimaux;
    }
    return *this;
  }
  
  //On sait que les ID sont sémantiquement différent, on pourrait s'arreter à la vérification, mais 
  bool operator==(Enclos &e1) const{
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
  
  bool operator!=(Enclos &) const{
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
  
  Animal getAnimal(int & rang) const{
    return *tabAnimaux[rang];
  }
  
  int getNombreAnimaux(int &codeEspece) const{
    return tabComptageEspeces[codeEspece].iNombreAnimaux;
  }
  