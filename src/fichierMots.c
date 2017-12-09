#include <stdio.h>
#include <stdlib.h>
#include "fichierMots.h"
#include "mots.h"

int nombreMotsDansFichier(FILE* fichier)
{
	int nombreMots = 0;
	char mot[TAILLE_MOT_MAX] = "";
	while (fgets(mot, TAILLE_MOT_MAX, fichier) != NULL)
	{
		nombreMots++;
	}

    rewind(fichier);

	return nombreMots;
}

void chercherMotDansFichier(char motSecret[], FILE* fichier, const int numeroMot, const int tailleMot)
{
	int nombreMots = 0;
	while (nombreMots != numeroMot)
	{
		if (fgets(motSecret, tailleMot, fichier) != NULL)
        {
            nombreMots++;
        }
        else
        {
            printf("!!! Erreur de lecture du fichier !!!");
        }
	}
    rewind(fichier);

    retirerSautLigneDansString(motSecret);
}
