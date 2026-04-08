#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void FindNextPermutation(vector<int>& nums){
    int pivotIdx=-1;                        //to keep track of the pivot element index (pivot element is the element which is just smaller than the next element in the array)

    for(int i=nums.size()-2; i>=0; i--){
        if(nums[i]<nums[i+1]){                 //we just check and note the index of the pivot element 
            pivotIdx=i;
            break;
        }
    }

    if(pivotIdx==-1){                        //if the pivot element is -1, hence there is no such element which is smaller than its next element
        reverse(nums.begin(), nums.end());   //hence the array is in descending order and we just have to reverse it to get the next permutation
        return;
    }

    for(int i=nums.size()-1; i>pivotIdx; i--){       //this finds the element just bigger than the pivot element (we start from the end of the array and find the first element which is bigger than the pivot element)
        if(nums[i]>nums[pivotIdx]){
            swap(nums[i], nums[pivotIdx]);      //once found, we just swap the pivot with just bigger element than that
            reverse(nums.begin()+pivotIdx+1, nums.end());    //and then reverse the array after pivot element to get next permutation
            break;
        }
    }
}
int main(){
    vector<int> nums={1,2,5,4,3};
    FindNextPermutation(nums);
    for(int i:nums){
        cout<<i<<" ";
    }
    return 0;
}