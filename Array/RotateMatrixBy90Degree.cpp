#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix){
    int row=matrix.size();
    int col=matrix[0].size();

    for(int i=0; i<row; i++){           //we just transpose the matrix first
        for(int j=0; j<col; j++){
            
            if( i < j ){           //we can also do (i > j) {just keep in mind to swap indices with either i<j, or i>j, }
                swap(matrix[i][j], matrix[j][i]);    //if u use both (i<j || i>j) then u will end up swapping the same elements twice and get the original matrix back
            }                     // i!=j is also fine, but this loop runs across all matrix elements, hence it will later swap the elements a second time, returning the original matrix

        }
    }

    int leftPtr=0;
    int rightPtr=col-1;

    for(int i=0; i<row; i++){            //then simply reverse each row of the matrix to get the final answer
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