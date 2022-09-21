#include <iostream>
using namespace std;

void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<", ";
    }
    cout<<endl;
}

void merge(int A[], int mid, int low, int high, int n)
{
    int i, j, k, B[n];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}

void mergeSort(int A[], int low, int high, int n){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid, n);
        mergeSort(A, mid+1, high, n);
        merge(A, mid, low, high, n);
    }
}


int main(){
    int size = 5;
    int arr[] = {2, 5, 3, 12, 3};
    printArray(arr, size);
    mergeSort(arr, 0, size-1, size);
    printArray(arr, size);
    return 0;
}