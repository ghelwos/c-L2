#include <stdio.h>
#include <unistd.h>
#include <string.h>

//void myPrint(char* str);
//void myPrint2(char* str);
int mylen(char* string);
int countLettersAndNumbers(char* str, int length);
void printReverse(char* str);
int occOfChar(char* str, char search);
int posOfChar(char* str, char search);
int compareStr(char* str1, char* str2);
void printUpperCase(char* str);

int main(void) {
    char mystring[255];
    printf("Veuillez entrer une chaine de caracteres : \n");
    scanf("%s", mystring);
    /*
    char mystring2[255];
    char c = '0';
    printf("Veuillez entrer le caractere a rechercher : \n");
    scanf("%c", &c);
    printf("Veuillez entrer une chaine de caracteres : \n");
    scanf("%s", mystring2);
    printf("Longueur de la chaine : %d\n", mylen(mystring));
    printf("Nombre de chiffres et de lettres : %d\n", countLettersAndNumbers(mystring, mylen(mystring)));
    printReverse(mystring);
    printf("Il y a %d occurences de cette lettre dans la chaine.\n", occOfChar(mystring, c));
    printf("La premiere occurence de cette lettre dans la chaine est a la position : %d.\n", posOfChar(mystring, c));
    printf("%i\n", compareStr(mystring, mystring2));
    int a = 2;*/
    printUpperCase(mystring);
    return 0;
}

int mylen(char* string) {
    int res = 0;
    while (*string != '\0') {
        string++;
        res++;
    }
    string -= res;
    return res;
}

int countLettersAndNumbers(char* str, int length) {
    int res = 0;
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            res++;
        }
        if (*str >= 'A' && *str <= 'Z') {
            res++;
        }
        if (*str >= '0' && *str <= '9') {
            res++;
        }
        str++;
    }
    str -= length;
    return res;
}

void printReverse(char* str) {
    int i = 0;
    while (*str != '\0') {
        printf("%c", *str);
        str++;
        i++;
    }
    printf("\n");
    for (int j = i ; j >= 0 ; j--) {
        printf("%c", *str);
        str--;
    }
    printf("\n");
}

int occOfChar(char* str, char search) {
    int i = 0;
    int res = 0;
    while (*str != '\0') {
        str++;
        i++;
        if (*str == search) {
            res++;
        }
    }
    str -= i;
    return res;
}

int posOfChar(char* str, char search) {
    int i = 0;
    int res = -1;
    while (*str != '\0') {
        if (*str == search && res == -1) {
            res = i;
        }
        str++;
        i++;
    }
    str -= i;
    return res;
}

int compareStr(char* str1, char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] > str2[i]) {
            return 1;
        }
        else if (str1[i] < str2[i]) {
            return -1;
        }
        i++;
    }

    if (str1[i] == '\0' && str2[i] != '\0') {
        return 1;
    }

    if (str1[i] != '\0' && str2[i] == '\0') {
        return -1;
    }

    return 0;
}

void printUpperCase(char* str) {
    int i =0;
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            *str -= 32;
        }
        str++;
        i++;
    }
    str -= i;
    printf("%s\n", str);
}

/*void myPrint(char* str) {
    while (*str != '\0') {
        printf("%c", *str);
        str++;
    }
    printf("\n");
}*/

/*
void myPrint2(char* str) {
    char c = str[0];
    int i = 0;
    while (c != '\0') {
        c = str[i];
        printf("%s", &c);
        i++;
    }
    printf("\n");
}*/