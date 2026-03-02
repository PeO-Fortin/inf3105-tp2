# Équipe 22
# Ladam, Fatima Zahra LADF17289101
# Fortin, Pierre-Olivier FORP22028608

# Options standard.
#OPTIONS = -Wall

# L'option -g permet de générer les infos de débogage.
# Décommentez la ligne suivante si vous désirez utiliser un débogueur.
#OPTIONS = -g -O0 -Wall

# Les options -O, -O1, -O2, -O3 permettent d'optimiser le code binaire produit.
OPTIONS = -O0 -Wall -Wextra -g -Werror --std=c++11

all: cpsed

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

