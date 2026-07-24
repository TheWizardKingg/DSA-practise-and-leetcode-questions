#include<iostream>
#include<vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int beg=-1;
    int last=-1;
    int start=0;
    int end=nums.size()-1;
    int tempmid1;
    int tempmid2;
    vector<int> ans;

    while(start<=end){
        int mid= start + (end-start)/2;

        if (nums[mid]<target){
            start=mid+1;
        }else if(nums[mid]>target){
            end=mid-1;
        }else{
            tempmid1=mid;
            tempmid2=mid;
            beg=mid;
            last=mid;
            while(tempmid1 != 0 && nums[tempmid1-1] == target){      //just skip to the first occurrence of the target
                beg=tempmid1-1;
                tempmid1--;
            }
            while(tempmid2 != nums.size()-1 && nums[tempmid2+1] == nums[tempmid2]){     //skip to the last occurrence of the target
                last=tempmid2+1;
                tempmid2++;
            }
            break;
            
        }
    }
    ans.push_back(beg);       //push and return the first and last occurrence of the target
    ans.push_back(last);
    return ans;
}

int main(){
    vector<int> nums={5,7,7,8,8,10};
    int target=8;
    vector<int> ans=searchRange(nums,target);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}