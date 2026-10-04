#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> ans;
vector<int> temp;

void generate(vector<int>& nums, int index){
    if(nums.size() == index){      //if the index matches the size, hence we can't go for anymore branches in the recursion tree
        ans.push_back(temp);       //just save the current subset and return 
        return;
    }

    generate(nums, index+1);      //out of the two choices (either take an element or skip), this one skips the element first

    temp.push_back(nums[index]);   //include the element
    generate(nums, index+1);      //this one takes the element as the second choice
    temp.pop_back();         //remove that element to backtrack for next branch in the recursion tree
}

vector<vector<int>> subsets(vector<int> nums){  //starting point
    generate(nums, 0);    //call for recusion
    return ans;     //return final set of all subsets
}