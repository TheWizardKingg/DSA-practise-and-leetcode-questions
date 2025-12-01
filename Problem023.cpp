#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="daabcbaabcbc";
    string part="abc";
    while (s.length()>0 && s.find(part)<s.length()){
        s.erase(s.find(part),part.length());
    }
    for (auto val: s){
        cout<<val<<"";
    }
    return 0;
}
//removed all occurrences of substring "abc" from the given string "daabcbaabcbc" and printed the resulting string
//used string functions like find and erase