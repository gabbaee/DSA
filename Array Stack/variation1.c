#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int count;
} List;

typedef struct {
    List list;
    int front;
    int rear;
} Queue;

Queue* initialize(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->list.count = 0;
    q->front = 0;
    q->rear = 0;
    return q;
}

bool isFull(Queue* q){
    return q->list.count == MAX;
}

bool isEmpty(Queue* q){
    return q->list.count == 0;    
}

void enqueue(Queue* q, int value){
    if (isFull(q)){
        return;
    }

    q->list.items[q->rear] = value;
    q->rear = (q->rear + 1) % MAX;
    q->list.count++;
}

int dequeue(Queue* q){
    if (isEmpty(q)){
        return -1;
    }

    int dequeued = q->list.items[q->front];
    q->front = (q->front + 1) % MAX;
    q->list.count--;
    return dequeued;
}

int front(Queue* q){
    if (isEmpty(q)){
        return -1;
    }
    
    return q->list.items[q->front];
}

void display(Queue* q){
    if (isEmpty(q)){
        return;
    }

    for (int i = 0; i < q->list.count; i++) {
        int index = (q->front + i) % MAX;
        printf("%d ", q->list.items[index]);
    }
    printf("\n");
}

int main(){
    Queue *q = initialize();

    enqueue(q, 1); // 1
    enqueue(q, 3); // 1 3
    enqueue(q, 2); // 1 3 2
    enqueue(q, 5); // 1 3 2 5
    enqueue(q, 4); // 1 3 2 5 4
    display(q); // 1 3 2 5 4

    dequeue(q); // 3 2 5 4
    printf("Front: %d\n", front(q)); // 3
    display(q); // 3 2 5 4

    while (!isEmpty(q)){
        dequeue(q);
    }

    enqueue(q, 1); // 1
    enqueue(q, 3); // 1 3
    enqueue(q, 5); // 1 3 5
    enqueue(q, 10); // 1 3 5 10
    display(q); // 1 3 5 10

    free(q);
    return 0;
}
