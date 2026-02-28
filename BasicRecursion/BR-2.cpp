#include<iostream>
using namespace std;

int Factorial(int n){
    if(n==1){
        return 1;
    }
    return n*Factorial(n-1);
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"Factorial of "<<n<<" is: "<<Factorial(n)<<endl;
    return 0;
}

//again, just make sure to update the parameters in the recursive calls, like i did by decreasing n each call by 1
//also, make sure to have a base case to stop the infinite calls, like i did by returning 1 when n is 1