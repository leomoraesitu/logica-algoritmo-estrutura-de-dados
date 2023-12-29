/* Parte 1: Faça um programa que receba 10 números inteiros e armazene os mesmos
em uma pilha.

Parte 2: Após receber os 10 valores processe os dados da pilha até que ela fique
totalmente vazia. Para cada dado processado da pilha insira o mesmo em uma lista
duplamente encadeada.

Parte 3: Assim que a lista estiver preenchida, remova da lista os valores negativos.

Parte 4: No final, mostrar a quantidade de elementos restantes na lista. */

#include <stdio.h>
#include <stdlib.h>

#define N 5

struct Stack
{
    int *items;
    int top;
    int max_size;
};

// Inicializa a pilha
void initialize(struct Stack *s, int size)
{
    s->max_size = size;
    s->items = (int *)malloc(size * sizeof(int));
    s->top = -1;
}

// Verifica se a pilha está vazia
int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

// Verifica se a pilha está cheia
int isFull(struct Stack *s)
{
    return s->top == s->max_size - 1;
}

// Empilha um elemento na pilha
void push(struct Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Erro: Pilha cheia\n");
    }
    else
    {
        s->top++;
        s->items[s->top] = value;
    }
}

// Desempilha um elemento da pilha e devolve um int
int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Erro: Pilha vazia\n");
        return -1;
    }
    else
    {
        int value = s->items[s->top];
        s->top--;
        return value;
    }
}

// Função imprimir pilha
void imprimePilha(struct Stack *s)
{
    int i;
    printf("\nImprimindo a pilha:\n");
    for (i = N - 1; i >= 0; i--)
    {
        printf("%d\n", s->items[i]);
    }
    printf("\n");
}

// Libera a memória alocada pela pilha
void destroy(struct Stack *s)
{
    free(s->items);
}

// Estrutura para um nó da lista
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Estrutura para a lista duplamente encadeada
struct DoublyLinkedList
{
    struct Node *head;
    struct Node *tail;
};

// Função para criar uma nova lista vazia
struct DoublyLinkedList *createDoublyLinkedList()
{
    struct DoublyLinkedList *list = (struct DoublyLinkedList *)malloc(sizeof(struct DoublyLinkedList));
    if (!list)
    {
        perror("Erro na alocação de memória para a lista");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Função para inserir um elemento no final da lista
void insertAtEnd(struct DoublyLinkedList *list, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        perror("Erro na alocação de memória para o nó");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        newNode->prev = NULL;
        list->head = newNode;
        list->tail = newNode;
        return;
    }

    newNode->prev = list->tail;
    list->tail->next = newNode;
    list->tail = newNode;
}

// Função para inserir um elemento no começo da lista
void insertAtFront(struct DoublyLinkedList *list, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        perror("Erro na alocação de memória para o nó");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;

    if (list->head == NULL)
    {
        newNode->next = NULL;
        list->head = newNode;
        list->tail = newNode;
        return;
    }

    newNode->next = list->head;
    list->head->prev = newNode;
    list->head = newNode;
}

// Função para exibir os elementos da lista
void displayList(struct DoublyLinkedList *list)
{
    struct Node *current = list->head;
    printf("Lista: ");
    while (current != NULL)
    {
        printf("<- %d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n\n");
}

// Função para liberar a memória da lista
void freeDoublyLinkedList(struct DoublyLinkedList *list)
{
    struct Node *current = list->head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

int main()
{
    struct Stack myStack;
    int stackSize = N; // Tamanho máximo da pilha
    int i, numero;
    struct DoublyLinkedList *list = createDoublyLinkedList();

    initialize(&myStack, stackSize);

    // Inserindo elementos na pilha:
    printf("Digite %d numeros para a pilha:\n", N);

    for (i = 0; i < N; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%i", &numero);
        push(&myStack, numero);
    }

    imprimePilha(&myStack);

    // Remover todos os elementos da pilha e inserir na lista
    while (!isEmpty(&myStack))
    {
        insertAtEnd(list, pop(&myStack));
    }

    displayList(list);

    // Remover valores negativos da lista
    struct Node *current = list->head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;

        if (temp->data < 0)
        {
            if (temp->prev != NULL)
            {
                temp->prev->next = temp->next;
            }
            else
            {
                list->head = temp->next;
            }

            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
            else
            {
                list->tail = temp->prev;
            }

            free(temp);
        }
    }

    // Exibir a lista após a remoção dos valores negativos
    displayList(list);

    // Libera a memória alocada
    destroy(&myStack);
    freeDoublyLinkedList(list);

    return 0;
}