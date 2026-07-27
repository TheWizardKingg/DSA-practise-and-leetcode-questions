#include <iostream>
#include <vector>
using namespace std;
    
int findPeakElement(vector<int> &nums){     //we can return any of the peak elements present in the array
    int start = 1;        //we were asked to do it in O(Log n) hence, binary search comes into action
    int end = nums.size() - 1;
    int mid;
    if (nums.size() == 1) return 0;   //edge case (since outside array is -infinity on both sides) 
    if (nums[0] > nums[1]) return 0;    //edge case (since outside array is -infinity on both sides)
    if (nums[end] > nums[end - 1]) return end;
    end--;

    while (start <= end){
        mid = start + (end - start) / 2;

        if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]){     //hence we are currently on the peak element
            return mid;
        }
        else if (nums[mid] > nums[mid - 1]) start = mid + 1;     //hence we are on increasing slope, so peak will be on the left
        else end = mid - 1;    //hence we are on decreasing slope, so peak will be on the right
    }
    return mid;     //dummy statement to avoid compiler warning
}

int main(){
    vector<int> nums = {1, 2, 3, 1};
    cout << findPeakElement(nums) << endl;
    return 0;
}