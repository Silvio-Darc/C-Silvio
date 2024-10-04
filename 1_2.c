# include <stdio.h>
# include <locale.h>
// Escreva um programa que pergunta ao usu�rio qual o valor do seu sal�rio bruto e informa o valor a ser descontado de imposto de renda.

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    puts("Digite o valor do seu sal�rio");
    float lida;
    scanf("%g", &lida);
    if (lida <= 1499.14) {
        printf("Voc� est� isento");
    }
    else if( 1499.15 <= lida && lida <= 2246.75) {
        printf("Voc� ter� 7,5%% de desconto e ter� que pagar %.2f", lida*0.075+122.44);
    }
    else if( 2246.76 <= lida && lida <= 2995.70) {
        printf("Voc� ter� 15%% de desconto e ter� que pagar %.2f", lida*0.15+280.94);
    }
    else if (2995.71 <= lida && lida <= 3743.19) {
        printf("Voc� ter� 22,5%% de desconto e ter� que pagar %.2f", lida*0.225+505.62);
    }
    else if (lida > 3743.19) {
        printf("Voc� ter� 27,5%% de desconto e ter� que pagar %.2f", lida*0.275+692.78);
    }
    return 0;
}