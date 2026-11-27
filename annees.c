#include <stdio.h>
#include "annees.h"

void traitementAnnees(FILE *fichier)
{
    StatAnnee annees[20];
    char ligne[1000];
    int i;
    int colonne;
    int annee;
    int idAccident;
    int gravite;

    for (i = 0; i < 20; i++) {
        annees[i].nbAccidents = 0;
        annees[i].nbIndemnes = 0;
        annees[i].nbTues = 0;
        annees[i].nbBlessesGraves = 0;
        annees[i].nbBlessesLegers = 0;
    }

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

        if (annee >= 2005 && annee <= 2024) {
            int indice = annee - 2005;

            if (gravite == 1) {
                annees[indice].nbIndemnes++;
            } else if (gravite == 2) {
                annees[indice].nbTues++;
            } else if (gravite == 3) {
                annees[indice].nbBlessesGraves++;
            } else if (gravite == 4) {
                annees[indice].nbBlessesLegers++;
            }
        }
    }

    printf("2005 : %d tues, %d blesses graves\n", annees[0].nbTues, annees[0].nbBlessesGraves);
}
