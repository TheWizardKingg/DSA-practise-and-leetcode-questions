#include<iostream>
#include<vector>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());       //first we sort the array
        for(int a=0; a<nums.size(); a++){    //setup our first pointer a
            if(a>0 && nums[a]==nums[a-1]) continue;    //skip the duplicates (if any since sorting creates duplicates together)
            for(int b=a+1; b<nums.size()-1; b++){   //setup our second pointer b
                if(b>a+1 && nums[b]==nums[b-1]) continue;     //skip the b duplicates
                int c=b+1;           //setup our third pointer c
                int d=nums.size()-1;       //setup our fourth pointer d
                while(c<d){          //simple two pointer approach for c and d
                    long long int sum=(long long)nums[a]+nums[b]+nums[c]+nums[d];     //since leetcode cases can overflow int, we use long long
                    if(sum<target) c++;          
                    else if(sum>target) d--;
                    else if(sum==target){
                        ans.push_back({nums[a],nums[b],nums[c],nums[d]});
                        c++;              //update pointers after insertion
                        d--;
                    }
                    while(c>b+1 && c<d && nums[c]==nums[c-1]){     //skip all the duplicates for c
                        c++;
                    }
                    while(d>c && d<nums.size()-2 && nums[d]==nums[d+1]){   //skip all the duplicates for d
                        d--;
                    }
                }
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,0,-1,0,-2,2};
    int target=0;
    vector<vector<int>> ans=s.fourSum(nums,target);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}