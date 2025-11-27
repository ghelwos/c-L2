#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    
    int hauteur = 0, hauteurTronc = 0, rayonTronc = 0, proba = 0;
    printf("Entrez la hauteur : ");
    scanf("%d", &hauteur);
    printf("\n");


    printf("Entrez la hauteur du tronc: ");
    scanf("%d", &hauteurTronc);
    printf("\n");


    printf("Entrez le rayon du tronc: ");
    scanf("%d", &rayonTronc);
    printf("\n");

    printf("Entrez la proba d'avoir une boule: ");
    scanf("%d", &proba);
    printf("\n");


    int nbCarac = 2 * hauteur - 1;

    for (int i = 0 ; i < hauteur ; i++) {
        for (int j = 0 ; j < (nbCarac - 1) / 2 - i ; j++) {
            printf(" ");
        }
        for (int j = 0 ; j < nbCarac - 2 *((nbCarac - 1) / 2 - i) ; j++) {
            int val =rand()%100;
            if (val <= proba) {
                printf("o");
            }
            else {
                printf("*");
            }
        }
        for (int j = 0 ; j < (nbCarac - 1) / 2 - i ; j++) {
            printf(" ");
        }
        printf("\n");
    }

    for (int i = 0 ; i < hauteurTronc ; i ++) {
        for (int j = 0 ; j < (nbCarac - ((rayonTronc * 2) - 1 )) / 2; j++) {
            printf(" ");
        }
        for (int j = 0 ; j < (rayonTronc * 2) - 1 ; j++) {
            printf("+");
        }
        for (int j = 0 ; j < (nbCarac - ((rayonTronc * 2) - 1 )) / 2; j++) {
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}