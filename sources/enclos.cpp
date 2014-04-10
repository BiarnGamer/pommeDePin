#include <iostream>
#include <string>

#include "../entetes/enclos.h"

  void setID(int & d){
    iID=d;
  }
  
  Enclos():iID(-1),({
  }
  
  Enclos(string &, int & type, int& capacite, int & ID){
    
  }
  
  Enclos(Enclos &){
    
  }
  
  ~Enclos(){
    
  }
  
  int getID(){
    return iID;
  }
  
  int getType(){
    return iTypeEnclos;
  }
  
  string getNom(){
    return sNom;
  }
  
  int getOccupation(){
    return iOccupation;
  }
  
  void setNom(string &){
    
  }
  
  void setEspece(int &){
    
  }
  
  Enclos & operator=(Enclos &){
    
  }
  
  bool operator==(Enclos &){
    
  }
  
  bool operator!=(Enclos &){
    
  }
  
  Animal getAnimal(int & rang){
    return tabAnimaux[rang];
  }
  
  int getNombreAnimaux(int &codeEspece){
    return tabComptageEspeces[codeEspece].iNombreAnimaux;
  }
  