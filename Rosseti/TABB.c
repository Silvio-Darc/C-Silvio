#include "TABB.h"

TABB *TABB_inicializa(void){
  return NULL;
}

TABB *TABB_cria(int raiz, TABB *esq, TABB *dir){
  TABB *novo = (TABB *) malloc(sizeof(TABB));
  novo->info = raiz;
  novo->esq = esq;
  novo->dir = dir;
  return novo;
}

void TABB_imp_pre(TABB *a){
  if(a){
    printf("%d ", a->info);
    TABB_imp_pre(a->esq);
    TABB_imp_pre(a->dir);
  }
}

void TABB_imp_pos(TABB *a){
  if(a){
    TABB_imp_pos(a->esq);
    TABB_imp_pos(a->dir);
    printf("%d ", a->info);
  }
}

void TABB_imp_sim(TABB *a){
  if(a){
    TABB_imp_sim(a->esq);
    printf("%d ", a->info);
    TABB_imp_sim(a->dir);
  }
}

void TABB_imp_aux(TABB *a, int andar){
  int j;
  if(a){
    TABB_imp_aux(a->dir, andar + 1);
    for(j = 0; j <= andar; j++) printf("\t"); //printf("   ");
    printf("%d\n", a->info);
    TABB_imp_aux(a->esq, andar + 1);
  }
  else{
   for(j = 0; j <= andar; j++) printf("\t");
   printf("N\n");
  }
}

void TABB_imp_ident(TABB *a){
  TABB_imp_aux(a, 0);
}

void TABB_libera(TABB *a){
  if(a){
    TABB_libera(a->esq);
    TABB_libera(a->dir);
    free(a);
  }
}

TABB *TABB_busca(TABB *a, int elem){
  if((!a) || (a->info == elem)) return a;
  if(a->info > elem) return TABB_busca(a->esq, elem);
  return TABB_busca(a->dir, elem);
}

TABB *TABB_insere(TABB *a, int elem){
  if(!a) return TABB_cria(elem, NULL, NULL);
  if(a->info > elem) a->esq = TABB_insere(a->esq, elem);
  else if (a->info < elem) a->dir = TABB_insere(a->dir, elem);
  return a;
}

TABB *TABB_retira(TABB *a, int info){
  if(!a) return a;
  if(info < a->info) 
    a->esq = TABB_retira(a->esq, info);
  else if(info > a->info) 
    a->dir = TABB_retira(a->dir, info);
  else{ //info encontrada
    if((!a->esq) && (!a->dir)){ //CASO (1)
      free(a);
      a = NULL;
    }
    else if((!a->esq) || (!a->dir)){ //CASO (2)
      TABB *temp = a;
      if(!a->esq) a = a->dir;
      else a = a->esq;
      free(temp); 
    }
    else{ //CASO (3)
      TABB *filho = a->esq;
      while(filho->dir) filho = filho->dir;
      a->info = filho->info;
      filho->info = info;
      a->esq = TABB_retira(a->esq, info);
    }
  }
  return a; 
}

TABB* maior(TABB* a) {
  if (a->dir) return maior(a->dir);
  return a;
}

TABB* menor(TABB* a) {
  if (a->esq) return menor(a->esq);
  return a;
}

TABB* retira_impares(TABB* a) {
  if (a) {
    a->esq = retira_impares(a->esq);
    a->dir = retira_impares(a->dir);
    if (a->info % 2 != 0) {
      TABB* temp;
      if (!a->esq) temp = a->dir;
      else if (!a->dir) temp = a->esq;
      else {//caso 2 filhos
        TABB *no_anterior_ao_menor, *no_subsequente_ao_menor;
        no_anterior_ao_menor = a->dir;
        if (no_anterior_ao_menor->esq) {
          while (no_anterior_ao_menor->esq->esq) {
            no_anterior_ao_menor = no_anterior_ao_menor->esq;
          }
          no_subsequente_ao_menor = no_anterior_ao_menor->esq->dir;
          a->info = no_anterior_ao_menor->esq->info;
          free(no_anterior_ao_menor->esq);
          no_anterior_ao_menor->esq = no_subsequente_ao_menor;
        }
        else {
          a->info = no_anterior_ao_menor->info;
          a->dir = no_anterior_ao_menor->esq;
          free(no_anterior_ao_menor);
        }

        return a;
      }
      free(a);
      return temp;
    }
  }
  return a;
}

int qtd_nos(TABB* a) {
  if (a) {
    int qtd = 0;
    qtd += qtd_nos(a->esq);
    qtd += qtd_nos(a->dir);
    qtd++;
    return qtd;
  }
  return 0;
}

int* mN(TABB* a, int N) {
  int qtd = qtd_nos(a);
  int* vetor[qtd];
  while (a) {
    while (a->esq){}
  }
  return 0;
}
