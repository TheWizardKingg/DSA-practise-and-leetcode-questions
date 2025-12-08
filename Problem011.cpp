#include<iostream>
using namespace std;
int main(){
    int arr[5]={4,1,5,2,3};
    int temp,k=0,l=0;
    for (int i=1; i<5; i++){
        for (int j=0; j<=k; j++){
            if (arr[i]<arr[j]){
                swap(arr[i],arr[j]);
            }
        }
        k++;
    }
    while (l<5){
        cout << arr[l]<< " ";
        l++;
    }
    return 0;

}
//insertion sort program