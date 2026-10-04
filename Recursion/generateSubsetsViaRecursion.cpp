#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> ans;
vector<int> temp;

void generate(vector<int>& nums, int index){
    if(nums.size() == index){
        ans.push_back(temp);
        return;
    }

    generate(nums, index+1);

    temp.push_back(nums[index]);
    generate(nums, index+1);
    temp.pop_back();
}

vector<vector<int>> subsets(vector<int> nums){
    generate(nums, 0);
    return ans;
}