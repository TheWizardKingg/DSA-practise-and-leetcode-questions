#include<iostream>
#include<vector>
using namespace std;
bool isValid(vector<int> arr, int n, int maxPaintTime, int totalPainters){
    int time=0, Painters=1;
    for (int i=0; i<n; i++){
        if (arr[i]>maxPaintTime){
            return false;
        }
        if (time+arr[i]<=maxPaintTime){
            time+=arr[i];
        }else{
            Painters++;
            time=arr[i];
        }
    }
    return Painters<=totalPainters;
}
int calculateTime(vector<int> arr, int n, int totalPainters){
    int start=0, end=0;
    int mid,ans;
    for (int i=0; i<n; i++){
        end+=arr[i];
    }
    while(start<=end){
        mid=(start+(end-start)/2);
        if (isValid(arr, n, mid, totalPainters)){
            ans=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr={40,30,10,20};
    int n=arr.size();
    int totalPainters=2;
    cout<<calculateTime(arr, n, totalPainters);
    return 0;
}

// Problem: Painter's Partition Problem
// literally same as book allocation problem, just different context
// https://www.codingninjas.com/codestudio/problems/painter-s-partition-problem_1081470
// https://www.geeksforgeeks.org/painters-partition-problem/