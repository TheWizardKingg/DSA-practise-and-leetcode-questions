#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0; 
        int sum=0;
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if (mp.find(sum)!=mp.end()){
                mp[sum]++;
            }else{
            mp.insert({sum,1});
            }
        }
        sum=0;
        for (int j=0; j<nums.size(); j++){
            sum+=nums[j];
            int target=sum-k;
            if (mp.find(target)!=mp.end()){
                count+=mp[target];
            }
            if (mp.find(nums[j])==mp.end()){
                mp[nums[j]]=0;
            }
            mp[nums[j]]++;
        }
        return count;
    }
};
int main(){
    Solution sol;
    vector<int> vec={1,1,1};
    int k=2;
    cout<<sol.subarraySum(vec,k);
}

//This is also not completed or tested yet, this alone took me the whole day (the bruteforce approach)
//This is the optimized approach
//the brute approach include 2 loops and checking all subarrays
//the optimized approach include prefix sum and hashmap to store the frequency of prefix sums

