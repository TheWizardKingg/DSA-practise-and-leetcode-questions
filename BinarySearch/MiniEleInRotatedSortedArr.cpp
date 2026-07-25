#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int findMin(vector<int>& nums) {
    int start=0;
    int end=nums.size()-1;
    int minEle=INT_MAX;

    while (start<=end){
        int mid=start+(end-start)/2;
        
        if(nums[start]<nums[end]) minEle=min(nums[start], minEle);    //if the current range is sorted, then minimum must be the first element of the range

        if(nums[start]<=nums[mid]){     //if the left part is sorted (we store the first element of the range) and we search in the remaining right part
            minEle=min(nums[start], minEle);
            start=mid+1;

        }else if(nums[mid]<nums[end]){   //if right part is sorted, we store the first element of the right part and search in remaining left part
            minEle=min(nums[mid], minEle);
            end=mid-1;
        }else if(start==end) break;     //if start==end, hence start==mid==end, and loop will run forever, hence break the loop



    }
    return minEle;
}

int main(){
    vector<int> nums={3,4,5,1,2};
    cout<<findMin(nums);
}