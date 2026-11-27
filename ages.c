#include <stdio.h>
#include "ages.h"

void traitementAges(FILE *fichier)
{
    char ligne[1000];
    int i;
    int colonne;
    int annee;
    int type;
    int genre;
    int naissance;
    int age;

    fgets(ligne, 1000, fichier);

    while (fgets(ligne, 1000, fichier) != NULL) {
        colonne = 1;
        annee = 0;
        type = 0;
        genre = 0;
        naissance = 0;
        i = 0;

        while (ligne[i] != '\0' && ligne[i] != '\n') {
            if (ligne[i] == ';') {
                colonne++;
            } else if (colonne == 1) {
                annee = annee * 10 + (ligne[i] - '0');
            } else if (colonne == 5) {
                type = type * 10 + (ligne[i] - '0');
            } else if (colonne == 7) {
                genre = genre * 10 + (ligne[i] - '0');
            } else if (colonne == 8) {
                naissance = naissance * 10 + (ligne[i] - '0');
            }
            i++;
        }

        age = annee - naissance;

        
        
    }
}