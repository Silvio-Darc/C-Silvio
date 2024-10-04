# include <stdio.h>
# include <locale.h>
// Escreva um programa que pergunta ao usuário qual o valor do seu salário bruto e informa o valor a ser descontado de imposto de renda.

int main() {
  setlocale(LC_ALL, "Portuguese_Brazil");
  int somador = 0;
  int qtd_numeros;
  int lida;
  int contador;
  puts("Digite a quantidade de números a serem digitados");
  scanf("%d", &qtd_numeros);
  for(contador = 1; contador < qtd_numeros+1; contador++) {
    puts("Escreva aqui seu número");
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
        somador += lida;
      }
    }
  }
  printf("Soma final: %d", somador);
  return 0;
}