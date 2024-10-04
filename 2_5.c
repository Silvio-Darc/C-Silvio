# include <stdio.h>
# include <locale.h>
# include <math.h>

/*
Escreva uma função que recebe por parâmetro um valor inteiro e positivo "n"
e retorna o valor de S, calculado pela fórmula
S = 1 + 1/1! + 1/2! + 1/3! + 1/N!
*/

int fatorial(int n);
float formula(int n);

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    puts("Digite o valor de n");
    int n;
    scanf("%d", &n);
    printf("S = %.2f", formula(n));
    return 0;
}

float formula(int n) {
    float s = 1.0;
    for (int i = 1; i <= n; i++) {
        s += 1.0 / fatorial(i);
    }
    return s;
}

int fatorial(int n) {
    int produtorio = 1;
    for (; n > 1; n--) {
        produtorio *= n;
    }
    return produtorio;
}
