#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix){
    int row=matrix.size();
    int col=matrix[0].size();

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            
            if( i < j ){
                swap(matrix[i][j], matrix[j][i]);
            }

        }
    }

    int leftPtr=0;
    int rightPtr=col-1;

    for(int i=0; i<row; i++){
        while(leftPtr <= rightPtr){
            swap(matrix[i][leftPtr], matrix[i][rightPtr]);
            leftPtr++;
            rightPtr--;
        }
        leftPtr=0;
        rightPtr=col-1;
    }
}

int main(){
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};

    rotate(matrix);

    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}