#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#define PAGESIZE 4096

int main() {
    int fd;
    struct stat fileStat;
    char *map;
    off_t fileSize;
    long pageCount, offsetDiff;

    fd = open("kjv.txt", O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    if (fstat(fd, &fileStat) == -1) {
        perror("Erro ao obter o tamanho do arquivo");
        close(fd);
        return 1;
    }

    fileSize = fileStat.st_size;
    pageCount = fileSize / PAGESIZE;
    offsetDiff = fileSize % PAGESIZE;

    map = mmap(NULL, fileSize, PROT_READ, MAP_PRIVATE, fd, 0);
    if (map == MAP_FAILED) {
        perror("Erro ao mapear o arquivo");
        close(fd);
        return 1;
    }

    printf("\nConteúdo do arquivo:\n");
    fwrite(map, 1, fileSize, stdout);

    printf("\n\nO arquivo 'kjv.txt' tem %ld bytes.\n", fileSize);
    printf("Isso equivale a %ld páginas de memória virtual e um offset de %ld bytes.\n", pageCount, offsetDiff);

    munmap(map, fileSize);
    close(fd);

    return 0;
}
