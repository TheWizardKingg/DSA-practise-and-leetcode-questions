#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

bool isValid(int limit, int k, vector<int> &nums){
    int totalSubarray=1;
    int actualSum=0;

    for(int i=0; i<nums.size(); i++){
        if(actualSum + nums[i] <= limit){      //if total sum is lesser/equal than the current chosen limit, then add it to the current subarray
            actualSum += nums[i];
        }else{      //if total sum exceeds the current chosen limit, then create a new subarray and add the current element to it
            totalSubarray++;     //increase the total subarray count since the total sum exceeded the current chosen limit
            actualSum = nums[i];     //reset the total sum to the current element so that we don't have to go back one iteration
        }      //set actualSum = 0, but then we'll have to go back one iteration, hence i--; will be needed once
    }
    return totalSubarray <= k;    //return true if total subarrays formed is lesser/equal than given k, otherwise false
}

int splitArray(vector<int>& nums, int k) {
    int maxEle=INT_MIN;    //maximum subarrays given can be equal to array size, hence each subarray can have one element, hence maximum sum of any element will be the maximum element
    int sum=0;      //minimum subarrays given can be 1, hence sum of all elements will be the maximum sum of any subarray
    for(int x: nums){
        sum+=x;
        maxEle=max(maxEle, x);
    }

    int start=maxEle;
    int end=sum;
    int answer=-1;

    while(start <= end){
        int mid = start + (end-start) / 2;

        if(isValid(mid, k, nums)){   //if current mid value is valid, then save it and try finding an even smaller value (if any)
            answer = mid;
            end = mid - 1;
        }else{      //if current mid value is not valid, then try finding a bigger value
            start = mid + 1;
        }
    }
    return answer;     //return the valid answer so far

}

int main(){
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    cout << splitArray(nums, k) << endl;
    return 0;
}