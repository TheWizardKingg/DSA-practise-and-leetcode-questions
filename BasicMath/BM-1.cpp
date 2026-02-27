#include<iostream>
using namespace std;
int countDigitsOfNumber(int num){
    int n=num;
    int i=1;
    for (i=1; n!=0; i++){
        n=n/10;
    }
    return i-1;

}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"There are "<<countDigitsOfNumber(n)<<" digits in the number"<<endl;
    return 0;
}

//we just keep dividing by 10, until it becomes zero, once it is zero, just return the "i-1" 