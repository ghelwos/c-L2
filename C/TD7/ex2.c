#include <stdio.h>

int partInput(char* filename, int k); // Retournera le nombre de parties crees par le fichier.
int getSize(char* filename);
void reconstruct(int nbParts);

int main(int argc, char* argv[]) {
    argc--;
    argv++;

    int bytePacks;
    printf("Veuillez entrer le nombre d'octets par partie : ");
    scanf("%d", &bytePacks);

    int nbParts;
    nbParts = partInput(argv[0], bytePacks);

    reconstruct(nbParts);

    return 0;
}

int getSize(char* filename) {
    FILE* file;
    file = fopen(filename, "rb");
    fseek(file, 0L, SEEK_END);
    int res = ftell(file);
    fclose(file);
    return(res);
}

int partInput(char* filename, int k) {
    FILE* file;
    int fileSize = getSize(filename);
    file = fopen(filename, "rb");
    int i;
    char partName[16] = "input_part_i.txt";
    for (i = 0 ; i < fileSize / k ; i++) {
        FILE* partFile;
        partName[11] = i + 48;
        partFile = fopen(partName, "wb");
        char buffer[k];
        fread(buffer, sizeof(buffer), 1, file);
        fwrite(buffer, k, 1, partFile);
        fclose(partFile);
    }
    if (fileSize % k != 0) {
        FILE* partFile;
        partName[11] = i + 48;
        partFile = fopen(partName, "wb");
        char buffer[fileSize % k];
        fread(buffer, sizeof(buffer), 1, file);
        fwrite(buffer, sizeof(buffer), 1, partFile);
        fclose(partFile);
        return (fileSize / k) + 1;
    }
    fclose(file);
    return fileSize / k;
}

void reconstruct(int nbParts) {
    FILE * file;
    file = fopen("result.txt", "wb");
    for (int i = 0 ; i < nbParts ; i++) {
        FILE* partFile;
        char partName[16] = "input_part_i.txt";
        partName[11] = i + 48;
        partFile = fopen(partName, "rb");
        int partSize = getSize(partName);
        char buffer[partSize];
        fread(buffer, sizeof(buffer), 1, partFile);
        fwrite(buffer, sizeof(buffer), 1, file);
        fclose(partFile);
    }
    fclose(file);
}