#include<iostream>
#include<cmath>
using namespace std;
int countDigitsOfNumber(int num){
    int n=num;
    int i=1;
    for (i=1; n!=0; i++){
        n=n/10;
    }
    return i-1;

}
int countDigitsOfNumberUsingLog(int num){
    return (int)log10(num)+1;
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"There are "<<countDigitsOfNumber(n)<<" digits in the number"<<endl;
    cout<<"There are "<<countDigitsOfNumberUsingLog(n)<<" digits in the number using log method"<<endl;
    return 0;
}

//we just keep dividing by 10, until it becomes zero, once it is zero, just return the "i-1" 
//we can also use log10 to find the number of digits, because log10 of a number gives us the power to which 
// 10 must be raised to get that number, so if we add 1 to that, we get the number of digits in that number.