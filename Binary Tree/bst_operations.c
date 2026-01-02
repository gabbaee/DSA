#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

Node* insertBST(Node *root, int value){
    if (root == NULL){
        return createNode(value);
    }

    if (value < root->data){
        root->left = insertBST(root->left, value);
    } else if (value > root->data){
        root->right = insertBST(root->right, value);
    } else {}
    return root;
}

bool searchBST(Node *root, int value){
    if (root == NULL){
        return false;
    }

    if (value == root->data){
        return true;
    } 
    
    else if (value < root->data){
        return searchBST(root->left, value);
    } 
    
    else {
        return searchBST(root->right, value);
    }
}

Node* findMin(Node *root){
    if (root == NULL){
        return NULL;
    }

    Node *curr = root;
    while (curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

int height(Node *root){
    if (root == NULL){
        return -1; // height of empty tree
    }

    int hl = height(root->left);
    int hr = height(root->right);
    return (hl > hr) ? (hl + 1) : (hr + 1);
}

int countNodes(Node *root){
    if (root == NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

Node* deleteBST(Node *root, int value){
    if (root == NULL){
        return NULL;
    }

    if (value < root->data){
        root->left = deleteBST(root->left, value);
    } 
    
    else if (value > root->data){
        root->right = deleteBST(root->right, value);
    } 
    
    else {
        if (root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        } 
        
        else if (root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        } 
        
        else if (root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        } 
        
        else {
            Node *minRight = findMin(root->right);
            root->data = minRight->data;
            root->right = deleteBST(root->right, minRight->data);
        }
    }

    return root;
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

void inorder(Node *root){
    if (root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){
    Node *root = NULL;

    root = insertBST(root, 5);  // root = 5
    root = insertBST(root, 2);  // 2 goes left of 5
    root = insertBST(root, 8);  // 8 goes right of 5
    root = insertBST(root, 1);  // 1 left of 2
    root = insertBST(root, 3);  // 3 right of 2
    root = insertBST(root, 7);  // 7 left of 8
    root = insertBST(root, 9);  // 9 right of 8

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Search 7: %s\n", searchBST(root, 7) ? "true" : "false");
    printf("Search 6: %s\n", searchBST(root, 6) ? "true" : "false");

    printf("Min: %d\n", findMin(root)->data);
    printf("Height: %d\n", height(root));
    printf("Node count: %d\n", countNodes(root));

    root = deleteBST(root, 2); 
    printf("After delete 2: ");
    inorder(root);
    printf("\n");

    destroyTree(&root); 
    return 0;
}
