#include<iostream>
#include<vector>
using namespace std;

int floorSqrt(int n)  {
    int number=1;
    int start=1;
    int end=n;
    int mid;

    while(start<=end){
        mid=start+(end-start)/2;

        if(mid*mid == n){
            return mid;
        }else if(mid*mid < n){
            start=mid+1;
        }else if(mid*mid > n){
            end=mid-1;
        }
    }
    return mid-1;
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"The floor of square root of "<<n<<" is "<<floorSqrt(n)<<endl;
    return 0;
}