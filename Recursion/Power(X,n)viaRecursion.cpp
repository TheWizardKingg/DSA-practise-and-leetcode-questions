#include<iostream>
using namespace std;

double myPow(double x, int n) {
    long long N = n;
    if(N<0){     //handle the negative powers case by converting it to positive and taking reciprocal of x, rest everything is same
        N = -N;
        x = 1/x;
    }
    if(N==0) return 1;     //base case
    if(N%2 == 0){      //until the power is divisible by 2, we keep halving the power and multiplying the result with itself
        double half = myPow(x, N/2);
        return half*half;
    }
    return x*myPow(x,N-1);   //if power is odd, we reduce the power by 1, and repeat the process of halving the exponent until base case
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