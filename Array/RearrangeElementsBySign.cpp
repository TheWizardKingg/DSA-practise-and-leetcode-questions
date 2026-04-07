#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrangeArray1(vector<int>& nums) {
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

vector<int> rearrangeArray2(vector<int>& nums){
    vector<int> ans(nums.size(), 0);         //we just initialize the answer vector with zeroes of size equal to that of nums
    int odd=1;                               //keeps the track of negative elements (which will always be coming in odd indices)
    int even=0;                              //keeps the track of positive elements (which will always be coming in even indices)

    for(int i=0; i<nums.size(); i++){
        if(nums[i]<0){
            ans[odd]=nums[i];
            odd+=2;                          //increment by 2 since it is odd index pointer
        }
        if(nums[i]>=0){
            ans[even]=nums[i];
            even+=2;                         //increment by 2 since it is also even index pointer
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {3,1,-2,-5,2,-4};
    vector<int> ans1 = rearrangeArray1(nums);
    cout<<"Answer by two pointers approach:-"<<endl;
    for(int i=0; i<ans1.size(); i++){
        cout<<ans1[i]<<" ";
    }
    
    cout<<endl;

    vector<int> ans2 = rearrangeArray2(nums);
    cout<<"Answer by step 2 indexing approach:-"<<endl;
    for(int i=0; i<ans2.size(); i++){
        cout<<ans2[i]<<" ";
    }
}