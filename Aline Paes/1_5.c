# include <stdio.h>
# include <locale.h>
# include <math.h>
// Escreva um programa que pergunta ao usuário qual o valor do seu salário bruto e informa o valor a ser descontado de imposto de renda.

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    int a;
    int b;
    int c;
    puts("Digite o valor de a");
    scanf("%d", &a);
    puts("Digite o valor de b");
    scanf("%d", &b);
    puts("Digite o valor de c");
    scanf("%d", &c);
    int delta = pow(b, 2) - (4*a*c);
    if (delta == 0) {
        printf("Raíz: %d", (-b)/(2*a));
    }
    if (delta > 0) {
        printf("Raízes: %f, %f", (-b+sqrt(delta))/(2*a), (-b-sqrt(delta))/(2*a));
    }
    else {
        printf("Raízes: %f, %f", (-b+sqrt(-delta))/(2*a), (-b-sqrt(-delta))/(2*a));
    }
    return 0;
}