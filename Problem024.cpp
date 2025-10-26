#include<iostream>
#include<vector>
using namespace std;
bool isSame(vector<int> a, vector<int> b){
    for (int i=0; i<26; i++){
        if (a[i]!=b[i]){
            return false;
        }
    }
    return true;
}
bool checkInclusion(string s1, string s2) {
    if (s1.length()>s2.length()) return false;
    vector<int> freqArr(26,0);
    int k=0;
    for (int i=0; i<s1.length(); i++){
        freqArr[s1[i]-'a']++;
    }
    for (int j=0; j<s2.length()-s1.length()+1; j++){
        vector<int> freq2Arr(26,0);
        k=0;
        int index=j;
        while(k<s1.length()){
            
            freq2Arr[s2[index]-'a']++;
            index++;
            k++;
        }
        if (isSame(freqArr, freq2Arr)){
            return true;
        }
        
    }
    return false;
}
int main(){
    string s2="eidbaooo";
    string s1="ab";
    if (checkInclusion(s1, s2)){
        cout<< "The substring exists as a permutation"<<endl;
    }else{
        cout<<"The substring does not exist as a permutation"<<endl;
    }
    return 0;
}

// Problem: permutation in string on leetcode
// we just make two vectors, first stores no. of characters frequencies in s1, and the other stores the same for s2
// then we just check in each iteration whether the first vector for s1, and the second vector (modifying the second vector for each window) are same or not
// if same: true, else: false!