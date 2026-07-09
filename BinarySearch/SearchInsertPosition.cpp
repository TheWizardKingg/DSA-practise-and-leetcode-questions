#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size()-1;
    int mid;

    while (start <= end){
        int mid = start + (end-start)/2;

        if (nums[mid] == target){
            return mid;
        }else if (nums[mid] > target){
            end = mid - 1;
        }else if (nums[mid] < target){
            start = mid + 1;
        }
        
    }
    return start;     //start will be the position where the target should be inserted if not found, i was returning mid all this time
    

}
int main(){
    vector<int> nums = {1,3,5,6};
    int target = 5;
    cout << searchInsert(nums, target) << endl; // Output: 2
    return 0;
}