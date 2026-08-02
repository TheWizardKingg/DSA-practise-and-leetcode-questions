#include<iostream>
#include<vector>
#include<climits>
using namespace std;

bool isValid(int limit, int A, int B, vector<int>& nums){
    int actualPainters=1;
    int totalTime=0;
    for(int i=0; i<nums.size(); i++){

        if(totalTime + (nums[i]*B) <= limit){    //if total time is lesser/equal than the current chosen limit, then add it to the current painter's total timeual
            totalTime += nums[i]*B;
        }else{     //if current total time exceeds the current chosen limit, then assign a new painter, and reset the totalTime to current board's time
            actualPainters++;
            totalTime = nums[i]*B;
        }
    }
    return actualPainters <= A;    //if actual painters required is lesser/equal than given painters, then return true, otherwise false
}

int paint(int A, int B, vector<int>& nums) {
    int maxEle= INT_MIN;
    int sum=0;

    for(int x: nums){    //calculated sum, maximum value simultaneously, and multiplying by time according to question
        sum += x*B;
        maxEle=max(maxEle, x);
    }
    
    int start=maxEle*B;   //maximum painters given can be equal/more than size of array, hence one painter paints one board, hence maximum time taken by any painter will be maximum board length * time units
    int end=sum;   //minimum painters given can be 1, hence he'll have to paint all the boards, and hence total time would be sum*B (calculated above)
    int answer=-1;

    while(start <= end){
        int mid = start + (end-start) / 2;

        if(isValid(mid, A, B, nums)){   //if current value is valid, then save it and try finding an even smaller value (if any)
            answer=mid;
            end=mid-1;
        }else{      //if current value is not valid, then try finding a bigger value instead
            start=mid+1;
        }
    }
    return answer%10000003;     //return the valid answer so far (answer%10000003 is done to avoid integer overflow, as the answer can be very large)

}

int main(){
    vector<int> nums = {1, 10};
    int A = 2;
    int B = 5;
    cout << paint(A, B, nums) << endl;
    return 0;
}