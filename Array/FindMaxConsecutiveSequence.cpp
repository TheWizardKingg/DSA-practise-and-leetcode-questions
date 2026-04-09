#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int findMaxConsecutiveSequence(vector<int>& nums){
    map<int, int> map;
    int streakcount=1;
    int maxStreak=INT_MIN;
    for(int i=0; i< nums.size(); i++){
        map.insert({nums[i], i});
    }
    int pivot=nums[0];
    for(int i=0; i<nums.size(); i++){
        if(map.find(pivot+1)!=map.end()){
            streakcount++;
            maxStreak=max(maxStreak, streakcount);
        }else{
            streakcount=1;
        }
    }
    return maxStreak;
}

int main(){
    vector<int> nums={100, 4, 200, 1, 3, 2};
    cout<<findMaxConsecutiveSequence(nums);
}
        