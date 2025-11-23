#include<iostream>
using namespace std;
int main(){
    int mat[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int maxrow=0, maxcol=0;
    int sumrow=0, sumcol=0;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            sumrow+=mat[i][j];
        }
        maxrow=max(maxrow,sumrow);
        sumrow=0;
    }
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            sumcol+=mat[j][i];
        }
        maxcol=max(maxcol,sumcol);
        sumcol=0;
    }
    cout<<"Max row sum is: "<<maxrow<<endl;
    cout<<"Max column sum is: "<<maxcol<<endl;
    return 0;
}

// finding max row and col sum 
// only works for square matrixes (especially 3 by 3 in this program)