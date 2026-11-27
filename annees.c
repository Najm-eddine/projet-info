#include <stdio.h>
#include "annees.h"

void traitementAnnees(FILE *fichier)
{
    char ligne[1000];
    int nbLignes = 0;
    int i;
    int colonne;
    int annee;
    int idAccident;
    int gravite;

    fgets(ligne, 1000, fichier);

    while (fgets(ligne, 1000, fichier) != NULL) {
        colonne = 1;
        annee = 0;
        idAccident = 0;
        gravite = 0;
        i = 0;

        while (ligne[i] != '\0' && ligne[i] != '\n') {
            if (ligne[i] == ';') {
                colonne++;
            } else if (colonne == 1) {
                annee = annee * 10 + (ligne[i] - '0');
            } else if (colonne == 2) {
                idAccident = idAccident * 10 + (ligne[i] - '0');
            } else if (colonne == 6) {
                gravite = gravite * 10 + (ligne[i] - '0');
            }
            i++;
        }

        nbLignes++;
    }

    printf("Nb lignes lues : %d\n", nbLignes);
}
