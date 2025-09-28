#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 8
typedef bool Set[ARRAY_SIZE];

void initialize(Set set) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        set[i] = false;
    }
}

void insert(Set set, int element) {
    if (element >= 0 && element < ARRAY_SIZE) {
        set[element] = true;
    }
}

void delete(Set set, int element) {
    if (element >= 0 && element < ARRAY_SIZE) {
        set[element] = false;
    }
}

bool find(Set set, int element) {
    if (element >= 0 && element < ARRAY_SIZE) {
        return set[element];
    }
    return false;
}

void getUnion(Set A, Set B, Set C) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] || B[i];
    }
}

void intersection(Set A, Set B, Set C) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] && B[i];
    }
}

void difference(Set A, Set B, Set C) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] && !B[i];
    }
}

void display(Set set) {
    printf("{ ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (set[i]) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

int main() {
    Set A, B, C;

    initialize(A);
    initialize(B);

    insert(A, 0); // [1,0,0,0,0,0,0,0]
    insert(A, 2); // [1,0,1,0,0,0,0,0]
    insert(A, 7); // [1,0,1,0,0,0,0,1]
    printf("A = ");
    display(A);

    insert(B, 2); // [0,0,1,0,0,0,0,0]
    insert(B, 4); // [0,0,1,0,1,0,0,0]
    insert(B, 5); // [0,0,1,0,1,1,0,0]
    printf("B = ");
    display(B);

    delete(A, 0); // {2,7}
    delete(A, 7); // {2}
    printf("A after deletes = ");
    display(A);

    printf("2 in A: %s\n", find(A, 2) ? "true" : "false");
    printf("7 in A: %s\n", find(A, 7) ? "true" : "false");

    getUnion(A, B, C);
    printf("Union of A and B = ");
    display(C);

    intersection(A, B, C);
    printf("Intersection of A and B = ");
    display(C);

    difference(A, B, C);
    printf("Difference A - B = ");
    display(C);

    return 0;
}
