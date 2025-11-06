#include <string.h>
#include "TAB.h"
#include "TLSE.h"

//Q4 - 2,0 PONTOS
//int mesmos_elementos (TAB* a1, TAB* a2){
//}

int main(void){
  int no, pai;
  printf("Digite a raiz da PRIMEIRA arvore... ");
  scanf("%d", &no);
  TAB *a1 = TAB_cria(no, NULL, NULL), *resp;
  char repete;
  do{
    char lado[2];
    printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
    scanf(" %c", &repete);
    if((repete == 'N') || (repete == 'n')) break;
    printf("Digite o pai (que deve existir), o filho a ser inserido e a posição E(ESQ) ou D(DIR)... ");
    scanf("%d%d%s", &pai, &no, lado);
    resp = TAB_busca(a1, pai);
    if(!resp){
      TAB_libera(a1);
      return 0;
    }
    if(strcmp(lado, "E") == 0) resp->esq = TAB_cria(no, NULL, NULL);
    else resp->dir = TAB_cria(no, NULL, NULL);
  }while(1);
  TAB_imp_ident(a1);
  printf("\n");
 
  printf("Digite a raiz da SEGUNDA arvore... ");
  scanf("%d", &no);
  TAB *a2 = TAB_cria(no, NULL, NULL);
  do{
    char lado[2];
    printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
    scanf(" %c", &repete);
    if((repete == 'N') || (repete == 'n')) break;
    printf("Digite o pai (que deve existir), o filho a ser inserido e a posição E(ESQ) ou D(DIR)... ");
    scanf("%d%d%s", &pai, &no, lado);
    resp = TAB_busca(a2, pai);
    if(!resp){
      TAB_libera(a2);
      TAB_libera(a1);
      return 0;
    }
    if(strcmp(lado, "E") == 0) resp->esq = TAB_cria(no, NULL, NULL);
    else resp->dir = TAB_cria(no, NULL, NULL);
  }while(1);
  TAB_imp_ident(a2);
  printf("\n");
 
  //printf("%d\n", mesmos_elementos (a1, a2));
  
  TAB_libera(a1);
  TAB_libera(a2);
  return 0;
}
