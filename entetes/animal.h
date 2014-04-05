#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using namespace std;

class Animal{
    private:
    int iID;
    bool saitVoler;
    bool saitNager;
    bool estCarnivore;
    string sNom;

    void setID(const int i);
    // RAJOUTER UN TABLEAU DE CHAINE ALIMENTAIRE

    public:
    Animal();
    Animal(const string & nom, const bool vole, const bool nage, const bool carnivore, const int ID = -1);
    Animal(const Animal &);
    virtual ~Animal();

    int getID() const;
    bool getSaitNager() const;
    bool getSaitVoler() const;
    bool getEstCarnivore() const;
    string getNom() const;

    void setSaitNager(const bool nage);
    void setSaitVoler(const bool vole);
    void setEstCarnivore(const bool carnivore);
    void setNom(const string & n);

    virtual Animal & operator=(const Animal &);
    virtual bool operator==(const Animal &);
    virtual bool operator!=(const Animal &);

    friend ostream & operator<<(ostream &, const Animal &);
};

class Tigre: public Animal {
    private:
    float fHauteurGarot;
    int iNbGazellesCroquees;

    public:
    Tigre();
    Tigre(const float fGarot, const int iNbVict, const string & nom, const bool vole, const bool nage, const bool carnivore, const int ID = -1);
    Tigre(const Tigre &);
    ~Tigre();

    float getGarot() const;
    int getNbVictimes() const;

    void setGarot(const float);
    void setNbVictimes(const int);

    Tigre & operator=(const Tigre &);
    bool operator==(const Tigre &);
    bool operator!=(const Tigre &);

    friend ostream & operator<<(ostream &, const Tigre &);
};


class Basque: public Animal {
    private:
    float fLargeurBeret;
    float fTempsDeCuisson;
    int iNbPartiesPeloteGagnees;
    int iNbRicardBus;

    public:
    Basque();
    Basque(const float flBeret, const float fCuisson, const int iNbVictoires, const int iNbRicard, const string & nom, const bool vole, const bool nage, const bool carnivore, const int ID = -1);
    Basque(const Basque &);
    ~Basque();

    float getLargeurBeret() const;
    float getTempsCuisson() const;
    int getNbVictoires() const;
    int getNbRicard() const;

    void setLargeurBeret(const float);
    void setTempsCuisson(const float);
    void setNbVictoires(const int);
    void setNbRicard(const int);

    Basque & operator=(const Basque &);
    bool operator==(const Basque &);
    bool operator!=(const Basque &);

    friend ostream & operator<<(ostream &, const Basque &);
};

class Marmotte: public Animal {
    private:
    float fTaille;
    int iNbTablettesChocolatEmballees;

    public:
    Marmotte();
    Marmotte(const float taille, const int iNbTablettes, const string & nom, const bool vole, const bool nage, const bool carnivore, const int ID = -1);
    Marmotte(const Marmotte &);
    ~Marmotte();

    float getTaille() const;
    int getNbTabChocolat() const;

    void setTaille(const float);
    void setNbTabChocolat(const int);

    Marmotte & operator=(const Marmotte &);
    bool operator==(const Marmotte &);
    bool operator!=(const Marmotte &);

    friend ostream & operator<<(ostream &, const Marmotte &);
};

class Elephant: public Animal {
    private:
    float fPoids;
    float fLongueurTrompe;
    int iNbBraconniersEmpales;

    public:
    Elephant();
    Elephant(const float poids, const float lTrompe, const int iNbVict, const string & nom, const bool vole, const bool nage, const bool carnivore, const int ID = -1);
    Elephant(const Elephant &);
    ~Elephant();

    float getPoids() const;
    float getLongTrompe() const;
    int getNbVictimes() const;

    void setPoids(const float);
    void setLongTrompe(const float);
    void setNbVictimes(const int);

    Elephant & operator=(const Elephant &);
    bool operator==(const Elephant &);
    bool operator!=(const Elephant &);

    friend ostream & operator<<(ostream &, const Elephant &);
};

class Aigle: public Animal {
    private:
    float fLongueurBec;
    int iNbLoopings;

    public:
    Aigle();
    Aigle(const float fLBec, const int iNbLoopings, const string & nom, const bool vole, const bool nage, const bool carnivore, const int ID = -1);
    Aigle(const Aigle &);
    ~Aigle();

    float getLongueurBec() const;
    int getNbLoopings() const;

    void setLongueurBec(const float);
    void setNbLoopings(const int);

    Aigle & operator=(const Aigle &);
    bool operator==(const Aigle &);
    bool operator!=(const Aigle &);

    friend ostream & operator<<(ostream &, const Aigle &);
};
#endif
