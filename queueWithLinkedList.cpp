#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

int isFull()
{ // O(1)
    struct Node *n = new struct Node();
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{ // O(1)
    if (f == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int lastVal(struct Node *r)
{ // O(1)
    if (isEmpty())
    {
        cout << "The queue is empty" << endl;
        return -1;
    }
    else
    {
        return r->data;
    }
}

int firstVal(struct Node *f)
{ // O(1)
    if (isEmpty())
    {
        cout << "The queue is empty" << endl;
        return -1;
    }
    else
    {
        return f->data;
    }
}

int peek(struct Node *ptr, int pos)
{ // O(n)
    int index = 0;
    while (ptr != NULL)
    {
        if (index == pos - 1)
        {
            return ptr->data;
        }
        else
        {
            ptr = ptr->next;
            index++;
        }
    }
    cout<<"invalid position"<<endl;
    return -1;
}

void linkedListTraversal(struct Node *ptr)
{ //O(n)
    cout << "Printing the elements of this linked list" << endl;
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enQueue(int val)
{ // O(1)
    struct Node *n = new struct Node();
    if (n == NULL)
    {
        cout << "The queue is full" << endl;
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int deQueue()
{ // O(1)
    int deVal;
    struct Node *ptr = f;
    if (isEmpty())
    {
        cout << "The queue is empty" << endl;
        return -1;
    }
    else
    {
        f = f->next;
        deVal = ptr->data;
        free(ptr);
        return deVal;
    }
}

int main()
{

    linkedListTraversal(f);
    printf("Dequeuing element %d\n", deQueue());
    enQueue(34);
    enQueue(4);
    enQueue(7);
    enQueue(17);
    linkedListTraversal(f);
    cout<<"1: "<<peek(f,1)<<endl;
    cout<<"2: "<<peek(f,2)<<endl;
    cout<<"3: "<<peek(f,3)<<endl;
    cout<<"4: "<<peek(f,4)<<endl;
    printf("Dequeuing element %d\n", deQueue());
    printf("Dequeuing element %d\n", deQueue());
    printf("Dequeuing element %d\n", deQueue());
    printf("Dequeuing element %d\n", deQueue());
    cout<<"4: "<<peek(f,4)<<endl;
    linkedListTraversal(f);

    return 0;
}