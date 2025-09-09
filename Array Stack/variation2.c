#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

Stack* initialize(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = 0;
    return s;
}

bool isFull(Stack* s){
    return s->top == MAX;
}

bool isEmpty(Stack* s){
    return s->top == 0;
}

void push(Stack* s, int value){
    if(isFull(s)){
        
    }
    
    s->items[s->top] = value;
    s->top++;
}

int pop(Stack* s){
    if(isEmpty(s)){
        return -1;
    }

    s->top--;
    return s->items[s->top];
}

int peek(Stack* s){
    if(isEmpty(s)){
        return -1;
    }
    
    return s->items[s->top - 1];
}

void display(Stack* s){
    if(isEmpty(s)){
        return;
    }

    for(int i = 0; i < s->top; i++){
        printf("%d ", s->items[i]);
    }
    printf("\n");
}


int main() {
    Stack *s = initialize();

    push(s, 1); // 1 
    push(s, 3); // 1 3 
    push(s, 2); // 1 3 2 
    push(s, 5); // 1 3 2 5 
    push(s, 4); // 1 3 2 5 4 
    display(s); // 1 3 2 5 4

    printf("Popped: %d\n", pop(s)); // 4
    display(s);  // 1 3 2 5
    
    printf("Peeking: %d\n", peek(s));  // 5
    
    while (!isEmpty(s)){
        pop(s);
    }

    push(s, 1); // 1 
    push(s, 3); // 1 2 
    push(s, 5); // 1 2 5
    push(s, 10); // 1 2 5 10
    display(s); //1 3 5 10

    free(s);
    return 0;
}