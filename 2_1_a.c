# include <stdio.h>
# include <locale.h>
# include <math.h>
// Escreva um programa que pergunta ao usuário qual o valor do seu salário bruto e informa o valor a ser descontado de imposto de renda.
int contadigitos(int num_a, int dig_d);

int main() {
  setlocale(LC_ALL, "Portuguese_Brazil");
  int num_a;
  int dig_d;
  puts("Digite o número a ser verificado");
  scanf("%d", &num_a);
  puts("Digite o dígito a ser verificado");
  scanf("%d", &dig_d);
  contadigitos(num_a, dig_d);
  return 0;
}

int contadigitos(int num_a, int dig_d) {
  int total = 0;
  while (num_a > 0) {
    if (num_a % 10 == dig_d) {
      total++;
    }
    num_a /= 10;
  }
  printf("Total: %d", total);
  return total;
}