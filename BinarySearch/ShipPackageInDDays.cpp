#include<iostream>
#include<climits>
#include<vector>
using namespace std;

bool isValid(int capacity, int days, vector<int>& weights){
    int actualDays=1;
    int sum=0;
    
    for (int i=0; i<weights.size(); i++){
        if(sum + weights[i] > capacity){    //if current package exceeds the minimum capacity, then increase the days, and reset the sum to current package and try again
            actualDays++;
            sum = weights[i];
        }else{                   //keep going if the current package does not exceed the capacity
            sum += weights[i];
        }
        if(actualDays > days) return false;  //early return if actual days > days
    }
    return actualDays <= days;    //return true if capacity is valid, otherwise false
}
int shipWithinDays(vector<int>& weights, int days) {
    int maxEle=INT_MIN;  
    int sum=0;
    for(int x: weights){    //find the maximum weight
        maxEle=max(maxEle, x);
        sum+=x;
    }

    int start=maxEle;    //no. of days can be maximum to weigths.size(), hence, the ship will carry one weight each day and should be able to carry the maximum weight atleast
    int end=sum;     //minimum days can be 1, hence in such case, ship will have to carry all the load at once, hence the sum of all the weights
    int answer;

    while(start<=end){
        int mid = start + (end-start) / 2;

        if (isValid(mid, days, weights)){   //if current mid value is valid, then save it and try finding an even smaller value (if any)
            answer=mid;
            end=mid-1;
        }else{
            start=mid+1;    //if current mid value is not valid, then try finding a larger value than that
        }
    }
    return answer;    //return the answer
}

int main(){
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout << shipWithinDays(weights, days) << endl;
    return 0;
}