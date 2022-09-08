// in linked list 
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char data;
    struct Node *next;
};

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
        printf("Stack underflow\n");
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

int checkParanthesis(struct Node *top, string str)
{
    for (auto &ch : str)
    {
        if (ch == '(')
        {
            top = push(top, ch);
        }
        else if (ch == ')')
        {
            if (isEmpty(top))
            {
                cout << "Unmatched paranthesis" << endl;
                return 0;
            }
            top = pop(top);
        }
    }
    if (isEmpty(top))
    {
        cout << "Matched paranthesis" << endl;
        return 1;
    }
    else
    {
        cout << "Unmatched paranthesis" << endl;
        return 0;
    }
}

int main()
{
    struct Node *top = NULL;

    checkParanthesis(top, "3+21)");

    return 0;
}


//---------------------------------------------------------------------------------------------------
// in array 

// #include <stdio.h>
// #include <stdlib.h>
 
// struct stack
// {
//     int size;
//     int top;
//     char *arr;
// };
 
// int isEmpty(struct stack *ptr)
// {
//     if (ptr->top == -1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
 
// int isFull(struct stack *ptr)
// {
//     if (ptr->top == ptr->size - 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }
 
// void push(struct stack* ptr, char val){
//     if(isFull(ptr)){
//         printf("Stack Overflow! Cannot push %d to the stack\n", val);
//     }
//     else{
//         ptr->top++;
//         ptr->arr[ptr->top] = val;
//     }
// }
 
// char pop(struct stack* ptr){
//     if(isEmpty(ptr)){
//         printf("Stack Underflow! Cannot pop from the stack\n");
//         return -1;
//     }
//     else{
//         char val = ptr->arr[ptr->top];
//         ptr->top--;
//         return val;
//     }
// }
 
// int parenthesisMatch(char * exp){
//     // Create and initialize the stack
//     struct stack* sp;
//     sp->size = 100;
//     sp->top = -1;
//     sp->arr = (char *)malloc(sp->size * sizeof(char));
 
 
//     for (int i = 0; exp[i]!='\0'; i++)
//     {
//         if(exp[i]=='('){
//             push(sp, '(');
//         }
//         else if(exp[i]==')'){
//             if(isEmpty(sp)){
//                 return 0;
//             }
//             pop(sp); 
//         }
//     }
 
//     if(isEmpty(sp)){
//         return 1;
//     }
//     else{
//         return 0;
//     }
    
// }
// int main()
// {
//     char * exp = "((8)(*--$$9))";
//     // Check if stack is empty
//     if(parenthesisMatch(exp)){
//         printf("The parenthesis is matching");
//     }
//     else{
//         printf("The parenthesis is not matching");
//     }
//     return 0;
// }
