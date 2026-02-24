#include "texte.hpp"
#include <iostream>

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
  // TODO : A compléter
  return os;
}

const std::istream& operator>>(std::istream& is, Texte& texte) {
  // TODO : A compléter
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
