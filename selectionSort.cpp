#include <iostream>
using namespace std;

void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<", ";
    }
    cout<<endl;
}
void selectionSort(int *A, int n){
    int temp, min;
    for (int i = 0; i < n-1; i++) // For number of pass
    {
        cout<<"Working on pass number "<<i+1<<endl;
        min = i;
        // Loop for each pass
        for (int j = i+1; j < n ; j++) // For comparison in each pass
        {
            if(A[min]>A[j]){
                min = j;
            }
            temp = A[min];
            A[min] = A[i];
            A[i] = temp;
        }  
    } 
}

int main(){
    int size = 5;
    int arr[] = {2, 5, 3, 12, 3};
    selectionSort(arr, size);
    printArray(arr, size);
    return 0;
}