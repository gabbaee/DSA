#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

Queue* initialize(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = 0;
    return q;
}

bool isFull(Queue* q){
    return q->front == (q->rear + 1) % MAX;
}

bool isEmpty(Queue* q){
    return q->front == q->rear;
}

void enqueue(Queue* q, int value){
    if(isFull(q)){
        return;
    }
    
    q->items[q->rear] = value;
    q->rear = (q->rear + 1) % MAX;
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        return -1;
    }
    
    int dequeued = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    return dequeued;
}

int front(Queue* q){
    if(isEmpty(q)){
        return -1;
    }
    
    return q->items[q->front];
}

void display(Queue* q){
    if(isEmpty(q)){
        return;
    }
    
    for (int i = q->front; i != q->rear; i = (i + 1) % MAX) 
        printf("%d ", q->items[i]);
    printf("\n");
}

int main() {
    Queue *q = initialize();

    enqueue(q, 1); // 1
    enqueue(q, 3); // 1 3
    enqueue(q, 2); // 1 3 2
    enqueue(q, 5); // 1 3 2 5
    enqueue(q, 4); // 1 3 2 5 4
    display(q); // 1 3 2 5 4

    printf("Dequeued: %d\n", dequeue(q)); // 1
    display(q); // 3 2 5 4

    printf("Front: %d\n", front(q)); // 3

    while (!isEmpty(q)){
        dequeue(q);
    }

    enqueue(q, 1);  // 1
    enqueue(q, 3);  // 1 3
    enqueue(q, 5);  // 1 3 5
    enqueue(q, 10); // 1 3 5 10
    display(q); // 1 3 5 10

    free(q);
    return 0;
}

