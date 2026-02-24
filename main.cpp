#include <fstream>
#include <iostream>
#include <istream>

#include "texte.hpp"

std::string lire(const char* fichier) {
	std::fstream flux(fichier);
	std::string contenu((std::istreambuf_iterator<char>(flux)), std::istreambuf_iterator<char>());
	return contenu;
}

const std::string manuel = lire("man.md");

void afficherUtilisation() {
	std::cout << manuel;
}

Texte lireTexte(const char *fichier) {
    std::ifstream contenu(fichier);
    Texte texte;
    contenu >> texte;
    return texte;
}

void placerCurseurTerminal() {
    std::cout << "\033[9999;1H";
    std::flush(std::cout);
}

/*
 *  Efface la console - caractère  : \033[2J
 *  Place le curseur en haut -  caractère \033[H
 */
void effacer() {
    std::cout << "\033[2J\033[H";
    std::flush(std::cout);
}

/*
 * affiche la totalite du texte 
 */
void afficher(const Texte& texte) {
    std::cout << texte << std::endl;
}

void chercher(const Texte& texte, std::string& mot) {
    texte.chercher(mot);
}

void remplacer(Texte& texte, std::string& mot) {
    texte.remplacer(mot);
}

void annuler(Texte& texte) {
    texte.annuler();
}


void sauvegarder(const Texte& texte, const std::string &nomFichier) {
    Liste<std::string>::Iterateur it = texte.enleverCurseur();
    std::ofstream sortie(nomFichier);
    sortie << texte;
    texte.placerCurseur(it);
}

/*
  Fonction main() 

  Prend 1 ou 2 fichiers comme paramètres : un texte et unfichier de commandes 

*/
int main(int argc,const char *argv[]) {
    if (argc < 2 || argc > 3) {
        afficherUtilisation();
        return -1;
    }

    // Lecture du texte 
    Texte texte = lireTexte(argv[1]);
    bool estInteractif = argc == 2;


    std::ifstream commandes;
    if (!estInteractif)
        commandes = std::ifstream(argv[2]);
    std::istream& entree = estInteractif ? std::cin : commandes;

    
    while(entree) {
        if (estInteractif) {
            effacer();  // efface ;a 
            afficher(texte);
            placerCurseurTerminal();
        }

        // Lecture de la commande de l'utilisateur 
        std::string command;
        entree >> command;
        if (command == "chercher") {
            if (!entree) {
                afficherUtilisation();
                return -1;
            }
            // La commande est : chercher
            std::string mot;
            entree >> mot;
            chercher(texte, mot);            
        }
        else if (command == "sauvegarder") {
            if (!entree) {
                afficherUtilisation();
                return -1;
            }

            // La commande est : sauvegarder
            std::string fichier;
            entree >> fichier;
            sauvegarder(texte, fichier);            
        }
        else if (command == "remplacer") {
            if (!entree) {
                afficherUtilisation();
                return -1;
            }
            // La commande est : remplacer 
            std::string mot;
            entree >> mot;
            remplacer(texte, mot);            
        }
        else if (command == "annuler") {
            // La commande est : annuler 
            annuler(texte);
        }
    }

    if (estInteractif){
        effacer();
    }
    
    return 0;
}
