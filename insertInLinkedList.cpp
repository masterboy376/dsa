#include <iostream>
// #include<stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Case 1
struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    return ptr; 
}

// Case 2
struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Case 3
struct Node * insertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Case 4
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    
    return head;
}


int main(){
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link first and first nodes
    head->data = 7;
    head->next = first;

    // Link first and second nodes
    first->data = 11;
    first->next = second;

    // Link second and third nodes
    second->data = 41;
    second->next = third;

    // Terminate the list at the second node
    third->data = 66;
    third->next = NULL;

    printf("\nLinked list before insertion\n");
    linkedListTraversal(head);
    // head = insertAtFirst(head, 56);
    head = insertAtIndex(head, 56, 1);
    // head = insertAtEnd(head, 56);
    // head = insertAfterNode(head, second, 45);
    printf("Linked list after insertion\n");
    linkedListTraversal(head);

    
    return 0;
}