#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

typedef struct{
    Node *items[100];
    int front;
    int rear;
}Queue;


Node* createNode(int value){
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL){
        return NULL;
    }
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void initQueue(Queue *q){
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue *q){
    return q->front == q->rear;
}

void enqueue(Queue *q, Node *n){
    q->items[q->rear] = n;
    q->rear++;
}

Node* dequeue(Queue *q){
    Node *n = q->items[q->front];
    q->front++;
    return n;
}

void BFS(Node *root){
    if (root == NULL){
        return;
    }

    Queue q;
    initQueue(&q);

    enqueue(&q, root);

    while (isEmpty(&q) == 0){
        Node *curr = dequeue(&q);
        printf("%d ", curr->data);

        if (curr->left != NULL){
            enqueue(&q, curr->left);
        }
        if (curr->right != NULL){
            enqueue(&q, curr->right);
        }
    }
}

void destroyTree(Node **root){
    if (root == NULL){
        return;
    }
    if (*root == NULL){
        return;
    }

    destroyTree(&((*root)->left));
    destroyTree(&((*root)->right));

    free(*root);
    *root = NULL;
}

int main(){

    Node *root = createNode(10);
    root->left = createNode(20); 
    root->right = createNode(30); 
    root->left->left = createNode(40);
    root->left->right = createNode(50); 
    root->right->left = createNode(60);    
    root->right->right = createNode(70); 

    printf("BFS (level-order): ");
    BFS(root);
    printf("\n");

    destroyTree(&root);
    return 0;
}
