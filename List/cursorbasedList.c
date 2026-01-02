#include <stdio.h>

#define MAX 4   
typedef struct {
    int elem;
    int next;
} Cell;

typedef struct {
    Cell H[MAX];
    int avail;
} VHeap;

typedef int List; 


void initializeVHeap(VHeap *V) {
    int i;
    for (i = 0; i < MAX-1; i++) {
        V->H[i].next = i+1;
    }
    V->H[MAX-1].next = -1;
    V->avail = 0;
}

int allocSpace(VHeap *V) {
    int p = V->avail;
    if (p != -1) {
        V->avail = V->H[p].next;
    }
    return p;
}

void deallocSpace(VHeap *V, int index) {
    V->H[index].next = V->avail;
    V->avail = index;
}

void insertFirst(List *L, VHeap *V, int elem) {
    int newNode = allocSpace(V);
    if (newNode == -1) {
        printf("Heap full! Cannot insert %d\n", elem);
        return;
    }
    V->H[newNode].elem = elem;
    V->H[newNode].next = *L;
    *L = newNode;
}

void insertLast(List *L, VHeap *V, int elem) {
    int newNode = allocSpace(V);
    if (newNode == -1) {
        printf("Heap full! Cannot insert %d\n", elem);
        return;
    }
    V->H[newNode].elem = elem;
    V->H[newNode].next = -1;

    if (*L == -1) {
        *L = newNode;
    } else {
        int trav = *L;
        while (V->H[trav].next != -1) {
            trav = V->H[trav].next;
        }
        V->H[trav].next = newNode;
    }
}

void insertPos(List *L, VHeap *V, int elem, int position) {
    int newNode = allocSpace(V);
    if (newNode == -1) {
        printf("Heap full! Cannot insert %d\n", elem);
        return;
    }
    V->H[newNode].elem = elem;

    if (position == 0) {
        V->H[newNode].next = *L;
        *L = newNode;
    } else {
        int trav = *L;
        for (int i = 0; trav != -1 && i < position-1; i++) {
            trav = V->H[trav].next;
        }
        if (trav != -1) {
            V->H[newNode].next = V->H[trav].next;
            V->H[trav].next = newNode;
        }
    }
}

void insertSorted(List *L, VHeap *V, int elem) {
    int newNode = allocSpace(V);
    if (newNode == -1) {
        printf("Heap full! Cannot insert %d\n", elem);
        return;
    }
    V->H[newNode].elem = elem;

    int prev = -1, curr = *L;
    while (curr != -1 && V->H[curr].elem < elem) {
        prev = curr;
        curr = V->H[curr].next;
    }
    V->H[newNode].next = curr;
    if (prev == -1) {
        *L = newNode;
    } else {
        V->H[prev].next = newNode;
    }
}

void deletePos(List *L, VHeap *V, int position) {
    if (*L == -1) return;

    int temp;
    if (position == 0) {
        temp = *L;
        *L = V->H[temp].next;
        deallocSpace(V, temp);
    } else {
        int trav = *L;
        for (int i = 0; trav != -1 && i < position-1; i++) {
            trav = V->H[trav].next;
        }
        if (trav != -1 && V->H[trav].next != -1) {
            temp = V->H[trav].next;
            V->H[trav].next = V->H[temp].next;
            deallocSpace(V, temp);
        }
    }
}

void display(List L, VHeap V) {
    for (int trav = L; trav != -1; trav = V.H[trav].next) {
        printf("%d ", V.H[trav].elem);
    }
    printf("\n");
}

int main() {
    VHeap V;
    List L = -1;
    initializeVHeap(&V);

    insertFirst(&L, &V, 1); // 1
    display(L, V);

    insertLast(&L, &V, 3);  // 1,3
    display(L, V);

    insertPos(&L, &V, 2, 1); // 1,2,3
    display(L, V);

    insertSorted(&L, &V, 4); // 1,2,3,4
    display(L, V);

    deletePos(&L, &V, 1); // 1,3,4
    display(L, V);

    return 0;
}
