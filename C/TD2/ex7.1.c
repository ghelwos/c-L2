#include <stdio.h>

int main(void) {
    int a = 0, k = 0, n = 1;

    printf("Entrez la valeur de a : ");
    scanf("%d", &a);
    printf("Entrez la valeur de k : ");
    scanf("%d", &k);

    do {
        if (a % 2 == 0) {
            a = a / 2;
        }
        else {
            a = (3 * a) + 1;
        }
        printf("%d\n", a);
        n++;
    } while (n < k);

    return 0;
}