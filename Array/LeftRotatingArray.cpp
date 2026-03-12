#include<iostream>
using namespace std;
void LeftRotateArray(int arr[], int size){
    int first_element=arr[0];
    int i=0;
    for(i=0; i<size-1; i++){
        arr[i]=arr[i+1];
    }
    cout<<"i: "<<i<<endl;
    arr[i]=first_element;

}

int main(){
    int arr[5]={1,2,3,4,5};
    LeftRotateArray(arr, 5);
    cout<<"The array after left rotation is: ";
    for (int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//we store the first element of the array becaue it will get overwritten in the first iteration
//we keep overwriting the current element with the next element until we reach the end of the array
//we simply place the first element at the end of the array after loop is done