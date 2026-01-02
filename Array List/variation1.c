#include <stdio.h>

#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
} List;

List initialize(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    if (position >= 0 && position <= L.count && L.count < MAX)  {
        for (int i = L.count; i > position; i--){
            L.elem[i] = L.elem[i-1];
        }
        L.elem[position] = data;
        L.count++;
    }
    return L;
}

List deletePos(List L, int position){
    if (position >= 0 && position < L.count)  {
        for (int i = position; i < L.count - 1; i++){
            L.elem[i] = L.elem[i+1];
        }
        L.count--;
    }
    return L;
}

int locate(List L, int data){
    for (int i = 0; i < L.count; i++){
        if(L.elem[i] == data){
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, int data){
    if (L.count < MAX){
        int pos = 0;
        while (pos < L.count && L.elem[pos] < data){
            pos++;
        }
        L = insertPos(L, data, pos);
    }
    return L;
}

void display(List L){
    for (int i = 0; i < L.count; i++){
        printf("%d ", L.elem[i]);
    }
    printf("\n");   
}


int main(){
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
    L = insertSorted(L, 8); // 1,3,5,8,10  
    display(L); // 1 3 5 8 10
    return 0;
}

