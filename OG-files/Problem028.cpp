#include<iostream>
using namespace std;
int n=3;
void fibo(int a, int b){
    if (n==10){
        return;
    }
    n++;
    int temp;
    temp=a;
    a=b;
    b=a+temp;
    cout<<b<<" ";
    return fibo(a,b);
    
}
int main(){
    int a=0;
    cout<<a<<" ";
    int b=1;
    cout<<b<<" ";
    fibo(a,b);
    return 0;
}