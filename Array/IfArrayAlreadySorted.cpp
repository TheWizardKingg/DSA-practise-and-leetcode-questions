#include<iostream>
using namespace std;
bool isSorted(int arr[], int size){
    bool sorted=true;
    for(int i=0; i<size-1; i++){
        if(arr[i]>arr[i+1]){
            sorted=false;
            break;
        }
    }
    return sorted;
}
int main(){
    int arr[5]={1,2,4,3,5};
    if(isSorted(arr, 5)){
        cout<<"The array is already sorted."<<endl;
    }else{
        cout<<"The array is not sorted."<<endl;
    }
    return 0;
}
//keep checking if the next element is greater than previous or not