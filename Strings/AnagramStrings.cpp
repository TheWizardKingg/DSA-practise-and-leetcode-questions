#include<iostream>
#include<strings>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;

    int freq1[26] = {0};
    int freq2[26] = {0};

    for (int i=0; i<s.size(); i++){
        freq1[s[i] - 'a']++;
        freq2[t[i] - 'a']++;
    }

    for (int j=0; j<26; j++){
        if(freq1[j] != freq2[j]) return false;
    }
    return true;
}

int main() {
    Solution obj;

    string s = "anagram";
    string t = "nagaram";

    cout << obj.isAnagram(s, t);

    return 0;
}