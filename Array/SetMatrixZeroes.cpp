#include<iostream>
#include<utility>
#include<vector>
using namespace std;
void SetMatrixZeroes(vector<vector<int>>& matrix){
    pair<int,int> tempPair;            //we make a temporary pair to store the coordinates of all the zeroes in the matrix
    vector<pair<int,int>> tempVector;     //store those coordinates of all zeroes in the matrix
    int rows=matrix.size();             //row size
    int cols=matrix[0].size();         //column size 
    int totalzeros=0;
    for(int i=0; i<rows; i++){           //this is just a nested loop to find and store all the coordinates of zeroes in the matrix
        for(int j=0; j<cols; j++){
            if(matrix[i][j]==0){
                tempVector.push_back({i,j});
                totalzeros++;
            }
        }
    }
     
    for(int zeroCounter=totalzeros-1; zeroCounter>=0; zeroCounter--){ //this loop is to one by one iterate over all the coordinates in the tempVector
        tempPair=tempVector[zeroCounter];       //temporarily store that coordinate in tempPair for easiness of access 
        for(int tempCounter=0; tempCounter<rows; tempCounter++){      //this loop simply turns the entire row of that zero into zeroes 
            matrix[tempPair.first][tempCounter]=0;
        }
        for(int tempCounter=0; tempCounter<cols; tempCounter++){        //this loop simply turns the entire column of that zero into zeroes
            matrix[tempCounter][tempPair.second]=0;
        }
        tempVector.pop_back();           //we remove that coordinate once its entire row and column has been turned into zeroes
    }
}

int main(){
    vector<vector<int>> matrix={{1,1,1},{1,0,1},{1,1,1}};
    SetMatrixZeroes(matrix);
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
