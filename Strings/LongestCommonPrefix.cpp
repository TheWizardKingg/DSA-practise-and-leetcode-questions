#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    for (int i = 0; i < strs[0].size(); i++) {
        char ch = strs[0][i];

        for (int j = 1; j < strs.size(); j++) {
            if (i >= strs[j].size() || strs[j][i] != ch) {
                return strs[0].substr(0, i);
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