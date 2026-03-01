/*
 * INF3105 - Structures de données et algorithmes
 * UQAM / Département d'informatique
 *
 * Implémentation de la classe Texte
 *
 * Auteurs : 
 *
 * Beeckmans, Nicolas et
 *
 * Équipe 22
 * Ladam, Fatima Zahra - LADF17289101
 * Fortin, Pierre-Olivier - FORP22028608
*/

#include "texte.hpp"
#include <iostream>
#include <string>

void Texte::chercher(const std::string& mot) const {
	Liste<std::string>::Iterateur tempIter = curseur;

  do{
    if(!curseur)
      curseur = mots.debut();

    if(mots[curseur] == mot) return;

    ++curseur;

  }while(curseur != tempIter);
}

void Texte::remplacer(const std::string& mot) {
  if(curseur) {
    std::string motRempl = mots[curseur];
    for(Liste<std::string>::Iterateur i = mots.debut(); i ;++i) {
      if(mots[i] == mot) {
        modifications.empiler(Texte::Modification(i, mots[i]));
        mots[i] = motRempl;
      }
    }
  }	
}

void Texte::annuler() {
	if(modifications.vide()){
    return;
  }
  Modification derniereModif = modifications.depiler();
  mots[derniereModif.position] = derniereModif.ancienMot;
}

std::ostream& operator<<(std::ostream& os, const Texte& texte) {
  Liste<std::string>::Iterateur it = texte.mots.debut();

  while(it) {
    os << texte.mots[it];
    ++it;
    if (it)
      os << " ";
    else
      os << std::endl;
  }
  return os;
}

const std::istream& operator>>(std::istream& is, Texte& texte) {
  std::string mot;

  is >> mot;
  texte.mots.inserer_debut(mot);

  while(is >> mot) {
    texte.mots.inserer_fin(mot);
  }

  return is;
}

void Texte::placerCurseur(const Liste<std::string>::Iterateur& iterateur) const {
  curseur = iterateur;
}

Liste<std::string>::Iterateur Texte::enleverCurseur() const {
  Liste<std::string>::Iterateur iterateur = curseur;
  curseur = mots.fin();
  return iterateur;
}
