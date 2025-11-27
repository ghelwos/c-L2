#include <stdio.h>

int main(void) {
    int a, b = 0;

    printf("Valeur de a :" );
    scanf("%i", &a);
    printf("Valeur de b : ");
    scanf("%i", &b);

    if (a < 0 && b < 0) {
        printf("Le produit sera positif.");
    }
    else if (a > 0 && b > 0) {
        printf("Le produit sera positif");
    }
    else {
        printf("Le produit sera negatif.");
    }
}