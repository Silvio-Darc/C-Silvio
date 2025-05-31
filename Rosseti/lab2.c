#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "TLSEINT.h"
#include "TAB.h"
#include "TABB.h"



TLSEINT* misc(TAB *a, int elem){
  if (a){
    TLSEINT* lista = (TLSEINT*) malloc (sizeof(TLSEINT));
    if (a->info == elem){
      lista->lim_inf = INT_MIN;
      lista->lim_sup = INT_MAX;
      return lista;
    }
    if(a->info < elem){
      lista->lim_inf = a->info;
      lista->lim_sup = INT_MAX;
    }
    else{
      lista->lim_inf = INT_MIN;
      lista->lim_sup = a->info;
    }
    lista->prox = misc(a->esq, elem);
    if (lista->prox) return lista;
    lista->prox = misc(a->dir, elem);
    if (!lista->prox) {
      free(lista);
      return NULL;
    }
    return lista;
  }
  return NULL;
}

TLSEINT* misc2(TABB *a, int elem){
  if (a){
    TLSEINT* lista = (TLSEINT*) malloc (sizeof(TLSEINT));
    if (a->info == elem){
      lista->lim_inf = INT_MIN;
      lista->lim_sup = INT_MAX;
      return lista;
    }
    if(a->dir && a->info < elem){
      lista->lim_inf = a->info;
      lista->lim_sup = INT_MAX;
      lista->prox = misc2(a->dir, elem);
    }
    else if(a->esq && a->info > elem){
      lista->lim_inf = INT_MIN;
      lista->lim_sup = a->info;
      lista->prox = misc2(a->esq, elem);
    }
    if (!lista->prox) {
      free(lista);
      return NULL;
    }
    return lista;
  }
  return NULL;
}


int teste_arv(TAB* a);
int teste_arv_aux(TAB* a);

int teste_arv(TAB* a){
  if (!a) return 1;
  if((!a->esq && !a->dir) || (a->esq && a->dir)){
    if(teste_arv_aux(a->esq) && teste_arv_aux(a->dir)){
      return 1;
    }
  }
  return 0;
}

int teste_arv_aux(TAB* a){
  if (!a) return 1;
  if((a->esq && !a->dir) || (a->dir && !a->esq)){
    if(teste_arv(a->esq) && teste_arv(a->dir)){
      return 1;
    }
  }
  return 0;
}


int main(int argc, char const *argv[])
{
  TAB* arvore = TAB_cria(3, NULL, NULL);
  arvore->esq = TAB_cria(1, NULL, NULL);
  arvore->esq->esq = TAB_cria(4, NULL, NULL);
  arvore->dir = TAB_cria(5, NULL, NULL);
  arvore->dir->dir = TAB_cria(7, NULL, NULL);
  //arvore->dir->esq = TAB_cria(8, NULL, NULL);
  TLSEINT_imprime(misc(arvore, 1));
  TAB_libera(arvore);
  return 0;
}
