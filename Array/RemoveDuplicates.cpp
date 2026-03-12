#include<iostream>
using namespace std;
int RemoveDuplicates(int arr[], int size){
    int unique_index=0;

    for (int i=0; i<size; i++){
        while(arr[i]==arr[unique_index] && i<size){
            i++;
        }
        swap(arr[i],arr[++unique_index]);
    }
    return unique_index+1;

}

int main(){
    int arr[5]={1,2,2,3,4};
    int new_size=RemoveDuplicates(arr, 5);
    cout<<"The array after removing duplicates is: ";
    for (int i=0; i<new_size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
//we take a fast pointer (i) and a slow pointer (unique_index)
//we keep moving the fast pointer until we find a different element than the one at slow pointer
//we just swap the different element with the next position of slow pointer and move the slow pointer forward
//at the end we return the new size of the array which is unique_index+1 because.
//array is sorted hence all duplicates will be together, we just keep one copy of the element and skip the rest of the duplicates until we find another unique element.