#include<iostream>
#include<cmath>
#include<vector>
#include<climits>
using namespace std;

bool isValid(int k, int h, vector<int>& nums){
    long long actualHours=0;
    for(int val: nums){
        actualHours+= (val + k - 1) / k;    //since one pile takes atleast one hour, and if bananas in that pile are more than theeating speed per hour, we need extra hours to finish the pile
    }
    return actualHours<=h;    //if total calculated hours are more than the given hours, then current eating speed is not valid, else it is valid
}

int minEatingSpeed(vector<int>& nums, int h) {   
    int maxEle=INT_MIN;
    for (int i=0; i<nums.size(); i++){   //finds maximum number of bananas in a pile to set the upper limit for binary search
        maxEle=max(maxEle, nums[i]);
    }
    int start=1;
    int end=maxEle;
    int answer;

    while(start<=end){      //binary search to find the minimum possible eating speed until guards return 
        long long mid=start+(end-start)/2;

        if(isValid(mid, h, nums)){   //if current predicted speed is valid, we try to find an even smaller speed while saving current speed in answer
            answer=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return answer;
}

int main(){
    int n, h;
    cout<<"Enter the number of piles: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the number of bananas in each pile: ";
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cout<<"Enter the number of hours: ";
    cin>>h;
    int result = minEatingSpeed(nums, h);
    cout<<"The minimum eating speed to finish all bananas in "<<h<<" hours is "<<result<<endl;
    return 0;
}