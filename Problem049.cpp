#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &arr, int start, int mid, int end){
    int i=start,j=mid+1;
    vector<int> vec;
    while (i<=mid && j<=end){
        if (arr[i]<arr[j]){
            vec.push_back(arr[i]);
            i++;
        }else{
            vec.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        vec.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        vec.push_back(arr[j]);
        j++;
    }
    for (int idx=0; idx<vec.size(); idx++){
        arr[start+idx]=vec[idx];
    }
}
void mergesort(vector<int> &arr,int start, int end){
    if (start<end){
        int mid=start+(end-start)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);

        merge(arr,start,mid,end);
    }
}
int main(){
    vector<int> nums={5,3,1,2,4};
    mergesort(nums,0,nums.size()-1);
    for (int x: nums){
        cout<<x<<" ";
    }
    return 0;
}

//https://leetcode.com/problems/sort-an-array/description/
//Bro, this is hell of a code, merge sort is the toughest one i did so far (in sorting), recursion is no easy task.