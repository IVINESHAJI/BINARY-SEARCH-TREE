#include <stdio.h>
#include <stdlib.h>

struct Node {

    struct Node *lchild;
    int data;
    struct Node *rchild;
};

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

int main () {

    struct Node *head;
    head = NULL;

    head = insert(head,25);

    insert(head,50);
    insert(head,27);
    insert(head,28);
    insert(head,30);
    insert(head,30);
    insert(head,45);

    Inorder(head);

    return 0;
}