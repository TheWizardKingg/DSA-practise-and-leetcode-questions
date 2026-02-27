#include<iostream>
#include<vector>
using namespace std;
bool isValid(vector<int> arr, int n, int maxPages, int totalStudents){
    int pages=0, students=1;
    for (int i=0; i<n; i++){
        if (arr[i]>maxPages){
            return false;
        }
        if (pages+arr[i]<=maxPages){
            pages+=arr[i];
        }else{
            students++;
            pages=arr[i];
        }
    }
    return students<=totalStudents;
}
int allocateBooks(vector<int> arr, int n, int totalStudents){
    int start=0, end=0;
    int mid,ans;
    for (int i=0; i<n; i++){
        end+=arr[i];
    }
    while(start<=end){
        mid=(start+(end-start)/2);
        if (isValid(arr, n, mid, totalStudents)){
            ans=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr={15,17,20};
    int n=arr.size();
    int totalStudents=2;
    cout<<allocateBooks(arr, n, totalStudents);
    return 0;
}

// Problem: Book allocation problem
// Link: https://www.codingninjas.com/codestudio/problems/allocate-books_1090540
// Difficulty: Hard
// Topic: Binary Search