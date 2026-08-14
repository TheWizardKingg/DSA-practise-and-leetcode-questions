#include<iostream>
#include<string>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;   //if size mismatch, then it can't be an anagram

    int freq1[26] = {0};     //make two fixed arrays of size 26 (this one for 's' letter's frequencies)
    int freq2[26] = {0};     //(this one for 't' letter's frequencies)

    for (int i=0; i<s.size(); i++){
        freq1[s[i] - 'a']++;     //calculate the index of the frequency array by subtracting ASCII codes for 's'
        freq2[t[i] - 'a']++;     //do the same for 't'
    }

    for (int j=0; j<26; j++){
        if(freq1[j] != freq2[j]) return false;     //just check all the frequencies, at any point of mismatch, return false
    }
    return true;    //all loops ran successfully, return true
}

int main() {

    string s = "anagram";
    string t = "nagaram";

    cout << isAnagram(s, t);

    return 0;
}