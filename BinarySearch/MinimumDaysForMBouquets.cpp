#include<iostream>
#include<climits>
#include<vector>
using namespace std;

bool isValid(int n, int m, int k, vector<int>& bloomDay){
    int totalBouquet=0;
    for(int i=0; i<bloomDay.size(); i++){
        if(bloomDay[i] <= n){
            int streak=0;
            while(i<bloomDay.size() && bloomDay[i] <= n){     //if current flower can be used to make bouquet, then check for the next flower and keep counting the streak of flowers that can be used to make bouquet
                streak++;
                i++;
            }
            totalBouquet+=streak/k;   //check how many bouquets can be made from the streak 
            if(totalBouquet >= m) return true;   //if total bouquets made so far is greater than or equal to m, then return true

        }
        
    }
    return false;   //return false if total bouquets made so far is less than m after checking all flowers in the array
}

int minDays(vector<int>& bloomDay, int m, int k) {

    if((long long)m*k > bloomDay.size()) return -1;

    int minEle=INT_MAX;
    int maxEle=INT_MIN;

    for(int x: bloomDay){    //find the minimum and maximum element in the array for starting and ending point of the binary search range
        minEle=min(minEle, x);
        maxEle=max(maxEle, x);
    }

    int start=minEle;
    int end=maxEle;
    int answer;

    while(start<=end){
        int mid=start+(end-start)/2;

        if(isValid(mid, m, k, bloomDay)){   //if the current mid value is valid, save it and then try finding an even smaller value (if any) after saving 
            answer=mid;
            end=mid-1;
        }else{      //if current mid value is not valid, then try finding a larger value (if any)
            start=mid+1;
        }
    }
    return answer;
    
}

int main(){
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;
    cout << minDays(bloomDay, m, k) << endl;
    return 0;
}