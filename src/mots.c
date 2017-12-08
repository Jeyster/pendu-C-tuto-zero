#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialisationMot(char* pMot, int tailleMot)
{
	for (int i = 0; i < tailleMot; i++)
	{
		pMot[i]= '*';
	}
	pMot[tailleMot] = '\0';
}

void chercherRemplacerDansMot(const char* motSecret, char* motAffiche, const char caractereSaisi, const int longueurMot, int* nombreCoup)
{
	if (strchr(motSecret, caractereSaisi) == NULL)
	{
		(*nombreCoup)--;
	}
	else
	{
		for (int i = 0; i < longueurMot; i++)
		{
			if (motSecret[i] == caractereSaisi)
			{
				motAffiche[i] = caractereSaisi;
			}
		}
	}
}
