#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int count;
} PriorityQueue;

PriorityQueue* initialize(){
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->count = 0;
    return pq;
}

bool isFull(PriorityQueue* pq){
    return pq->count == MAX;
}

bool isEmpty(PriorityQueue* pq){
    return pq->count == 0;
}

void enqueue(PriorityQueue* pq, int value){
    if (isFull(pq)) {
        return;
    }

    int i;
    for (i = pq->count - 1; i >= 0 && pq->items[i] > value; i--) {
        pq->items[i + 1] = pq->items[i];
    }

    pq->items[i + 1] = value;
    pq->count++;
}

int dequeue(PriorityQueue* pq){
    if (isEmpty(pq)) {
        return -1;
    }

    int removed = pq->items[0];

    for (int i = 1; i < pq->count; i++) {
        pq->items[i - 1] = pq->items[i];
    }

    pq->count--;
    return removed;
}

int front(PriorityQueue* pq){
    if (isEmpty(pq)) {
        return -1;
    }
    return pq->items[0];
}

void display(PriorityQueue* pq){
    for (int i = 0; i < pq->count; i++) {
        printf("%d ", pq->items[i]);
    }
    printf("\n");
}

int main(){
    PriorityQueue *pq = initialize();

    enqueue(pq, 3); // 3
    enqueue(pq, 1); // 1 3
    enqueue(pq, 4); // 1 3 4
    enqueue(pq, 2); // 1 2 3 4
    display(pq);

    printf("Front: %d\n", front(pq)); // 1
    printf("Dequeued: %d\n", dequeue(pq)); // 1
    display(pq); // 2 3 4

    enqueue(pq, 5); // 2 3 4 5
    enqueue(pq, 6); // 2 3 4 5 6
    display(pq);

    free(pq);
    return 0;
}
