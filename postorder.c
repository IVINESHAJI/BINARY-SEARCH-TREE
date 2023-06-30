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

void PostOrder(struct Node*temp) {
    if (temp != NULL) {
        PostOrder(temp -> left);
        PostOrder(temp -> right);
        printf("%d\t",temp -> data);
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
    
    PostOrder(root);
    
    return 0;
}