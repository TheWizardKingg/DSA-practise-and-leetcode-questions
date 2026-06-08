#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int count1=0, count2=0, el1=INT_MIN, el2=INT_MIN;   //atmost 2 majority elements can be there, wo we maintain 2 counters and 2 elements
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==el1){
                count1++;        //might not be the actual count of majority element, more like a score which is increased when we encounter same elements
            }else if(nums[i]==el2){
                count2++;        //might not be the actual count of majority element, more like a score which is increased when we encounter same elements
            }else if(count1==0 && nums[i]!=el2){
                el1=nums[i];
                count1=1;
            }else if(count2==0 && nums[i]!=el1){
                el2=nums[i];
                count2=1;
            }else{        //since the element is unique, it will decrease the count of both majority elements
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(int val: nums){        //we now find actual counts of the potential majority elements
            if(val==el1) count1++;
            else if(val==el2) count2++;
        }
        if(count1>(int)nums.size()/3) ans.push_back(el1);      //if they occur more than n/3 times, they get added
        if(count2>(int)nums.size()/3) ans.push_back(el2);
        return ans;
        
    }
};
int main(){
    Solution s;
    vector<int> nums={1,1,3,2,1,3,2,2};
    vector<int> ans=s.majorityElement(nums);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}