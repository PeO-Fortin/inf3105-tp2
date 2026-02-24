#include "texte.hpp"
#include <iostream>
#include <string>

void Texte::chercher(const std::string& mot) const {
	// TODO : A compléter
}

void Texte::remplacer(const std::string& mot) {
	// TODO : A compléter
}

void Texte::annuler() {
	// TODO : A compléter
}

std::ostream& operator<<(std::ostream& os, const Texte& texte) {
  texte.curseur = texte.mots.debut();

  while(texte.curseur) {
    os << texte.mots[texte.curseur];
    ++texte.curseur;
    if (texte.curseur)
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

  while(is) {
    is >> mot;
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
