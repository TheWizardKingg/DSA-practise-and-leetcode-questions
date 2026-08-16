#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;

string frequencySort(string s) {
    unordered_map<char,int> mp;
    vector<pair<char,int>> vec;
    string answer="";

    for(int i=0; i<s.size(); i++){
        if(mp.find(s[i]) != mp.end()){
            mp[s[i]]++;
        }else{
            mp.insert({s[i], 1});
        }
    }
    for(auto x: mp){
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end(), [](auto &a, auto &b){return a.second > b.second;});

    for(auto x: vec){
        answer += string(x.second, x.first);
    }
    return answer;


}
int main() {

    string s = "tree";

    cout << frequencySort(s) << endl;

    return 0;
}
