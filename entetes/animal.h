#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

#define INDEFINI -1
#define GIRAFE 0
#define TIGRE 1
#define BASQUE 2
#define MARMOTTE 3
#define ELEPHANT 4
#define AIGLE 5
#define TORTUE 6
#define LOUTRE 7
#define CROCODILE 8
#define LAPIN 9

#define NB_ESPECES 10

using namespace std;

class Animal{
    private:
    int iID;
    bool saitVoler;
    bool saitNager;
    int iEspece;
    string sNom;

    void setID(const int i);
    // On met les deux setters suivant en privée car on ne veut pas que la classe fille puisse modifier la valeur. Si une espèce ne sait pas nager, il est illogique de pouvoir mettre la valeur à vrai pour un animal de cette espèce. Ainsi, la valeur ne peut être modifiée que lors de l'instanciation de l'objet car seul le constructeur d'Animal pourra appeler ces deux setters.
    void setSaitNager(const bool nage);
    void setSaitVoler(const bool v1ole);

    public:
    Animal();
    Animal(const string & nom, const int & espece, const bool vole, const bool nage, const int ID = -1);
    Animal(const Animal &);
    virtual ~Animal();

    int getID() const;
    bool getSaitNager() const;
    bool getSaitVoler() const;
    string getNom() const;
    int getEspece() const;

    void setNom(const string & n);
    void setEspece(const int & e);

    virtual Animal & operator=(const Animal &);
    virtual bool operator==(const Animal &) const;
    virtual bool operator!=(const Animal &) const;

    friend ostream & operator<<(ostream &, const Animal &);
};

class Tigre: public Animal {
    private:
    float fHauteurGarot;
    int iNbGazellesCroquees;

    public:
    Tigre();
    Tigre(const float fGarot, const int iNbVict, const string & nom, const int ID = -1);
    Tigre(const Tigre &);
    ~Tigre();

    float getGarot() const;
    int getNbVictimes() const;

    void setGarot(const float);
    void setNbVictimes(const int);

    Tigre & operator=(const Tigre &);
    bool operator==(const Tigre &) const;
    bool operator!=(const Tigre &) const;

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
    Basque(const float flBeret, const float fCuisson, const int iNbVictoires, const int iNbRicard, const string & nom, const int ID = -1);
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
    bool operator==(const Basque &) const;
    bool operator!=(const Basque &) const;

    friend ostream & operator<<(ostream &, const Basque &);
};

class Marmotte: public Animal {
    private:
    float fTaille;
    int iNbTablettesChocolatEmballees;

    public:
    Marmotte();
    Marmotte(const float taille, const int iNbTablettes, const string & nom, const int ID = -1);
    Marmotte(const Marmotte &);
    ~Marmotte();

    float getTaille() const;
    int getNbTabChocolat() const;

    void setTaille(const float);
    void setNbTabChocolat(const int);

    Marmotte & operator=(const Marmotte &);
    bool operator==(const Marmotte &) const;
    bool operator!=(const Marmotte &) const;

    friend ostream & operator<<(ostream &, const Marmotte &);
};

class Elephant: public Animal {
    private:
    float fPoids;
    float fLongueurTrompe;
    int iNbBraconniersEmpales;

    public:
    Elephant();
    Elephant(const float poids, const float lTrompe, const int iNbVict, const string & nom, const int ID = -1);
    Elephant(const Elephant &);
    ~Elephant();

    float getPoids() const;
    float getLongTrompe() const;
    int getNbVictimes() const;

    void setPoids(const float);
    void setLongTrompe(const float);
    void setNbVictimes(const int);

    Elephant & operator=(const Elephant &);
    bool operator==(const Elephant &) const;
    bool operator!=(const Elephant &) const;

    friend ostream & operator<<(ostream &, const Elephant &);
};

class Aigle: public Animal {
    private:
    float fLongueurBec;
    int iNbLoopings;

    public:
    Aigle();
    Aigle(const float fLBec, const int iNbLoopings, const string & nom, const int ID = -1);
    Aigle(const Aigle &);
    ~Aigle();

    float getLongueurBec() const;
    int getNbLoopings() const;

    void setLongueurBec(const float);
    void setNbLoopings(const int);

    Aigle & operator=(const Aigle &);
    bool operator==(const Aigle &) const;
    bool operator!=(const Aigle &) const;

    friend ostream & operator<<(ostream &, const Aigle &);
};

class Tortue: public Animal {
    private:
    int iVitesseMax;
    int iAge;
    string sCouleur;

    public:
    Tortue();
    Tortue(const int iVitesseMax, const int iAge, const string sCouleur, const string & nom, const int ID = -1);
    Tortue(const Tortue &);
    ~Tortue();

    int getVitesseMax() const;
    int getAge() const;
    string getCouleur() const;

    void setVitesseMax(const int);
    void setAge(const int);
    void setCouleur(const string);

    Tortue & operator=(const Tortue &);
    bool operator==(const Tortue &) const;
    bool operator!=(const Tortue &) const;

    friend ostream & operator<<(ostream &, const Tortue &);
};

class Loutre: public Animal {
    private:
    int iNbAmis;
    float fTaille;

    public:
    Loutre();
    Loutre(const int iNbAmis, const float fTaille, const string & nom, const int ID = -1);
    Loutre(const Loutre &);
    ~Loutre();

    int getNbAmis() const;
    float getTaille() const;

    void setTaille(const float);
    void setNbAmis(const int);

    Loutre & operator=(const Loutre &);
    bool operator==(const Loutre &) const;
    bool operator!=(const Loutre &) const;

    friend ostream & operator<<(ostream &, const Loutre &);
};

class Crocodile: public Animal {
    private:
    int iEnfantMange;
    int iNbDents;

    public:
    Crocodile();
    Crocodile(const int iEnfantMange, const int iNbDents, const string & nom, const int ID = -1);
    Crocodile(const Crocodile &);
    ~Crocodile();

    int getEnfantMange() const;
    int getNbDents() const;

    void setEnfantMange(const int);
    void setNbDents(const int);

    Crocodile & operator=(const Crocodile &);
    bool operator==(const Crocodile &) const;
    bool operator!=(const Crocodile &) const;

    friend ostream & operator<<(ostream &, const Crocodile &);
};

class Lapin: public Animal {
    private:
    int iNbCarotteMange;
    string sCouleur;

    public:
    Lapin();
    Lapin(const int iNbCarotteMange, const string sCouleur, const string & nom, const int ID = -1);
    Lapin(const Lapin &);
    ~Lapin();

    int getNbCarotteMange() const;
    string getCouleur() const;

    void setNbCarotteMange(const int);
    void setCouleur(const string);

    Lapin & operator=(const Lapin &);
    bool operator==(const Lapin &) const;
    bool operator!=(const Lapin &) const;

    friend ostream & operator<<(ostream &, const Lapin &);
};

class Girafe: public Animal {
    private:
    float fTaille;
    int iNbTaches;

    public:
    Girafe();
    Girafe(const float fTaille, const int iNbTaches, const string & nom, const int ID = -1);
    Girafe(const Girafe &);
    ~Girafe();

    float getTaille() const;
    int getNbTaches() const;

    void setTaille(const float);
    void setNbTaches(const int);

    Girafe & operator=(const Girafe &);
    bool operator==(const Girafe &) const;
    bool operator!=(const Girafe &) const;

    friend ostream & operator<<(ostream &, const Girafe &);
};
#endif
