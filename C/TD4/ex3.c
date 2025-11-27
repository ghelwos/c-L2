#include <stdio.h>

union ascii {
    char c;
    unsigned short code;
};

char intToChar(unsigned int code);
unsigned int charToInt(char character);

int main(void) {
    for (unsigned int i = 0 ; i < 128 ; i++) {
        printf("%c\n", intToChar(i));
    }
}

char intToChar(unsigned int code) {
    union ascii u;
    u.code = code;
    return(u.c);
}

unsigned int charToInt(char character) {
    union ascii u;
    u.c = character;
    return(u.code);
}