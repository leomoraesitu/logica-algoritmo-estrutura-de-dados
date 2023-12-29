#include <stdio.h>

int main(){
   
    float value1, value2, result;
    char operator;

    printf("Digite o primeiro numero: ");
    scanf("%f", &value1);

    printf("Digite a operacao: ");
    scanf("%s", &operator);

    printf("Digite o segundo numero: ");
    scanf("%f", &value2);

    switch(operator){
        case '+' :
            result = value1 + value2;
            break;
        case '-' :
            result = value1 - value2;
            break;
        case '*' :
            result = value1 * value2;
            break;
        case '/' :
            result = value1 / value2;
            break;
    }

    printf("Resultado: %.2f", result);

    return 0;
}