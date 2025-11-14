#include<iostream>
using namespace std;
int n=50;
int SUM(int n){
    if (n==0){
        return 0;
    }
    return SUM(n-1);
}
int main(){
    cout<<"Sum is: "<<SUM(n);
    return 0;
}