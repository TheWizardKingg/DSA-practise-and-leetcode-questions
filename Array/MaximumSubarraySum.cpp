#include<iostream>
#include<algorithm>                   //kadane's algorithm {reset the current sum to 0 if it becomes negative}
#include<climits>                     //cause if we add that overall negative sum to next element, it will only drag the sum down
#include<vector>                      //hence the current sum should not be included further in the next elements
using namespace std;                  //cause it will only decrease the sum of the next elements, so we reset it to 0,
                                      //and start a fresh subarray from the next element, and again check whether the sum of this new subarray is maximum?
                                      
int maximumSubarraySum(vector<int> arr){
    int currentSum=0;                   //we initialize maxSum with INT_MIN because if all elements in array are negative,       
    int maxSum=INT_MIN;               //then maximum subarray sum will also be negative, and intitializing it with zero will set it to zero in the further code.
    for(int i=0; i<arr.size(); i++){
        currentSum+=arr[i];
        maxSum=max(maxSum, currentSum);
        if(currentSum<0){
            currentSum=0;
        }
    }
    return maxSum;
}

int main(){
    vector<int> arr={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maximumSubarraySum(arr)<<endl;
    return 0;
}