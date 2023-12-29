/* 10. Receber 10 numeros inteiros e armazenar em um vetor. Imprimir os dados do vetor em ordem crescente.*/

#include <stdio.h>
#define TAM 10

int main()
{
	int i, x, y, vet[TAM], aux;
	
	printf("Digite %i numeros:\n\n", TAM);
	
	for(i=0; i<TAM; i++)
	{
		printf("%io numero: ", i+1);
		scanf("%i", &vet[i]);
	}
	
	for(x=0; x<TAM; x++)
	{
		for(y=x; y<TAM; y++)
		{
			if(vet[x] > vet[y])
			{
				aux = vet[x];
				vet[x] = vet[y];
				vet[y] = aux;
			}
		}
	}
	
	printf("\n");
	
	for(i=0; i<TAM; i++)
	{
		printf("%i ", vet[i]);
	}
	
	return 0;
}
