#include <stdio.h>
#include <math.h>

double calculDistance(double xA, double yA, double xB, double yB);

int main(void) {
    double xA, xB, yA, yB;
    printf("Veuillez entrer xA :");
    scanf("%lf", &xA);
    printf("\n");
    printf("Veuillez entrer xB :");
    scanf("%lf", &xB);
    printf("\n");
    printf("Veuillez entrer yA :");
    scanf("%lf", &yA);
    printf("\n");
    printf("Veuillez entrer yB :");
    scanf("%lf", &yB);
    printf("\n");
    printf("La distance entre ces deux points est de : %f.\n", calculDistance(xA, yA, xB, yB));
}

double calculDistance(double xA, double yA, double xB, double yB) {
    return (sqrt((xB - xA)*(xB - xA) + (yB - yA)*(yB - yA)));
}