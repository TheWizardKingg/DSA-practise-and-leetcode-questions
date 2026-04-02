#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;


void SortArrayOf_0_1_2(vector<int> &nums){
    int idx=0;
    
    for(int i=0; i<nums.size(); i++){        // put the 0's in the front of the array
        if(nums[i]==0){
            swap(nums[i],nums[idx++]);
        }
    }

    for(int j=0; j<nums.size(); j++){        //put the 1's in the middle of the array after zeros
        if(nums[j]==1){
            swap(nums[j],nums[idx++]);
        }
    }

    for(int k=0; k<nums.size(); k++){        //put the 2's in the end of the array after 1's
        if(nums[k]==2){
            swap(nums[k],nums[idx++]);
        }
    }
}

int main(){
    vector<int> nums={0,1,2,0,1,2};
    SortArrayOf_0_1_2(nums);

    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
}