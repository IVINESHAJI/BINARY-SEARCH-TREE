#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data) {

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;

    return temp;
}

void PreOrder(struct Node*temp) {
    if (temp != NULL) {
        printf("%d\t",temp -> data);
        PreOrder(temp -> left);
        PreOrder(temp -> right);
    }
}

int main () {
    
    struct Node *root = newNode(1);

    root -> left = newNode(2);
    root -> right = newNode(3);

    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);

    root -> right -> left = newNode(6);
    root -> right -> right = newNode(7);
    
    PreOrder(root);
    
    return 0;
}