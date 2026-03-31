#include<iostream>
using namespace std;

int LongestSubarraySumK(int arr[], int n, int k){
    int sum=arr[0];
    int right=0, left=0;
    int longestSubarraySize=0;
     
    while(right<n){                  //we use two pointer approach to create a sum window (check until whole array is completed, aka right<n)
         
        while(left<=right && sum>k){            //if sum exceeds the target, keep shrinking the sum window till it becomes equal or smaller than target
            sum-=arr[left++];               //update statement for the inner loop
        }

        if(sum == k){                 //if sum equals target, then note the size of this subarray and continue further
            longestSubarraySize=max(longestSubarraySize, right-left);
        }
        
        right++;                  //update statement for the outer loop
        if(sum<k){                //inner loop must have made it smaller by only one value
            sum+=arr[right];      //inner loop must have been terminated after the last shrinking value made it smaller than the target
        }                         //hence the next value will either make it bigger than target or make it equal, (which will be handled similarly like above)
        
    }

    return longestSubarraySize;   //eventually return the longest subarray size we've came across
}

int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=9;
    cout<<"Longest subarray size with sum k is: "<<LongestSubarraySumK(arr,n,k)<<endl;
}