#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

vector<int> FindMaxSumSubarray(const vector<int>& nums){
    int currentSum = 0;
    int maxSum = INT_MIN;
    int start = 0, end = 0;
    int tempStart = 0;
    for(int i = 0; i < nums.size(); i++){
        currentSum += nums[i];
        if(currentSum > maxSum){
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
        if(currentSum < 0){
            currentSum = 0;
            tempStart = i + 1;
        }
    }
    vector<int> ans;
    for(int i = start; i <= end; i++)
        ans.push_back(nums[i]);
    return ans;
}
int main(){
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    vector<int> ans=FindMaxSumSubarray(nums);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}