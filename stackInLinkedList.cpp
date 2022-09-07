#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void linkedListTraversal(struct Node *ptr) // O(n)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top)
{ // O(1)
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top)
{ // O(1)
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int x)
{ // O(1)
    if (isFull(top))
    {
        printf("Stack Overflow\n");
        return top;
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        return n;
    }
}

struct Node *pop(struct Node *top)
{ // O(1)
    if (isEmpty(top))
    {
        printf("Stack Underflow\n");
        return top;
    }
    else
    {
        struct Node *n = top;
        top = (top)->next;
        free(n);
        return top;
    }
}

int stackTop(struct Node *tp) // O(1)
{
    if (isEmpty(tp))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        return tp->data;
    }
}

int stackBottom(struct Node *tp) // O(n)
{
    if (isEmpty(tp))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        while (tp->next != NULL)
        {
            tp = tp->next;
        }
        return tp->data;
    }
}

int peak(struct Node *tp, int position) // O(n)
{
    if (isEmpty(tp))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        int i = 0;
        while (i < position - 1 && tp != NULL)
        {
            tp = tp->next;
            i++;
        }
        if (tp != NULL)
        {
            return tp->data;
        }
        else
        {
            return -1;
        }
    }
}

int main()
{
    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);
    printf("after push \n");

    linkedListTraversal(top);

    top = pop(top);

    printf("after pop \n");
    linkedListTraversal(top);

    printf("top element is %d\n", stackTop(top));
    printf("bottom element is %d\n", stackBottom(top));
    printf("second element is %d\n", peak(top, 2));

    printf("top element is %d\n", stackTop(top));

    return 0;
}
