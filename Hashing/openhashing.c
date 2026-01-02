#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 8

typedef struct Node {
    int key;
    struct Node *next;
} Node;

void initialize(Node *table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }
}

int hash(int key) {
    return key % TABLE_SIZE;
}

bool find(Node *table[], int key) {
    int index = hash(key);
    Node *curr = table[index];

    while (curr != NULL) {
        if (curr->key == key) return true;
        curr = curr->next;
    }
    return false;
}

bool insert(Node *table[], int key) {
    if (find(table, key)) return false;

    int index = hash(key);
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->key = key;
    newNode->next = table[index];
    table[index] = newNode;

    return true;
}

bool deleteKey(Node *table[], int key) {
    int index = hash(key);
    Node *curr = table[index];
    Node *prev = NULL;

    while (curr != NULL) {
        if (curr->key == key) {
            if (prev == NULL) {
                table[index] = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

void display(Node *table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d - ", i);
        Node *curr = table[i];
        while (curr != NULL) {
            printf("%d -> ", curr->key);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Node *H[TABLE_SIZE];

    initialize(H);

    insert(H, 5);   // bucket 5
    insert(H, 13);  // bucket 5 
    printf("H = \n");
    display(H);

    insert(H, 21);  // bucket 5
    insert(H, 9);   // bucket 1
    insert(H, 2);   // bucket 2
    printf("\nH after inserts = \n");
    display(H);

    deleteKey(H, 13);
    printf("\nH after delete 13 = \n");
    display(H);

    printf("\n21 in H: %s\n", find(H, 21) ? "true" : "false");
    printf("13 in H: %s\n", find(H, 13) ? "true" : "false");

    return 0;
}
