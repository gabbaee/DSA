#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

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

void preorder(Node *root){
    if (root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root){
    if (root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node *root){
    if (root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
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
    Node *root = createNode(1);       
    root->left = createNode(2);         
    root->right = createNode(3);      
    root->left->left = createNode(4);    
    root->left->right = createNode(5);   
    root->right->left = createNode(6);    
    root->right->right = createNode(7);    

    printf("DFS Preorder:  ");
    preorder(root); // 1 2 4 5 3 6 7
    printf("\n");

    printf("DFS Inorder:   ");
    inorder(root); // 4 2 5 1 6 3 7
    printf("\n");

    printf("DFS Postorder: ");
    postorder(root); // 4 5 2 6 7 3 1
    printf("\n");

    destroyTree(&root);
    return 0;
}
