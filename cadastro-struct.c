#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM 3

struct pessoa{
    int idade;
    float peso;
    char nome [50];
};

typedef struct pessoa pessoa;

int main(){
    setlocale(LC_ALL, "Portuguese");

    pessoa lista[TAM];
    int i;

    for(i=0; i<TAM;i++){
        printf("Insira os dados (%d) : \n", i+1);
        puts("Nome: ");
        scanf("%50[^\n]s", &lista[i].nome);
        fflush(stdin);

        puts("Idade: ");
        scanf("%d", &lista[i].idade);
        fflush(stdin);

        puts("Peso: ");
        scanf("%f", &lista[i].peso);
        fflush(stdin);
    }
    system("cls");

     puts("Seus dados:\n");
     for(i=0; i<TAM;i++){
        printf("------------ Pessoa %d ------------\n", i+1);
        printf("\tNome: %s\n", lista[i].nome);
        printf("\tIdade: %d\n", lista[i].idade);
        printf("\tPeso: %.2f\n\n", lista[i].peso);
     }
     printf("----------------------------------\n");
}