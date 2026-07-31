#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool isValid(int distance, int k, vector<int> &nums){
    int i=0;              //pointer to keep track of the last placed cow's position
    int tempPtr=i+1;      //pointer to check the next cow's position
    k--;                  //in very first iteration, two cows will be done being placed since one will be on 'i', and other will be on 'tempPtr'

    while(tempPtr < nums.size() && k>0){

        if(nums[tempPtr] - nums[i] >= distance){
            k--;
            i=tempPtr;
            
        }
        tempPtr++;
        
    }
    return k==0;    //true if all cows placed safely, false if any of the cows remain
}

int aggressiveCows(vector<int> &nums, int k) {

    sort(nums.begin(), nums.end());      //sorting the array to get minimum and maximum distance between the cows

    int start=1;    //minimum distance can be 1 
    int end = nums[nums.size()-1] - nums[0];     //maximum distance can be the difference between the last and first element of the sorted array
    int answer;

    while(start <= end){
        int mid = start + (end-start) / 2;

        if(isValid(mid, k, nums)){     //if distance is valid, then save it and try finding an even better or greater distance
            answer=mid;
            start=mid+1;
        }else{     //if distance is not valid, then try finding a smaller one
            end=mid-1;
        }
    }
    return answer;    //return the maximum possible minimum distance between the cows
}

int main(){
    vector<int> nums = {1, 2, 8, 4, 9};
    int k = 3;
    cout << aggressiveCows(nums, k) << endl;
    return 0;
}