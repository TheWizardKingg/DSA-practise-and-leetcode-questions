#include<iostream>
#include<vector>
#include<climits>
using namespace std;

bool isValid(int divisor, int threshold, vector<int>& nums){

    long long sum=0;

    for(int x: nums){
        sum += (x + divisor -1) / divisor;   //ceiling formulae for division (TheWizardKingg's code btw)
        if(sum > threshold) return false;
    }
    return sum <= threshold;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int maxEle=INT_MIN;

    for (int x: nums){
        maxEle=max(maxEle, x);
    }

    int start=1;
    int end=maxEle;
    int answer=1;

    while(start<=end){
        int mid=start+(end-start)/2;

        if(isValid(mid, threshold, nums)){
            answer=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return answer;
}

int main(){
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    cout << smallestDivisor(nums, threshold) << endl;
    return 0;
}