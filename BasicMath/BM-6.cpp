#include<iostream>
using namespace std;

void PrintAllDivisiors(int num){
    for (int i=1; i<=num/2; i++){
        if (num%i==0){
            cout<<i<<endl;
        }
    }
}

int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    cout<<"The divisors of the number are: "<<endl;
    PrintAllDivisiors(num);
    return 0;
}

//just run a loop till half of the number's value, and print every number that divides that number completely
