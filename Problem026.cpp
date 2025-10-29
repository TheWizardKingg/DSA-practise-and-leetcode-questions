#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main(){
    vector<char> chars={'a','a','b','b','c','c','c','d'};
    int count=0;
    int index=0;
    char temp;
    for (int i=0; i<chars.size(); i++){
        temp=chars[i];
        while(temp==chars[i] && i<chars.size()){
            count++;
            i++;
        }
        if (count==1){
            chars[index++]=temp;
        }else{
            chars[index++]=temp;
            string multinum=to_string(count);
            for (char c: multinum){
                chars[index++]=c;
            }
        }
        i--;
        count=0;
    }
    chars.resize(index);
    for (char c: chars){
        cout<<c<<" ";
    }
    return 0;
}