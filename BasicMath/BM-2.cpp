#include<iostream>
using namespace std;
int ReverseTheNumber(int num){
    int rem=0;
    int rev=0;
    while(num!=0){
        rem=num%10;
        rev=rev*10+rem;
        num=num/10;
    }
    return rev;
}
int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    cout<<"The reverse of the number is: "<<ReverseTheNumber(num);
    return 0;
}

//just divide the number by 10, store the remainder, make a rev variable, multiply it by 10 and add rem
//repeat this process and keep updating/dividing the num by 10 until it becomes zero. ur chillin