#include<iostream>
#include<vector>
using namespace std;
int singleNumber(vector<int>& nums) {
    int XORarr=0;
    for (int val: nums){
        XORarr^=val;
    }
    return XORarr;
    
}
int main(){
    vector<int> nums={4,1,2,1,2};
    int result=singleNumber(nums);
    cout<<result;
    return 0;
}
//https://leetcode.com/problems/single-number/
//using XOR operation properties, x^x=0 and x^0=x, cause all duplicate elements cancel each other, leaving only unique figure