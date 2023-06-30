#include <stdio.h>
#include <stdlib.h>

struct Node {

    struct Node *lchild;
    int data;
    struct Node *rchild;
    
};

int height(struct Node *node) {

    if (node == NULL) {
        return 0;
    }

    else {
        int left = height(node -> lchild);
        int right = height(node -> rchild);
        return (left > right) ? (left + 1) : (right + 1);
    }
}

void printLevel(struct Node* node,int level) {

    if (node == NULL) {
        return;
    }

    if (level == 1) {
        printf("%d\t",node -> data);
    }

    else if (level > 1) {
        printLevel(node -> lchild,level - 1);
        printLevel(node -> rchild,level - 1);
    }
}

void levelOrder(struct Node* node) {

    int h = height(node);

    for (int i = 1;i <= h; i ++) {
        printLevel(node,i);
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

    int h = height(head);

    printf("LevelOrder Elements are : ");
    levelOrder(head);

    return 0;
}