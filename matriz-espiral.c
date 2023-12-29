/*7. Matriz Espiral em Vetor:
   Enunciado: Crie um programa que gera uma matriz quadrada de tamanho N (N é ímpar) preenchida com números sequenciais, 
   iniciando em 1 até N. Em seguida, transforme essa matriz em um vetor, percorrendo-a em ordem de espiral.*/
   
#include <stdio.h>

//Função espiral:
void espiral(int size, int matriz[size][size]) {

 

	int cima = 1, baixo = size, esquerda = 1, direita = size;
	
	printf("\nMatriz em espiral:\n");

 

	while (cima <= baixo && esquerda <= direita) {

 

		for (int i = esquerda; i <= direita; i++) {
			printf("%d ", matriz[cima][i]);
		}
		cima++;

 

 

		for (int i = cima; i <= baixo; i++) {
			printf("%d ", matriz[i][direita]);
		}
		direita--;

 

 

		if (cima <= baixo) {
			for (int i = direita; i >= esquerda; i--) {
				printf("%d ", matriz[baixo][i]);
			}
			baixo--;
		}

 

		if (esquerda <= direita) {
			for (int i = baixo; i >= cima; i--) {
				printf("%d ", matriz[i][esquerda]);
			}
			esquerda++;
		}
	}
}

//Gerando o vetor:
int main(){

	int N, j, v=1;

	printf("Digite o tamanho do Vetor (deve ser impar): ");
	scanf("%i",&N);

	while(N % 2 == 0){
		printf("Digite um numero impar:\n");
		scanf("%i",&N);
	}
	
	int matriz[N][N];
	
	printf("\n");
		
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			matriz[i][j]=v;
			v++;
		}		
	}
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");		
	}
	
	espiral(N, matriz);
					
}

