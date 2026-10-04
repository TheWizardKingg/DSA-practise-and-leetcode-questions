#include<iostream>
#include<string>
using namespace std;

bool checkValidString(string s) {
    int minOpen = 0;
    int maxOpen = 0;

    for(char x: s){

        if(x == '('){
            minOpen++;
            maxOpen++;
        }else if(x == ')'){
            minOpen--;
            maxOpen--;
        }else if(x == '*'){
            minOpen--;
            maxOpen++;
        }

        if(maxOpen < 0) return false;

        if(minOpen < 0) minOpen = 0;
    }
    return minOpen == 0;
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