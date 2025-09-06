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