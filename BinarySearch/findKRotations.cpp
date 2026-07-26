#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findKRotation(vector<int> &nums){
    int start = 0;
    int end = nums.size() - 1;

    while (start < end){
        int mid = start + (end - start) / 2;

        if (nums[mid] > nums[end]){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return start;
}
int main(){
    vector<int> nums = {15, 18, 2, 3, 6, 12};
    cout << findKRotation(nums);
}