#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string removeOuterParentheses(string s) {
    string answer = "";
    int n = s.length();

    for(int i=0; i<n; i++){
        if(s[i] == '('){
            int counter=1;
            int startIdx=i;

            while(counter > 0){
                i++;
                if(s[i] == '(') counter++;
                else counter--;

                if(counter == 0){
                    answer += s.substr(startIdx+1, i-startIdx-1);
                }
            }
        }
    }
    return answer;
}

int main(){
    string s = "(()())(())";
    cout << removeOuterParentheses(s) << endl; // Output: "()()()"
    return 0;
}