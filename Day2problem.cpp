#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int maxArea(vector<int>& height) {
    long int i=0, j=height.size()-1,maxarea=0;
    while (i<j){
        maxarea=max(abs(i-j)*min(height[i],height[j]),maxarea);
        if (height[i]<height[j]){
            i++;
        }else{
            j--;
        }
    }
    return maxarea;    
}
int main(){
    vector<int> height={1,8,6,2,5,4,8,3,7};
    cout << maxArea(height)<< endl;
    return 0;
} 
// https://leetcode.com/problems/container-with-most-water/
// we use two pointer approach here, one pointer at the start and one at the end and keep calculating the area and updating the maximum area so far
// and then we move the pointer which is at the smaller height towards the other pointer until both pointers meet
