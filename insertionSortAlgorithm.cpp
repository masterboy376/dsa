#include <iostream>
using namespace std;

void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<", ";
    }
    cout<<endl;
}
void insertionSort(int *A, int n){
    int temp, key, j;
    for (int i = 1; i < n; i++) // For number of pass
    {
        cout<<"Working on pass number "<<i<<endl;
        key = A[i];
        j = i-1;
        // Loop for each pass
        while(j>=0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;  
    } 
}

int main(){
    int size = 5;
    int arr[] = {2, 5, 3, 12, 3};
    insertionSort(arr, size);
    printArray(arr, size);
    return 0;
}