#include<iostream>
using namespace std;
int i=0;
int table(int n){
    i++;
    if (i>10){
        return 1;
    }
    cout<<n<<" x "<<i<<" = "<<n*i<<endl;
    return table(n);

}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    table(n);
    return 0;
}