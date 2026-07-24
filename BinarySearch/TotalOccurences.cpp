#include<iostream>
#include<vector>
using namespace std;

int countOccurrences(vector<int>& nums, int target) {
    int start=0;
    int end=nums.size()-1;
    int count=0;
    int temp1;
    int temp2;
    while(start<=end){
        int mid= start+(end-start)/2;

        if (nums[mid] == target){
            count++;
            temp1=mid;
            temp2=mid;

            while(temp1!=0 && nums[temp1-1] == target){   //skip to the first occurence, if any, and count the occurrences of the target
                count++;
                temp1--;
            }
            while(temp2!=nums.size()-1 && nums[temp2+1] == target){   //keep skipping to the last occurrence, if any, and count the occurrences of the target
                count++;
                temp2++;
            }

            return count;
        }else if (nums[mid] < target){
            start=mid+1;
        }else if (nums[mid] > target){
            end=mid-1;
        }
    }
    return -1;
}
int main(){
    vector<int> nums={5,7,7,8,8,10};
    int target=8;
    int ans=countOccurrences(nums,target);
    cout<<ans<<endl; // Output: 2
    return 0;
}