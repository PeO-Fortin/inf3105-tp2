# Makefile pour TP4.
# Adaptez ce fichier au besoin.

# Options standard.
#OPTIONS = -Wall

# L'option -g permet de générer les infos de débogage.
# Décommentez la ligne suivante si vous désirez utiliser un débogueur.
#OPTIONS = -g -O0 -Wall

# Les options -O, -O1, -O2, -O3 permettent d'optimiser le code binaire produit.
# Décommentez la ligne suivante si avant la remise finale
OPTIONS = -O0 -Wall -Wextra -g -Werror --std=c++11

all: cpsed

# Syntaxe : cible : dépendance1 dépendance2 ...
# Ensuite, la ou les ligne(s) débutant par une tabulation (\t) donne les commandes pour construire une cible
cpsed: main.o texte.o
	g++ $(OPTIONS) -o cpsed texte.o main.o

main.o : main.cpp texte.hpp 
	g++ $(OPTIONS) -c -o main.o main.cpp

texte.o : texte.cpp texte.hpp liste.h pile.h
	g++ $(OPTIONS) -c -o texte.o texte.cpp

clean :
	rm -f *.o
	rm -f cpsed
	rm -f *~

