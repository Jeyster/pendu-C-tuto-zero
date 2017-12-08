#ifndef DEF_FICHIER_MOTS

#define DEF_FICHIER_MOTS

#define TAILLE_MOT_MAX 1000

/* Prototypes */
int nombreMotsDansFichier(FILE* fichier);
void chercherMotDansFichier(char* motSecret, FILE* fichier, const int numeroMot, const int tailleMot);

#endif
