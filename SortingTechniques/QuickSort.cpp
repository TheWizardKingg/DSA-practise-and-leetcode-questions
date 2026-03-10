#include<iostream>
using namespace std;

int Partition(int arr[], int start, int end){  
    int i=start-1;
    int pivot_element=arr[end];
    for (int j=start; j<end; j++){
        if (arr[j]<=pivot_element){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    i++;
    swap(arr[end],arr[i]);
    return i;
    
}

void QuickSort(int start, int end, int arr[]){    
    if(start<end){
        int pivot_index=Partition(arr, start, end);
        
        QuickSort(start, pivot_index -1, arr);
        QuickSort(pivot_index +1, end, arr);
    }
}

int main(){
    int arr[]={10, 80, 30, 90, 40, 50, 70};
    int n=sizeof(arr)/sizeof(arr[0]);
    QuickSort(0, n-1, arr);
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//we just pick a pivot_element (first/last/median element) and then we just partition the array. 
//elements less than pivot element are moved to the left, and the elements greater than pivot element are moved to the right.
//eventually the array is partitioned into two and individually (after being left with only one element) they are sorted.
//that's the base case (if start>=end {then that means we are left with only one element hence no further recursion};)
//then the partition function just does the remaining job of partitioning the array, actually moving the elements, and returning pivot_index