#include <stdio.h>
#include <stdlib.h>

typedef enum {A = 0, B = 1, C = 2} idSocle;

typedef struct {
    idSocle id;
    int* diametreSocles;
    int nbDisquesCurr;
    int nbDisquesMax;
} socle_t;

void creationSocle(socle_t* socle, idSocle id, int hauteur);
void destructionSocle(socle_t* socle);
void afficheSocle(socle_t socle);
void hanoi(int disquesA, socle_t* src, socle_t* inter, socle_t* dest);
void deplace(socle_t* src, socle_t* dest);

int main(void) {
    socle_t socleA, socleB, socleC;
    int hauteur;

    printf("Veuillez entrer le nombre de disques :");
    scanf("%d", &hauteur);

    creationSocle(&socleA, A, hauteur);
    creationSocle(&socleB, B, hauteur);
    creationSocle(&socleC, C, hauteur);

    afficheSocle(socleA);
    printf("\n");
    afficheSocle(socleB);
    printf("\n");
    afficheSocle(socleC);

    printf("\n");
    printf("//////////////////////////////////////\n");
    printf("\n");

    hanoi(hauteur, &socleA, &socleB, &socleC);
    afficheSocle(socleA);
    printf("\n");
    afficheSocle(socleB);
    printf("\n");
    afficheSocle(socleC);
    printf("\n");

    destructionSocle(&socleA);
    destructionSocle(&socleB);
    destructionSocle(&socleC);

    return 0;
}

void creationSocle(socle_t* socle, idSocle id, int hauteur) {
    socle->id = id;
    socle->diametreSocles = (int*)malloc(hauteur * sizeof(int));
    if (id != A) {
        socle->nbDisquesCurr = 0;
        for (int i = 0 ; i < hauteur ; i++) {
            socle->diametreSocles[i] = 0;
        }
    }
    else {
        socle->nbDisquesCurr = hauteur;
        for (int i = 0 ; i < hauteur ; i++) {
            socle->diametreSocles[i] = i + 1;
        }
    }
    socle->nbDisquesMax = hauteur;
}

void destructionSocle(socle_t* socle) {
    free(socle->diametreSocles);
}

void afficheSocle(socle_t socle) {
    for (int i = 0 ; i < socle.nbDisquesMax + 1 ; i++) {
        if (i == socle.nbDisquesMax) {
            for (int j = 0 ; j < (socle.nbDisquesMax * 2) + 1 ; j++) {
                printf("=");
            }
            printf("\n");
        }
        else {
            if (socle.diametreSocles[i] == 0) {
                for (int j = 0 ; j < socle.nbDisquesMax ; j++) {
                    printf(" ");
                }
                printf("|");
                for (int j = 0 ; j < socle.nbDisquesMax ; j++) {
                    printf(" ");
                }
                printf("\n");
            }
            else {
                for (int j = 0 ; j < socle.nbDisquesMax - socle.diametreSocles[i] ; j++) {
                    printf(" ");
                }
                for (int j = 0 ; j < (socle.diametreSocles[i] * 2) + 1 ; j++) {
                    printf("+");
                }
                for (int j = 0 ; j < socle.nbDisquesMax - socle.diametreSocles[i] ; j++) {
                    printf(" ");
                }
                printf("\n");
            }
        }
    }
}

void deplace(socle_t* src, socle_t* dest) {
    dest->diametreSocles[dest->nbDisquesMax - dest->nbDisquesCurr - 1] = src->diametreSocles[src->nbDisquesMax - src->nbDisquesCurr];
    src->diametreSocles[src->nbDisquesMax - src->nbDisquesCurr] = 0;
    dest->nbDisquesCurr++;
    src->nbDisquesCurr--;
}

void hanoi(int disquesA, socle_t* src, socle_t* inter, socle_t* dest) { 
    if (disquesA == 1) {
        deplace(src, dest);
    }
    else {
        hanoi(disquesA - 1, src, dest, inter);
        deplace(src, dest);
        hanoi(disquesA - 1, inter, src, dest);
    }
}