#include<iostream>
using namespace std;

int LinearSearch(int arr[], int size, int target){
    for (int i=0; i<size; i++){
        if (arr[i]==target){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[]={1,4,3,-1,0,3};
    int target=0;
    int target_index=LinearSearch(arr, 6, target);
    cout<<"index of the target element is: "<<target_index<<endl;
    return 0;
}

//i mean, man....., ur joking righttt