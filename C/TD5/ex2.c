#include <stdio.h>
#include <stdlib.h>

struct EA {
    unsigned short* array;
    int k;
    int signe;
};

void initEA(struct EA* nombre, int p);
void afficheEA(struct EA nombre);
struct EA additionneEA(struct EA n1, struct EA n2);
struct EA multiplieEA(struct EA n1, struct EA n2);
int myMin(int a, int b);
int myMax(int a, int b);

int main(void){
    struct EA monNombre;
    struct EA monNombre2;
    initEA(&monNombre, 4);
    initEA(&monNombre2, 4);
    for (int i = 0 ; i < monNombre.k; i++) {
        monNombre.array[i] = 9;
        monNombre2.array[i] = 9;
    }
    struct EA maSomme;
    initEA(&maSomme, 4);
    maSomme = additionneEA(monNombre, monNombre2);
    afficheEA(monNombre);
    afficheEA(monNombre2);
    afficheEA(maSomme);
    struct EA monProduit;
    initEA(&monProduit, 4);
    monProduit = multiplieEA(monNombre, monNombre2);
    afficheEA(monProduit);
}

void initEA(struct EA* nombre, int p) {
    nombre->array = (unsigned short*)malloc(sizeof(unsigned short) * p);
    for (int i = 0 ; i < p ; i++) {
        nombre->array[i] = 0;
    }
    nombre->k = p;
}

void afficheEA(struct EA nombre) {
    for (int i = 0 ; i < nombre.k ; i++) {
        printf("%d ", nombre.array[i]);
    }
    printf("\n");
}

struct EA additionneEA(struct EA n1, struct EA n2) {
    struct EA res;
    initEA(&res, myMax(n1.k, n2.k));
    int retenue = 0;
    for (int i = 0 ; i < myMin(n1.k, n2.k) ; i++) {
        unsigned short temp = n1.array[i] + n2.array[i] + retenue;
        if (retenue == 1) {
            retenue = 0;
        }
        if (temp < n1.array[i] || temp < n2.array[i]) {
            retenue = 1;
        }
        res.array[i] = temp;
    }
    // COPIE DES ELEMENTS QUI DEPASSENT DANS LE CAS OU ON A DEUX EA DE TAILLES DIFFERENTES.
    if (n1.k != n2.k) {
        if (n1.k == myMax(n1.k, n2.k)) {
            for (int i = myMax(n1.k, n2.k) - myMin(n1.k, n2.k) ; i > myMin(n1.k, n2.k) ; i--) {
                unsigned short temp = n1.array[i] + retenue;
                if (retenue == 1) {
                    retenue = 0;
                }
                if (temp < n1.array[i]) {
                    retenue = 1;
                }
                res.array[i] = temp;
            }
        }
        else {
            for (int i = myMax(n1.k, n2.k) - myMin(n1.k, n2.k) ; i > myMin(n1.k, n2.k) ; i--) {
                unsigned short temp = n2.array[i] + retenue;
                if (retenue == 1) {
                    retenue = 0;
                }
                if (temp < n2.array[i]) {
                    retenue = 1;
                }
                res.array[i] = temp;
            }
        }
    }
    else if (n1.k == n2.k && retenue == 1) {
        struct EA newRes;
        initEA(&newRes, n1.k + 1);
        newRes[0] = 1;
        for (int i = 0 ; i < n1.k ; i++) {
            newRes.array[i + 1] = res.array[i];
        }
        return newRes;
    }
    return res;
}

/*
struct EA multiplieEA(struct EA n1, struct EA n2) {
    struct EA res;
    res.array = (unsigned short*)malloc(sizeof(unsigned short) * n1.k / 16);
    for (int i = 0 ; i < n1.k / 16 ; i++) {
        res[i] = 0;
    }
    int power = n1.k / 16;
    struct EA temp;
    temp.array = (unsigned short*)malloc(sizeof(unsigned short) * n1.k / 16);
    int times = 0;

    for (int i = 0 ; i < n1.k / 16 ; i++) {
        temp[(n1.k / 16) - power] = n1[(n1.k / 16) - power];
        for (int i = 0 ; i < n1.k / 16 ; i++) {
            if (i != (n1.k / 16) - power) {
                temp[i] = 0;
            }
        }

        power--;
    }
    return res;
}*/

int myMin(int a, int b) {
    if(a < b) {
        return a;
    }
    else {
        return b;
    }
}

int myMax(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}
