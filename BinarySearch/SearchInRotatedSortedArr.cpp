#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int start=0;
    int end=nums.size()-1;
    int beg=0;
    int last=nums.size()-1;

    while (start<=end){
        int mid = start + (end-start)/2;

        if (nums[mid]== target) return mid;

        if (nums[start] <= nums[mid]){       //check if left side is sorted
            if (nums[start]<=target && target<=nums[mid]){      //check if target is in left side or not
                end=mid-1;
            }else{
                start=mid+1;
            }
        }else{                               //check if right side is sorted
            if (nums[mid]<=target && target<=nums[end]){        //check if target is in right side or not
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
    }
    return -1;          //target not found
}
int main(){
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << search(nums, target) << endl;
    return 0;
}