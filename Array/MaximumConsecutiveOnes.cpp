#include<iostream>
using namespace std;
int findMaximumOnes(int arr[], int n){
    int MaxOnes=0;
    for (int i=0; i<n; i++){
        if(arr[i]==1){
            int tempCount=0;
            while(arr[i]==1){
                tempCount++;
                i++;
            }
            MaxOnes=max(tempCount, MaxOnes);

        }
    }
    return MaxOnes;
}
int main(){
    int arr[]={1,1,0,1,1,1,1,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum consecutive ones are: "<<findMaximumOnes(arr,n)<<endl;
}

//just run a loop to skip till the first 1 is found
//after that, run another while loop until that chunk of 1's is finished and count the number of 1's in that chunk
//keep track of the maximum number of 1's found in any chank and eventually return the maximum number of 1's found in any chunk.