#include <stdio.h>
#include <math.h>

int main(void) {
    int rayon = 0;
    printf("Veuillez entrer le rayon :");
    scanf("%d", &rayon);
    printf("Le perimetre est : %f", 2 * M_PI * rayon);
}