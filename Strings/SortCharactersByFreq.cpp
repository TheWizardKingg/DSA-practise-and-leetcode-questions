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

    for(int i=0; i<s.size(); i++){       //store {char, frequency} in map
        if(mp.find(s[i]) != mp.end()){
            mp[s[i]]++;
        }else{
            mp.insert({s[i], 1});
        }
    }
    for(auto x: mp){    //store all the map contents into a vector to sort them based on their values (map only sorts based on keys )
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end(), [](auto &a, auto &b){return a.second > b.second;});    //write a sort function which sorts based on second values (aka frequencies)

    for(auto x: vec){      //make a new string and add the characters times their frequency in the string
        answer += string(x.second, x.first);
    }
    return answer;    //return the final answer


}
int main() {

    string s = "tree";

    cout << frequencySort(s) << endl;

    return 0;
}
