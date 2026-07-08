#include<iostream>
#include<vector>
using namespace std;

int LowerBound(vector<int> &nums, int target){
    int start =0;
    int end = nums.size()-1;

    while (start <= end){
        int mid = start + (end-start)/2;       //to prevent overflow

        if (nums[mid] == target){
            while (mid != 0 && nums[mid-1] == nums[mid]){      //to skip to the lowest index 
                mid--;
            }
            return mid;

        }else if (nums[mid] < target){
            start = mid + 1;

        }else if (nums[mid] > target){
            while (mid !=0 && nums[mid-1] > target){       //to skip to the minimum just bigger element 
                mid--;
            }
            return mid;
        }
    }
    return nums.size();       //otherwise, retruning size as asked in question
}
int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 3;
    int result = LowerBound(nums, target);
    cout << "Lower Bound of " << target << " is: " << result << endl;
    return 0;
}