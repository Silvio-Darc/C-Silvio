#include "TABB.h"
#include "TLSE.h"

//Q3 - 2,0 PONTOS
void imp_zz(TABB* a){
  TLSE* l1 = NULL;
  TLSE* l2 = NULL;
  if(!a) return;
  l1 = TLSE_insere(l1, a->info);
  while(l1 || l2){
      while(l1){
          TABB* atual = TABB_busca(l1->info, a);
          if(atual->esq) l2 = TLSE_insere(l2, atual->esq->info);
          if(atual->dir) l2 = TLSE_insere(l2, atual->dir->info);
          printf("%d ", l1->info);
          TLSE* temp = l1;
          l1 = l1->prox;
          free(temp);
      }
      while(l2){
          TABB* atual = TABB_busca(l2->info, a);
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

int main(void){
  int n, m;
  TABB *a = NULL;
  while(1){
    scanf("%d", &n);
    if(n < 0) break;
    a = TABB_insere(n, a);
  }
  TABB_imprime(a);
  
  imp_zz(a);
  TABB_libera(a);
  return 0;
}
