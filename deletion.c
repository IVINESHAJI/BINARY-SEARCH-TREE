#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
};


struct Node *insert(struct Node *Node, int data) {
    if (Node == NULL) {
        struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode->lchild = NULL;
        newNode->rchild = NULL;
        newNode->data = data;
        printf("%d added successfully\n", data);
        return newNode;
    }
    else if (Node->data > data) {
        Node->lchild = insert(Node->lchild, data);
    } 
    else if (Node->data < data) {
        Node->rchild = insert(Node->rchild, data);
    } 
    else {
        printf("%d already exists\n", data);
    }
    return Node;
}

void Inorder(struct Node* Node) {
    if (Node != NULL) {
        Inorder(Node->lchild);
        printf("%d\t", Node->data);
        Inorder(Node->rchild);
    }
}

struct Node *search(struct Node *Node,int data) {

    if (Node == NULL) {
        return NULL;
    }

    if (Node -> data == data) {
        return Node;
    }

    else {

        if (Node -> data > data) {
            return search(Node -> lchild,data);
        }

        else {
            return search(Node -> rchild,data);
        }

    }

}

struct Node *delete(struct Node *Node, int data) {

    struct Node *delNode = search(Node, data);

    if (delNode == NULL) {
        printf("%d not found in Binary Search Tree\n", data);
        return Node;
    }

    struct Node *temp = delNode;

    if (temp->rchild != NULL) {

        temp = temp->lchild;

        while (temp->rchild != NULL) {
            temp = temp->rchild;
        }

        delNode->data = temp->data;
        free(temp);
    }

    else if (temp->lchild != NULL) {

        temp = temp->rchild;

        while (temp->lchild != NULL) {
            temp = temp->lchild;
        }

        delNode->data = temp->data;
        free(temp);
    }

    else {

        free(delNode);
        delNode = NULL;
    }

    printf("%d Deleted Successfully.\n", data);
    return Node;
}


int main() {
    struct Node *head = NULL;
    head = insert(head, 25);

    insert(head, 50);
    insert(head, 27);
    insert(head, 28);
    insert(head, 30);
    insert(head, 30);
    insert(head, 45);

    delete(head, 25);
    delete(head,100);
    Inorder(head);

    return 0;
}
