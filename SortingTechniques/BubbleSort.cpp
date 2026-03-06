#include<iostream>
using namespace std;
void BubbleSort(int arr[], int n){

    for (int i=0; i<n-1; i++){           //we running loop n-1 times, cause it will be sorted by then
        bool swapped=false;              //just a variable to check if any swapping is done in the first pass
                                         

        for(int j=0; j<n-i-1; j++){      //we not checking the last i elements, cause they already sorted

            if(arr[j]>arr[j+1]){         //if current element is bigger than the next element, then swap them

                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(swapped==false) break;   //if no swapping is done in the first iteration, then array is already sorted
    }
}

int main(){
    int arr[5]={64, 34, 25, 12, 22};
    int n=sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr,n);
    cout<<"Sorted array: "<<endl;
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

//compare adjacent elements and swap if the current element is bigger than the next one
//just like bubbles rise to the top
//array:                      [unsorted   | sorted]
//                             ^ ^
//                             j j+1  
//                                         <- (n-i-1)     [decreasing unsorted part]
//                                         <- (i)           [increasing sorted part]