#include <stdio.h>
#include <stdlib.h> 

int** alloueMatrice(int** matrice, int n, int m);
void alloueMatriceReference(int*** matrice, int n, int m);
void printMatrice(int** matrice, int n, int m);
int** produitMatriciel(int** m1, int** m2, int r1, int c1, int r2, int c2, int** res);
void transposeMatrice(int** m1, int n, int m, int*** res);
void detruitMatrice(int** matrice, int nbLignes);

int main(void) {
    int** mat1;
    int** mat2;
    int n, m;
    printf("Veuillez entrer la taille n : ");
    scanf("%d", &n);
    printf("Veuillez entrer la taille m : ");
    scanf("%d", &m);

    mat1 = alloueMatrice(mat1, n, m);
    alloueMatriceReference(&mat2, n, m);

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            mat1[i][j] = i+j;
            mat2[i][j] = i+j;
        }
    }

    printMatrice(mat1, n, m);
    printf("\n");
    printMatrice(mat2, n, m);
    printf("\n");

    int** res;
    alloueMatriceReference(&res, n, m);
    res = produitMatriciel(mat1, mat2, 4, 3, 4, 3, res);
    //printMatrice(res, 4, 3);
    int** res2;
    transposeMatrice(mat1, n, m, &res2);
    printMatrice(res2, m, n);

    for (int i = 0 ; i < n ; i++) {
        free(mat1[i]);
        free(mat2[i]);
    }
    free(mat1);
    free(mat2);
}

int** alloueMatrice(int** matrice, int n, int m) {
    matrice = (int**)malloc(n * sizeof(int*));
    for (int i = 0 ; i < n ; i++) {
        matrice[i] = (int*)malloc(m * sizeof(int));
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            matrice[i][j] = 0;
        }
    }
    return matrice;
}

void alloueMatriceReference(int*** matrice, int n, int m) {
    *matrice = (int**)malloc(n * sizeof(int*));
    for (int i = 0 ; i < n ; i++) {
        (*matrice)[i] = (int*)malloc(m * sizeof(int));
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            (*matrice)[i][j] = 0;
        }
    }
}

void printMatrice(int** matrice, int n, int m) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

int** produitMatriciel(int** m1, int** m2, int r1, int c1, int r2, int c2, int **res)
{
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < r2; k++) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return res;
}

void transposeMatrice(int** m1, int n, int m, int*** res) {
    alloueMatriceReference(res, m, n);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            (*res)[j][i] = m1[i][j];
        }
    }
}

void detruitMatrice(int** matrice, int nbLignes) {
    for (int i = 0 ; i < n ; i++) {
        free(matrice[i]);
    }
    free(matrice);
}