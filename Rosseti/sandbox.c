#include <stdio.h>
#include "TAB.h"

int main(){
    TAB* arvore = TAB_cria(4, NULL, NULL);
    arvore->esq = TAB_cria(8, NULL, NULL);
    arvore->esq->esq = TAB_cria(7, NULL, NULL);
    arvore->esq->dir = TAB_cria(2, NULL, NULL);
    arvore->dir = TAB_cria(9, NULL, NULL);
    arvore->dir->esq = TAB_cria(77, NULL, NULL);
    arvore->dir->dir = TAB_cria(32, NULL, NULL);

    TAB* arvore2 = TAB_cria(4, NULL, NULL);
    arvore2->esq = TAB_cria(8, NULL, NULL);
    arvore2->esq->esq = TAB_cria(7, NULL, NULL);
    arvore2->esq->dir = TAB_cria(2, NULL, NULL);
    arvore2->dir = TAB_cria(9, NULL, NULL);
    arvore2->dir->esq = TAB_cria(77, NULL, NULL);
    arvore2->dir->dir = TAB_cria(32, NULL, NULL);

    TAB_imp_ident(arvore);
    puts("");
    printf("%d", igual(arvore, arvore2));
    return 0;
}