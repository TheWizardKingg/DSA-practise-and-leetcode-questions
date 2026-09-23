#include<iostream>
using namespace std;

double myPow(double x, int n) {
    long long N = n;
    if(N<0){
        N = -N;
        x = 1/x;
    }
    if(N==0) return 1;
    if(N%2 == 0){
        double half = myPow(x, N/2);
        return half*half;
    }
    return x*myPow(x,N-1);
}

int main(){
    double x;
    int n;
    cout<<"Enter the value of x: ";
    cin>>x;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"The value of "<<x<<" raised to the power "<<n<<" is: "<<myPow(x,n)<<endl;
    return 0;
}