# include <stdio.h>
# include <locale.h>
# include <math.h>

/*
Implemente uma função que retorne uma aproximação do valor de PI, de
acordo com a fórmula de Leibniz abaixo. A função deve receber como entrada
o número que indica a quantidade de termos na série. Após, escreva um
programa completo que leia o número de termos via teclado e chame a função
implementada.
*/
float leibniz(int n);
int elevecao(int x, int z);

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    puts("Digite o número de termos para a aproximação de Pi");
    int num_termos;
    scanf("%d", &num_termos);

    printf("A aproximação de Pi usando %d termo(s) é %.2f", num_termos, leibniz(num_termos));

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

float leibniz(int n) {
    float resultado = 0;

    for (float i = 0; i < n; i++) {
        resultado += elevecao(-1.0, i) / (2*i+1);
    }

    resultado *= 4;
    return resultado;
}