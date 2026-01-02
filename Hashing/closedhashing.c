#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 8
#define EMPTY -1
#define DELETED -2

void initialize(int table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = EMPTY;
    }
}

int hash(int key) {
    return key % TABLE_SIZE;
}

bool insert(int table[], int key) {
    int index = hash(key);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int slot = (index + i) % TABLE_SIZE;

        if (table[slot] == key) {
            return false;
        }

        if (table[slot] == EMPTY || table[slot] == DELETED) {
            table[slot] = key;
            return true;
        }
    }
    return false; 
}

bool deleteKey(int table[], int key) {
    int index = hash(key);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int slot = (index + i) % TABLE_SIZE;

        if (table[slot] == EMPTY) {
            return false;
        }

        if (table[slot] == key) {
            table[slot] = DELETED;
            return true;
        }
    }
    return false;
}

bool find(int table[], int key) {
    int index = hash(key);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int slot = (index + i) % TABLE_SIZE;

        if (table[slot] == EMPTY) {
            return false;
        }

        if (table[slot] == key) {
            return true;
        }
    }
    return false;
}

void display(int table[]) {
    printf("[ ");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == EMPTY){
            printf("E ");
        } 
        
        else if (table[i] == DELETED){
            printf("D ");
        }
        
        else {
            printf("%d ", table[i]);
        }
    }
    printf("]\n");
}

int main() {
    int H[TABLE_SIZE];

    initialize(H);

    insert(H, 5);   // 5
    insert(H, 13);  // 5 13
    printf("H = ");
    display(H);

    insert(H, 21);  // collision with 5
    insert(H, 9);   // collision with 1
    insert(H, 2);   // no collision
    printf("H after inserts = ");
    display(H);

    deleteKey(H, 13); 
    printf("H after delete 13 = ");
    display(H);

    printf("21 in H: %s\n", find(H, 21) ? "true" : "false");
    printf("13 in H: %s\n", find(H, 13) ? "true" : "false");

    return 0;
}
