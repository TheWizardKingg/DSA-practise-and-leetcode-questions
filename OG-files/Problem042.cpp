#include<iostream>
#include<map>
#include<vector>
using namespace std;
int majorityElement(vector<int>& nums) {
    map<int,int> mp;
    for (int i=0; i<nums.size(); i++){
        if (mp.find(nums[i])==mp.end()){
            mp.insert({nums[i],1});
        }else{
            mp[nums[i]]++;
        }
    }
    for(int i=0; i<nums.size(); i++){
        if (mp[nums[i]]>nums.size()/2){
            return nums[i];
        }
    }
    return -1;
}
int main(){
    vector<int> nums={3,2,3};
    int result=majorityElement(nums);
    cout<<result;
    return 0;
}
//https://leetcode.com/problems/majority-element/
//using a map to store frequency of each element in the array, then checking,if occurence of any element is more than n/2.