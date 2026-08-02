#include<iostream>
#include<vector>
#include<climits>
using namespace std;

bool isValid(int limit, int A, int B, vector<int>& nums){
    int actualPainters=1;
    int totalTime=0;
    for(int i=0; i<nums.size(); i++){

        if(totalTime + (nums[i]*B) <= limit){
            totalTime += nums[i]*B;
        }else{
            actualPainters++;
            totalTime = nums[i]*B;
        }
    }
    return actualPainters <= A;
}

int paint(int A, int B, vector<int>& nums) {
    int maxEle= INT_MIN;
    int sum=0;

    for(int x: nums){
        sum += x*B;
        maxEle=max(maxEle, x);
    }
    
    int start=maxEle*B;
    int end=sum;
    int answer=-1;

    while(start <= end){
        int mid = start + (end-start) / 2;

        if(isValid(mid, A, B, nums)){
            answer=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return answer;

}

int main(){
    vector<int> nums = {1, 10};
    int A = 2;
    int B = 5;
    cout << paint(A, B, nums) << endl;
    return 0;
}