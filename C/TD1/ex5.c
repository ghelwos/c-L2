#include <stdio.h>
#include <math.h>

int main(void) {
    float x1, x2, x3 = 0;
    printf("Valeur de x1 : " );
    scanf("%f", &x1);
    printf("Valeur de x2 : ");
    scanf("%f", &x2);
    printf("Valeur de x3 : ");
    scanf("%f", &x3);

    float delta = (x2 * x2) - 4 * (x1 * x3);
    
    if (delta < 0) {
        printf("L'equation n'admet aucune solution reelle.");
    }
    else if (delta == 0) {
        printf("L'unique solution est : %f", (-x2) / (2 * x1));
    }
    else {
        printf("La premiere solution est : %f.\n", (-x2 - sqrt(delta)) / (2 * x1));
        printf("La seconde solution est : %f\n", (-x2 + sqrt(delta)) / (2 * x1));
    }
}