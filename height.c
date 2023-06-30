#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *lchild;
    struct Node* rchild;

};

int height(struct Node* node) {
    if (node == NULL) {

        return 0;

    } 
    
    else {

        int left = height(node->lchild);
        int right = height(node->rchild);
        return (left > right) ? (left + 1) : (right + 1);

    }
}
struct Node *insert(struct Node *node, int data) {
    
    if (node == NULL) {
        
        struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode->lchild = NULL;
        newNode->rchild = NULL;
        newNode->data = data;
        printf("%d added successfully\n", data);
        return newNode;

    }
    
    if (node->data > data) {
        
        node->lchild = insert(node->lchild, data);

    } 
    
    else if (node->data < data) {
     
        node->rchild = insert(node->rchild, data);

    } 
    else {
  
        printf("%d already exists\n", data);
    }
    
    return node;
}

void Inorder(struct Node* Node) {
    
    if (Node != NULL){

        Inorder(Node -> lchild);
        printf("%d\t",Node -> data);
        Inorder(Node -> rchild);
            
    }

}

int main() {
    struct Node *head;
    head = NULL;

    head = insert(head, 25);
    head = insert(head, 50);
    head = insert(head, 24);
    head = insert(head, 28);
    head = insert(head, 30);
    head = insert(head, 45);

    printf("Height of the tree: %d\n", height(head));

    Inorder(head);

    return 0;
}
