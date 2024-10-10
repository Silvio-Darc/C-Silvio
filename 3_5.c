# include <stdio.h>
# include <stdlib.h>

float media(float vetor[], int tam_vetor){
	float somatorio = 0;
	for (int counter = 0; counter < tam_vetor; counter++){
		somatorio += vetor[counter];
	}
	return somatorio / tam_vetor;
}

float mais_proximo(float vetor[], int tam_vetor, float val_media){
	float val_mais_proximo = vetor[0];
	for(int i = 1; i < tam_vetor; i++){
		if (abs(val_media - vetor[i]) < abs(val_media - val_mais_proximo)){
			val_mais_proximo = vetor[i];
			}
	}
	return val_mais_proximo;
}

 int main(){
 	puts("Digite o número de notas lançadas");
 	int qtd_notas;
 	scanf("%d", &qtd_notas);
 	float notas[qtd_notas];
 	for(int counter = 0; counter < qtd_notas; counter++){
 		puts("Digite uma nota");
 		scanf("%f", &notas[counter]);
 	}
 	
 	printf("Valor mais próximo da média: %.1f", mais_proximo(notas, qtd_notas, media(notas, qtd_notas)));
 	
 	
 	return 0;
 }
