#include <stdio.h>
#include <stdbool.h>

bool isPerfect(int N);

int main(void) {
    printf("Veuillez entrer un entier : ");
    int k = 0;
    scanf("%d", &k);
    
    for (int i = 1 ; i <= k ; i++)
    {
        if (isPerfect(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}

bool isPerfect(int N) {
    int sum = 0;
    for (int i = 1 ; i < N ; i++) {
        if (N % i == 0 && i != N) {
            sum += i;
        }
    }
    return(sum == N);
}