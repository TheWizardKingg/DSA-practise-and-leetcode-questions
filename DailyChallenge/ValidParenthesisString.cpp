#include<iostream>
#include<string>
using namespace std;

bool checkValidString(string s) {
    int minOpen = 0;    //least number of possible open parenthesis pairs if we treat '*' as ')'
    int maxOpen = 0;    //max number of possible open parenthesis pairs if we treat '*' as '('

    for(char x: s){

        if(x == '('){
            minOpen++;      //increase both minOpen and maxOpen brackets possibilities
            maxOpen++;
        }else if(x == ')'){
            minOpen--;      //decrease both minOpen and maxOpen brackets possibilities
            maxOpen--;
        }else if(x == '*'){
            minOpen--;     //minOpen decreases because what if we treat '*' as ')'
            maxOpen++;     //maxOpen increases because what if we treat '*' as '('
        }

        if(maxOpen < 0) return false;    //if maximum brackets possible is lesser than 0 [even after treating '*' as '('] then string is invalid

        if(minOpen < 0) minOpen = 0;     //minimum possible brackets can't be negative ofc
    }
    return minOpen == 0;     //if there are any unmatched open brackets present, then ofc its invalid
}

int main(){
    string s = "(*))";
    if(checkValidString(s)){
        cout << "Valid" << endl;
    }else{
        cout << "Invalid" << endl;
    }
    return 0;
}