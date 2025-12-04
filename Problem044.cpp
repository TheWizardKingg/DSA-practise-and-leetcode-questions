#include<iostream>
using namespace std;
class Solution {
public:
    bool isMember(string s, char c){
        for (char x: s){
            if (x==c){
                return true;
            }
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        string s2 = "";
        int gap = 0;
        for (int i = 0; i < s.length(); i++) {
            if (!s2.empty() && isMember(s2,s[i])) {  
                gap = max(static_cast<int>(s2.size()), gap); 
                s2 = "";
            } else {
                s2 = s2 + s[i];
                gap = max(static_cast<int>(s2.size()), gap);
            }
        }
        gap = max(static_cast<int>(s2.size()), gap);
        return gap;
    }
};
int main() {
    Solution sol;
    string s;
    cout << "Enter the string: ";
    cin >> s;
    int result = sol.lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;
    return 0;
}
//https://leetcode.com/problems/longest-substring-without-repeating-characters/
