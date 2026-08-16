#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<climits>
using namespace std;

int maxDepth(string s) {
    int counter = 0;
    int maxCounter = INT_MIN;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '(') counter++;   //current iteration depth
        else if(s[i] == ')') counter--;

        maxCounter = max(maxCounter, counter);   //store the maximum depth 
    }
    return maxCounter; //return the maximum depth
}

int main() {

    string s = "(1+(2*3)+((8)/4))+1";

    cout << maxDepth(s) << endl;

    return 0;
}