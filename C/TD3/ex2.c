#include <stdio.h>
#include <stdbool.h>

void sort(int* array, int size);

int main(void) {
    int n = 0;
    printf("Entrez une limite n : ");
    scanf("%d", &n);
    printf("\n");
    int array[n];
    int sortedArray[n];
    for (int i = 0 ; i < n ; i++) {
        sortedArray[i] = i;
        printf("Entrez une valeur pour le tableau : ");
        scanf("%d", &array[i]);
        printf("\n");
    }
    sort(array, n);
    bool isSorted = true;
    for (int i = 0 ; i < n ; i++) {
        if (array[i] != sortedArray[i]) {
            isSorted = false;
        }
    }
    if (isSorted) {
        printf("Le tableau est bel est bien une permutation.\n");
    }
    else {
        printf("Le tableau n'est pas une permutation.\n");
    }
}

void sort(int* array, int size) {
   for (int i = 0 ; i < size - 1 ; i++) {
       for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] =  temp;
            }
       }
   }
}