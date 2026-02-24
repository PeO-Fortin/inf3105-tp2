/*
 * Déclaration de la classe Texte
 * 
 *  autheur: Beeckmans, Nicolas
*/

#ifndef __TEXTE_CPP__
#define __TEXTE_CPP__
#include <ostream>
#include <istream>
#include <string>

// Pour la fonction annuler()
// #include "pile.h"
#include "liste.h"

class Texte {

  class Modification;
  Liste<std::string> mots; // La liste des mots du texte
  // mutable : permet à la variable d'être modifiée même si l'objet est marqué "const"
  mutable Liste<std::string>::Iterateur curseur = mots.fin();
  
  
  // Définition de la classe Modification : elle représente une modification dans le texte. 
  // Les objets Modification seront placés dans une pile. 
  // Cela est Nécessaire pour la commande annuler
  // 
  // Pile<Modification> modifications;


  class Modification {
    private:
      // TODO : Ajouter les variables nécessaires.
    public:
      Modification(/* TODO: A compléter */);
      friend Texte;
  };

  public:
    /**
    * Deplace le curseur sur la prochaine occurence du mot à partir du curseur.
    * Si le mot n'apparait pas entre le curseur et la fin, il faut reprendre la rechercher à partir du début du texte.
    */
    void chercher(const std::string& mot) const;
    
    /**
    * Remplace toutes les occurences trouvées par le mot sous le curseur
    */
    void remplacer(const std::string& aRemplacer);

    /**
    * Annule la deniere opération
    */
    void annuler();

    /**
    * Ecrire dans le contenu texte dans le ostream
    */
    friend std::ostream& operator<<(std::ostream& os , const Texte& texte);
  
    /**
    * Pour lire un fichier donne dans le istream
    */
    friend const std::istream& operator>>(std::istream& is, Texte& texte);

    /**
    * Enleve le curseur
    */
    Liste<std::string>::Iterateur enleverCurseur() const;

    /**
    * Place le curseur
    */
    void placerCurseur(const Liste<std::string>::Iterateur& iterateur) const;
};
#endif
