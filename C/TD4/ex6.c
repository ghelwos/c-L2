#include <stdio.h> 

void printSolution(int t, int p);

int main(void) {
    int tetes = 0, pattes = 0;
    printf("Veuillez entrer le nombre de pattes : ");
    scanf("%d", &pattes);
    printf("Veuillez entrer le nombre de tetes : ");
    scanf("%d", &tetes);
    printSolution(tetes, pattes);
}

void printSolution(int t, int p) {
    int moutons = 0, poulets = 0;
    while (p >= 4 ) {
        p -= 2;
        t--;
        moutons++;
    }
    printf("Il y a %d moutons.\n", moutons);
    printf("Il reste %d tetes. et %d pattes.\n", t, p);
    while (p > 0) {
        p -= 2;
        t--;
        poulets++;
    }
    printf("Il y a %d poulets.\n", poulets);
}