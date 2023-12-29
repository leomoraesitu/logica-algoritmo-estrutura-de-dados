#include <stdio.h>

int main() {
    int contador = 0;
    double soma = 0.0;
    double numero;

    printf("Digite um numero (ou qualquer letra para encerrar):\n");

    while (scanf("%lf", &numero) == 1) {
        soma += numero;
        contador++;

        printf("Digite outro numero (ou qualquer letra para encerrar):\n");
    }

    if (contador > 0) {
        double media = soma / contador;
        printf("A média dos numeros digitados é: %.2f\n", media);
    } else {
        printf("Nenhum numero foi digitado.\n");
    }

    return 0;
}