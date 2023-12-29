#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

struct HashNode {
    char *key;
    int value;
    struct HashNode *next;
};

struct HashNode *table[TABLE_SIZE] = { NULL };

int hash(char *key) {
    int hash = 0;
    while (*key) {
        hash = (hash + *key) % TABLE_SIZE;
        key++;
    }
    return hash;
}


void insert(char *key, int value) {
    int index = hash(key);
    struct HashNode *newNode = malloc(sizeof(struct HashNode));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = table[index];
    table[index] = newNode;
}

int search(char *key) {
    int index = hash(key);
    struct HashNode *current = table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

void delete(char *key) {
    int index = hash(key);
    struct HashNode *current = table[index];
    struct HashNode *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (previous == NULL) {
                table[index] = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->key);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void print_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct HashNode *current = table[i];
        while (current != NULL) {
            printf("Key: %s, Value: %d\n", current->key, current->value);
            current = current->next;
        }
    }
}


int main() {
    insert("apple", 42);
    insert("banana", 17);
    insert("cherry", 73);

    printf("Value for 'apple': %d\n", search("apple"));
    printf("Value for 'banana': %d\n", search("banana"));
    printf("Value for 'cherry': %d\n", search("cherry"));

    delete("banana");

    print_table();


    return 0;
}
