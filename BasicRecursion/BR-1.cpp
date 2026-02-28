#include<iostream>
using namespace std;
int n=0;
int i=0;

//this function is to print something n times using recursion

void Print_N_Times(){
    if (n==10){
        return;
    }
    cout<<"This is recursion's fundamental logic "<<n+1<<endl;
    n++;
    Print_N_Times();
}

//below function is to print sum of first 10 natural numbers using recursion

void Sum_N_numbers(int sum){
    if(i==10){
        cout<<"Sum of first 10 natural numbers is: "<<sum<<endl;
        return ;
    }
    sum+=i+1;
    i++;
    Sum_N_numbers(sum);
}

int main(){
    cout<<"-----Printing Ten Times-----"<<endl;
    Print_N_Times();
    cout<<"-----Sum of first 10 natural numbers-----"<<endl;
    Sum_N_numbers(0);
}

//just make sure u have a base case to stop avoid infinite calls, and then make sure to update the parameters in the recursive calls

