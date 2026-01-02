#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;
    int max;
} List;

void initialize(List *L){
    L->elemPtr = (int*)malloc(sizeof(int)*LENGTH);
    L->count = 0;
    L->max = LENGTH;
}

void resize(List *L){
    int newMax = (L->max > 0) ? L->max * 2 : LENGTH;
    int *p = (int*)realloc(L->elemPtr, sizeof(int)*newMax);
    if (p){
        L->elemPtr = p;
        L->max = newMax;
    }
}

void insertPos(List *L, int data, int position){
    if (position < 0 || position > L->count){
        return;
    }
    if (L->count == L->max) resize(L);
    for (int i = L->count; i > position; i--){
        L->elemPtr[i] = L->elemPtr[i-1];
    }
    L->elemPtr[position] = data;
    L->count++;
}

void deletePos(List *L, int position){
    if (position < 0 || position >= L->count){
        return;
    }
    for (int i = position; i < L->count - 1; i++){
        L->elemPtr[i] = L->elemPtr[i+1];
    }
    L->count--;
}

int locate(List *L, int data){
    for (int i = 0; i < L->count; i++){
        if (L->elemPtr[i] == data){
            return i;
        }
    }
    return -1;
}

int retrieve(List *L, int position){
    if (position >= 0 && position < L->count) {
        return L->elemPtr[position];
    }
    return -1;
}

void insertSorted(List *L, int data){
    if (L->count == L->max) resize(L);
    int pos = 0;
    while (pos < L->count && L->elemPtr[pos] < data){
        pos++;
    }
    insertPos(L, data, pos);
}

void display(List *L){
    for (int i = 0; i < L->count; i++){
        printf("%d ", L->elemPtr[i]);
    }
    printf("\n");
}

void makeNULL(List *L){
    free(L->elemPtr);
    L->elemPtr = NULL;
    L->count = 0;
    L->max = 0;
}

int main(void){
    List L;

    initialize(&L);
    insertPos(&L, 1, 0); // 1
    insertPos(&L, 3, 1); // 1,3
    insertPos(&L, 2, 1); // 1,2,3
    insertPos(&L, 5, 3); // 1,2,3,5
    insertPos(&L, 4, 2); // 1,2,4,3,5
    deletePos(&L, 1); // 1,4,3,5
    printf("locate 3: %d\n", locate(&L, 3)); // 2
    printf("retrieve 2: %d\n", retrieve(&L, 2)); // 3
    display(&L); // 1 4 3 5

    makeNULL(&L);
    initialize(&L);
    insertPos(&L, 1, 0); // 1
    insertPos(&L, 3, 1); // 1,3
    insertPos(&L, 5, 2); // 1,3,5
    insertPos(&L, 10, 3); // 1,3,5,10
    insertSorted(&L, 8); // 1 3 5 8 10
    display(&L); // 1 3 5 8 10

    makeNULL(&L);
    return 0;
}
