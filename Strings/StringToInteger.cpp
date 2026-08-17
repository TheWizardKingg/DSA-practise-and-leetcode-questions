#include<iostream>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;

int myAtoi(string s) {
    long long sum = 0;
    bool isNeg = false;
    int i = 0;

    while(i < s.size() && s[i] == ' ') {
        i++;
    }

    if(i < s.size() && s[i] == '-') {
        isNeg = true;
        i++;
    }
    else if(i < s.size() && s[i] == '+') {
        i++;
    }

    while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
        sum = sum * 10 + (s[i] - '0');

        if(!isNeg && sum > INT_MAX)
            return INT_MAX;

        if(isNeg && -sum < INT_MIN)
            return INT_MIN;

        i++;
    }

    if(isNeg)
        sum = -sum;

    return (int)sum;
}

int main(){
    string s = "-42abs";
    cout << myAtoi(s)<<endl;
    return 0;
}