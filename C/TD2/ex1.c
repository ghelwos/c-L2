#include <stdio.h>
#include <string.h>

void factorielN(int N);
void factorielNBis(int N);
void nbChiffresNonNul(int N);

int main(int argc, char* argv[]) {
    int N = 0;
    printf("Entrez un entier : ");
    scanf("%d", &N);
    if (!strcmp(argv[argc - 1], "1")) {
        factorielN(N);
        factorielNBis(N);
    }
    else {
        nbChiffresNonNul(N);
    }
}

void factorielN(int N) {
    int res = 1;
    for(int i = 1 ; i <= N ; i++) {
        res *= i;
    }
    printf("%d\n", res);
}


void factorielNBis(int N) {
    int res = 1;
    int i = 1;
    while(i <= N){
        res *= i;
        i++;
    }
    printf("%d\n", res);
}

void nbChiffresNonNul(int N) {
    int res = 0;
    while (N != 0) {
        if (N % 10 != 0) {
            res++;
        }
        N /= 10;
    }
    printf("Il y a %d chiffres non-nuls dans l'ecriture decimale de ce nombre.\n", res);
}