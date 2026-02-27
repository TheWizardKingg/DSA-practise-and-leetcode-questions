#include<iostream>
#include<cmath>
using namespace std;

int countDigits(int num){
    if(num==0){
        return 1;
    }
    return floor(log10(num)+1);
}

int isArmstrong(int num){
    int n=num;
    int digits=countDigits(num);
    int sum=0;
    while(num>0){
        int rem=num%10;
        sum+=static_cast<int>(round(pow(rem,digits)));
        num=num/10;
    }
    return sum==n;
    
}

int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    if(isArmstrong(num)){
        cout<<"The number is an Armstrong number.";
    }
    else{
        cout<<"The number is not an Armstrong number.";
    }
    return 0;
}

//we first count the number of digits in the number using log10 method
//then we keep dividing the number by 10, and for each digit
//we raise it to the power of the number of digits and add it to sum.
//if sum==n then its an armstrong otherwise not.