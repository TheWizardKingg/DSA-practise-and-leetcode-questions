#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int,int> mp;
    vector<int> vec;
    for (int i=0; i<nums.size(); i++){
        if (mp.find(target-nums[i])!=mp.end()){
            vec.push_back(i);
            vec.push_back(mp[target-nums[i]]);
            break;
        }else{
            mp.insert({nums[i],i});
        }
        
    }
    return vec;
}
int main(){
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> result=twoSum(nums,target);
    for (int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}
//https://leetcode.com/problems/two-sum/
//This program literally took me more than 5 days to solve, like wtf is wrong with me. THis is the first leetcode problem T-T