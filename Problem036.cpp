#include<iostream>
using namespace std;
int main(){
    int mat[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int sumdiagonal=0;
    for (int i=0; i<3; i++){
        sumdiagonal+=mat[i][i];
    }
    cout<<"Sum of main diagonal is: "<<sumdiagonal<<endl;
    int secondary_diag=0;
    for (int i=0; i<3; i++){
        for (int j=2; j>=0; j--){
            if (i+j==2){
                secondary_diag+=mat[i][j];
            }
        }
    }
    cout<<"Sum of secondary diagonal is: "<<secondary_diag<<endl;
    return 0;
}

// sum of main and secondary diagonal of a square matrix