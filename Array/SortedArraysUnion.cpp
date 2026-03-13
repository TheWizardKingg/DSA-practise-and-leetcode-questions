#include<iostream>
using namespace std;
int* UnionArray(int arr1[], int size1, int arr2[], int size2){
    int* UnionArray= new int[size1+size2];   // just using a pointer to create an array in heap memory
    int i=0, j=0, k=0;                      //so that we can return this pointer to main function
    while (i<size1 && j<size2){            //cause when function ends, all local variables/arrays are gone
        if(arr1[i]<arr2[j]){              //  
            UnionArray[k++]=arr1[i++];
        }else if(arr1[i]>arr2[j]){
            UnionArray[k++]=arr2[j++];
        }else{
            UnionArray[k++]=arr1[i];
            i++;
            j++;
        }
    }
    while(i<size1){
        UnionArray[k++]=arr1[i++];
    }
    while(j<size2){
        UnionArray[k++]=arr2[j++];
    }
    return UnionArray;
}
int main(){
    int arr1[]={1,2,4,5,6};
    int arr2[]={2,3,5,7};
    int size1=5;
    int size2=4;
    int* UnionArr=UnionArray(arr1,size1,arr2,size2);
    for(int i=0; i<size1+size2; i++){
        cout<<UnionArr[i]<<" ";
    }
    return 0;
}

//we may see zeroes at the end because there might be duplicate values in both arrays, (union picks only once)
//we just create a new array of size(size1+size2) in heap memory in order to return array
//both arrays are sorted hence we insert whichever is smaller, then add the remaining elements of both arrays
