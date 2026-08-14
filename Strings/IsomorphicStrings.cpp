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
        if(mp.find(s[i]) != mp.end()){  //make one hashmap to store s->t mapping
            if(mp[s[i]] != t[i]){
                return false;
            }
        }else{
            mp.insert({s[i], t[i]});
        }

        if(mp2.find(t[i]) != mp2.end()){   //make another hashmap to store t->s mapping
            if(mp2[t[i]] != s[i]){
                return false;
            }
        }else{
            mp2.insert({t[i], s[i]});
        }

        if(mp.find(s[i]) == mp.end() && mp2.find(t[i]) == mp2.end()){    //in case if both mapping don't exist primarily
            mp.insert({s[i], t[i]});    //insert both simultaneously for forward and reverse mapping 
            mp2.insert({t[i], s[i]});   //one to one mapping
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