#include <stdio.h>
#include "annees.h"

void traitementAnnees(FILE *fichier)
{
    char ligne[1000];
    int nbLignes = 0;

    fgets(ligne, 1000, fichier);

    while (fgets(ligne, 1000, fichier) != NULL) {
        nbLignes++;
    }

    printf("Nb lignes lues : %d\n", nbLignes);
}
