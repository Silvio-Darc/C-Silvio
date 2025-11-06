#include "../TABB/TABB.h"

int main(){
    TABB* a = TABB_inicializa();
    a = TABB_insere(a, 30);
    a = TABB_insere(a, 50);
    a = TABB_insere(a, 10);
    a = TABB_insere(a, 5);
    a = TABB_insere(a, 15);
    a = TABB_insere(a, 45);
    a = TABB_insere(a, 55);
    a = TABB_insere(a, 3);
    a = TABB_insere(a, 7);
    a = TABB_insere(a, 13);
    a = TABB_insere(a, 17);
    a = TABB_insere(a, 43);
    a = TABB_insere(a, 47);
    a = TABB_insere(a, 53);
    a = TABB_insere(a, 57);

    TABB_imp_ident(a);
    imp_zigzag(a);
    return 0;
}