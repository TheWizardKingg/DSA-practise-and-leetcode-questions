#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {  //the common prefix always occurs at the beginning of the string 
    for (int i = 0; i < strs[0].size(); i++) {
        char ch = strs[0][i];

        for (int j = 1; j < strs.size(); j++) {   //i thought the prefix could appear anywhere in the string and spent 2 days on this easy problem 
            if (i >= strs[j].size() || strs[j][i] != ch) {   //but we just simply check first string's characters one by one with every other string
                return strs[0].substr(0, i);   //wherever we find a mismatch, we return the substring from the start upto that point
            }
        }
    }

    return strs[0];
}

int main(){
    vector<string> strs = {"flower", "flow", "flight"};
    string result = longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl;
    return 0;
}