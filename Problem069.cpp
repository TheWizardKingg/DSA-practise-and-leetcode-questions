#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        for (int i=0; i<nums.size(); i++){
            for (int j=i+1; j<nums.size(); j++){
                for (int k=j+1; k<nums.size(); k++){
                    if (nums[i]+nums[j]+nums[k]==0){
                        ans.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> nums={-1,0,1,2,-1,-4};
    vector<vector<int>> vec=sol.threeSum(nums);
    for (vector<int> x: vec){
        for (int y: x){
            cout<<y<<" ";
        }
        
    }
    return 0;
}