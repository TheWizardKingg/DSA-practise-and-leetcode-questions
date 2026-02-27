#include<iostream>
using namespace std;
bool PalindromeOrNot(int number){
    int num=number;
    int rev=0;
    while (num>0){
        int rem=num%10;
        rev=rev*10+rem;
        num=num/10;
    }
    if(number==rev){
        return true;
    }
    return false;
}
int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    if(PalindromeOrNot(num)){
        cout<<"The number is a palindrome.";
    }
    else{
        cout<<"The number is not a palindrome.";
    }
    return 0;
}

//keep dividing by 10, store remainder, make a rev variable, multiply it by 10 and add rem
//repeat this process and keep updating/dividing the num by 10 until it becomes zero. then compare the original number with the rev variable
//if they are equal then it's a palindrome otherwise it's not.