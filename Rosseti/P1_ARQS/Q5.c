#include "TG.h"
#include "TLSE.h"

//Q5 - 3,0 PONTOS
//int tripartido_k_arestas (TG* g, int k){
//}

int main(void){
  TG *g = TG_inicializa();
  printf("Digite o no do grafo e sua cor (pare quando um numero menor ou igual a zero for fornecido para o no)...\n");
  int no1, no2, cor;
  while(1){
    scanf("%d", &no1);
    if(no1 <= 0) break;
    scanf("%d", &cor);
    g = TG_ins_no(g, no1, cor);    
  }
 
  printf("Digite as arestas (pare quando um dos nos nao pertencer ao grafo)...\n");
  while(1){
    scanf("%d%d", &no1, &no2);
    if(!TG_busca_no(g, no1) || !TG_busca_no(g, no2)) break;
    TG_ins_aresta(g, no1, no2);
  }
  TG_imprime(g);
   
  printf("Digite o valor de k... ");
  int k;
  scanf("%d", &k);
  //printf("%d\n", tripartido_k_arestas (g, k));
  
  TG_libera(g);
  return 0;
}

