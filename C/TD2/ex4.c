#include <stdio.h>

int main(void) {
    float value = 0;
    float minValue = 0;
    float maxValue = 0;
    scanf("%f", &value);
    minValue = value;
    maxValue = value;
    while (scanf("%f", &value) != EOF) {

        if (value > maxValue) {
            maxValue = value;
        }
        if (value < minValue) {
            minValue = value;
        }
    }
    printf("La valeur minimale est %f\n", minValue);
    printf("La valeur maximale est %f\n", maxValue);
    return 0;
}