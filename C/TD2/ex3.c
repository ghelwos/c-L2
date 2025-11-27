#include <stdio.h>

int main(void) {
    float value = 0;
    float counter = 0;
    float sum = 0;
    while (scanf("%f", &value) != EOF) {
        sum += value;
        counter++;
    }
    printf("\n%f", sum / counter);
    return 0;
}