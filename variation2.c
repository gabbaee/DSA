#include <stdio.h>

#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
} Etype, *EPtr;

void initialize(EPtr L){ 
    L->count = 0; 
}

void insertPos(EPtr L, int data, int position){
    if (position >= 0 && position <= L->count && L->count < MAX){
        for (int i = L->count; i > position; i--){
            L->elem[i] = L->elem[i-1];
        }
        L->elem[position] = data;
        L->count++;
    }
}

void deletePos(EPtr L, int position){
    if (position >= 0 && position < L->count){
        for (int i = position; i < L->count - 1; i++){
            L->elem[i] = L->elem[i+1];
        }
        L->count--;
    }
}

int locate(EPtr L, int data){
    for (int i = 0; i < L->count; i++){
        if (L->elem[i] == data){
            return i;
        }
    }
    return -1;
}

int retrieve(EPtr L, int position){
    if (position >= 0 && position < L->count){
        return L->elem[position];
    }
    return -1;
}

void insertSorted(EPtr L, int data){
    if (L->count == MAX){
        return;
    }
    int pos = 0;
    for (; pos < L->count && L->elem[pos] < data; pos++){}
    insertPos(L, data, pos);
}

void display(EPtr L){
    for (int i = 0; i < L->count; i++) 
    printf("%d ", L->elem[i]);
    printf("\n");
}

void makeNULL(EPtr L){ 
    L->count = 0; 
}

int main(void){
    Etype A; 
    EPtr L = &A;

    initialize(L);                    
    insertPos(L, 1, 0); // 1
    insertPos(L, 3, 1); // 1,3
    insertPos(L, 2, 1); // 1,2,3
    insertPos(L, 5, 3); // 1,2,3,5
    insertPos(L, 4, 2); // 1,2,4,3,5
    deletePos(L, 1); // 1,4,3,5
    printf("locate 3: %d\n", locate(L, 3)); // 2
    printf("retrieve 2: %d\n", retrieve(L, 2)); // 3
    display(L); // 1 4 3 5

    initialize(L);                     
    insertPos(L, 1, 0); // 1
    insertPos(L, 3, 1); // 1,3
    insertPos(L, 5, 2); // 1,3,5
    insertPos(L, 10, 3); // 1,3,5,10
    insertSorted(L, 8); // 1,3,5,8,10  
    display(L); // 1 3 5 8 10

    makeNULL(L);
    return 0;
}
