#include<iostream>
#include<string>
#include<vector>
using namespace std;

void generate(string s, int open, int close, int n, vector<string>& ans){
    if(s.size() == 2*n){      //base case if current string contains n parenthsis pairs 
        ans.push_back(s);    //store that current string in vector, and return from current recursion stack
        return;
    }

    if(open < n){      //if string has available space for an opening bracket
        generate(s + '(', open+1, close, n, ans);  //increment the open counter and add '(' to the current string
    }

    if(close < open){    //if string has available space for an unmatched closing bracket
        generate(s + ')', open, close+1, n, ans);    //increment the close counter and add ')' to the unmatched opening bracket in the string
    }
}

vector<string> generateParenthesis(int n){   //starting point
    vector<string> ans;    //make an empty vector to store all possible strings

    generate("", 0, 0, n, ans);   //make another function to keep things readable

    return ans;     //return the vector 
}