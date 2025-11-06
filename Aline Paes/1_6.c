# include <stdio.h>
int main() {
    puts("Digite um numero");
    int fatorial = 1;
    int n;
    scanf("%d", &n);
    int counter;
    for (counter = n; counter > 1; counter--) {
        fatorial *= counter;
    }
    printf("Fatorial de %d: %d", n, fatorial);
    return 0;
}