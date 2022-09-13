#include <iostream>
using namespace std;

struct Queue {
    int size;
    int f = 0;
    int r = 0;
    int *arr = NULL;
};

int isFull(struct Queue * ptr){ // O(1)
    if(((ptr->r + 1)%ptr->size) == (ptr->f)){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct Queue * ptr){ // O(1)
    if((ptr->r)==(ptr->f)){
        return 1;
    }
    else{
        return 0;
    }
}

int lastVal(struct Queue * ptr){ // O(1)
    if(isEmpty(ptr)){
        cout<<"The queue is empty"<<endl;
        return -1;
    }
    else{
        return ptr->arr[ptr->r];
    }
}

int firstVal(struct Queue * ptr){ // O(1)
    if(isEmpty(ptr)){
        cout<<"The queue is empty"<<endl;
        return -1;
    }
    else{
        return ptr->arr[ptr->f + 1];
    }
}

int peek(struct Queue * ptr, int pos){ // O(1)
    int index = pos-1;
    if((index<ptr->f+1) || (index>ptr->r)){
        cout<<"Invalid index"<<endl;
        return -1;
    }
    else{
        return ptr->arr[index];
    }
}

void enQueue(struct Queue * ptr, int val){ // O(1)
    if(isFull(ptr)){
        cout<<"The queue is full"<<endl;
    }
    else{
        ptr->r = ((ptr->r + 1)%ptr->size);
        ptr->arr[ptr->r] = val;
    }
}

int deQueue(struct Queue * ptr){ // O(1)
    int deVal;
    if(isEmpty(ptr)){
        cout<<"The queue is empty"<<endl;
        return -1;
    }
    else{
        ptr->f = ((ptr->f + 1)%ptr->size);
        deVal = ptr->arr[ptr->f];
        return deVal;
    }
}

int main(){

    struct Queue * q = new struct Queue();
    q->size=4 + 1; // one position in queue must be empty for front item
    q->arr=new int[q->size]; 

    enQueue(q, 15);
    enQueue(q, 34);
    enQueue(q, 45);
    enQueue(q, 75);

    cout<<deQueue(q)<<endl;
    cout<<deQueue(q)<<endl;
    cout<<deQueue(q)<<endl;
    cout<<deQueue(q)<<endl;

    enQueue(q, 100);

    cout<<lastVal(q)<<endl;
    cout<<firstVal(q)<<endl;

    return 0;
}