#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int countChar(char* filename);
int countLines(char* filename);
int countWords(char* filename);

int main(int argc, char* argv[]) {
    argc--;
    argv++;

    if ( argc == 0 ) {
        printf( "ERR : Veuillez entrer un nom de fichier.\n" );
        return -1;
    }

    printf("Il y a %d caracteres non-espace dans le fichier.\n", countChar(argv[0]));
    printf("Il y a %d mots dans le fichier.\n", countWords(argv[0]));
    printf("Il y a %d lignes dans le fichier.\n", countLines(argv[0]));

    return 0;
}

int countChar(char* filename) {
    FILE* file;
    int character;
    int res = 0;

    file = fopen(filename, "r");
    if ( file == NULL ) {
        printf( "ERR : Le fichier n'a pas pu etre ouvert. %s\n", filename );
        return -1;
    }

    character = fgetc(file);
    while (character != EOF) {
        if (character != ' ' && character != '\n') {
            res++;
        }
        character = fgetc(file);
    }

    fclose(file);

    return res;
}

int countLines(char* filename) {
    FILE* file;
    int character;
    int res = 0;

    file = fopen(filename, "r");
    if ( file == NULL ) {
        printf( "ERR : Le fichier n'a pas pu etre ouvert. %s\n", filename );
        return -1;
    }

    character = fgetc(file);
    while (character != EOF) {
        if (character == '\n') {
            res++;
        }
        character = fgetc(file);
    }

    fclose(file);

    return res;
}

int countWords(char* filename) {
    FILE* file;
    int character;
    int res = 0;
    

    file = fopen(filename, "r");
    if ( file == NULL ) {
        printf( "ERR : Le fichier n'a pas pu etre ouvert. %s\n", filename );
        exit( 0 );
    }

    character = fgetc(file);
    bool isInWord = false;
    while (character != EOF) {
        if (isspace(character)) {
            if (isInWord) {
                isInWord = false;
            }
        } else {
            if (!isInWord) {
                isInWord = true;
                res++;
            }
        }
        character = fgetc(file);
    }

    fclose(file);

    return res;
}