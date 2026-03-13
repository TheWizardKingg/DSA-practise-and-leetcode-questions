#include<iostream>
using namespace std;

void MoveZeroesToEnd(int arr[], int size){
    int i=0, j=0;
    for (i=0; i<size; i++){
        if(arr[i]!=0){
            arr[j++] = arr[i];
        }
    }
    while (j<size){
        arr[j++]=0;
    }
}




int main(){
    int arr[]={0,4,5,0,8,0,1,0};
    int size=8;
    MoveZeroesToEnd(arr,size);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// if(i==0 && arr[i]!=0){
    //     zero_index++;
    // }
    // else if(arr[i]!=0){
    //     arr[++zero_index]=arr[i];
    //     arr[i]=0;
    // }

//chatgpt said, this code above (in comments) is ugly, but works completely fine. 
//we just use two pointers, (j) tracks the zero element, and (i) moves forward to find the non-zero element
//once a non-zero element is found, we just do arr[j++]=arr[i], and i moves on to find next non-zero element
//after i reaches the end, this means, there are no non-zero elements left after j, 
//so we make all the elements after j to zero.