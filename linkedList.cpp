#include <iostream>
#include <stdlib.h>
using namespace std;

class Node {
    friend void linkedListTraversal(Node * ptr); // only needed for accessing private members
    public:
        int data;
        Node * next;
};

void linkedListTraversal(Node * ptr){
    while(ptr!=NULL){
    cout<<ptr->data<<" ";
    ptr = ptr->next;
    }
    cout<<endl;
}

int main()
{
    Node * head;
    Node * second;
    Node * third;

    // dynamic memory allocation
    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));

    // linking and setting value
    head->data = 7;
    head->next = second;

    second->data = 60;
    second->next = third;

    third->data = 50;
    third->next = NULL;

    linkedListTraversal(head);

    return 0;
}
