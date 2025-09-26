#include<iostream>
using namespace std;
int main(){
    int n=5;
    int arr[5]={4,1,5,2,3};
    for (int i=0;i<5; i++){
        for (int j=0; j<5-i-1;j++){
            if (arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for (int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
    
}
// Bubble sort algorithm to sort an array of integers in ascending order.
// Time complexity : O(n^2)