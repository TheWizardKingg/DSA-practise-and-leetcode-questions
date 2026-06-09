#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());       //first sort the array, hence all big values at the end, small values at beginning
        int j,k;
        for(int i=0; i<nums.size(); i++){   //i is fixed on each element one by one, and j is the smallest value(after i), k is largest
            if(i>0 && nums[i]==nums[i-1] ) continue;
            j=i+1;
            k=nums.size()-1;
            while(j<k){
                int sum=nums[i] + nums[j] + nums[k];
                if(sum<0){     //if sum less than zero, then increase the sum by increasing j
                    j++;
                }else if(sum>0){      //if sum greater than zero, then decrease sum by decreasing k
                    k--;
                }else if(sum==0){    //if sum is zero, then we push the triplet into answer vector
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;k--;       //update j, k values to avoid duplicates in array (since array is sorted, duplicates will be adjacent) and program will create redundant triplets
                    while(nums[j]==nums[j-1] && j<k){     //we keep skipping duplicate values of j, to start checking once a unique value in triplet is found
                        j++;
                    }
                }
            }
        }
        return ans;
        
    }
};
int main(){
    Solution s;
    vector<int> nums={-1,0,1,2,-1,-4};
    vector<vector<int>> ans=s.threeSum(nums);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}