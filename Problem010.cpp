#include<iostream>
using namespace std;
int main(){
    int arr[5]={4,1,5,2,3};
    int i,k=0,index,j=0;
    while (j<5){
        int min=arr[j];
        for (i=j;i<5;i++){
            if (arr[i]<=min){
                index=i;
                min=arr[i];
            }
            
        }
        swap(arr[j],arr[index]);
        j++;
    }
    while (k<5){
        cout << arr[k]<< " ";
        k++;

    }
    return 0;
}