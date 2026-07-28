#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int NthRoot(int N, int M){
    int prod=1;
    int count=0;
    for (int i=1; i<=M; i++){
        prod=prod*N;
        count++;
        if(prod==M){
            return count;
        }else if(prod>M){
            return -1;
        }

    }
    return -1;
}

int main(){
    int N, M;
    cout<<"Enter a number: ";
    cin>>N;
    cout<<"Enter the root: ";
    cin>>M;
    int result = NthRoot(N, M);
    if(result != -1){
        cout<<"The "<<M<<"th root of "<<N<<" is "<<result<<endl;
    }else{
        cout<<"The "<<M<<"th root of "<<N<<" does not exist."<<endl;
    }
    return 0;
}