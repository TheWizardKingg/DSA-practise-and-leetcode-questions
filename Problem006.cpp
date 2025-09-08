#include<iostream>
#include<vector>
using namespace std;
int peakIndexInMountainArray(vector<int>& arr) {
    int start=1, end =arr.size()-2;
    int mid=start+(end-start)/2;
    while (start<=end){
        if (arr[mid-1]< arr[mid] && arr[mid] >arr[mid+1]){
            return mid;
        }
        if (arr[mid-1]< arr[mid] && arr[mid]< arr[mid+1]){
            start=mid+1;
        }
        if (arr[mid-1]> arr[mid] && arr[mid]> arr[mid+1]){
            end=end-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}
int main(){
    vector<int> arr={0,2,1,0};
    cout<<peakIndexInMountainArray(arr);
    return 0;
}
// Problem link: https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
// we just simply apply binary search , and check if our mid is peak, or on the left side of peak or right side of peak
// after checking, we just update the start or end accordingly and proceed to find the result