#include <stdio.h>
#include <stdlib.h>

int* alloueTableau(int* tableau, int taille);
void alloueTableauReference(int** tableau, int taille);
void printTableau(int* tableau, int taille);

int main(void) {
    int* tab1;
    int* tab2;
    int taille;

    printf("Veuillez entrer la taille des tableaux : ");
    scanf("%d", &taille);

    tab1 = alloueTableau(tab1, taille);
    alloueTableauReference(&tab2, taille);

    printTableau(tab1, taille);
    printf("\n");
    printTableau(tab2, taille);

    free(tab1);
    free(tab2);
}

int* alloueTableau(int* tableau, int taille) {
    tableau = (int*)malloc(taille * sizeof(int));
    for (int i = 0 ; i < taille ; i++) {
        tableau[i] = 0;
    }
    return tableau;
}

void alloueTableauReference(int** tableau, int taille) {
    *tableau = (int*)malloc(taille * sizeof(int));
    for (int i = 0 ; i < taille ; i++) {
        (*tableau)[i] = 0;
    }
}

void printTableau(int* tableau, int taille) {
    for (int i = 0 ; i < taille ; i++) {
        printf("%d ", tableau[i]);
    }
}