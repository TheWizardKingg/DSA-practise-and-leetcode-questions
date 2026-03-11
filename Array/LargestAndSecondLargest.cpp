#include<iostream>
using namespace std;
int main(){
    int arr[5]={1,2,4,3,5};
    int largest=arr[0];
    int second_largest=arr[0];
    for (int i=0; i<5; i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }

    for (int i=0; i<5; i++){
        if(arr[i]==largest){
            continue;
        }else if(arr[i]>second_largest){
            second_largest=arr[i];
        }
    }

    cout<<"The largest element in the array is: "<<largest<<endl;
    cout<<"The second largest element in the array is: "<<second_largest<<endl;
    return 0;
}

//ur trolling at this point bro XD