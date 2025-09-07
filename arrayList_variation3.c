#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;
    int max;
} List;

List initialize(List L){
    L.elemPtr = (int*)malloc(sizeof(int)*LENGTH);
    L.count = 0;
    L.max = LENGTH;
    return L;
}

List resize(List L){
    int newMax = (L.max > 0) ? L.max * 2 : LENGTH;
    int *p = (int*)realloc(L.elemPtr, sizeof(int)*newMax);
    if (p){ 
        L.elemPtr = p; L.max = newMax; 
    }
    return L;
}

List insertPos(List L, int data, int position){
    if (position < 0 || position > L.count){
        return L;
    }
    if (L.count == L.max) L = resize(L);
    for (int i = L.count; i > position; i--){
        L.elemPtr[i] = L.elemPtr[i-1];
    }
    L.elemPtr[position] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position){
    if (position < 0 || position >= L.count){
        return L;
    }
    for (int i = position; i < L.count - 1; i++){
        L.elemPtr[i] = L.elemPtr[i+1];
    }
    L.count--;
    return L;
}

int locate(List L, int data){
    for (int i = 0; i < L.count; i++){
        if (L.elemPtr[i] == data){
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, int data){
    if (L.count == L.max) L = resize(L);
    int pos = 0;
    while (pos < L.count && L.elemPtr[pos] < data){
        pos++;
    }
    L = insertPos(L, data, pos);
    return L;
}

void display(List L){
    for (int i = 0; i < L.count; i++){
        printf("%d ", L.elemPtr[i]);
    }
    printf("\n");
}

int main(void){
    List L; 
    L = initialize(L);

    L = insertPos(L, 1, 0); // 1
    L = insertPos(L, 3, 1); // 1,3
    L = insertPos(L, 2, 1); // 1,2,3
    L = insertPos(L, 5, 3); // 1,2,3,5
    L = insertPos(L, 4, 2); // 1,2,4,3,5
    L = deletePos(L, 1); // 1,4,3,5
    printf("locate 3: %d\n", locate(L, 3)); // 2
    display(L); // 1 4 3 5

    L = initialize(L);
    L = insertPos(L, 1, 0); // 1
    L = insertPos(L, 3, 1); // 1,3
    L = insertPos(L, 5, 2); // 1,3,5
    L = insertPos(L, 10, 3); // 1,3,5,10
    L = insertSorted(L, 8); // 1 3 5 8 10
    display(L); // 1 3 5 8 10

    free(L.elemPtr);
    return 0;
}
