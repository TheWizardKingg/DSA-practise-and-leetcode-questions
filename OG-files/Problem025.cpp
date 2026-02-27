#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main(){
    string s="the sky is blue";
    string ans=" ";
    string word=" ";
    reverse(s.begin(), s.end());
    for (int i=0; i<s.length(); i++){
        string word="";
        while (i<s.length() && s[i] != ' '){
            word+=s[i];
            i++;
        }
        reverse(word.begin(), word.end());
        if (word.length() > 0 ){
            ans+=" "+word;
        }
    }
    cout<<ans.substr(2);
}


// Problem: reverse words in string on leetcode
// we first reverse the whole original string which also reverses the individual words but atleast corrects their position
// now we just individually reverse every word separately inside the original string
//return the answer starting from one index ahead so that it does not return an extra space in beginning 