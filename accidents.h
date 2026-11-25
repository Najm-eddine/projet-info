typedef struct Victime {
    short age;
    char genre;
    char gravite;
    char type;
    struct Victime *suivant;
} Victime;

typedef struct Vehicule {
    char id[8];
    char trajet;
    Victime *victimes;
    struct Vehicule *suivant;
} Vehicule;

typedef struct Accident {
    long long cle;
    Vehicule *vehicules;
    int equilibre;
    struct Accident *gauche;
    struct Accident *droite;
} Accident;
