#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums1={1,2,3,0,0,0};          //m=total elements other than zero in nums1
    vector<int> nums2={2,5,6};                //n=total elements in nums2
    int n=3,m=3;        // actual size of nums1=n+m (so that we can rewrite all the elements from both arrays into nums1 in increasing order)
    int a=m-1;
    int b=n-1;
    int i=m+n-1;
    while (a>=0 && b>=0){
        if (nums1[a]>nums2[b]){
            nums1[i]=nums1[a];
            a--;
        }else{
            nums1[i]=nums2[b];
            b--;
        }
        i--;
    }
    while (b>=0){
        nums1[i]=nums2[b];
        b--;
        i--;
    }
    for (int val: nums1){
        cout<< val<<" ";
    }
    return 0;
}

//Problem no. 88 on leetcode "merge sorted arrays"
// we just check and overwrite all the elements from both the arrays into nums1 so that eventually nums1 becomes an array in increasing order
// time complexity = O(m+n) withing constant space 