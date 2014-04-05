#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
 
class Animal{
    private:
    int iID;
    bool saitVoler;
    bool saiNager;
    bool estCarnivore;
    string sNom;

    void setID(const int i);
    // RAJOUTER UN TABLEAU DE CHAINE ALIMENTAIRE

    public:
    Animal();
    Animal(const string & nom, const bool v, const bool n, const bool c, const string ID = -1);
    Animal(const Animal &);
    ~Animal();

    int getID() const;
    bool getSaitNager() const;
    bool getSaitVoler() const;
    string getNom() const;

    void setSaitNager(const bool b);
    void setSaitVoler(const bool b);
    void setNom(const string & n);

    Animal & operator=(const Animal &);
    bool operator==(const Aninmal &);
    bool operator!=(const Aninmal &);

    friend ostream & operator<<(const ostream &, const Animal &);
};

class Tigre: public Animal {
    private:
    float fHauteurGarot;
    int iNbGazellesCroques;

    public:
    Tigre();
    Tigre(const float f, const int iNbVict, const string & nom, const bool v, const bool n, const bool c, const string ID = -1);
    Tigre(const Tigre &);
    ~Tigre();

    float getGarot() const;
    int getNbVictimes() const;

    void setGarot(const float);
    void setNbVictimes(const int);

    Tigre & operator=(const Tigre &);
    bool operator==(const Tigre &);
    bool operator!=(const Tigre &);

    friend ostream & operator<<(const ostream &, const Tigre &);
};

#endif
