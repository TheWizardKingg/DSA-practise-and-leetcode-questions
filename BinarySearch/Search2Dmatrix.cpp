#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

bool searchMatrix(vector<vector<int>>& nums, int target) {
    int m = nums.size();
    int n = nums[0].size();
    int low = 0;
    int high = m-1;
    

    while(low <= high){
        int middle = low + (high-low) / 2;

        if(nums[middle][0] <= target && target <= nums[middle][n-1]){

            int start = 0;
            int end = n-1;

            while(start <= end){
                int mid = start + (end-start) / 2;

                if(nums[middle][mid] == target){
                    return true;

                }else if(nums[middle][mid] < target){
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
            return false;
            
        }else if(nums[middle][0] > target){

            high = middle - 1;
        }else{

            low = middle + 1;
        }
    } 
    return false;
}

int main(){
    vector<vector<int>> nums = {{1, 3, 5, 7},
                                 {10, 11, 16, 20},
                                 {23, 30, 34, 60}};
    int target = 13;
    cout << searchMatrix(nums, target);
    return 0;
}