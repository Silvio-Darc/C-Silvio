# include <stdio.h>
# include <locale.h>
# include <math.h>
// Construa uma função sufixo que, dados dois inteiros positivos a e b, verifica se b corresponde aos últimos dígitos de a.

int sufixo(int a, int b);
int segmento(int a, int b);

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    puts("Digite o valor de a");
    int a;
    scanf("%d", &a);
    puts("Digite o valor de b");
    int b;
    scanf("%d", &b);
    if (sufixo(a, b)) {
        puts("sufixo");
    }
    else {
        puts("não é sufixo");
    }
    if (segmento(a, b) == 1) {
        puts("b é segmento de a");
    }
    else if (segmento(a, b) == 2) {
        puts("a é segmento de b");
    }
    else {
        puts("não são segmentos");
    }

    return 0;
}

int sufixo(int a, int b) {
    int i;
    for (i = 0; b / 10 != 0; i++) {
        if (a % 10 != b % 10) {
            return 0;
        }
        a /= 10;
        b /= 10;
    }
    return 1;
}

int segmento(int a, int b) {
    if (a > b) {
        for (;a / 10 != 0; a /= 10) {
            if (sufixo(a, b)) {
                return 1;
            }
        }
        return 0;
    }
    else {
        for (;b / 10 != 0; b /= 10) {
            if (sufixo(b, a)) {
                return 2;
            }
        }
        return 0;
    }

}