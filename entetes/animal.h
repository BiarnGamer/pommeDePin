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

    protected:
    // On met les deux setters suivant en protected car on ne veut pas que la classe fille puisse modifier la valeur. Si une espèce ne sait pas nager, il est illogique de pouvoir mettre la valeur à vrai pour un animal de cette espèce. Ainsi, la valeur ne peut être modifiée que lors de l'instanciation de l'objet car seul le constructeur d'Animal pourra appeler ces deux setters.
    // Il en va de même pour l'espèce.
    void setSaitNager(const bool nage);
    void setSaitVoler(const bool vole);
    void setEspece(const int & e);

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

    virtual Animal & operator=(const Animal &);
    virtual bool operator==(const Animal &) const;
    virtual bool operator!=(const Animal &) const;

    friend ostream & operator<<(ostream &, const Animal &);

    virtual void affiche(ostream & flot) const;

    // Fonctions virtuelles pour héritage ; obligatoire pour utiliser sans souci le pointeur sur animal
   /* virtual float getTaille(){}
    virtual int getNbTaches(){}
    virtual int getNbVictimes(){}
    virtual float getLargeurBeret(){}
    virtual int getTempsCuisson(){}
    virtual int getNbRicardBus(){}
    virtual int getNbVictoires(){}
    virtual int getNbTabChocolat(){}
    virtual float getPoids(){}
    virtual float getLongTrompe(){}
    virtual float getLongueurBec(){}
    virtual int getNbLoopings(){}
    virtual int getVitesseMax(){}
    virtual int getAge(){}
    virtual string getCouleur(){}
    virtual int getNbAmis(){}
    virtual int getEnfantMange(){}
    virtual int getNbDents(){}
    virtual int getNbCarotteMange(){}

    virtual void setTaille(const float){}
    virtual void setNbTaches(const int){}
    virtual void setNbVictimes(const int){}
    virtual void setLargeurBeret(const float){}
    virtual void setTempsCuisson(const float){}
    virtual void setNbRicardBus(const int){}
    virtual void setNbVictoires(const int){}
    virtual void setNbTabChocolat(const int){}
    virtual void setPoids(const float){}
    virtual void setLongTrompe(const float){}
    virtual void setLongueurBec(const float){}
    virtual void setNbLoopings(const int){}
    virtual void setVitesseMax(const int){}
    virtual void setAge(const int){}
    virtual void setCouleur(const string &){}
    virtual void setNbAmis(const int){}
    virtual void setEnfantMange(const int){}
    virtual void setNbDents(const int){}
    virtual void setNbCarotteMange(const int){}*/
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
    void affiche(ostream & flot) const;
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
    void affiche(ostream & flot) const;
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
    void affiche(ostream & flot) const;
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
    void affiche(ostream & flot) const;
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
    void affiche(ostream & flot) const;
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
    void affiche(ostream & flot) const;
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
    void affiche(ostream & flot) const;
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
    void affiche(ostream & flot) const;
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
    void affiche(ostream & flot) const;
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
    void affiche(ostream & flot) const;
};
#endif
