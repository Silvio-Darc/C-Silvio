#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_int(const void *x, const void *y) {
    int *ix = (int*)x,
    *iy = (int*)y;
    if ((*ix) < (*iy)) return -1;
    if ((*ix) == (*iy)) return 0;
    return 1;
}

int class_ini(char* ent, char* part, int tam) {
    FILE* fp = fopen(ent, "r");
    if (!fp){return 1;}
    int i, vet[tam], r, elem, n = 0;
    while (1) {
        i = 0;
        while (i<tam) {
            r = fscanf(fp, "%d", &elem);
            if (r != 1)break;
            vet[i++] = elem;
        }
        if (!i) {
            fclose(fp);
            return n;
        }
        qsort(vet, i, sizeof(int), cmp_int);
        n++;
        char nome_part[51], num[5];
        strcpy(nome_part, part);
        sprintf(num, "%d.txt", n);
        strcat(nome_part,num);
        FILE* fps = fopen(nome_part, "w");
        if (!fps) exit(1);
        int j;
        for (j = 0; j<i; j++) {
            fprintf(fps, "%d\n", vet[j]);
        }
        fclose(fps);
    }
}