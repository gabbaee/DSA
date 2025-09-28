#include <stdio.h>
#include <stdbool.h>

#define SIZE 8  

void initialize(unsigned char *set) {
    *set = 0;  
}

void insert(unsigned char *set, int element) {
    if (element >= 0 && element < SIZE) {
        *set |= (1 << element);
    }
}

void delete(unsigned char *set, int element) {
    if (element >= 0 && element < SIZE) {
        *set &= ~(1 << element);
    }
}

bool find(unsigned char set, int element) {
    if (element >= 0 && element < SIZE) {
        return (set & (1 << element)) != 0;
    }
    return false;
}

unsigned char getUnion(unsigned char A, unsigned char B) {
    return A | B;
}

unsigned char intersection(unsigned char A, unsigned char B) {
    return A & B;
}

unsigned char difference(unsigned char A, unsigned char B) {
    return A & (~B);
}

void display(unsigned char set) {
    printf("{ ");
    for (int i = 0; i < SIZE; i++) {
        if (set & (1 << i)) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

int main() {
    unsigned char A, B, C;

    initialize(&A);
    initialize(&B);

    insert(&A, 1);  // A = {1}
    insert(&A, 6);  // A = {1,6}
    printf("A = ");
    display(A);

    insert(&B, 3);  // B = {3}
    insert(&B, 6);  // B = {3,6}
    insert(&B, 7);  // B = {3,6,7}
    printf("B = ");
    display(B);

    delete(&A, 6);  // A = {1}
    printf("A after delete 6 = ");
    display(A);

    printf("3 in A: %s\n", find(A, 3) ? "true" : "false");
    printf("1 in A: %s\n", find(A, 1) ? "true" : "false");

    C = getUnion(A, B);
    printf("Union of A and B = ");
    display(C);

    C = intersection(A, B);
    printf("Intersection of A and B = ");
    display(C);

    C = difference(A, B);
    printf("Difference of A - B = ");
    display(C);

    return 0;
}
