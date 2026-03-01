#include<iostream>
#include<string>
#include<cctype>
using namespace std;
bool isPalindrome(string s){
    int left=0;
    int right=s.length()-1;
    
    while(left<right){                                             //1st loop
        while(left<right && !isalpha(s[left])){                    //2nd loop
            left++;
        }
        while(left<right && !isalpha(s[right])){                   //3rd loop
            right--;
        }
        if ( tolower( s[left] )  !=  tolower( s[right] )) {         //4th condition
            return false;
        }
        left++;
        right--;
    }
    return true;
    

}
int main(){
    string s;
    cout<<"Enter a string: ";
    getline(cin, s);
    
    if (isPalindrome(s)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    
    return 0;
}
// in this program, the first loop is iterates through the whole string
// the second loop is to skip the non alphabetic characters from the left side
// the third loop is to skip the no alphabetic characters from the right side
// the fourth condition finally checks if the characters match each other from right and left side