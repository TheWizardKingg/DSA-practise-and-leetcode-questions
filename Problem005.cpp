#include<iostream>
#include<vector>
using namespace std;
int search(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (nums[mid] == target) return mid;
        if (nums[start] <= nums[mid]) {
            if (nums[start] <= target && target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } 
        else {
            if (nums[mid] < target && target <= nums[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return -1;
}
int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << search(nums, target) << endl;
    return 0;
}
// Problem link: https://leetcode.com/problems/search-in-rotated-sorted-array/
// we just introduce two start, end variables. And then we check if the mid element is equal to target, 
// if not we check which part is sorted, left or right. And then we check if the target lies in that part or not,
// if it lies we update the start or end accordingly, if not we search in the other. 