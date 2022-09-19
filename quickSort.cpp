#include <iostream>
using namespace std;

void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<", ";
    }
    cout<<endl;
}

int partition(int *A, int low, int high){
    int pivot = A[low];
    int i = low+1;
    int j = high;
    int temp;

    do{
        while (A[i]<=pivot)
        {
            i++;
        }
        while (A[j]>pivot)
        {
            j--;
        }
        if(i < j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i<j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    
    return j;
}

void quickSort(int *A, int low, int high){
    int partitionIndex;
    if(low < high){
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex-1);
        quickSort(A, partitionIndex+1, high);
    }
}

int main(){
    int size = 5;
    int arr[] = {2, 5, 3, 12, 3};
    printArray(arr, size);
    quickSort(arr, 0, size - 1);
    printArray(arr, size);
    return 0;
}