#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main(){
    vector<int> prices={7,1,5,3,6,4};
    int profit=0;
    int min_Ele=prices[0];
    for (int i=1; i<prices.size(); i++){
        profit=max(profit,prices[i]-min_Ele);
        min_Ele=min(min_Ele, prices[i]);
    }
    cout << profit<< endl;
    return 0;
}
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// we just run a loop until the vector's size and keep updating the maximum between profit and the current price - minimum element so far
// and also keep updating the minimum element so far with the minimum between the current minimum element and the current price