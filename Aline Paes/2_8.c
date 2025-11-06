# include <stdio.h>
# include <locale.h>
# include <math.h>

/*
Implemente um programa que leia um inteiro "n" e n inteiros positivos,
determinando o maior desses "n" inteiros.
*/
float leibniz(int n);
int elevecao(int x, int z);

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    puts("Digite a quantidade de termos que serão digitados");
    int qtd_num;
    scanf("%d", &qtd_num);

    int maior = 0;
    for (int i = 0; i < qtd_num; i++) {
        puts("Digite um valor");
        int val_digitado;
        scanf("%d", &val_digitado);
        if (val_digitado > maior) {
            maior = val_digitado;
        }
    }


    printf("O maior valor digitado foi %d", maior);

    return 0;
}
