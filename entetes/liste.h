#ifndef LISTE_H
#define LISTE_H
using namespace std;

template <class T> class Liste {
   private:
   int iNbElem;
   T * tab;

   public:
   // Générateurs du type
   Liste(); // crée une liste vide
   void inserer(const T &, const int);

   // Constructeurs du type
   void retirer(const int);

   // Observateurs du type
   bool estVide() const;
   int getNbElem() const;
   T getElem(int i) const;

   // Méthodes propres à cette implémentation
   ~Liste();
   Liste(const Liste &);
   Liste& operator=(const Liste &);
   T operator[](const int i) const;
};

template <class T> T Liste<T>::operator[](const int i) const {
    if(0<=i && i<getNbElem()) {
        return getElem(i);
    }
}


// Générateurs du type
template <class T> Liste<T>::Liste() {
   iNbElem = 0;
   tab = new T [0];
}

template <class T> void Liste<T>::inserer(const T & t1, const int iRang) {
   if(0 <= iRang && iRang <= iNbElem) {
      T * tab2 = new T [++iNbElem];
      int j = 0;

      // Recopie l'ancienne liste en insérant le nouvel élément au bon endroit
      // Comme la spécification l'indique, tous les éléments situés à droite de
      // celui inséré (donc qui ont un rang strictement supérieur) sont décalés
      // d'un cran vers la droite
      for(int i=0; i<iNbElem; i++) {
         if(i == iRang) {
            tab2[i] = t1;
         }
         else {
            tab2[i] = tab[j];
            j++;
         }
      }

      delete [] tab;
      tab = tab2;
   }
}

// Constructeurs du type
template <class T> void Liste<T>::retirer(const int iRang) {
   if(0 <= iRang && iRang < iNbElem) {
      T * tab2 = new T [--iNbElem];
      int j = 0;

      for(int i=0; i<=iNbElem; i++) {
         if(i != iRang) {
            tab2[j] = tab[i];
            j++;
         }
      }

      delete [] tab;
      tab = tab2;
   }
}

// Observateurs du type

template <class T> bool Liste<T>::estVide() const {
  if(iNbElem == 0) {
   return true;
  }
  else {
   return false;
  }
}

template <class T> int Liste<T>::getNbElem() const {
   return (iNbElem);
}

template <class T> T Liste<T>::getElem(int i) const {
   if(0<=i && i<iNbElem) {
      return tab[i];
   }
}


// Méthodes propres à cette implémentation
template <class T> Liste<T>::~Liste() {
   iNbElem = 0;
   delete [] tab;
}

template <class T> Liste<T>::Liste(const Liste & s1) {
   iNbElem = s1.iNbElem;
   tab = new T [iNbElem];
   for(int i=0; i<iNbElem; i++) {
      tab[i] = s1.tab[i];
   }
}

template <class T> Liste<T>& Liste<T>::operator=(const Liste & s1) {
   iNbElem = s1.iNbElem;
   delete [] tab;
   tab = new T [iNbElem];
   for(int i=0; i<iNbElem; i++) {
      tab[i] = s1.tab[i];
   }
   return (*this);
}


// Fonctions d'affichage sur les Liste
template <class T>
void afficheSiVide(const Liste <T> & s, const int & n) {
   if(s.estVide()) {
      cout << "Liste" << n << " est vide" << endl;
   }
   else {
      cout << "Liste" << n << " n'est pas vide" << endl;
   }
}

template <class T>
void afficheIeme(const Liste <T> & s, const int n, const int i) {
   if(0<=i && i<s.getNbElem()) {
      cout << "Liste" << n << "[" << i << "] = " << s.getElem(i) << endl;
   }
   else {
      cout << "Liste" << n << "[" << i << "] n'existe pas"<< endl;
   }
}

template <class T>
void affiche(const Liste <T> & s, const int n) {
   cout << "Liste" << n << "  = {" << s.getElem(0);
   for(int i=1; i<s.getNbElem() ; i++) {
      cout << ", " << s.getElem(i);
   }
   cout << "}" << endl;
}

#endif
