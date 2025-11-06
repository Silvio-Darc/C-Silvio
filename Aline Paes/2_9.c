# include <stdio.h>
# include <locale.h>
# include <math.h>

/*
Escreva um programa que leia caracteres da entrada padrão e escreva
para a saída padrão os caracteres lidos de código compreendido entre 32 e
127 (extremos incluídos), passando para maiúsculas as letras minúsculas. Por
exemplo, a entrada As armas e os 7 barões, deve virar AS ARMAS E OS 7
BARES. Use apenas a função getchar().
*/

void conversora();

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    conversora();

    return 0;
}

void conversora() {
    int ch = getchar();
    while (ch != 10) {
        if (97 <= ch && ch <= 122) {
            printf("%c", ch-32);
        }
        else if(32 <= ch && ch <= 127) {
            printf("%c", ch);
        }
        ch = getchar();
    }
}