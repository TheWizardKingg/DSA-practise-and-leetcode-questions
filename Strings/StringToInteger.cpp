#include<iostream>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;

int myAtoi(string s) {
    long long sum = 0;
    bool isNeg = false;
    int i = 0;
      
    while(i < s.size() && s[i] == ' ') {     //skip the leading spaces 
        i++;
    }

    if(i < s.size() && s[i] == '-') {    //check whether - or + occurs after skipping spaces or any 0z
        isNeg = true;
        i++;
    }else if(i < s.size() && s[i] == '+') {   
        i++;
    }

    while(i < s.size() && s[i] >= '0' && s[i] <= '9') {     //now start adding the string as integer into the sum and check for overflow every time
        sum = sum * 10 + (s[i] - '0');

        if(!isNeg && sum > INT_MAX)   //round off to 2^31 - 1
            return INT_MAX;

        if(isNeg && -sum < INT_MIN)   //round off to -2^31
            return INT_MIN;

        i++;
    }

    if(isNeg)
        sum = -sum;    //return negative number if string is negative 

    return (int)sum;     //return answer as integer as per question's primary requirement
}

int main(){
    string s = "-42abs";
    cout << myAtoi(s)<<endl;
    return 0;
}