#include<iostream>
using namespace std;
int findMissingNumber(int arr[], int n){
    int sum=0;                                   //example: for size(5), array can be [1,3,2,5]        answer:(4)
    int totalSum=((n+1)*(n+2))/2;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    return totalSum-sum;
}

int main(){
    int arr[]={1,3,2,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Missing number is: "<<findMissingNumber(arr,n)<<endl;
}

//find sum of all array elements
//find sum of all natural numbers from [1,n+1]
//return the difference of both sums, which will be the missing number in the array.