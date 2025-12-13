#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<vector<int>> threeSum(vector<int> nums){
    vector<vector<int>> ans;
    vector<int> vec;
    map<int,int> mp;
    for (int i=0; i<nums.size(); i++){
        mp.insert({nums[i],i});
    }

    for (int i=0; i<nums.size(); i++){
        for (int j=i+1; j<nums.size(); j++){
            int target=-(nums[i]+nums[j]);
            if(mp.find(target)!=mp.end()){
                if(i!=j && j!=mp[target] && mp[target]!=i){
                    
                    ans.push_back({nums[i],nums[j],target});
                }
            }
        }
    }
    return ans;
}
int main(){
    vector<int> nums={-1,0,1,2,-1,-4};
    vector<vector<int>> sol=threeSum(nums);
    for(vector<int> x: sol){
        for(int y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}