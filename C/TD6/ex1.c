#include <stdio.h>

int additionRecursive(int a, int b);
int soustractionRecursive(int a, int b);
int selecteurAddiSous(int a, int b);
int multiplicationRecursive(int a, int b, int res);

int main(void) {
    int a, b;
    printf("Veuillez entrer a : ");
    scanf("%d", &a);
    printf("Veuillez entrer b : ");
    scanf("%d", &b);

    printf("Le résultat de l'addition est : %d\n", additionRecursive(a, b));
    printf("Le résultat de la soustraction est : %d\n", soustractionRecursive(a, b));
    printf("Le résultat de la multiplication est : %d\n", multiplicationRecursive(a, b, 0));
}

int additionRecursive(int a, int b) {
    if (b > 0) {
        return(additionRecursive(a + 1, b - 1));
    }
    else if (b < 0){
        return(additionRecursive(a - 1, b + 1));
    }
    else {
        return a;
    }
}

int soustractionRecursive(int a, int b) {
    if (b > 0) {
        return(soustractionRecursive(a - 1, b - 1));
    }
    else if (b < 0){
        return(soustractionRecursive(a + 1, b + 1));
    }
    else {
        return a;
    }
}

int multiplicationRecursive(int a, int b, int res) {
    if (b == 0) {
        return res;
    }
    else if (a >= 0 && b > 0) {
        return(multiplicationRecursive(a, b - 1, additionRecursive(res, a)));
    }
    else if (a >= 0 && b < 0) {
        return -(multiplicationRecursive(a,-b, res));
    }
    else if (a <= 0 && b > 0) {
        return -(multiplicationRecursive(-a, b, res));
    }
    else if (a <= 0 && b < 0) {
        return multiplicationRecursive(-a, -b, res);
    }
    else {
        return res;
    }
}