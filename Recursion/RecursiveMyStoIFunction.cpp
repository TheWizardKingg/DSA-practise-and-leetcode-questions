#include<iostream>
#include<string>
#include<climits>
using namespace std;
 
int helper(string &s, int i, long long num, int sign){
    if(i >= s.size() || !isdigit(s[i])) return sign*num;

    num = num*10 + (s[i] - '0');

    if(sign * num > INT_MAX) return INT_MAX;
    if(sign * num < INT_MIN) return INT_MIN;

    return helper(s, i+1, num, sign);
}

int myAtoi(string s) {
    int num = 0;
    int sign = 1;
    int i = 0;

    while(i<s.size() && (s[i] == ' ')) i++;

    if(i<s.size() && (s[i] == '+' || s[i] == '-')){
        if(s[i] == '-') sign = -1;
        i++;
    }

    return helper(s, i, num, sign);
}
