#include<iostream>
using namespace std;
void InsertionSort(int arr[], int n){
    
    for(int i=1; i<n; i++){
        int j=i-1;
        int key=arr[i];

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        
        arr[j+1]=key;     // executes when while loop is over, hence j is either -1 or arr[j] is smaller than key,
                          // arr[j+1] element is already copied to arr[j+2] 
                          // hence in both cases we can insert the key element at j+1 position.
    }
    
}

int main(){
    int arr[]={12, 11, 13, 5, 6};
    int n=sizeof(arr)/sizeof(arr[0]);
    InsertionSort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

//the part between arr[0] to arr[i-1] is the sorted part, the part from arr[i] to arr[n-1] is the unsorted part
//we just simply take the key element (arr[i]) and compare it with the elements before it (sorted part)
//if the key element is smaller than the element before it, we take the key element, scan the sorted part,
//insert the key element in it's correct position in the sorted part and shift each of the remaining elements one step to the right.
//             [sorted | unsorted ]
//                   ^   ^
//                   j   i 
//                       key=arr[i]
//we scan the sorted part in the descending order and decrement the j until we find the correct position for the key element.