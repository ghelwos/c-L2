#include <stdio.h>

int main(void) {
    int age = 0;
    printf("Entrez votre age : \n");
    scanf("%i", &age);

    printf("Vous devriez vous inscrire dans la categorie ");
    
    switch(age) {
        case 5:
        case 6: {
            printf("poussin.\n");
            break;
        }
        case 7:
        case 8: {
            printf("diablotin.\n");
            break;
        }
        case 9:
        case 10: {
            printf("preminime.\n");
            break;
        }
        case 11:
        case 12: {
            printf("minime.\n");
            break;
        }
        case 13:
        case 14: {
            printf("cadet.\n");
            break;
        }
        case 15:
        case 16: {
            printf("scolaire.\n");
            break;
        }
        case 17:
        case 18: {
            printf("minime.\n");
            break;
        }
        default: {
            printf("senior.\n");
            break;
        }
    }
}