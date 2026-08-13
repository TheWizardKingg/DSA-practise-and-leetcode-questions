#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

bool isIsomorphic(string s, string t) {
    if(s.size() != t.size()) return false;
    map<char, char> mp;
    map<char, char> mp2;
    for(int i=0; i<s.size(); i++){
        if(mp.find(s[i]) != mp.end()){
            if(mp[s[i]] != t[i] ) return false;
        }else{
            mp.insert({s[i], t[i]});
            mp2.insert({t[i], s[i]});
        }
    }
    return true;
}

int main(){
    string s = "egg";
    string t = "add";
    bool result = isIsomorphic(s, t);
    cout << "Are the strings isomorphic? " << (result ? "Yes" : "No") << endl;
    return 0;
}