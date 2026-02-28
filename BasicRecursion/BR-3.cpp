#include<iostream>
using namespace std;

void reverse(int arr[], int n, int start=0){
    if(start>=n/2){
        return;
    }
    swap(arr[start++],arr[n-start-1]);
    reverse(arr,n,start);
}

int main(){
    int arr[5]={1,2,3,4,5};
    reverse(arr,5);
    for(int val: arr){
        cout<<val<<endl;
    }
    return 0;
}

//we simply just made a function having array, its size, and a default parameter "start=0" 
//function simply swaps the values at the start, with the values at the end, both pointers keep moving towards each other and meet in mid
//then the base case avoids re-reversal of the values after the pointers reach the middle and cross each other and stops the recursion
//hence total recursive calls = approx half the size of the array