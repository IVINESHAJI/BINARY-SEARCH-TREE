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
        printf("%d added successfully.\n", data);
        return newNode;

    }
    
    if (node->data > data) {
        
        node->lchild = insert(node->lchild, data);

    } 
    
    else if (node->data < data) {
     
        node->rchild = insert(node->rchild, data);

    } 
    else {
  
        printf("%d already exists.\n", data);
    }
    
    return node;
}

void search(struct Node* Node,int n) {

    static int ct = 0;
    
    if (Node == NULL) {
        return;
    }

    if (ct <= n) {
        search(Node -> lchild,n);
        ct ++;

        if (ct == n) {
            printf("%dth element is %d.\n",n,Node -> data);
        }

        search(Node -> rchild,n);

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

    search(head,1);

    return 0;
}