#include<iostream>
using namespace std;
int HCF(int number1, int number2){
    if(number1==0){
        return number2;
    }else if(number2==0){
        return number1;
    }
    HCF(max(number1,number2)%min(number1,number2),min(number1,number2));
}
int main(){
    int num1,num2;
    cout<<"Enter the first number: ";
    cin>>num1;
    cout<<"Enter the second number: ";
    cin>>num2;
    cout<<"The HCF of the two numbers is: "<<HCF(num1,num2);
    return 0;
}
//we just follow the Euclidean algorithm to find the HCF of two numbers. 
//we check if either of the numbers is zero, if it is then we return the other number as the HCF.
//if both numbers are non-zero then we call the HCF function recursively 
//by passing the remainder of the larger number divided by the smaller number and the smaller number itself until one of the numbers becomes zero.