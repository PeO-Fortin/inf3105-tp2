/*
  INF3105 - Structures de données et algorithmes
  UQAM / Département d'informatique
  Liste doublement chaînée.
  TP 2 

   À compléter.

   autheurs : Beeckmans, Nicolas et vous 
*/

#ifndef __LISTE_H__
#define __LISTE_H__

#include <cassert>

// Déclaration

template<class T>
class Liste {
 public:
  class Iterateur;

  Liste();
  Liste(const Liste&);
  ~Liste();

  bool estVide() const;
  void vider();

  bool operator==(const Liste&) const;
  const Liste& operator=(const Liste&);

  T& operator[](const Iterateur&);
  const T& operator[](const Iterateur&) const;

  // Les fonctions insérer retournent un Itérateur sur la position de l'objet inséré.
  // La fonction enlever retourne un Iterateur sur la position suivante de l'objet enlevé.
  Iterateur inserer(const T&, const Iterateur&);
  Iterateur enlever(const Iterateur&);

  Iterateur inserer_debut(const T&);
  Iterateur inserer_fin(const T&);
  void enlever_debut();

  Iterateur debut() const;  // Iterateur sur le début.
  Iterateur fin() const;    // Iterateur sur la fin. La fin est la position suivante du dernier élément.

  Iterateur trouver( const T&) const;  // Retourne un itérateur sur le premier élément cherché.
                                       // S'il n'existe pas, retourne fin().

 private:

  // Classe Cellule : modélise un noeud de la liste doublement chainée
  class Cellule {
   public:
    Cellule(const T& c, Cellule* p = nullptr, Cellule* s = nullptr)
        : contenu(c), precedente(p), suivante(s) {}
    T contenu;
    Cellule* precedente;
    Cellule* suivante;
  };

 public:
  // Classe Iterateur : 
  class Iterateur {
   public:
    Iterateur(const Liste&);
    Iterateur(const Iterateur&);
    Iterateur(const Liste&, Cellule*);

    operator bool() const;  // retourne vrai si l'itérateur n'est pas rendu à la fin. Permet de faire while(iter)
    bool operator!() const;  // retourne faux si l'itérateur n'est pas rendu à la fin
    bool operator==( const Iterateur&) const;  // compare deux itérateur (deux "positions")
    bool operator!=( const Iterateur&) const;  // !compare deux itérateur (deux "positions")

    Iterateur operator++(int);  // post-incrément (i++)
    Iterateur& operator++();    // pré-incrément (++i)

    // T& operator*(); // Bonne idée? Pourquoi? Qu'arrive-t-il si la liste est constante?
    const T& operator*() const;  // déréférencement

    Iterateur& operator=(const Iterateur&);

   private:
    Cellule* courante;   // pointeur sur la Cellule courante
    const Liste& liste;  // référence sur la Liste associée à l'itérateur courant (pour des fins de robustesse).

    friend class Liste;
  };

 private:
  Cellule* premiere;
  Cellule* derniere;
};

/*
 Puisque Liste<T> est une classe générique, toutes ses définitions doivent être
 inclues après les déclarations. On peut quand même séparer les déclarations et
 les définitions en deux fichiers (liste.h et liste.hcc), à condition d'inclure
 le deuxième (liste.hcc) à la fin du premier (liste.h). Ainsi, un fichier source
 (.cc, .cpp, c++) qui inclut liste.h inclura indirectement aussi liste.hcc.
*/

// Implémentation des constructeurs, destructeurs et fonctions
template<class T>
Liste<T>::Liste() : premiere(nullptr), derniere(nullptr) {}

template<class T>
Liste<T>::~Liste() {
  vider();
}

template<class T>
bool Liste<T>::estVide() const {
  return premiere == nullptr;
}

template<class T>
void Liste<T>::vider() {
  // À compléter.
  // Requis pour la tâche 3.
}

template<class T>
const Liste<T>& Liste<T>::operator=(const Liste<T>& autre) {
  // À compléter.
  return *this;
}

template<class T>
T& Liste<T>::operator[](const Iterateur& i) {
  assert(&i.liste == this);
  assert(i.courante != nullptr);

  return i.courante->contenu;
}

template<class T>
const T& Liste<T>::operator[](const Iterateur& i) const {
  assert(&i.liste == this);
  assert(i.courante != nullptr);

  return i.courante->contenu;
}

template<class T>
typename Liste<T>::Iterateur Liste<T>::inserer(const T& e, const Iterateur& i) {
  // À compléter.
  return fin();
}

template<class T>
typename Liste<T>::Iterateur Liste<T>::inserer_debut(const T& e) {
  // À compléter.
  return fin();
}

template<class T>
typename Liste<T>::Iterateur Liste<T>::inserer_fin(const T& e) {
  // À compléter.
  // Requis pour la tâche 3.
  return fin();
}

template<class T>
typename Liste<T>::Iterateur Liste<T>::enlever(const Iterateur& i) {
  // À compléter.
  return fin();
}

template<class T>
void Liste<T>::enlever_debut() {
  // À compléter.
  // Requis pour la tâche 3.
}

template<class T>
typename Liste<T>::Iterateur Liste<T>::debut() const {
  return Iterateur(*this, premiere);
}

template<class T>
typename Liste<T>::Iterateur Liste<T>::fin() const {
  return Iterateur(*this, nullptr);
}

template<class T>
typename Liste<T>::Iterateur Liste<T>::trouver(const T& e) const {
  // À compléter.
  // Probablement non requis pour la tâche #3.
  return fin();
}

template<class T>
bool Liste<T>::operator==(const Liste& autre) const {
  if (this == &autre) return true;
  // À compléter.
  return false;
}

//----------------------------------------------------//
template<class T>
Liste<T>::Iterateur::Iterateur(const Iterateur& i)
  : courante(i.courante), liste(i.liste) {}

template<class T>
Liste<T>::Iterateur::Iterateur(const Liste<T>& l)
  : courante(liste.premiere), liste(l) {}

template<class T>
Liste<T>::Iterateur::Iterateur(const Liste<T>& l, Cellule* c)
  : courante(c), liste(l) {}

template<class T>
Liste<T>::Iterateur::operator bool() const {
  return courante != nullptr;
}

template<class T>
bool Liste<T>::Iterateur::operator!() const {
  return courante == nullptr;
}

template<class T>
bool Liste<T>::Iterateur::operator==(const Iterateur& autre) const {
  assert(&liste == &autre.liste);
  return courante == autre.courante;
}

template<class T>
bool Liste<T>::Iterateur::operator!=(const Iterateur& autre) const {
  assert(&liste == &autre.liste);
  return courante != autre.courante;
}

// operator++() est le post-incrément
template<class T>
typename Liste<T>::Iterateur Liste<T>::Iterateur::operator++(int) {
  Iterateur temp(*this);
  if (courante != nullptr) courante = courante->suivante;
  return temp;
}

// operator++() est le pré-incrément
template<class T>
typename Liste<T>::Iterateur& Liste<T>::Iterateur::operator++() {
  if (courante != nullptr) courante = courante->suivante;
  return *this;
}

template<class T>
const T& Liste<T>::Iterateur::operator*() const {
  assert(courante != nullptr);
  return courante->contenu;
}

template<class T>
typename Liste<T>::Iterateur& Liste<T>::Iterateur::operator=(
    const Iterateur& autre) {
  assert(&liste == &autre.liste);
  courante = autre.courante;
  return *this;
}

#endif
