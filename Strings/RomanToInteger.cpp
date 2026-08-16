#include <iostream>
#include <map>
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