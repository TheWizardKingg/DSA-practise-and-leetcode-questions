#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> findTwoSumIndices(vector<int> nums, int target){
    unordered_map<int,int> map;
    vector<int> ans;
    
    //loop to store all array values into the map
    for (int i=0; i<nums.size(); i++){
        map.insert({nums[i],i});
    }

    //loop to check if the two indices exist
    for( int i=0; i<nums.size(); i++){

        //check if the elements exist and both should be at different indices (no same element twice)
        if( map.find( target-nums[i]) != map.end() && map[target-nums[i]]!=i){

            ans.push_back(i);
            ans.push_back(map[target-nums[i]]);
        }
    }

    return ans;
}
int main(){
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> ans=findTwoSumIndices(nums,target);
    cout<<"Two sum indices are: "<<ans[0]<<" and "<<ans[1]<<endl;
}

