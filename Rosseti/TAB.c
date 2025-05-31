#include "TAB.h"

TAB *TAB_inicializa(void){
  return NULL;
}

TAB *TAB_cria(int raiz, TAB *esq, TAB *dir){
  TAB *novo = (TAB *) malloc(sizeof(TAB));
  novo->info = raiz;
  novo->esq = esq;
  novo->dir = dir;
  novo->cor = 0;
  return novo;
}

TAB *TAB_busca(TAB *a, int elem){
  if((!a) || (a->info == elem)) return a;
  TAB *resp = TAB_busca(a->esq, elem);
  if(resp) return resp;
  return TAB_busca(a->dir, elem);
}

TAB* TAB_achafolha(TAB *a) {
  if (!a) return NULL;

  if (!a->esq && !a->dir) {
    return a;
  }

  TAB *folha_esq = TAB_achafolha(a->esq);
  if (folha_esq) return folha_esq;

  return TAB_achafolha(a->dir);
}

void TAB_imp_pre(TAB *a){
  if(a){
    printf("%d ", a->info);
    TAB_imp_pre(a->esq);
    TAB_imp_pre(a->dir);
  }
}

void TAB_imp_pos(TAB *a){
  if(a){
    TAB_imp_pos(a->esq);
    TAB_imp_pos(a->dir);
    printf("%d ", a->info);
  }
}

void TAB_imp_sim(TAB *a){
  if(a){
    TAB_imp_sim(a->esq);
    printf("%d ", a->info);
    TAB_imp_sim(a->dir);
  }
}

void TAB_imp_aux(TAB *a, int andar){
  int j;
  if(a){
    TAB_imp_aux(a->dir, andar + 1);
    for(j = 0; j <= andar; j++) printf("\t"); //printf("   ");
    printf("%d %d\n", a->info, a->cor);
    TAB_imp_aux(a->esq, andar + 1);
  }
  else{
   for(j = 0; j <= andar; j++) printf("\t");
   printf("N\n");
  }
}

void TAB_imp_ident(TAB *a){
  TAB_imp_aux(a, 0);
}

void TAB_libera(TAB *a){
  if(a){
    TAB_libera(a->esq);
    TAB_libera(a->dir);
    free(a);
  }
}

TAB* TAB_copia(TAB* a) {
  if (a) {
    TAB* nova_arvore = TAB_cria(a->info,NULL,NULL);
    nova_arvore->esq = TAB_copia(a->esq);
    nova_arvore->dir = TAB_copia(a->dir);
    return nova_arvore;
  }
  return NULL;
}

TAB* TAB_espelho(TAB* a) {
  if (a) {
    TAB* nova_arvore = TAB_cria(a->info,NULL,NULL);
    nova_arvore->esq = TAB_espelho(a->dir);
    nova_arvore->dir = TAB_espelho(a->esq);
    return nova_arvore;
  }
  return NULL;
}

TAB* TAB_maior(TAB* a) {
  if (a) {
    TAB* maior = a;
    TAB* esq_maior = TAB_maior(a->esq);
    TAB* dir_maior = TAB_maior(a->dir);
    if (esq_maior != NULL && esq_maior->info > maior->info) {
      maior = esq_maior;
    }
    if (dir_maior != NULL && dir_maior->info > maior->info) {
      maior = dir_maior;
    }
    return maior;
  }
  return NULL;
}

TAB* TAB_menor(TAB* a) {
  if (a) {
    TAB* menor = a;
    TAB* esq_menor = TAB_menor(a->esq);
    TAB* dir_menor = TAB_menor(a->dir);
    if (esq_menor != NULL && esq_menor->info < menor->info) {
      menor = esq_menor;
    }
    if (dir_menor != NULL && dir_menor->info < menor->info) {
      menor = dir_menor;
    }
    return menor;
  }
  return NULL;
}

int igual(TAB* a1, TAB* a2) {
  if (a1 == NULL && a2 == NULL){return 1;}
  if (a1 == NULL || a2 == NULL){return 0;}
  if (a1->info != a2->info){return 0;}
  return igual(a1->esq, a2->esq) && igual(a1->dir, a2->dir);
}

TAB* retira_pares (TAB* arv) {
  if (arv) {
    arv->esq = retira_pares(arv->esq);
    arv->dir = retira_pares(arv->dir);

    if (arv->info % 2 == 0) {
      //Nó atual é par
      TAB* temp;
      if (!arv->esq) {
        temp = arv->dir;
      }
      else if (!arv->dir) {
        temp = arv->esq;
      }
      else {
        //Nó com dois filhos
        TAB* aux = arv->esq;
        while (aux->dir) aux = aux->dir;
        aux->dir = arv->dir;
        temp = arv->esq;
      }
      free(arv);
      return temp;
    }
    return arv;
  }
}

void colore (TAB* arv) {
  if (arv) {
    if (arv->cor == 0) {
      if (arv->esq) {
        arv->esq->cor = 1;
        colore(arv->esq);
      }
      if (arv->dir) {
        arv->dir->cor = 1;
        colore(arv->dir);
      }
    }
  }
}

int ni(TAB *a) {
  int sum = 0;
  if (a->esq) {
    sum += ni(a->esq);
  }
  if (a->dir) {
    sum += ni(a->dir);
  }
  if (a->esq || a->dir) sum++;
  return sum;
}

int nf(TAB *a) {
  int sum = 0;
  if (a->esq) {
    sum += nf(a->esq);
  }
  if (a->dir) {
    sum += nf(a->dir);
  }
  if (!a->esq && !a->dir) sum++;
  return sum;
}