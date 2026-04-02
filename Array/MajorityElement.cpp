#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int,int> map;               //just make a freequency map to count the frequency of each element in the array and return the element which has frequency more than n/2
    int count=0;
    if(nums.size()==1){
        return nums[0];
    }
    for(int i=0; i<nums.size(); i++){
        if(map.find(nums[i])==map.end()){
            map.insert({nums[i],1});
        }else{
            map[nums[i]]++;
            if(map[nums[i]]>nums.size()/2){
                return nums[i];
            }
        }
    }
    return -1;
}
int main(){
    vector<int> nums={2,2,1,1,1,2,2};
    cout<<majorityElement(nums);
}