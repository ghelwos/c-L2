#include <stdio.h>
#include <stdlib.h>

void printArray(int* array, int size);
void printMaxValue(int* array, int size);
void printMinValue(int* array, int size);
void arrValuesLowerThan(int* array, int size, int comparison);
int * rotateArrayByK(int* array, int size, int k);

int main(void) {
    int array[20];
    for (int i = 0 ; i < 20 ; i++) {
        array[i] = i;
    }
    printArray(array, 20);
    printMaxValue(array, 20);
    printMinValue(array, 20);
    int comparison = 0;
    printf("Entrez la valeur seuil : ");
    scanf("%d", &comparison);
    arrValuesLowerThan(array, 20, comparison);
    int rotationValue = 0;
    printf("Entrez la valeur de rotation : ");
    printArray(array, 20);
    scanf("%d", &rotationValue);
    int * rotatedArray;
    rotatedArray = rotateArrayByK(array, 20, rotationValue);
    printArray(rotatedArray, 20);
}

void printArray(int* array, int size) {
    for (int i = 0 ; i < size ; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void printMaxValue(int* array, int size) {
    int max = array[0];
    for (int i = 0 ; i < size ; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    printf("La valeur maximale est : %d.\n", max);
}

void printMinValue(int* array, int size) {
    int min = array[0];
    for (int i = 0 ; i < size ; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    printf("La valeur minimale est : %d.\n", min);
}

void arrValuesLowerThan(int* array, int size, int comparison) {
    int res = 0;
    for (int i = 0 ; i < size ; i++) {
        if (array[i] < comparison) {
            res++;
        }
    }
    printf("Il y a %d valeurs inferieures a %d dans le tableau.\n", res, comparison);
}

int * rotateArrayByK(int* array,int size, int k){
    int * rotatedArray = malloc(size * sizeof(int));
    for (int i = 0 ; i < size - k ; i++) {
        rotatedArray[i + k] = array[i];
    }
    for (int i = 0 ; i < k ; i++) {
        rotatedArray[i] = array[i + size - k];
    }
    return rotatedArray;
}