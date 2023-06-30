#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* lchild;
    int data;
    struct Node* rchild;
};

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->lchild = NULL;
        newNode->rchild = NULL;
        printf("%d added successfully\n", data);
        return newNode;
    } 
    
    else if (data < root->data) {
        root->lchild = insert(root->lchild, data);
    } 
    
    else if (data > root->data) {
        root->rchild = insert(root->rchild, data);
    } 
    
    else {
        printf("%d already exists\n", data);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%d\t", root->data);
        inorder(root->rchild);
    }
}

struct Node* findMin(struct Node* root) {

    if (root == NULL) {
        return NULL;
    } 
    
    else if (root->lchild == NULL) {
        return root;
    } 
    
    else {
        return findMin(root->lchild);
    }
}

struct Node* deleteNode(struct Node* root, int data) {
    
    if (root == NULL) {

        printf("%d not found in the BST\n", data);
        return root;

    }

    if (data < root->data) {

        root->lchild = deleteNode(root->lchild, data);

    } 
    
    else if (data > root->data) {

        root->rchild = deleteNode(root->rchild, data);

    } 
    
    else {
        
        // Node with one child or no child
        if (root->lchild == NULL) {
            
            struct Node* temp = root->rchild;
            free(root);
            printf("%d deleted successfully\n", data);
            return temp;

        } 
        
        else if (root -> rchild == NULL) {

            struct Node* temp = root -> lchild;
            free(root);
            printf("%d deleted successfully\n", data);
            return temp;

        }

        // Node with two children
        struct Node* temp = findMin(root -> rchild);
        root -> data = temp -> data;
        root -> rchild = deleteNode(root -> rchild, temp -> data);
    }

    return root;
}

int main() {
    struct Node* head = NULL;
    head = insert(head, 25);

    head = insert(head, 50);
    head = insert(head, 27);
    head = insert(head, 28);
    head = insert(head, 30);
    head = insert(head, 30);
    head = insert(head, 45);

    head = deleteNode(head, 25);
    head = deleteNode(head, 100);
    head = deleteNode(head, 25);

    inorder(head);

    return 0;
}
