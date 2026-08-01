#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

bool isValid(int limit, int k, vector<int> &nums){
    int totalSubarray=1;
    int actualSum=0;

    for(int i=0; i<nums.size(); i++){
        if(actualSum + nums[i] <= limit){
            actualSum += nums[i];
        }else{
            totalSubarray++;
            actualSum = nums[i];
        }
    }
    return totalSubarray <= k;
}

int splitArray(vector<int>& nums, int k) {
    int maxEle=INT_MIN;    //
    int sum=0;
    for(int x: nums){
        sum+=x;
        maxEle=max(maxEle, x);
    }

    int start=maxEle;
    int end=sum;
    int answer=-1;

    while(start <= end){
        int mid = start + (end-start) / 2;

        if(isValid(mid, k, nums)){
            answer = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return answer;

}

int main(){
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    cout << splitArray(nums, k) << endl;
    return 0;
}