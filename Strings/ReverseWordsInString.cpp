#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string reverseWords(string s) {
    int n = s.size();

    // 1. Remove leading and trailing spaces
    int left = 0;
    while (left < n && s[left] == ' ')
        left++;

    int right = n - 1;
    while (right >= 0 && s[right] == ' ')
        right--;

    // 2. Remove extra spaces between words
    int j = 0;

    for (int i = left; i <= right; i++) {
        if (s[i] != ' ') {
            s[j++] = s[i];
        }
        else if (j > 0 && s[j - 1] != ' ') {
            s[j++] = ' ';
        }
    }

    s.resize(j);

    // 3. Reverse the entire string
    reverse(s.begin(), s.end());

    // 4. Reverse each individual word
    int start = 0;

    for (int i = 0; i <= s.size(); i++) {
        if (i == s.size() || s[i] == ' ') {
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }

    return s;
}
int main(){
    string s = "  the sky is       blue  ";
    cout << reverseWords(s) << endl; // Output: "blue is sky the"
    return 0;
}