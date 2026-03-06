#include<iostream>
using namespace std;
void SelectionSort(int arr[], int n){
    int minimum_element_index;

    for(int i=0; i<n; i++){
        minimum_element_index=i;            //we assume minimum element is on the front already (sorted part)

        for(int j=i+1; j<n; j++){           //start searching for minimum element in the unsorted part
            if(arr[j]<arr[minimum_element_index]){
                minimum_element_index=j;        //note the index of the minimum element (in the unsorted part)
            }
        }

        swap ( arr[i] , arr[minimum_element_index] );    //just swap the minimum element with the front element

    }
}

int main(){
    int arr[5]={64, 25, 12, 22, 11};
    int n=sizeof(arr)/sizeof(arr[0]);
    SelectionSort(arr,n);
    cout<<"Sorted array: "<<endl;
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// assume two parts in the array         [ sorted |  unsorted ]
//                                         ^         ^
//                                         i         j
// find the minimum element in the unsorted part, and move it to the front
// the sorted part will grow, and unsorted part will keep on getting smaller and eventually vanish!