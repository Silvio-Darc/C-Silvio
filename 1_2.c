# include <stdio.h>
# include <locale.h>
// Escreva um programa que pergunta ao usuário qual o valor do seu salário bruto e informa o valor a ser descontado de imposto de renda.

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    puts("Digite o valor do seu salário");
    float lida;
    scanf("%g", &lida);
    if (lida <= 1499.14) {
        printf("Você está isento");
    }
    else if( 1499.15 <= lida && lida <= 2246.75) {
        printf("Você terá 7,5%% de desconto e terá que pagar %.2f", lida*0.075+122.44);
    }
    else if( 2246.76 <= lida && lida <= 2995.70) {
        printf("Você terá 15%% de desconto e terá que pagar %.2f", lida*0.15+280.94);
    }
    else if (2995.71 <= lida && lida <= 3743.19) {
        printf("Você terá 22,5%% de desconto e terá que pagar %.2f", lida*0.225+505.62);
    }
    else if (lida > 3743.19) {
        printf("Você terá 27,5%% de desconto e terá que pagar %.2f", lida*0.275+692.78);
    }
    return 0;
}