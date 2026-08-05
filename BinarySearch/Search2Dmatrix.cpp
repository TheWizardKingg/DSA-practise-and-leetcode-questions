#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

bool searchMatrix(vector<vector<int>>& nums, int target) {    //O(log(m) + log(n)) == O(Log(m*n)) time complexity
    int m = nums.size();
    int n = nums[0].size();
    int low = 0;        //basically we're first gonna search over the rows to select the correct row which may contain the target, since matrix contains strictly increasing elements
    int high = m-1;   
    

    while(low <= high){  //this is the binary search for selecting the correct row 
        int middle = low + (high-low) / 2;

        if(nums[middle][0] <= target && target <= nums[middle][n-1]){    //if the target lies within the current row, then we shall perform another binary search in that row

            int start = 0;
            int end = n-1;

            while(start <= end){
                int mid = start + (end-start) / 2;

                if(nums[middle][mid] == target){     //traditional binary search, if we find target, return true, 
                    return true;

                }else if(nums[middle][mid] < target){      //if target < current element, then we move to the left
                    start = mid + 1;
                }else{         //if target > current element, then we move to the right of the row
                    end = mid - 1;
                }
            }
            return false;  //if the target actually belongs to current selected row, but unfortunately doesn't exist, then we return false
            
        }else if(nums[middle][0] > target){    //move to the previous row if target is lesser than first element of the current row

            high = middle - 1;
        }else{    //move to the next row if the target is greater than the first element of the current row

            low = middle + 1;
        }
    } 
    return false;   //return false if the target doesn't even belong to any of the matrix rows, hence (target < first element of first row) or
}                                                                                           //        (target > last element of the last row)

int main(){
    vector<vector<int>> nums = {{1, 3, 5, 7},
                                 {10, 11, 16, 20},
                                 {23, 30, 34, 60}};
    int target = 13;
    cout << searchMatrix(nums, target);
    return 0;
}