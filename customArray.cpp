#include <iostream>
#include <cmath>
using namespace std;

class CustomArray
{
    int *ptr;

public:
    int size;
    CustomArray(int s)
    {
        size = s;
        ptr = (int *)malloc(size * sizeof(int));
    }

    void setVal(int n, int i){
        if(i<size){
            ptr[i]=n;
            // cout<<*(ptr+1)<<endl;
        }
        else{
            size = size + ((i+1) - size);
            // int *tempPtr = ptr;
            ptr = (int *)realloc(ptr, size * sizeof(int));
            // ptr = tempPtr;
            // free(tempPtr);
            ptr[i]=n;
        }
    }

    void getVal(int i){
        if(i<size){
            cout<<ptr[i]<<endl;
        }
    }

    void showAll(){
        for (int i = 0; i<size; i++){
            cout<<ptr[i]<<", ";
        }
        cout<<endl;
    }

    void max(){
        int max = ptr[0];
        for (int i = 1; i<size; i++){
            if(max<ptr[i]){
                max = ptr[i];
            }
        }
        cout<<max<<endl;
    }

    void min(){
        int min = ptr[0];
        for (int i = 1; i<size; i++){
            if(min>ptr[i]){
                min = ptr[i];
            }
        }
        cout<<min<<endl;
    }

    void sum(){
        int sum = 0;
        for (int i = 0; i<size; i++){
                sum = sum + ptr[i];
        }
        cout<<sum<<endl;
    }

    void product(){
        int product = 1;
        for (int i = 0; i<size; i++){
                product = ((product) * (ptr[i]));
        }
        cout<<product<<endl;
    }

    void avg(){
        int sum = 0;
        for (int i = 0; i<size; i++){
                sum = sum + ptr[i];
        }
        cout<<(sum/size)<<endl;
    }

};

int main()
{

    CustomArray arr(2);

    arr.setVal(10,0);
    arr.setVal(20,1);
    arr.setVal(30,2);

    arr.getVal(0);
    arr.getVal(1);
    arr.getVal(2);

    arr.showAll();

    arr.max();

    arr.min();

    arr.sum();

    arr.avg();

    arr.product();

    cout<<arr.size<<endl;
    
    return 0;
}