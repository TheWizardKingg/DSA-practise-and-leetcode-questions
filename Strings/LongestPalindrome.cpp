#include<iostream>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;

string longestPalindrome(string s) {
    string answer = "";
    int maxLen = 0;

    for(int i = 0; i < s.size(); i++) {

        int start = i;
        int end = i;

        while(start >= 0 && end < s.size() && s[start] == s[end]) {
            int len = end - start + 1;

            if(len > maxLen) {
                maxLen = len;
                answer = s.substr(start, len);
            }

            start--;
            end++;
        }


        start = i;
        end = i + 1;

        while(start >= 0 && end < s.size() && s[start] == s[end]) {
            int len = end - start + 1;

            if(len > maxLen) {
                maxLen = len;
                answer = s.substr(start, len);
            }

            start--;
            end++;
        }
    }

    return answer;
}

int main() {
    string s = "babad";

    cout << "Longest Palindromic Substring: "
         << longestPalindrome(s) << endl;

    return 0;
}