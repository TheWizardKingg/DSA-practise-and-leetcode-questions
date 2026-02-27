#include<iostream>
#include<cmath>
#include<set>
#include<vector>
using namespace std;
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    set<int> st;
    vector<int> ans;
    int n=grid.size();
    int a,b;
    int mainsum=0,stsum=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (st.find(grid[i][j])!=st.end()){
                a=grid[i][j];
                
            }
            st.insert(grid[i][j]);
        }
        
    }
    for (int i=1; i<=n*n; i++){
        mainsum+=i;
    }
    for(int x: st){
        stsum+=x;
    }
    b=abs(mainsum-stsum);
    ans.push_back(a);
    ans.push_back(b);
    return ans;
}
int main(){
    vector<vector<int>> grid={{1,2,2},{3,4,5},{6,7,8}};
    vector<int> result=findMissingAndRepeatedValues(grid);
    for (int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}
//https://leetcode.com/problems/find-missing-and-repeated-values/
//make a set since inserting to set ignores values that already exists, then calculating the entire range sum and subtracting from the set elements sum, we get b