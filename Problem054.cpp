#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    if(nums.size()<=3) return ans;
    sort(nums.begin(), nums.end());
    set<vector<int>> st;
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1; 
        while(j<nums.size()-2){
            if (j>0 && nums[j]==nums[j-1]){
                j++;
                continue;
            }
            int k = j + 1, l = nums.size() - 1;
            while (k < l) {
                long long int sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                if (sum > target) {
                    l--;
                } else if (sum < target) {
                    k++;
                } else {
                    st.insert({nums[i],nums[j],nums[k],nums[l]});
                    l--;
                    k++;
                    while (k < l && nums[k] == nums[k - 1]) k++;
                }
            }
            j++;
        }
    }
    for (auto x: st){
        ans.push_back(x);
    }
    return ans;
}
int main(){
    vector<int> vec={1,0,-1,0,-2,2};
    int target=0;
    vector<vector<int>> res=fourSum(vec,target);
    for (auto x: res){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
    
}
//https://leetcode.com/problems/4sum/description/
//same approach as 3sum, just some additional things to take care of the 4th element
