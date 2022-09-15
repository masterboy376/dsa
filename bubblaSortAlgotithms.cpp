#include <iostream>
using namespace std;

void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<", ";
    }
    cout<<endl;
}
void bubbleSort(int *A, int n){
    int temp;
    for (int i = 0; i < n-1; i++) // For number of pass
    {
        cout<<"Working on pass number "<<i+1<<endl; 
        for (int j = 0; j <n-1-i ; j++) // For comparison in each pass
        {
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp; 
            }
        }  
    } 
}
void bubbleSortAdaptive(int *A, int n){
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n-1; i++) // For number of pass
    {
        cout<<"Working on pass number "<<i+1<<endl; 
        isSorted = 1;
        for (int j = 0; j <n-1-i ; j++) // For comparison in each pass
        {
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSorted = 0;
            }
        } 
        if(isSorted){
            return;
        }
    } 
}

int main(){
    int size = 5;
    int arr[] = {2, 5, 3, 12, 3};
    bubbleSort(arr, size);
    printArray(arr, size);
    bubbleSortAdaptive(arr, size);

    return 0;
}