#include <stdio.h>

int main(void) {
    int age = 0;
    printf("Entrez votre age : \n");
    scanf("%i", &age);

    printf("Vous devriez vous inscrire dans la categorie ");

    if (age == 5 || age == 6) {
        printf("poussin.\n");
    }
    else if (age == 7 || age == 8) {
        printf("diablotin.\n");
    }
    else if (age == 9 || age == 10) {
        printf("preminime.\n");
    }
    else if (age == 11 || age == 12) {
        printf("minime.\n");
    }
    else if (age == 13 || age == 14) {
        printf("cadet.\n");
    }
    else if (age == 15 || age == 16) {
        printf("scolaire.\n");
    }
    else if (age == 17 || age == 18) {
        printf("minime.\n");
    }
    else if (age > 18) {
        printf("senior.\n");
    }
}