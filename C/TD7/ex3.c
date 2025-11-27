#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int seconde;
    long int minute;
    int heure;
    long int jour;
    int mois;
    long int annee;
} une_date;

typedef struct {
    unsigned int seconde : 6;
    unsigned int minute : 6;
    unsigned int heure : 5;
    unsigned int jour : 5;
    unsigned int mois : 4;
    unsigned int annee : 12;
} date_opti;

bool estNbDansArr(int n, int* array, int taille);
void afficherDate(une_date date);

int main(void) {
    une_date date = {-1, -1, -1, -1, -1, -1};
    int mois31[7] = {1, 3, 5, 7, 8, 10, 12};
    int mois30[5] = {2, 4, 6, 9, 11};
    printf("%d est la taille allouee en octets par la structure.\n", sizeof(une_date));
    printf("%d est la taille allouee en octets par la structure optimisee.\n", sizeof(date_opti));
    while(date.annee < 1970 || date.annee > 2999) {
        printf("Veuillez entrer une annee comprise entre 1970 et 2999 : ");
        scanf("%ld", &date.annee);
    }
    while(date.mois < 1 || date.mois > 12) {
        printf("Veuillez entrer un mois compris entre 1 et 12 :");
        scanf("%d", &date.mois);
    }
    if (date.mois == 2) {
        if ( (date.annee % 4 == 0 && date.annee % 100 != 0) || (date.annee % 400 == 0) ) {
            while(date.jour < 1 || date.jour > 29) {
                printf("Veuillez entrer un jour compris entre 1 et 29 :");
                scanf("%ld", &date.jour);
            }
        }
        else {
            while(date.jour < 1 || date.jour > 28) {
                printf("Veuillez entrer un jour compris entre 1 et 28 :");
                scanf("%ld", &date.jour);
            }
        }
    }
    else if (estNbDansArr(date.mois, mois31, 7)) {
        while(date.jour < 1 || date.jour > 31) {
            printf("Veuillez entrer un jour compris entre 1 et 31 :");
            scanf("%ld", &date.jour);
        }
    }
    else if (estNbDansArr(date.mois, mois30, 5)) {
        while(date.jour < 1 || date.jour > 30) {
            printf("Veuillez entrer un jour compris entre 1 et 30 :");
            scanf("%ld", &date.jour);
        }
    }
    while(date.heure < 0 || date.heure > 23) {
        printf("Veuillez entrer une heure comprise entre 0 et 23 : ");
        scanf("%d", &date.heure);
    }
    while(date.minute < 0 || date.minute > 59) {
        printf("Veuillez entrer une minute comprise entre 0 et 59 : ");
        scanf("%ld", &date.minute);
    }
    while(date.seconde < 0 || date.seconde > 59) {
        printf("Veuillez entrer une seconde comprise entre 0 et 59 : ");
        scanf("%d", &date.seconde);
    }
    afficherDate(date);
    return 0;
}

bool estNbDansArr(int n, int* array, int taille) {
    for (int i = 0 ; i < taille ; i++) {
        if (n == array[i]) {
            return true;
        }
    }
    return false;
}

void afficherDate(une_date date) {
    char* mois[12] = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};
    printf("Le %ld %s %ld, a %dh%ldm%ds.\n", date.jour, mois[date.mois - 1], date.annee, date.heure, date.minute, date.seconde);
}