#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());   //just sort the array

        vector<int> ans;      //store in a temporary vector

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {      //save the updated indexes 
                ans.push_back(i);
            }
        }

        return ans;
    }
};