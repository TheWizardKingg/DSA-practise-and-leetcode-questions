#include<iostream>
using namespace std;
int main(){
    int arr[6]={2,0,2,1,1,0};
    int zero=0;
    for (int i=0; i<6; i++){
        if (arr[i]==0){
            swap(arr[i],arr[zero]);
            zero++;
        }
    }
    int one=zero;
    for (int i=zero; i<6; i++){
        if (arr[i]==1){
            swap(arr[i],arr[one]);
            one++;
        }
    }
    int k=0;
    while(k<6){
        cout<<arr[k]<<endl;
        k++;
    }return 0;
}

//literally took loops individually and looked in the array each element wise
//first threw all zeros in the array in the front
//then threw all the ones after the zeros
//and after the ones, the rest of the array already became sorted cause it had only 2s, lol
//leetcode 75:https://leetcode.com/problems/sort-colors/description/