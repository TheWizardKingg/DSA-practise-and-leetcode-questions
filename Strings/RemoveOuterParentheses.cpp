#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string removeOuterParentheses(string s) {
    string answer = "";   //final answer empty string
    int n = s.length();

    for(int i=0; i<n; i++){
        if(s[i] == '('){     //if we find opening bracket
            int counter=1;     //start the counter from 1
            int startIdx=i;      //note the starting index of the outermost opening bracket

            while(counter > 0){    //run a loop until the outermost closing bracket appears (basically until counter becomes 0 again)
                i++;
                if(s[i] == '(') counter++;    //if we find opening bracket, increment counter
                else counter--;      //if we find a closing bracket, decrement counter, eventually when outermost closing bracket appears, counter will be 0

                if(counter == 0){     //when counter 0
                    answer += s.substr(startIdx+1, i-startIdx-1);   //add the substring between the outermost opening and closing brackets to the answer
                }
            }
        }
    }

    return answer;    //return the answer string
}

int main(){
    string s = "(()())(())";
    cout << removeOuterParentheses(s) << endl; // Output: "()()()"
    return 0;
}