#include <stdio.h>

#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
} List;

List initialize(){
    List L;
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    if (position <= L.count && L.count < MAX)  {
        for (int i = L.count; i >= position; i--){
            L.elem[i+1] = L.elem[i];
        }
        L.elem[position] = data;
        L.count++;
    }
    return L;
}

List deletePos(List L, int position){
    if (position <= L.count && L.count < MAX)  {
        for (int i = position; i <= L.count; i++){
            L.elem[i+1] = L.elem[i];
        }
        L.count--;
    }
    return L;
}

int locate(List L, int data){
    for (int i = 0; i < L.count; i++){
        if(L.elem[i] == data){
            printf("%d\n\n", data);
        }
    }
    return -1;
}

List insertSorted(List L, int data){
    int temp = 0;
    if (temp <= L.count && L.count < MAX)  {
        for (; temp < L.count && L.elem[temp] <= data; temp++){
            return insertPos(L, data, temp);
        }
    }
}

void display(List L){
    for (int i = 0; i < L.count; i++){
        printf("%d ", L.elem[i]);
    }
    printf("\n");   
}


int main(){
    List L = initialize();
    L = insertPos(L, 1, 0);
    L = insertPos(L, 2, 1);
    L = insertPos(L, 3, 2);
    L = insertPos(L, 9, 1);
    L = deletePos(L, 2);
    //locate(L, 3);
    //L = insertSorted(L, 4);
    //L = insertSorted(L, 0);
    display(L);
    return 0;
}
