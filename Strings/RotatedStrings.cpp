#include<iostream>
#include<string>
using namespace std;

bool rotateString(string s, string goal) {
    if(s.size() != goal.size()) return false;      //if the size is not equal, then it can't ever be its rotation

    int k = goal.size();

    for(int i=0; i<k; i++){     //basically search goal string till we find the first letter of s in it
        if(s[0] == goal[i]){
            int idx = i;
            int j = 0;
            int iterations = 0;

            while(s[j] == goal[idx % k]){   //after finding the first char, we then check for the whole string, if it matches, we return true
                j++;
                idx++;
                iterations++;
            }
            if(iterations == s.size()) return true;

        }
    }
    return false;   //return false if all the loops ran but didn't find any permutation of s in goal string
}

int main(){
    string s, goal;
    cin >> s >> goal;

    if(rotateString(s, goal)){
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}