#include <stdio.h>
#include <stdlib.h>
#include "fichierMots.h"

int nombreMotsDansFichier(FILE* fichier)
{
	int nombreMots = 0;
	char mot[TAILLE_MOT_MAX] = "";
	while (fgets(mot, TAILLE_MOT_MAX, fichier) != NULL)
	{
		nombreMots++;
	}

	return nombreMots;
}

void chercherMotDansFichier(char motSecret[], FILE* fichier, const int numeroMot, const int tailleMot)
{
	int nombreMots = 0;
	while (nombreMots != numeroMot)
	{
		fgets(motSecret, tailleMot, fichier);
		nombreMots++;
	}
}
