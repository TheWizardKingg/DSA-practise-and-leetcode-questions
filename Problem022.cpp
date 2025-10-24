#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    // string str1="RacecaR";
    // string str2=str1;
    // reverse(str2.begin(),str2.end());
    // if (str1==str2){
    //     cout<<"String is a pallindrome";
    // }else{
    //     cout<<"string is not a pallindrome";
    // }
    // return 0;
    string str1="Racecar";
    int st=0, end=str1.length()-1;
    while(st<end){
        if (str1[end--]!=str1[st++]){
            cout<<"string is not a pallindrome";
            return 0;
        }
    }
    cout<<"String is a pallindrome"<<endl;
    return 0;

}