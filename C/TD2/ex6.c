#include <stdio.h>

int main(void) {
    int a = 0, b = 0, res = 0;

    printf("Entrez a :");
    scanf("%d", &a);
    printf("Entrez b :");
    scanf("%d", &b);

    while (b != 0) {
        if (b % 2 == 0) {
            a *= 2;
            b /= 2;
        }
        else {
            b--;
            res += a;
        }
    }
    printf("Le résultat est : %d\n", res);

    return 0;
}