#include<iostream>
#include<vector>
using namespace std;

bool search(vector<int>& nums, int target) {
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;


        if (nums[mid]==target) return true;
        
        if(nums[low]==nums[mid] && nums[mid]==nums[high]){    //shrink the search space if all three are equal, cause in this case, we can't determine which side is sorted because of the duplicates
            low++;                                            //try [1,0,1,1,1] target=0. 
            high--;
            continue;
        }
        
        if(nums[low]<=nums[mid]){
            if(nums[low]<=target && target<=nums[mid]){

                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{
            if(nums[mid]<=target && target<=nums[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }
    return false;
}

int main(){
    vector<int> nums={2,5,6,0,0,1,2};
    int target=0;
    cout<<search(nums,target);
}