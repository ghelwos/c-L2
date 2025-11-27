#include <stdio.h>
#include <string.h>

void pairOuImpair();
void ordonneValeurs();

int main(int argc, char* argv[]) {
    if (strcmp(argv[argc - 1], "1") == 0) {
        pairOuImpair();
    } 
    else {
        ordonneValeurs();
    }

    return 0;
}

void pairOuImpair() {
    int valeur = 0;
    printf("Entrez une valeur :");
    scanf("%i", &valeur);
    if (valeur % 2 == 0) {
        printf("La valeur est paire.\n");
    }
    else {
        printf("La valeur est impaire.\n");
    }
}

void ordonneValeurs() {
    int a = 0;
    int b = 0;
    printf("Entrez une premiere valeur :");
    scanf("%i", &a);
    printf("Entrez une seconde valeur :");
    scanf("%i", &b);
    
    if (a >= b) {
        printf("%i %i", a, b);
    }
    else {
        printf("%i %i", b, a);
    }
}