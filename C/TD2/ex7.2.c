#include <stdio.h>

int main(void) {
    int a = 0, k = 0, n = 1, l = 0;

    printf("Entrez la valeur de l : ");
    scanf("%d", &l);

    for (int a = 2 ; a < l ; a++) {
        n = a;
        while (n < l) {
            if (a % 2 == 0) {
                a = a / 2;
            }
            else {
                a = (3 * a) + 1;
            }
            printf("%d\n", a);
            n++;
        }
        n = 0;
    }

    return 0;
}