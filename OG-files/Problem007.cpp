#include<iostream>
#include<vector>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
    int start=1, end=nums.size()-2;
    int mid=start+(end-start)/2;
    if (nums.size()==1) return nums[0];
    if (nums[0]!=nums[start]) return nums[0];
    if (nums[nums.size()-1]!=nums[end]) return nums[nums.size()-1];
    while (start<=end){
        if (nums[mid]==nums[mid-1]){
            if (mid%2==0){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }else if(nums[mid]==nums[mid+1]){
            if (mid%2==0){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }else{
            return nums[mid];
        }
        mid=start+(end-start)/2;

    }
    return -1;
}
int main(){
    vector<int> arr={1,1,2,3,3,4,4,8,8};
    cout<<singleNonDuplicate(arr);
    return 0;
}
// Problem link: https://leetcode.com/problems/single-element-in-a-sorted-array/description/
// we just initialize the binary search program structure and then simply check if the mid is equal to its previous or next element
// if mid is equal to its previous element AND number of elements on both the sides of mid are even, then we know that the single element lies on left side becasue even-1=odd
// if mid is equal to its previous element AND number of elements on both the sides of mid are odd, then we know that the single element lies on right side becasue odd-1=even
// follow the same logic if duplicate element of the mid lies after it
