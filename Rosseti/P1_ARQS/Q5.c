#include "TG.h"
#include "TLSE.h"

//Q5 - 3,0 PONTOS
int tripartido_k_arestas (TG* g, int k){
  if(!g) return 0;
  int* num_arestas = (int*) malloc (sizeof(int)*3);
  for (int i = 0; i < 3; i++) num_arestas[i] = 0;
  int cor0, cor1, cor2;
  // indice i representa numero de arestas que cada cor tem
  TG* g_aux = g;
  while (g_aux){
    // mapeamento de cor
    if(g_aux->cor_no != cor0 && !num_arestas[0]) cor0 = g_aux->cor_no;
    if(g_aux->cor_no != cor0 && !num_arestas[1]) cor1 = g_aux->cor_no;
    if(g_aux->cor_no != cor0 && g_aux->cor_no != cor1 && !num_arestas[2]) cor2 = g_aux->cor_no;
    TVIZ* viz = g_aux->prim_viz;
    while(viz){
      TG* viz_no = TG_busca_no(g, viz->id_viz);
      // verificacao de vizinhos, tripartido
      if (viz_no->cor_no == g_aux->cor_no){
        free(num_arestas);
        return 0;
      }
      // somatorio de aresta naquela cor
      if(g_aux->cor_no == cor0) num_arestas[0]++;
      if(g_aux->cor_no == cor1) num_arestas[1]++;
      if(g_aux->cor_no == cor2) num_arestas[2]++;
      viz = viz->prox_viz;
    }
    g_aux = g_aux->prox_no;
  }
  // em tese, cada grupo de cor deve ter 2k de arestas, num grafo com 3 cores, para que ele seja tripartido em k arestas
  printf("%d %d %d \n", num_arestas[0], num_arestas[1], num_arestas[2]);
  for(int i = 0; i < 3; i++){
    if (num_arestas[i] != 2*k){
      free(num_arestas);
      return 0;
    }
  }
  free(num_arestas);
  return 1;
}

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
  printf("%d\n", tripartido_k_arestas (g, k));
  
  TG_libera(g);
  return 0;
}

