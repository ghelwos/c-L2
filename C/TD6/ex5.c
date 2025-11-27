#include <stdio.h>

enum cellType {
    whiteFirst, blackFirst
};

void drawGrid(int t, int c);
void drawLine(int t, int c, enum cellType firstCell);

int main(void) {
    int t, c;
    printf("Veuillez entrer la taille d'une case : ");
    scanf("%d", &c);
    printf("Veuillez le nombre de cases par ligne : ");
    scanf("%d", &t);
    drawGrid(t, c);
    }

void drawGrid(int t, int c) {
    for (int i = 0 ; i < t ; i++) {
        if (i % 2 == 0) {
            drawLine(t, c, blackFirst);
        }
        else {
            drawLine(t, c, whiteFirst);
        }
        printf("\n");
    }
}

void drawLine(int t, int c, enum cellType firstCell) {
    if (firstCell == blackFirst) {
        for (int i = 0 ; i < c ; i++) {
            char currentChar = 'X';
            for (int j = 0 ; j < c * t ; j++) {
                printf("%c", currentChar);
                if ((j + 1) % c == 0) {
                    if (currentChar == 'X') {
                        currentChar = '.';
                    }
                    else {
                        currentChar = 'X';
                    }
                }
            }
            if (i != c - 1) {
                printf("\n");
            }
        }
    }

    else  {
        for (int i = 0 ; i < c ; i++) {
            char currentChar = '.';
            for (int j = 0 ; j < c * t ; j++) {
                printf("%c", currentChar);
                if ((j + 1) % c == 0) {
                    if (currentChar == 'X') {
                        currentChar = '.';
                    }
                    else {
                        currentChar = 'X';
                    }
                }
            }
            if (i != c - 1) {
                printf("\n");
            }
        }
    }
}