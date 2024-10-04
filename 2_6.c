# include <stdio.h>
# include <locale.h>
# include <math.h>

/*
Escreva uma função que recebe dois valores x e z e calcula e retorna x^z
(sem utilizar funções ou operadores de potência prontos).
*/
int elevecao(int x, int z);

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    puts("Digite o valor de x");
    int x;
    scanf("%d", &x);

    puts("Digite o valor de z");
    int z;
    scanf("%d", &z);

    printf("O resultado de %d elevado a %d é igual a %d", x, z, elevecao(x,z));
    return 0;
}

int elevecao(int x, int z) {
    if (z == 0) {
        return 1;
    }
    int elevatorio = x;
    for (int i = 1; i < z; i++) {
        elevatorio *= x;
    }
    return elevatorio;
}
