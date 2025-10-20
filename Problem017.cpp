#include<iostream>
#include<vector>
using namespace std;
void NextPermutations(vector<int> &nums){
    int a=-1;
    for (int i=nums.size()-1; i>0; i--){
        if (nums[i]>nums[i-1]){
            a=i-1;
            break;
        }
    }
    if (a==-1){
        int st=a+1, end=nums.size()-1;
        while (st<end){
            swap(nums[st],nums[end]);
            st++;
            end--;
        }
        return;
    }
    for (int i=nums.size()-1; i>a; i--){
        if (nums[i]>nums[a]){
            swap(nums[i],nums[a]);
            break;
        }
    }
    int st=a+1, end=nums.size()-1;
    while (st<end){
        swap(nums[st],nums[end]);
        st++;
        end--;
    }
    return;
}
int main(){
    vector<int> nums1={1,2,3};
    vector<int> nums2={3,2,1};
    NextPermutations(nums1);
    NextPermutations(nums2);
    cout<<"next permutation of the first array {1,2,3} is: ";
    for (int val1: nums1){
        cout<< val1<<" ";
    }
    cout<<endl;
    cout<<"next permutation of the second array {3,2,1} is: ";
    for (int val2: nums2){
        cout<< val2<< " ";
    }
    return 0;
}

// program number: 31 on leetcode "NextPermutations"
// we first find the element which is the first element to break the decreasing trend from the right end of the array
// then we just swap that element with the element just greater than that pivot element from the array's right end
// then we simply reverse the array elements after the pivot element's position
// if no such pivot element is found and the whole array is in decreasing order then we just reverse the whole array and return 