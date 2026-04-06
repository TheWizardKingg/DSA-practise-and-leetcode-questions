#include<iostream>
using namespace std;

int findMaxProfit(int arr[], int n){
    int minPrice=arr[0];
    int minPriceIdx;
    for(int i=0; i<n; i++){            //just find the minimum price and its index
        if(arr[i]<minPrice){
            minPrice=arr[i];
            minPriceIdx=i;
        }
    }
    int maxPrice=arr[minPriceIdx];

    for(int i=minPriceIdx; i<n; i++){         //then check if here is any price greater than the minimum price
        if(arr[i]>maxPrice){                  //if there exists price greater than minimum price (after the minimum price index)
            maxPrice=arr[i];                  //then keep updating the maximum price
        }
    }
    return maxPrice-minPrice==0 ? 0 : maxPrice-minPrice;            //return the difference, if no profit is possible then return 0
}

int main(){
    int arr[]={7,1,5,3,6,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<findMaxProfit(arr,n);
    return 0;
}