#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void) {
    srand(time(NULL));

    int max = 0;
    int triesRemaining = 0;
    printf("Quelle valeur maximale pour la generation : ");
    scanf("%d", &max);
    printf("Combien d'essais maximum : ");
    scanf("%d", &triesRemaining);
    int value = rand()%max;

    bool hasFound = false;

    while (hasFound == false && triesRemaining > 0) {
        int currentTry = 0;
        printf("Entrez votre tentative : ");
        scanf("%d", &currentTry);
        if (currentTry > value) {
            printf("C'est moins.\n");
        }
        else if (currentTry < value) {
            printf("C'est plus.\n");
        }
        else {
            hasFound = true;
        }
        triesRemaining--;
    }

    if (hasFound == true) {
        printf("Bien joue !!");
    }
    else {
        printf("C'est perdu !");
    }
}