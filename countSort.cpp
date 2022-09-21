#include <iostream>
using namespace std;

void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<", ";
    }
    cout<<endl;
}

void countSort(int A[], int n){
    int index = 0;
    int max = A[0]; 
    for (int i = 0; i < n; i++)
    {
        if(max<A[i]){
            max = A[i]+1;
        }
    }
    int B[max];
    for (int i = 0; i < max; i++)
    {
        B[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        B[A[i]]++;
    }
    for(int i = 0; i<max; i++){
        while(B[i]>0){
            A[index]=i;
            index++;
            B[i]--;
        }
    }
}


int main(){
    int size = 5;
    int arr[] = {2, 5, 3, 12, 3};
    printArray(arr, size);
    countSort(arr, size);
    printArray(arr, size);
    return 0;
}