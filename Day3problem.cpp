#include<iostream>
#include<vector>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
    int prod=1;
    vector<int> answer;
    for (int i=0; i<nums.size(); i++){
        answer.push_back(prod);
        prod*=nums[i];
    }
    prod=1;
    for (int j=nums.size()-1; j>=0; j--){
        answer[j]*=prod;
        prod*=nums[j];
    }
    return answer;
}
int main(){
    vector<int> nums={1,2,3,4};
    vector<int> result=productExceptSelf(nums);
    for (int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
// https://leetcode.com/problems/product-of-array-except-self/
// first, we calculate product of all elements to the left of each index (prefix element)
// then we calculate product of all elements to the right of each index (suffix element)
// finally, we multiply both prefix and suffix on each answer index to get the final result array