#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>nums){
    vector<vector<int>> ans;
    map<int,int> mp;
    set<vector<int>> st;
    
    for (int i=0; i<nums.size(); i++){
        mp.insert({nums[i],i});
    }
    for (int i=0; i<nums.size(); i++){
        for (int j=i+1; j<nums.size(); j++){
            int target=-(nums[i]+nums[j]);
            if (mp.find(target)!=mp.end()){
                if(i!=j && j!=mp[target] && mp[target]!=i){
                    vector<int> vec={nums[i],nums[j],target};
                    sort(vec.begin(), vec.end());
                    st.insert(vec);
                }
            }
        }
    }
    for (vector<int> vec: st){
        ans.push_back(vec);
    }
    return ans;
}
int main(){
    vector<int> nums={-1,0,1,2,-1,-4};
    vector<vector<int>> vec=threeSum(nums);
    for (vector<int> x: vec){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}
//dude finally, i got to understand this better approach after coding it for 5 days, i was stuck, kept thinking about how to avoid duplicates
// and finally i came to know that set also can be used to ensure unique elements inside a vector which blew my mind.