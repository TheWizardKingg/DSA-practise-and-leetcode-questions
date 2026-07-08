#include<iostream>
#include<vector>
using namespace std;

int BinarySearch(vector<int> nums, int target){
    int start = 0;
    int end = nums.size()-1;

    while (start <= end){
        int mid = start + (end-start)/2;

        if (nums[mid] < target){
            start = mid + 1;
        }else if (nums[mid] > target){
            end = mid - 1;
        }else{
            return mid;
        }
    }

    return -1;

}
int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 3;
    int result = BinarySearch(nums, target);
    cout << "Index of " << target << " is: " << result << endl;
    return 0;
}