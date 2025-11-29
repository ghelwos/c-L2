#include <stdio.h>
#define SIGN_MASK     0x80000000u  // bit 31
#define EXPO_MASK     0x7F800000u  // bits 30 à 23
#define MANT_MASK     0x007FFFFFu  // bits 22 à 0


typedef union {
    float f;
    unsigned int u;
    struct {
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign     : 1;
    } parts;
} float_32t;

int main(void) {
    float_32t n;

    printf("Veuillez entrer un reel : ");
    scanf("%f", &n.f);
    printf("Version entiere non-signee : %u.\n", n.u);

    unsigned int sign = (n.u & SIGN_MASK) >> 31;
    unsigned int exponent = (n.u & EXPO_MASK) >> 23;
    unsigned int mantissa =  n.u & MANT_MASK;

    printf("Signe : %u, exposant : %u, mantisse %u.\n", sign, exponent, mantissa);

    n.parts.sign = sign;
    n.parts.exponent = exponent;
    n.parts.mantissa = mantissa;

    printf("Le nombre entier-non signe : %u.\n", n.u);

    return 0;
}