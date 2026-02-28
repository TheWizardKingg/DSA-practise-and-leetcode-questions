#include<iostream>
using namespace std;
int n=0;
void Print_N_Times(){
    if (n==10){
        return;
    }
    cout<<"This is recursion's fundamental logic "<<n+1<<endl;
    n++;
    Print_N_Times();
}
int main(){
    cout<<"-----Printing Ten Times-----"<<endl;
    Print_N_Times();
}