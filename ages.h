typedef struct Age {
    int age;
    int compteur[3][2];
    struct Age *suivant;
} Age;

void traitementAges(FILE *fichier);
