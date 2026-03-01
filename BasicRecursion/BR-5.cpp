#include<iostream>
using namespace std;

int Fibonacci(int n){
    if(n<=1){
        return n;
    }
    return Fibonacci(n-1)+Fibonacci(n-2);
}

int main(){
    int n;
    cout<<"Enter the number of terms: ";
    cin>>n;
    
    cout<<"Fibonacci series: ";
    for(int i=0; i<n; i++){
        cout<<Fibonacci(i)<<" ";
    }
    
    return 0;
}

//this function just takes in the number of terms, and then calculates the sum of it's previous two terms
//now those two terms are also calculated by this funtion (recursion) and added together for the final result
//the loop in the main function just iterates till the number of terms entered by the user and then calls the Fibonnaci function for each term
//then for each term, the Fibonacci function again recursively keeps calling itself until it reaches the base case 
//that's why the time complexity of this program is O(2^n) (the worst time complexity)
