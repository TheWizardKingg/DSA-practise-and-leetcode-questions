#include<iostream>
#include<string>
using namespace std;

void ReverseTheArray(int arr[], int size, int start, int end){  //simple array reversal function
    while(start<end){
        swap(arr[start++],arr[end--]);
    }
}
void OffsetArrayRotation(int arr[], int size, int offset, string direction){
    if(direction=="left"){                             //or we can use arr[i]=arr[(offset+i)%size] for left rotation, 
        ReverseTheArray(arr,size,0, offset-1);
        ReverseTheArray(arr,size,offset,size-1);
        ReverseTheArray(arr,size,0,size-1);
    }else if(direction=="right"){                      //or we can use arr[i]=arr[(size-offset+i)%size] for right rotation
        ReverseTheArray(arr,size,size-offset,size-1);
        ReverseTheArray(arr,size,0,size-offset-1);
        ReverseTheArray(arr,size,0,size-1);
    }else{
        cout<<"Invalid Direction"<<endl;
    }
}
int main(){
    int arr[5]={1,2,3,4,5};
    int offset=3;
    string direction="right";
    cout<<"original array is: ";
    for (int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"offset: "<<offset<<endl<<"Direction: "<<direction<<endl;
    OffsetArrayRotation(arr, 5, offset, direction);
    cout<<"The array after "<<direction<<" rotation is: ";
    for (int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//we noticed a pattern after left and right rotating the array by k places
//for left rotation, we reverse the first k elements, then reverse the remaining n-k elements and finally reverse the whole array one more time
//for right rotation, we reverse the last k elements, then reverse the first n-k elements and finally reverse the whole array one more time
//we're done, otherwise, we can use arr[i]=arr[(offset+i)%size] for left rotation and arr[i]=arr[(size-offset+i)%size] for right rotation
//we can also use a temporary array to store the original array elements, use the temp array to refer the original elements, modify the original array, delete the temp array
