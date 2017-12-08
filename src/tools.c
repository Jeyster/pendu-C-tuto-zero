#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


char lireCaractere()
{
    char caractere = 0;

    caractere = getchar(); // On lit le premier caract�re
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas d�j�

    // On lit les autres caract�res m�moris�s un � un jusqu'au \n (pour les effacer)
    while (getchar() != '\n') ;

    return caractere; // On retourne le premier caract�re qu'on a lu
}

char* allouerMemoireString(char* pointeur, int tailleTab)
{
	pointeur = malloc((tailleTab + 1) * sizeof(char));
	if (pointeur == NULL)
	{
		printf("!!! Echec malloc !!!");
		exit(0);
	}
	return pointeur;
}
