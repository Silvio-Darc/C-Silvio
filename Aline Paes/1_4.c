# include <stdio.h>
# include <locale.h>
// Escreva um programa que pergunta ao usuário qual o valor do seu salário bruto e informa o valor a ser descontado de imposto de renda.

int main() {
  setlocale(LC_ALL, "Portuguese_Brazil");
  int m;
  puts("Digite aqui o número");
  scanf("%d", &m);
  int primeiro_termo = m*(m-1)+1;
  printf("%d^3 = ", m);
  int counter;
  for (counter = 0; counter < m; counter++) {
    printf("%d", primeiro_termo+(2*counter));
    if (counter != m-1) {
      printf("+");
    }
  }

  return 0;
}