#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int count;
} List;

List* initialize(){
    List *list = (List *)malloc(sizeof(List));
    list->head = NULL;
    list->count = 0;
    return list;
}

void empty(List *list){
    for(struct Node *trav = list->head; list->head != NULL;){
        trav = list->head;
        list->head = list->head->next;
        free(trav);
    }
    list->count = 0;
}


struct Node* createNode(int data) {                        
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void deleteNode(struct Node **node, List *list){
    if (*node == NULL){
        return;
    } 

    struct Node *temp = *node;
    *node = temp->next;
    free(temp);

    list->count--;
}

void insertFirst(List *list, int data){
    struct Node *newNode = createNode(data);
    
    newNode->next = list->head;
    list->head = newNode;     
    
    list->count++;
}

void insertLast(List *list, int data){
    struct Node *newNode = createNode(data);
    
    struct Node **trav = &list->head;
    for(; *trav != NULL; trav = &(*trav)->next){}
    
    *trav = newNode;   

    list->count++;
}

void insertPos(List *list, int data, int index){
    struct Node *newNode = createNode(data);
    
    struct Node **trav = &list->head;
    for(int i = 0; *trav != NULL && i < index; trav = &(*trav)->next, i++){}

    newNode->next = *trav;
    *trav = newNode;

    list->count++;
}

void deleteStart(List *list){
    if (list->head == NULL){
        return;
    }
    deleteNode(&list->head, list);
}

void deleteLast(List *list){
    if(list->head == NULL){
        return;
    }
    
    struct Node **trav = &list->head;
    for(; (*trav)->next != NULL; trav = &(*trav)->next){}

    deleteNode(trav, list);
}

void deletePos(List *list, int index){
    if(list->head == NULL){
        return;
    }
    
    struct Node **trav = &list->head;
    for(int i = 0; *trav != NULL && i < index; trav = &(*trav)->next, i++){}

    if(*trav == NULL){
        return;
    }
    deleteNode(trav, list);
}

int retrieve(List *list, int index){
    struct Node *trav = list->head;
    for (int i = 0; i < index; i++, trav = trav->next) {}

    return trav->data;
}

int locate(List *list, int data){
    if(list->head == NULL){
        return - 1;
     }
     
    struct Node *trav = list->head;
    for(int i = 0; i < list->count; i++, trav = trav->next)
        if (trav->data == data){
        	return i;
        }    
     return -1;
}

void display(List *list){
    for(struct Node *trav = list->head; trav != NULL; trav = trav->next)
        printf("%d ", trav->data);   
    printf("\n");       
}

int main(){
    List *L = initialize();

    insertPos(L, 1, 0); // 1
    insertPos(L, 3, 1); // 1,3
    insertPos(L, 2, 1); // 1,2,3
    insertPos(L, 5, 3); // 1,2,3,5
    insertPos(L, 4, 2); // 1,2,4,3,5
    deletePos(L, 1);    // 1,4,3,5
    printf("locate 3: %d\n", locate(L, 3)); // 2
    display(L); // 1 -> 4 -> 3 -> 5 

    empty(L);

    insertPos(L, 1, 0); // 1
    insertPos(L, 3, 1); // 1,3
    insertPos(L, 5, 2); // 1,3,5
    insertPos(L, 10, 3); // 1,3,5,10
    display(L); // 1 -> 3 -> 5 -> 10 

    empty(L);
    free(L);
    return 0;
}

