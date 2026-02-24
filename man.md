Nom

	cpsed - "C'est Pas SED"

Résumé

	cpsed FICHIER [COMMANDES]

Description

	Editeur de texte pour le TP 2 d'INF3105 - Structure de données et Algorithmes - Hiver 2026

	FICHIER   - Fichier texte à éditer (OBLIGATOIRE)
	COMMANDES - Fichier contenant des commandes (OPTIONNEL)

	Si `cpsed` est lancé sans COMMANDES, le programme passe en mode interactif. Vous pouvez ainsi
	utiliser des commandes les unes après les autres manuellement. Pour quitter le progamme
	gracieusement, utiliser CTRL-D.
	
	LISTE DES COMMANDES :
	chercher mot        - Déplace le curseur sur la prochaine occurence du à partir du curseur.
	                      Si le mot n'apparait entre le curseur et la fin, le curseur est placé
						  sur la première occurence du mot dans le texte.
						  Si le mot n'existe pas, le curseur n'est pas déplacé.
	remplacer mot       - Remplace toutes les occurences du mot par celui sous le curseur
	annuler             - Annule le dernier remplacement
	sauvegarder fichier - Sauvergarde le texte dans le fichier spécifié

Autheur(s)

	Nicolas Beeckmans et Vous :)
