#include<iostream>
using namespace std;
int main(){
    int target,mat[3][3];
    cout<<"Enter elements of matrix"<<endl;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cin>>mat[i][j];
        }
    }
    cout<<"Enter the target to search: ";
    cin>>target;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (mat[i][j]==target){
                cout<<"wo rha sala bhadwa ("<<i<<","<<j<<")"<<endl;
                break;
            }
        }
    }
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (mat[i][j]==target){
                cout<<"("<<mat[i][j]<<")"<<" ";
            }else{
                cout<<mat[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;

}
// just increasing no. of problems, cause why not and who cares
// who tf reads readme files anyway
