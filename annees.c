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

    
    static char dejaVu[20][100000];

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

            
            if (idAccident < 100000 && dejaVu[indice][idAccident] == 0) {
                dejaVu[indice][idAccident] = 1;
                annees[indice].nbAccidents++;
            }

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
    int choix=-1;

    while (choix != 0) {
        printf("Annee (0 pour quitter) : ");
        scanf("%d", &choix);

        if (choix >= 2005 && choix <= 2024) {
            int indice = choix - 2005;

            printf("Accidents : %d\n", annees[indice].nbAccidents);
            printf("Indemnes : %d\n", annees[indice].nbIndemnes);
            printf("Tues : %d\n", annees[indice].nbTues);
            printf("Blesses graves : %d\n", annees[indice].nbBlessesGraves);
            printf("Blesses legers : %d\n", annees[indice].nbBlessesLegers);
        } else if (choix != 0) {
            printf("Annee invalide\n");
        }
    }

}