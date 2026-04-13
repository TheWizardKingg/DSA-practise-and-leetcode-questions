#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<climits>
using namespace std;

int FindMaxConsecutiveSequence(vector<int>& nums){
    unordered_set<int> set;           //we use set datastructure because it stores unique values and we can search for O(1) time complexity
    int count; 
    int maxCount=INT_MIN;
    int tempElement;

    if(nums.size() == 0) return 0;        //return if the array is empty (edge case)

    for(int i=0; i<nums.size(); i++){      //store all the element of the array into the set
        set.insert(nums[i]);
    }

    for(auto it: set){              //iterate over set elements 
        if(set.find(it-1)== set.end()){        //check if the previous element of the current element is present or not
            count=1;                           //if not then we know that the current element is the starting point of the sequence
            tempElement=it;
            while(set.find(++tempElement)!=set.end()){      //keep increasing count until we keep finding the next consecutive elements
                count++;
            }
            maxCount=max(maxCount, count);       //eventually update maxCount with maximum count of the recent consecutive sequence
        }
    }
    return maxCount;     //ultimately return the maximum count of the biggest consecutive sequence 
}

int main(){
    vector<int> nums={100, 4, 200, 1, 3, 2};
    cout<<FindMaxConsecutiveSequence(nums);
    return 0;
}