#include "../TABB/TABB.h"
#include "../TLSE/TLSE.h"

//imprimir nível par: esq -> dir
//imprimir nível ímpar: esq <- dir
void imp_zigzag(TABB* a){
    TLSE* l1 = TLSE_inicializa();
    TLSE* l2 = TLSE_inicializa();
    if(!a) return;
    l1 = TLSE_insere(l1, a->info);
    while(l1 || l2){
        while(l1){
            TABB* atual = TABB_busca(a, l1->info);
            if(atual->esq) l2 = TLSE_insere(l2, atual->esq->info);
            if(atual->dir) l2 = TLSE_insere(l2, atual->dir->info);
            printf("%d ", l1->info);
            TLSE* temp = l1;
            l1 = l1->prox;
            free(temp);
        }
        while(l2){
            TABB* atual = TABB_busca(a, l2->info);
            if(atual->dir) l1 = TLSE_insere(l1, atual->dir->info);
            if(atual->esq) l1 = TLSE_insere(l1, atual->esq->info);
            printf("%d ", l2->info);
            TLSE* temp = l2;
            l2 = l2->prox;
            free(temp);
        }
    }
    printf("\n");
}

int main(){
    TABB* a = TABB_inicializa();
    a = TABB_insere(a, 30);
    a = TABB_insere(a, 50);
    a = TABB_insere(a, 10);
    a = TABB_insere(a, 5);
    //a = TABB_insere(a, 15);
    a = TABB_insere(a, 45);
    a = TABB_insere(a, 55);
    a = TABB_insere(a, 3);
    a = TABB_insere(a, 7);
    a = TABB_insere(a, 13);
    a = TABB_insere(a, 17);
    a = TABB_insere(a, 43);
    a = TABB_insere(a, 47);
    a = TABB_insere(a, 53);
    //a = TABB_insere(a, 57);
    a = TABB_insere(a, 2);
    a = TABB_insere(a, 4);
    a = TABB_insere(a, 6);
    a = TABB_insere(a, 8);
    //a = TABB_insere(a, 12);
    a = TABB_insere(a, 14);
    a = TABB_insere(a, 16);
    a = TABB_insere(a, 18);
    //a = TABB_insere(a, 42);
    a = TABB_insere(a, 44);
    a = TABB_insere(a, 46);
    a = TABB_insere(a, 48);
    //a = TABB_insere(a, 52);
    a = TABB_insere(a, 54);
    a = TABB_insere(a, 56);
    a = TABB_insere(a, 58);


    TABB_imp_ident(a);
    imp_zigzag(a);
    TABB_libera(a);
    return 0;
}
