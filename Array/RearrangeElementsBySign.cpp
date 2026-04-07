#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int positive=0, negative=0;                     //just make two pointers (one for first occuring positive element, one for first occuring negative element)

    vector<int> ans;

    for(int i=0; i<nums.size(); i++){

        while(positive < nums.size() && nums[positive]<0){       //keep on incresing the positive pointer until we find our first positive element
            positive++;
        }
        if(positive < nums.size()) ans.push_back(nums[positive++]);     //if pointer inside the array, then push it into the answer vector and increase the pointer      
        

        while(negative < nums.size() && nums[negative]>=0){       //keep on incresing the negative pointer until we find our first negative element
            negative++;
        }
        if(negative < nums.size())ans.push_back(nums[negative++]);      //if pointer inside the array, then push it into the answer vector and increase the pointer
    }
    return ans;       

    
}
int main(){
    vector<int> nums = {3,1,-2,-5,2,-4};
    vector<int> ans = rearrangeArray(nums);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}