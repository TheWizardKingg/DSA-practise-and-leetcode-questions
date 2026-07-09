#include<iostream>
#include<vector>
using namespace std;

vector<int> getFloorAndCeil(vector<int> nums, int target) {
    int start =0;
    int end = nums.size()-1;
    int floor=-1;
    int ceil=-1;
    vector<int> ans;

    while (start <= end){
        int mid = start + (end-start)/2;
        
        if (nums[mid] == target){
            floor = nums[mid];
            ceil = nums[mid];
            ans.push_back(floor);
            ans.push_back(ceil);
            return ans;
        }else if(nums[mid] < target){
            floor=nums[mid];
            start=mid+1;
        }else{
            ceil=nums[mid];
            end=mid-1;
        }
    }
    ans.push_back(floor);
    ans.push_back(ceil);
    return ans;
}
int main(){
    vector<int> nums = {1,2,8,10,10,12,19};
    int target = 5;
    vector<int> ans = getFloorAndCeil(nums, target);
    cout << "Floor: " << ans[0] << ", Ceil: " << ans[1] << endl; // Output: Floor: 2, Ceil: 8
    return 0;
}