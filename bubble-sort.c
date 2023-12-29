#include<stdio.h>
#define N 4

int main()
{
    int i, aux, flag;
    int lista[N] = {23, -9, 13, 9};

   	printf("Vetor original: ");
    for (i = 0; i<N; i++)
    {
        printf("%d ",lista[i]);
    }    
    
    flag=1;
    while(flag){
        flag=0;
        for(i=0; i<N-1; i++){
            if(lista[i]>lista[i+1]){
                aux=lista[i];
                lista[i]=lista[i+1];
                lista[i+1]=aux;
                flag=1;
            }
        }
    }    
   
    printf("\nVetor ordenado: ");
    for (i = 0; i<N; i++)
    {
        printf("%d ",lista[i]);
    }    
}