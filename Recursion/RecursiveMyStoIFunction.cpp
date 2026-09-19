#include<iostream>
#include<string>
#include<climits>
using namespace std;
 
int helper(string &s, int i, long long num, int sign){
    if(i >= s.size() || !isdigit(s[i])) return sign*num;    //base case when iterator runs out of bounds

    num = num*10 + (s[i] - '0');     //basically convert the string to integer by multiplying previous number by 10, and adding new digit to it

    if(sign * num > INT_MAX) return INT_MAX;     //base cases if the number exceed the 32-bit signed integer limits (positive)
    if(sign * num < INT_MIN) return INT_MIN;     //base cases if the number exceed the 32-bit signed integer limits (negative)

    return helper(s, i+1, num, sign);     //recursive call for the next character in the string
}

int myAtoi(string s) {  //starting point 
    int num = 0;
    int sign = 1;
    int i = 0;

    while(i<s.size() && (s[i] == ' ')) i++;   //skip all the leading spaces

    if(i<s.size() && (s[i] == '+' || s[i] == '-')){    //check for sign (1 if positive, -1 if negative)
        if(s[i] == '-') sign = -1;
        i++;
    }

    return helper(s, i, num, sign);    //start the recursion once digits arrive
}
