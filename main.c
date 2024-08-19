#include <stdio.h>
#include <stdlib.h>

#define PAGESIZE 4096

int main() {
    FILE *f;
    long fileSize, pageCount, offsetDiff;

    f = fopen("./kjv.txt", "r");   
    if (!f) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    fseek(f, 0, SEEK_END);
    fileSize = ftell(f);
    fseek(f, 0, SEEK_SET);

    pageCount = fileSize / PAGESIZE;
    offsetDiff = fileSize % PAGESIZE;

    // Aloca memória para ler o arquivo
    char *data = malloc(fileSize + 1);  
    if (!data) {
        perror("Erro ao alocar memória");
        fclose(f);
        return 1;
    }

    
    fread(data, 1, fileSize, f);
    data[fileSize] = '\0';  

    
    printf("\nConteúdo do arquivo:\n");
    printf("%s\n", data);

    printf("\nO arquivo 'kjv.txt' tem %ld bytes.\n", fileSize);
    printf("\nIsso equivale a %ld paginas de memoria virtual e um offset de %ld bytes.\n", pageCount, offsetDiff);
    printf("\nEndereco inicial: %p\n", (void *)data);
    printf("\nEndereco final: %p\n", (void *)(data + fileSize - 1));

    fclose(f);
    free(data);

    return 0;
}
