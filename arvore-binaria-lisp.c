/*Criar uma aplicação em C que consiga avaliar expressões matemáticas apresentadas a seguir. Usar o conceito de arvore binária para avaliar as expressões:

(+ (+ 5 3) (* 2 4))                       -> Resultado 16
(+ 3 4)                                        -> Resultado 7
(- (* 5 2) 3)                                 -> Resultado 7 
(/ (* (+ 2 3) 4) 2)                        -> Resultado 10
(+ (+ (+ 1 2) 3) 4)                      -> Resultado 10 
(- (* 2 (+ 3 5)) (/ 8 2))                 -> Resultado 12 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Função para criar um novo nó
struct Node* createNode(char value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Função para verificar se o caractere é um operador
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Função para criar uma árvore a partir de uma expressão
struct Node* createTreeFromExpression(const char* expression, int* pos) {
    struct Node* root = NULL;

    // Ignorar espaços em branco
    while (expression[*pos] == ' ') {
        (*pos)++;
    }

    // Se o caractere atual é '(', significa que estamos começando uma nova subexpressão
    if (expression[*pos] == '(') {
        (*pos)++;  // Avançar para o próximo caractere após '('

        // O próximo caractere é o operador
        root = createNode(expression[*pos]);
        (*pos)++;  // Avançar para o próximo caractere após o operador

        // Construir as subárvores esquerda e direita recursivamente
        root->left = createTreeFromExpression(expression, pos);
        root->right = createTreeFromExpression(expression, pos);

        // Avançar para o próximo caractere após a subexpressão
        (*pos)++;

        // Se o caractere atual é ')', significa que a subexpressão terminou
        if (expression[*pos] == ')') {
            (*pos)++;
        }
    } else {
        // Se não for '(', é um operando
        root = createNode(expression[*pos]);
        (*pos)++;  // Avançar para o próximo caractere após o operando
    }

    return root;
}

// Função para avaliar a expressão representada pela árvore
int evaluateExpression(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    // Se for um operando, retorna o valor correspondente
    if (!isOperator(root->data)) {
        return root->data - '0';
    }

    // Se for um operador, avalia as subárvores esquerda e direita
    int leftValue = evaluateExpression(root->left);
    int rightValue = evaluateExpression(root->right);

    // Realiza a operação correspondente ao operador
    switch (root->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        default:
            return 0; // Operador desconhecido
    }
}


int main() {
    // Definindo as expressões:
    const char* expression1 = "(+ (+ 5 3) (* 2 4))";
    const char* expression2 = "(+ 3 4)";
    const char* expression3 = "(- (* 5 2) 3)";
    const char* expression4 = "(/ (* (+ 2 3) 4) 2) ";
    const char* expression5 = "(+ (+ (+ 1 2) 3) 4)";
    const char* expression6 = "(- (* 2 (+ 3 5)) (/ 8 2))";

    // Criando as árvores
    int pos = 0; // Posição inicial para análise da expressão
    struct Node* root1 = createTreeFromExpression(expression1, &pos);
    pos = 0; // Reiniciando a posição para a próxima expressão
    struct Node* root2 = createTreeFromExpression(expression2, &pos);
    pos = 0;
    struct Node* root3 = createTreeFromExpression(expression3, &pos);
    pos = 0;
    struct Node* root4 = createTreeFromExpression(expression4, &pos);
    pos = 0;
    struct Node* root5 = createTreeFromExpression(expression5, &pos);
    pos = 0;
    struct Node* root6 = createTreeFromExpression(expression6, &pos);

    // Imprimindo expressões e resultados
    printf("\nExpressao 1: %s ",expression1);
    
    printf(" -> Resultado: %d\n", evaluateExpression(root1));

    printf("\nExpressao 2: %s ", expression2);
    
    printf(" -> Resultado: %d\n", evaluateExpression(root2));

    printf("\nExpressao 3: %s ", expression3);
    
    printf(" -> Resultado: %d\n", evaluateExpression(root3));

    printf("\nExpressao 4: %s ", expression4);
    
    printf(" -> Resultado: %d\n", evaluateExpression(root4));

    printf("\nExpressao 5: %s ", expression5);
    
    printf(" -> Resultado: %d\n", evaluateExpression(root5));

    printf("\nExpressao 6: %s ",expression6);
    
    printf(" -> Resultado: %d\n\n", evaluateExpression(root6));

    return 0;
}


