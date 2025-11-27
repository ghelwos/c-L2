#include <stdio.h>

int getMax(int* arr, int size);
int getMin(int* arr, int size);

int main(int argc, char* argv[]) {
    int indexes[26];
    for (int i  = 0 ; i < 26 ; i++) {
        indexes[i] = 0;
    }
    while (*argv[argc - 1] != '\0') {
        indexes[*argv[argc - 1] - 97] ++;
        argv[argc - 1]++;
    }
    for (int i  = 0 ; i < 26 ; i++) {
        printf("%i\n", indexes[i]);
    }
    char c = getMin(indexes, 26);
    printf("Le caractere avec la plus faible occurence est le %c.\n", c + 97);
    c = getMax(indexes, 26);
    printf("Le caractere avec la plus forte occurence est le %c.\n", c + 97);
    return 0;
}

int getMax(int* arr, int size) {
    int res = arr[0];
    for (int i = 0 ; i < size ; i++) {
        if (res < arr[i]) {
            res = i;
        }
    }
    return res;
}

// DANS CE CONTEXTE ON CHERCHE LE NOMBRE QUI SORT LE MOINS POSSIBLE HORS 0 (EVIDEMMENT)
int getMin(int* arr, int size) {
    int res = arr[0];
    for (int i = 0 ; i < size ; i++) {
        if (res > arr[i] && arr[i] != 0) {
            res = i;
        }
    }
    return res;
}