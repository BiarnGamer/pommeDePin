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
  
  void setSaitNager(bool &){
    
  }
  
  void setSaitVoler(bool &){
    
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
  
  Animal getAnimal(int &){
    
  }
  
  int getNbAnimal(int &){
    
  }
  
  int getNombreAnimaux(int &){
    
  }
  