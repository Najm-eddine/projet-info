#include "main.h"

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Erreur : nombre d'arguments incorrect\n");
        return 1;
    }

    FILE *fichier = fopen(argv[2], "r");

    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s\n", argv[2]);
        return 1;
    }

    if (strcmp(argv[1], "YEAR_DATA") == 0) {
        printf("Mode YEAR_DATA\n");
    } else if (strcmp(argv[1], "AGE_DATA") == 0) {
        printf("Mode AGE_DATA\n");
    } else if (strcmp(argv[1], "CRASH_DATA") == 0) {
        printf("Mode CRASH_DATA\n");
    } else {
        printf("Erreur : mode inconnu\n");
        fclose(fichier);
        return 1;
    }

    fclose(fichier);
    return 0;
}
