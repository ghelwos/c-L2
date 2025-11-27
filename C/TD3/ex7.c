#include <stdio.h>
#include <stdlib.h>

int** matrixProduct2x2(int **mat1, int ** mat2);
void afficheMatrice(int **mat);
int** fiboMatrixProduct(int **mat, int iterations);

int main(void) {
    /*
    int n = 0;
    printf("Veuillez entrer le n : ");
    scanf("%i", &n);
    int fiboArr[n + 1];
    fiboArr[0] = 0;
    fiboArr[1] = 1;
    for(int i = 2 ; i < n + 1 ; i++) {
        fiboArr[i] = fiboArr[i - 1] + fiboArr[i - 2];
    }
    printf("%i\n", fiboArr[n]);*/

    int **mat;
    mat = (int **)malloc(sizeof(int*) * 2);
    for (int i = 0 ; i < 2 ; i++) {
        mat[i] = (int *)malloc(sizeof(int) * 2);
    }
    mat[0][0] = 1;
    mat[0][1] = 1;
    mat[1][0] = 1;
    mat[1][1] = 0;
    int n = 0;
    scanf("%i", &n);
    mat = fiboMatrixProduct(mat, n);
    afficheMatrice(mat);
    return 0;

}

int** matrixProduct2x2(int **mat1, int **mat2) {
    int **res;
    res = (int **)malloc(sizeof(int*) * 2);
    for (int i = 0 ; i < 2 ; i++) {
        res[i] = (int *)malloc(sizeof(int) * 2);
    }
    res[0][0] = mat1[0][0] *  mat2[0][0] + mat1[0][1] *  mat2[1][0];
    res[0][1] = mat1[0][0] *  mat2[0][1] + mat1[0][1] *  mat2[1][1];
    res[1][0] = mat1[1][0] *  mat2[0][0] + mat1[1][1] *  mat2[1][0];
    res[1][1] = mat1[1][0] *  mat2[0][1] + mat1[1][1] *  mat2[1][1];
    return res;
}

void afficheMatrice(int **mat) {
    printf("%i | %i\n", mat[0][0], mat[0][1]);
    printf("%i | %i\n", mat[1][0], mat[1][1]);
}

int** fiboMatrixProduct(int **mat, int iterations) {
    int **F;
    F = (int **)malloc(sizeof(int*) * 2);
    for (int i = 0 ; i < 2 ; i++) {
        F[i] = (int *)malloc(sizeof(int) * 2);
    }
    F[0][0] = 1;
    F[0][1] = 1;
    F[1][0] = 1;
    F[1][1] = 0;
    for (int i = 0 ; i < iterations ; i++) {
        mat = matrixProduct2x2(mat,F);
    }
    return mat;
}