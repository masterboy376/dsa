#include <iostream>
// #include<stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    struct Node *head = ptr;
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

// Case 1 - O(n)
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != head)
    {
        p = p->next;
    }

    ptr->next = head;
    p->next = ptr;
    return ptr;
}

// Case 2 - O(n)
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    if (index == 0)
    {
        while (p->next != head)
        {
            p = p->next;
        }
        ptr->data = data;
        ptr->next = head;
        p->next = ptr;
        return ptr;
    }
    else
    {
        while (i != index - 1)
        {
            if (p->next == head)
            {
                break;
            }
            else
            {
                p = p->next;
                i++;
            }
        }
        ptr->data = data;
        ptr->next = p->next;
        p->next = ptr;
        return head;
    }
}

// Case 3 - O(n)
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}

// Case 4 - O(1)
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

// Case 1: Deleting the first element from the linked list
struct Node * deleteFirst(struct Node * head){
    struct Node *p = head;
    struct Node *ptr = head->next;

    while (p->next != head)
    {
        p = p->next;
    }

    p->next = ptr;
    free(head);
    return ptr;
}

// Case 2: Deleting the element at a given index from the linked list
struct Node * deleteAtIndex(struct Node * head, int index){
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);
    return head;
}

// Case 3: Deleting the last element
struct Node * deleteAtLast(struct Node * head){
    struct Node *p = head;
    struct Node *q = head;

    while (p->next != head)
    {
        p = p->next;
    }
    while (q->next != p)
    {
        q = q->next;
    }

    q->next = head;
    free(p);
    return head;
}


// Case 4: Deleting the element with a given value from the linked list
struct Node * deleteAfterNode(struct Node * head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data!=value && q->next!= head)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}

int main()
{
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
    third->next = head;

    printf("\nLinked list before insertion\n");
    linkedListTraversal(head);
    // head = insertAtFirst(head, 56);
    // head = insertAtIndex(head, 56, 0);
    // head = insertAtEnd(head, 56);
    // head = insertAfterNode(head, second, 56);
    // head = deleteFirst(head);
    // head = deleteAtLast(head);
    head = deleteAfterNode(head,7);
    head = deleteAtIndex(head,1);
    printf("Linked list after insertion\n");
    linkedListTraversal(head);

    return 0;
}