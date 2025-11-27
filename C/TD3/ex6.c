#include <stdio.h>

int** matrixProduct2x2(int** mat1, int **mat2);

int main(void) {
    
}

int** matrixProduct2x2(int** mat1, int **mat2) {
    int res[2][2] = { {mat1[0][0] *  mat2[0][0] + mat1[0][1] *  mat2[1][0],
                       mat1[0][0] *  mat2[0][1] + mat1[0][1] *  mat2[1][1]},
                      {mat1[1][0] *  mat2[0][0] + mat1[1][1] *  mat2[1][0],
                       mat1[1][0] *  mat2[0][1] + mat1[1][1] *  mat2[1][1]}};
    return res;
}