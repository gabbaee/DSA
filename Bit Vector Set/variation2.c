#include <stdio.h>
#include <stdbool.h>

#define SIZE 8  

typedef struct {
    unsigned char field : 8;   
} Set;

void initialize(Set *set) {
    set->field = 0; 
}

void insert(Set *set, int element) {
    if (element >= 0 && element < SIZE) {
        set->field |= (1 << element);
    }
}

void delete(Set *set, int element) {
    if (element >= 0 && element < SIZE) {
        set->field &= ~(1 << element);
    }
}

bool find(Set set, int element) {
    if (element >= 0 && element < SIZE) {
        return (set.field & (1 << element)) != 0;
    }
    return false;
}

Set getUnion(Set A, Set B) {
    Set C;
    C.field = A.field | B.field;
    return C;
}

Set intersection(Set A, Set B) {
    Set C;
    C.field = A.field & B.field;
    return C;
}

Set difference(Set A, Set B) {
    Set C;
    C.field = A.field & (~B.field);
    return C;
}

void display(Set set) {
    printf("{ ");
    for (int i = 0; i < SIZE; i++) {
        if (set.field & (1 << i)) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

int main() {
    Set A, B, C;

    initialize(&A);
    initialize(&B);

    insert(&A, 0); // {0}
    insert(&A, 4); // {0,4}
    insert(&A, 5); // {0,4,5}
    printf("A = ");
    display(A);

    insert(&B, 2); // {2}
    insert(&B, 5); // {2,5}
    printf("B = ");
    display(B);

    delete(&A, 5); // {0,4}
    printf("A after deleting 5 = ");
    display(A);

    printf("4 in A: %s\n", find(A, 4) ? "true" : "false");
    printf("5 in A: %s\n", find(A, 5) ? "true" : "false");

    C = getUnion(A, B);
    printf("Union of A and B = ");
    display(C);

    C = intersection(A, B);
    printf("Intersection of A and B = ");
    display(C);

    C = difference(A, B);
    printf("Difference A - B = ");
    display(C);

    return 0;
}
