#include<iostream>
using namespace std;
int main(){
    int mat[3][3];
    cout<<"Enter elements of matrix"<<endl;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cin>>mat[i][j];
        }
    }
    cout<<"Matrix is: "<<endl;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
//took input of a 3x3 matrix from user and displayed it
//basic 2D array input output