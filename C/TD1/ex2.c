#include <stdio.h>
#include <string.h>

void francsEnEuro();
void moyenne();
void brutANet();

int main(int argc, char* argv[]) {
    if (strcmp(argv[argc - 1], "1") == 0) {
        francsEnEuro();
    } 
    else if (strcmp(argv[argc - 1], "2") == 0) {
        moyenne();
    }
    else {
        brutANet();
    }

    return 0;
}

void francsEnEuro() {
    float euros;
    printf("Valeur en francs :");
    scanf("%f", &euros);
    euros = euros / 6.55957;
    printf("Equivalent en euros : %f", euros);
}

void moyenne() {
    float somme = 0;
    float entierCourant = 0;
    for (int i = 0 ; i < 4 ; i++) {
        printf("Entier numero %i: ", i + 1);
        scanf("%f", &entierCourant);
        somme += entierCourant;
    }
    printf ("La moyenne de ces 4 entiers est : %f", somme / 4);
}

void brutANet() {
    float base = 0;
    float primeTechnicite = 0;
    float primeTransport = 0;
    printf("Salaire de base : ");
    scanf("%f", &base);
    printf("Prime de technicite : ");
    scanf("%f", &primeTechnicite);
    printf("Prime de transport : ");
    scanf("%f", &primeTransport);

    float nombreEnfants = 0;
    float primeParEnfant = 0;
    printf("Nombre d'enfants : ");
    scanf("%f", &nombreEnfants);
    printf("Prime d'un enfant: ");
    scanf("%f", &primeParEnfant);

    float nombreJours = 0;
    printf("Nombre de jours travailles : ");
    scanf("%f", &nombreJours);

    float salaireBrut = (base + primeTechnicite + primeTransport + (primeParEnfant * nombreEnfants)) * nombreJours / 26;
    float salaireNet = salaireBrut - (0.035 * salaireBrut) - (0.178 * salaireBrut);

    printf("Le salaire net est donc : %f", salaireNet);
}