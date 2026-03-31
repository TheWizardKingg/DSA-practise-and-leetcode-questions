#include<iostream>
using namespace std;
int UniqueInDuplicates(int arr[], int n){
    int XORall=0;
    for(int i=0; i<n; i++){
        XORall^=arr[i];
    }
    return XORall;
}
int main(){
    int arr[]={1,2,3,4,1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Unique element in duplicates is: "<<UniqueInDuplicates(arr,n)<<endl;
}
//just XOR all array elements together
//duplicate elements will cancel each other out,
//only unique element remains!
//cause XOR of duplicate elements will be 0, and XOR of 0 with unique element will be the unique element itself.