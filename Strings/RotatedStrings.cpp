#include<iostream>
#include<string>
using namespace std;

bool rotateString(string s, string goal) {
    if(s.size() != goal.size()) return false;

    int k = goal.size();

    for(int i=0; i<k; i++){
        if(s[0] == goal[i]){
            int idx = i;
            int j = 0;
            int iterations = 0;

            while(s[j] == goal[idx % k]){
                j++;
                idx++;
                iterations++;
            }
            if(iterations == s.size()) return true;

        }
    }
    return false;
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