#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int **triangle;
    int n = 0;
    printf("Entrez la valeur de n :");
    scanf("%d", &n);
    triangle = (int**)malloc(sizeof(int*) * n);
    for (int i = 0 ; i < n ; i++) {
        triangle[i] = (int*)malloc(sizeof(int) * i);
    }
    for (int i = 0 ; i < n; i++) {
        triangle[i][0] = 1;
    }
    for (int i = 1 ; i < n ; i++) {
        for (int j = 1 ; j < i ; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    for (int i = 0 ; i < n ; i++) {
        triangle[i][i] = 1;
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < i+1 ; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
}