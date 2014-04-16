#ifndef SET_H
#define SET_H

#include <iostream>
#include <cstring> // pour le memcpy
using namespace std;

template <class T> class Set {
private:
    int iNbElem;
    T * tab;

public:
    Set(); // crée un set vide
    Set(const Set &);
    ~Set();

    Set& operator=(const Set &);

    void ajouter(const T &);
    void enlever(const T &);
    // Échange la position de deux éléments dans le Set
    void intervertir(const T &, const T &);

    bool appartient(const T &) const;
    bool estVide() const;
    bool inclut(const Set &) const;
    bool operator==(const Set &) const;
    bool operator!=(const Set &) const;

    int getNbElem() const;
    T getElem(int i) const;

    T operator[](const int i) const;
};

template <class T> Set<T>::Set() {
    iNbElem = 0;
    tab = new T [0];
}

template <class T> Set<T>::~Set() {
    iNbElem = 0;
    delete [] tab;
}

template <class T> Set<T>::Set(const Set & s1) {
    iNbElem = s1.iNbElem;
    tab = new T [iNbElem];
    /*for(int i=0; i<iNbElem; i++) {
       tab[i] = s1.tab[i];
    }*/
    memcpy(tab, s1.tab, sizeof(T)*iNbElem);
}


template <class T> void Set<T>::ajouter(const T & t1) {
    if(!appartient(t1)) {
        T * tab2 = new T [++iNbElem];
        /*for(int i=0; i<iNbElem-1; i++) {
           tab2[i] = tab[i];
        }*/
        memcpy(tab2, tab, sizeof(T)*(iNbElem-1));
        tab2[iNbElem-1] = t1;
        delete [] tab;
        tab = tab2;
    }
}

template <class T> void Set<T>::enlever(const T & t1) {
    if(appartient(t1)) {
        T * tab2 = new T [--iNbElem];
        int j = 0;

        for(int i=0; i<=iNbElem; i++) {
            if(tab[i] != t1) {
                tab2[j] = tab[i];
                j++;
            }
        }

        delete [] tab;
        tab = tab2;
    }
}

template <class T> void Set<T>::intervertir(const T & t1, const T & t2) {
    T tmp;
    int t1Trouve = false;
    int t2Trouve = false;
    int iRangT1 = 0;
    int iRangT2 = 0;
    int i=0;

    while(!t1Trouve && !t2Trouve && i<getNbElem()) {
        if(tab[i] == t1) {
            t1Trouve = true;
            iRangT1 = i;
        }
        if(tab[i] == t2) {
            t2Trouve = true;
            iRangT2 = i;
        }
        i++;
    }

    if(t1Trouve && t2Trouve) {
        tmp = tab[iRangT1];
        tab[iRangT1] = tab[iRangT2];
        tab[iRangT2] = tmp;
    }
}

template <class T> bool Set<T>::appartient(const T & t1) const {
    for(int i=0; i<iNbElem; i++) {
        if(tab[i] == t1) {
            return true;
        }
    }
    return false;
}

template <class T> bool Set<T>::estVide() const {
    if(iNbElem == 0) {
        return true;
    }
    else {
        return false;
    }
}

template <class T> bool Set<T>::inclut(const Set & s1) const {
    if(iNbElem > s1.iNbElem) {
        return false;
    }

    for(int i=0; i<iNbElem; i++) {
        if(!s1.appartient(tab[i])) {
            return false;
        }
    }
    return true;
}

template <class T> bool Set<T>::operator==(const Set & s1) const {
    if(inclut(s1) && s1.inclut(*this)) {
        return true;
    }
    else {
        return false;
    }
}

template <class T> bool Set<T>::operator!=(const Set & s1) const {
    if( (!inclut(s1)) || (!s1.inclut(*this)) )  {
        return true;
    }
    else {
        return false;
    }
}

template <class T> int Set<T>::getNbElem() const {
    return (iNbElem);
}
template <class T> T Set<T>::getElem(int i) const {
    if(0<=i && i<iNbElem) {
        return tab[i];
    }
}

template <class T> Set<T>& Set<T>::operator=(const Set & s1) {
    iNbElem = s1.iNbElem;
    delete [] tab;
    tab = new T [iNbElem];
    /*for(int i=0; i<iNbElem; i++) {
       tab[i] = s1.tab[i];
    }*/
    memcpy(tab, s1.tab, sizeof(T)*iNbElem);
    return (*this);
}

template <class T> T Set<T>::operator[](const int i) const {
    if(0<=i && i<getNbElem()) {
        return getElem(i);
    }
}



// Fonctions d'affichage sur les Set
template <class T>
void afficheSiVide(const Set <T> & s, const int & n) {
    if(s.estVide()) {
        cout << "Set" << n << " est vide" << endl;
    }
    else {
        cout << "Set" << n << " n'est pas vide" << endl;
    }
}

template <class T>
void afficheSiEgaux(const Set <T> & s1, const int & n1, const Set <T> & s2, const int & n2) {
    if(s1 == s2) {
        cout << "Set" << n1 << " == Set" << n2 << endl;
    }
    else {
        cout << "Set" << n1 << " != Set" << n2 << endl;
    }
}

template <class T>
void afficheSiInlcut(const Set <T> & s1, const int & n1, const Set <T> & s2, const int & n2) {
    if(s1.inclut(s2)) {
        cout << "Set" << n1 << " est inclut dans Set" << n2 << endl;
    }
    else {
        cout << "Set" << n1 << " n'est pas inclut dans Set" << n2 << endl;
    }
}

template <class T>
void afficheSiAppartient(const Set <T> & s, const int & n, const T & e) {
    if(s.appartient(e)) {
        cout << e << " appatient à Set" << n<< endl;
    }
    else {
        cout << e << " n'appatient pas à Set" << n<< endl;
    }
}

template <class T>
void affiche(const Set <T> & s, const int n) {
    cout << "Set" << n << "  = {" << s.getElem(0);
    for(int i=1; i<s.getNbElem() ; i++) {
        cout << ", " << s[i];
    }
    cout << "}" << endl;
}

#endif
