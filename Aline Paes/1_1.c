# include <stdio.h>
// Escreva um programa em C que decide se um número é primo. Pergunte ao usuário qual número ele deseja verificar.
int main() {
    int lida;
    puts("Escreva qual numero voce deseja verificar se eh primo: ");
    scanf("%d", &lida);
    if (lida % 2 != 0 || lida == 2) {
        int div = 0;
        int i = 3;
        while (div == 0 && i < lida) {
            if (lida % i == 0){
                div++;
            }
            i += 2;
        }
        if (div == 0) {
            printf("%d eh um numero primo", lida);
        }
        else {
            printf("%d nao eh um numero primo", lida);
        }
    }
    else {
        printf("%d nao eh um numero primo", lida);
    }

    return 0;
}