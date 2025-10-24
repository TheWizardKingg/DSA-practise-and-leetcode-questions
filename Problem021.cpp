#include<iostream>
#include<string>
using namespace std;
int main(){
    string str="Mohit Sharma";
    int st=0, end=str.length()-1;
    while(st<end){
        swap(str[st],str[end]);
        st++;
        end--;
    }
    for(auto i: str){
        cout<<i;
    }
    return 0;
}

// I know this program doesn't deserve to be in this repo, but hey, who cares :P