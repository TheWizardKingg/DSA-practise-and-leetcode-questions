#include<iostream>
#include<vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int start=0; 
    int end=nums.size()-1;
    if(nums.size()==1) return nums[0];
    if(nums.size()>=2 && nums[0]!=nums[1]) return nums[0];

    while(start<=end){    //XOR trick does this in O(n), but we were asked to do it in O(Log n), hence we are using binary search
        int mid=start+(end-start)/2;

        if (mid%2 == 0){      //single element can only lie on even index, hence, if even indices element's pair is not equal, then its single
            if(mid!=0 && nums[mid-1]==nums[mid]){    //if even index element is equal to its previous element, then single element lies on left side
                end=mid-1;
            }else if(nums[mid+1]==nums[mid]){     //if even index element is equal to its next element, then single element lies on right side
                start=mid+1;
            }else{
                return nums[mid];    //if none of its neighbors are equal, then its single
            }
        }else{    //odd index element's pair is always on left side, hence, if odd indices element's pair is not equal, then its single
            if(nums[mid-1]==nums[mid]){    //if odd index element is equal to its previous element, then single element lies on right side
                start=mid+1;
            }else if(nums[mid+1]==nums[mid]){    //if odd index element is equal to its next element, then single element lies on left side
                end=mid-1;
            }else{
                return nums[mid];  //if none of its neighbors are equal, then its single
            }
        }

    }
    return -1;    //if no single element is found, although we can check if size of array is odd==no single element, else if size is even==single element exists

        
}
int main(){
    vector<int> nums={1,1,2,3,3,4,4,8,8};
    cout<<singleNonDuplicate(nums);
}