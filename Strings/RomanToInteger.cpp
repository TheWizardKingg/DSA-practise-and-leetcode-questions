#include <iostream>
#include <map>
#include <climits>
#include <string>
using namespace std;

int romanToInt(string s) {
    map<char, int> mp = {   //create a map to store all the fundamental mappings 
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int sum = 0;

    for (int i = 0; i < s.size(); i++) {
        if (i + 1 < s.size() && mp[s[i]] < mp[s[i + 1]]) {   //if current element is less valuable than the next one, then subtract it according to the pattern in roman numerals
            sum -= mp[s[i]];
        }
        else {   //if current element is more valuable than next one, then add it into the current sum
            sum += mp[s[i]];
        }
    }

    return sum;    //return the sum
}

int main() {
    string s = "MCMXCIV";

    cout << romanToInt(s) << endl;

    return 0;
}

//this is my own recursive approach

// int recursive_func(string s, map<char, int>& mp){
//     if(s == "") return 0;
//     if(s.size() == 1) return mp[s[0]];

//     int tempSum = 0;
//     int maxValue = INT_MIN;
//     char maxChar;
//     int index;

//     for(int i=0; i<s.size(); i++){
//         if(mp[s[i]] > maxValue){
//             index = i;
//             maxChar = s[i];
//             maxValue = mp[s[i]];
//         }
//     }
//     string left = s.substr(0, index);
//     string right = s.substr(index+1, s.size()-index-1);

//     return (int)(maxValue - recursive_func(left, mp)) + (int)recursive_func(right, mp);
// }

// int romanToInt(string s) {
//     map<char,int> mp;

//     mp.insert({'I', 1});
//     mp.insert({'V', 5});
//     mp.insert({'X', 10});
//     mp.insert({'L', 50});
//     mp.insert({'C', 100});
//     mp.insert({'D', 500});
//     mp.insert({'M', 1000});
    
//     return recursive_func(s, mp);

    
// }