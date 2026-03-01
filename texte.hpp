/*
 * Déclaration de la classe Texte
 * 
 *  auteurs: Beeckmans, Nicolas
*/

#ifndef __TEXTE_CPP__
#define __TEXTE_CPP__
#include <ostream>
#include <istream>
#include <string>

#include "pile.h"
#include "liste.h"

class Texte {

  class Modification;
  Liste<std::string> mots; // La liste des mots du texte
  mutable Liste<std::string>::Iterateur curseur = mots.fin();
  
  // Pour la commande annuler 
  Pile<Modification> modifications;


  class Modification {
    private:
      Liste<std::string>::Iterateur position;
      std::string ancienMot;

    public:
      Modification(const Liste<std::string>::Iterateur& pos, const std::string& ancien)
        : position(pos), ancienMot(ancien){}

      ~Modification(){}
        
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
