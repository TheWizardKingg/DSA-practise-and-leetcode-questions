#include<iostream>
#include<string>
using namespace std;

string largestOddNumber(string num) {
    for(int i=num.size()-1; i>=0; i--){    //start checking from the last digit, and if any odd digit is found, return substring from 0 to that index    
        if(num[i] % 2 != 0){               //because every odd number ends with an odd digit, 
            return num.substr(0,i+1);      //so as soon as the odd digit is found, 0 to that index substring will be the largest odd number
        }
    }
    return "";     //return empty string otherwise, if no odd digit exists
}


int main(){
    string num;
    cin>>num;
    cout<<largestOddNumber(num);
    return 0;
}