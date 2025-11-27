#include <stdio.h>

int main() {
    char myString[255];
    int k = 0;

    printf("Veuillez entrer la chaine de caracteres : ");
    scanf("%s", myString);
    printf("Veuillez entrer la valeur k : ");
    scanf("%i", &k);

    int i = 0;
    while (myString[i] != '\0') {
        if (myString[i] + k <= 'z') {
            myString[i] += k;
        }
        else {
            myString[i] -= 26 - k;
        }
        i++;
    }

    printf("%s\n", myString);
}