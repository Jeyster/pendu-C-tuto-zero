#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tools.h"
#include "mots.h"
#include "fichierMots.h"

int main()
{
	setbuf(stdout, NULL); //permet affichage correct en console

	printf("------------------------------------\n");
	printf("----------- Jeu du Pendu -----------\n");
	printf("------------------------------------\n");

	char rejouer;

	/* Ouverture fichier mots */
	FILE* fichierMots = NULL;
	fichierMots = fopen("liste-mots/ods4.txt","r");
	if (fichierMots == NULL)
	{
		printf("Impossible de lire le fichier, fermeture du programme.");
		exit(0);
	}

	/* Comptage nombre de mots */
	int nombreMots = nombreMotsDansFichier(fichierMots);

	do
	{
		int nombreCoup = 10;

		char motSecret[TAILLE_MOT_MAX];
		srand(time(NULL));
        int numeroMot = (rand() % nombreMots) + 1;
		chercherMotDansFichier(motSecret, fichierMots, numeroMot, TAILLE_MOT_MAX);

		int longueurMot = strlen(motSecret);

		/* Creation chaine de caractere a découvrir,
		 * allocation de la mémoire nécessaire
		 * et initialisation avec des '*' */
		char* motAffiche = NULL;
		motAffiche = allouerMemoireString(motAffiche, longueurMot);
		initialisationMot(motAffiche, longueurMot);

		/* !!! DEBUG !!! */
		/*
		printf("Mot secret : %s\n", motSecret);
		printf("Longueur mot : %d\n", longueurMot);
		printf("Mot affiche : %s\n", motAffiche);
		*/
		/* !!! DEBUG !!! */

		/* Boucle jusqu'à ce que le joueur trouve le mot secret ou utilise tous les coups permis */
		while ((nombreCoup != 0) && (strcmp(motSecret, motAffiche) != 0))
		{
			printf("\nIl vous reste %d coups a jouer.\n", nombreCoup);
			printf("Mot secret : %s\n", motAffiche);
			printf("Proposez une lettre : ");
			char caractereSaisi = lireCaractere();
			chercherRemplacerDansMot(motSecret, motAffiche, caractereSaisi, longueurMot, &nombreCoup);
		}

		if (nombreCoup == 0)
		{
			printf("\nVous etes nul, le mot secret etait %s !!!\n\n", motSecret);
		}
		else
		{
			printf("\nBravo !!! Vous avez trouve le mot secret %s !\n\n",motSecret);
		}

		free(motAffiche);

		printf("Voulez-vous rejouer ? (O/n)\n");
		rejouer = lireCaractere();
	}while(rejouer == 'O');

	printf("------------------------------------\n");
	printf("------------ Fin du jeu ------------\n");
	printf("------------------------------------\n");

	return 0;
}
