#include <stdio.h>

int calcularFatorial(int n) {
    // Caso base: fatorial de 0 é 1
    if (n == 0 || n == 1)
        return 1;
    else
        return n * calcularFatorial(n - 1);
}

int main() {
    int num;
    printf("Digite um numero para calcular o fatorial: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Nao e possivel calcular o fatorial de um numero negativo.\n");
    } else {
        int resultado = calcularFatorial(num);
        printf("O fatorial de %d e: %d\n", num, resultado);
    }

    return 0;
}
