#include<iostream>
using namespace std;

bool isPrime(int num){
    for(int i=2; i*i<=num; i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    if(isPrime(num)){
        cout<<"The number is a prime number.";
    }
    else{
        cout<<"The number is not a prime number.";
    }
    return 0;
}

//just run a loop till the square root of that number
//cause the factors start repeating after the square root value of that number
//if the number is divisible by any number in that range then it's not a prime number otherwise it is.
