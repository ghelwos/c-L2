#include <stdio.h>
#include <stdbool.h>

bool isPrime(int N);

int main(void) {
    printf("Veuillez entrer un entier : ");
    int k = 0;
    scanf("%d", &k);
    
    for (int i = 1 ; i <= k ; i++)
    {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}

bool isPrime(int N) {
    for (int i = 2 ; i < N ; i++) {
        if (N % i == 0 && i != N) {
            return false;
        }
    }
    return true;
}