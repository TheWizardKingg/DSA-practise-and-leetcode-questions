#include<iostream>
#include<vector>
using namespace std;

void MergeSort(int arr[], int start, int end){            //this function only splits the array into two halves
    if(start<end){                  // because if start==end (start can never be > end), then there is only one element (hence no need to further split)
        int mid=start+(end-start)/2;

        MergeSort(arr, start, mid);      //split into the left part
        MergeSort(arr, mid+1, end);      //split into the right part
    }

}

void Merge(int arr[], int start, int mid, int end){   //this function merges them back together (actual sorting in mergesort happens while backtracking)
    int i=start;
    int j=mid+1;
    vector<int> temp;         //temporary storage to hold the sorted values after combining both the splitted halves of the original array
    
    while (i<=mid && j<=end){    //just storing the values from both halves into the temp vector in sorted fashion
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){             //to add elements remaining in the left half (if any)
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=end){            //to add elements remaining in the right half (if any)
        temp.push_back(arr[j]);
        j++;
    }

    for(int i=0; i<temp.size(); i++){      //just copying the values from the temp vector back to the original array part in correct order now
        arr[i+start]=temp[i];
    }

}

int main(){
    int arr[]={38, 27, 43, 3, 9, 82, 10};
    int n=sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// we just keep splitting the original array into two halves until we reach the base case where the splitted array contains only one element 
// (hence no need to further split) and then we start merging them back together in sorted fashion using the Merge function 
// which merges the two halves together while sorting the values in the backtracking process.
// time complexity: O(nlogn) because we are splitting the array into two halves logn times and merging them back together takes O(n) time.