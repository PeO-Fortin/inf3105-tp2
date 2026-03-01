/*
 * INF3105 - Structures de données et algorithmes
 * UQAM / Département d'informatique
 *
 * Implémentation d'une Pile 
 *
 * Auteurs : 
 *
 * Beeckmans, Nicolas et
 *
 * Équipe 22
 * Ladam, Fatima Zahra - LADF17289101
 * Fortin, Pierre-Olivier - FORP22028608
*/

#ifndef __PILE_H__
#define __PILE_H__

template<class T>
class Pile {
 public:
  Pile();
  ~Pile();

  void empiler(const T&);

  void depiler(T& out);  // Depiler et copier le sommet dans out.
  T depiler();

  bool vide() const { return sommet == nullptr; }
  void vider();

 private:
  class Cellule {
   public:
    Cellule(const T& e, Cellule* c);
    T contenu;
    Cellule* suivante;
  };

  Cellule* sommet;
};

#include "assert.h"

template<class T>
Pile<T>::Pile() {
  sommet = nullptr;
}

template<class T>
Pile<T>::~Pile() {
  vider();
}

template<class T>
void Pile<T>::vider() {
  while (!vide())
    depiler();
}

template<class T>
Pile<T>::Cellule::Cellule(const T& e, Cellule* c) : contenu(e), suivante(c) {
}

template<class T>
void Pile<T>::empiler(const T& e) {
  sommet = new Cellule(e, sommet);
  assert(sommet);
}

template<class T>
T Pile<T>::depiler() {
  assert(sommet);
  Cellule c(*sommet);
  delete sommet;
  sommet = c.suivante;
  return c.contenu;
}

template<class T>
void Pile<T>::depiler(T& e) {
  assert(sommet != nullptr);
  e = sommet->contenu;
  Cellule* c = sommet;
  sommet = sommet->suivante;
  delete c;
}

#endif
