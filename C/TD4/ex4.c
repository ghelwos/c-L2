#include <stdio.h>

void printLine(int n);

int main() {
    int n = 0;
    printf("Veuillez entrer un n : ");
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        printLine(n);
    }
}

void printLine(int n) {
    for (int i = 0 ; i < n ; i++) {
        printf("*");
    }
    printf("\n");
}